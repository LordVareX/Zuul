// Copyright Pandores Marketplace 2023. All Rights Reserved.

#include "SmtpsSocket.h"
#include "Ssl.h"
#include "SocketSubsystem.h"
#include "Sockets.h"
#include "EasyEmail.h"
#include "EmailLibrary.h"
#include "Launch/Resources/Version.h"

#define UI UI_ST

#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>

#undef UI

#include <string>

static const SSL_METHOD* GetSslMethod()
{
#if PLATFORM_ANDROID && ENGINE_MAJOR_VERSION <= 4 && ENGINE_MINOR_VERSION <= 26
	return TLSv1_2_client_method();
#elif (PLATFORM_IOS || PLATFORM_MAC) && ENGINE_MAJOR_VERSION <= 4 && ENGINE_MINOR_VERSION <= 23
	return SSLv23_client_method();
#else
	return TLS_client_method();
#endif
}

static int PrintSslError(const char* Message, size_t Length, void* Data)
{
	FUTF8ToTCHAR Converter(Message, Length);
	UE_LOG(LogEasyEmail, Error, TEXT("SSL error: %s"), Converter.Get());
	return 0;
}

static FString GetOpenSSLError()
{
	BIO* bio = BIO_new(BIO_s_mem());
	ERR_print_errors(bio);
	char* buf;
	size_t len = BIO_get_mem_data(bio, &buf);
	FString Error = UTF8_TO_TCHAR(buf);
	BIO_free(bio);
	return Error;
}

FSmtpsSocket::FSmtpsSocket(const bool bStartWithSSL)
	: SslBio (nullptr)
	, Bio    (nullptr)
	, OutBio (nullptr)
	, Context(nullptr)
	, Ssl    (nullptr)
	, bIsSsl (bStartWithSSL)
{
	if (bStartWithSSL)
	{
		InitForSSL();
	}
	else
	{
		InitNoSSL();
	}
}


void FSmtpsSocket::InitForSSL()
{
	ERR_print_errors_cb(&PrintSslError, nullptr);

	const SSL_METHOD* const SslMethod = GetSslMethod();

	Context = SSL_CTX_new(SslMethod);

	if (!Context)
	{
		LastError = TEXT("Failed to create SSL Context.");
		return;
	}

	FSslModule::Get().GetCertificateManager().AddCertificatesToSslContext(Context);

	Bio = BIO_new_ssl_connect(Context);

	if (!Bio)
	{
		LastError = TEXT("Failed to create BIO.");
		return;
	}

	BIO_get_ssl (Bio, &Ssl);
	SSL_set_mode(Ssl, SSL_MODE_AUTO_RETRY);

	OutBio = BIO_new(BIO_f_buffer());

	BIO_push(OutBio, Bio);
}

void FSmtpsSocket::InitNoSSL()
{
	Bio = BIO_new(BIO_s_connect());

	OutBio = BIO_new(BIO_f_buffer());

	BIO_push(OutBio, Bio);
}

void FSmtpsSocket::UpgradeSSL()
{
	if (HasError())
	{
		UE_LOG(LogEasyEmail, Warning, TEXT("UpgradeSSL: Can't upgrade socket with errors."));
		return;
	}

	if (bIsSsl)
	{
		LastError = TEXT("Tried to upgrade socket to SSL but it is already an SSL socket.");
		return;
	}

	const SSL_METHOD* const SslMethod = GetSslMethod();

	Context = SSL_CTX_new(SslMethod);

	if (!Context)
	{
		LastError = TEXT("Failed to create SSL Context.");
		return;
	}

	FSslModule::Get().GetCertificateManager().AddCertificatesToSslContext(Context);

	Ssl = SSL_new(Context);

	if (!Ssl)
	{
		LastError = TEXT("SSL_new failed.");
		SSL_CTX_free(Context);
		return;
	}

	SslBio = BIO_new(BIO_f_ssl());

	BIO_set_ssl(SslBio, Ssl, BIO_CLOSE);

	// Place the SSL bio between the connection and the output
	BIO_pop(OutBio);
	BIO_push(SslBio, Bio);
	BIO_push(OutBio, SslBio);

	const int ConnectCode = SSL_connect(Ssl);
	if (ConnectCode <= 0)
	{
		LastError = FString::Printf(TEXT("Failed to connect SSL. Code: %d - %d - %s."),
			ConnectCode, SSL_get_error(Ssl, ConnectCode), *GetOpenSSLError());
		return;
	}
	
	const int AcceptCode = SSL_accept(Ssl);
	if (AcceptCode <= 0)
	{
		LastError = FString::Printf(TEXT("Failed to accept SSL connection. Code: %d - %d - %s."), 
			AcceptCode, SSL_get_error(Ssl, AcceptCode), *GetOpenSSLError());
		return;
	}

	const int Res = SSL_get_verify_result(Ssl);
	if (Res != X509_V_OK)
	{
		LastError = FString::Printf(TEXT("Error: peer certificate %s."), *FString(X509_verify_cert_error_string(Res)));
		return;
	}

	if (HasError())
	{
		return;
	}

	bIsSsl = true;
}

FSmtpsSocket::~FSmtpsSocket()
{
	UE_LOG(LogEasyEmail, Verbose, TEXT("Destroying SMTP Socket."));

	if (Ssl)
	{
		SSL_free(Ssl);
	}

	// The BIO isn't owned by SSL when we push it afterward. (Upgraded connection)
	if (Bio && SslBio)
	{
		BIO_free(Bio);
	}

	// SSL_free frees the associated BIO for us.
	//if (SslBio)
	//{
	//	BIO_free(SslBio);
	//}

	if (OutBio)
	{
		BIO_free(OutBio);
	}

	if (Context)
	{
		SSL_CTX_free(Context);
	}
	
	
	if (HasError())
	{
		UE_LOG(LogEasyEmail, Warning, TEXT("SMTP Socket destroyed with error: %s"), *LastError);
	}
	else
	{
		UE_LOG(LogEasyEmail, Verbose, TEXT("SMTP Socket destroyed without error."));
	}
}

int32 FSmtpsSocket::Connect(const FString& ServerAddress, const uint16 Port, FString & OutGreetings)
{
	if (HasError())
	{
		UE_LOG(LogEasyEmail, Warning, TEXT("Connect: Connect called on a socket with errors."));
		return 15;
	}

	UE_LOG(LogEasyEmail, VeryVerbose, TEXT("SmtpSocket: Connect() on %s:%d."), *ServerAddress, Port);

	if (!Bio)
	{
		LastError = TEXT("BIO is nullptr.");
		return 16;
	}

	TSharedPtr<FInternetAddr> Address = ResolveHost(ServerAddress, Port);

	if (!Address)
	{
		LastError = TEXT("Failed to solve host.");
		return 17;
	}

	Address->SetPort(Port);

	UE_LOG(LogEasyEmail, VeryVerbose, TEXT("SmtpSocket: Host solved."));

	BIO_set_conn_hostname(Bio, TCHAR_TO_ANSI(*Address->ToString(true)));

	if (BIO_do_connect(Bio) <= 0)
	{
		const auto ErrorCode = ERR_get_error();
		const FString Err(ERR_error_string(ErrorCode, nullptr));
		LastError = FString::Printf(TEXT("Failed to connect to %s. Reason: %s."), *Address->ToString(true), *Err);
		return ErrorCode;
	}

	UE_LOG(LogEasyEmail, VeryVerbose, TEXT("SmtpSocket: BIO_do_connect passed."));

	if (bIsSsl && Ssl && SSL_get_verify_result(Ssl) != X509_V_OK)
	{
		const long Err = SSL_get_verify_result(Ssl); 
		LastError = FString::Printf(TEXT("Certificate verification error. Code: %d. Reason: %s"), 
			Err, UTF8_TO_TCHAR(X509_verify_cert_error_string(Err)));
		return Err;
	}	

	UE_LOG(LogEasyEmail, VeryVerbose, TEXT("SmtpSocket: SSL_get_verify_result passed."));

	OutGreetings = GetBioBuffer();

	return GetCodeFromResponse(OutGreetings);
}

bool FSmtpsSocket::Send(const FString& Data, const bool bSensitiveData, const bool bSplitted, const bool bAllowSplit)
{
	if (HasError())
	{
		return false;
	}

	if (!Bio)
	{
		return false;
	}

	// Don't want to spam the output log with splitted strings.
	if (!bSplitted)
	{
		if (Data.Len() < 256)
		{
			UE_LOG(LogEasyEmail, Verbose, TEXT("Client: %s"), (bSensitiveData ? TEXT("[SENSITIVE DATA]") : *Data));
		}
		else
		{
			UE_LOG(LogEasyEmail, Verbose, TEXT("Client: [LARGE DATA OF LENGTH %d]"), Data.Len());
		}
	}

	const int32 Length = Data.Len();

	BIO* const BioUsed = SslBio ? SslBio : Bio;

	FTCHARToUTF8 Convert(*Data);

	const char* const DataToSend = Convert.Get();
	const int32 StrLength = Convert.Length();

	constexpr int32 MaxDataSizeForSplitting = 1024 * 128; /* Splits if > 1MB. */

	// We split large data.
	if (bAllowSplit && StrLength > MaxDataSizeForSplitting)
	{
		constexpr int32 ChunkSplitSize = 76;

		for (int32 i = 0; i < Length / ChunkSplitSize + 1; ++i)
		{
			const int32 ChunkStart = i * ChunkSplitSize;
			const int32 ChunkSize = FMath::Min(ChunkSplitSize, FMath::Max(StrLength - i * ChunkSplitSize, 0));

			int32 Written = 0;
			int32 Write = 0;

			if (i > 0)
			{
				BIO_write(BioUsed, "\n", 1);
			}

			while (Written < ChunkSize)
			{
				Write = BIO_write(BioUsed, DataToSend + ChunkStart + Written, ChunkSize - Written);

				if (Write < 0)
				{
					LastError = "Failed to write to BIO.";
					return false;
				}

				Written += Write;

			}
		}
	}
	else
	{
		int32 Written = 0;
		int32 Write   = 0;

		while (Written < StrLength)
		{
			Write = BIO_write(BioUsed, DataToSend + Written, StrLength - Written);

			if (Write < 0)
			{
				LastError = "Failed to write to BIO.";
				return false;
			}

			Written += Write;
		}
	}

	return true;
}

int FSmtpsSocket::SendCommand(const FString& Command, FString& OutResponse, const bool bSensitiveData)
{	
	if (HasError())
	{
		return 19;
	}

	OutResponse.Empty();
	
	if (!Send(Command, bSensitiveData))
	{
		OutResponse = LastError = TEXT("Failed to send command: ") + (bSensitiveData ? TEXT("[SENSITIVE DATA]") : LastError);
		return -1;
	}
	
	OutResponse = GetBioBuffer();

	const int32 ResponseCode = GetCodeFromResponse(OutResponse);

	if (ResponseCode == -1)
	{
		OutResponse = LastError = TEXT("Invalid response from server: ") + OutResponse;
	}

	return ResponseCode;
}

namespace
{
	// Pre 4.25 versions don't have AppendCharacters
	template<typename CharType>
	void AppendCharacters(TArray<TCHAR>& Out, const CharType* Str, int32 Count)
	{
		check(Count >= 0);

		if (!Count)
		{
			return;
		}

		checkSlow(Str);

		const int32 OldNum = Out.Num();

		// Reserve enough space - including an extra gap for a null terminator if we don't already have a string allocated
		Out.AddUninitialized(Count + (OldNum ? 0 : 1));

		TCHAR* Dest = Out.GetData() + OldNum - (OldNum ? 1 : 0);

		// Copy characters to end of string, overwriting null terminator if we already have one
		FPlatformString::Convert(Dest, Count, Str, Count);

		// (Re-)establish the null terminator
		Dest[Count] = '\0';
	}
};


FString FSmtpsSocket::GetBioBuffer(const bool bSensitiveData)
{
	if (!OutBio)
	{
		return TEXT("002 Invalid Out BIO buffer.");
	}

	FString BufferString;

	constexpr int32 BufferSize = 1024;

	ANSICHAR Buffer[BufferSize];

	const int32 Read = BIO_gets(OutBio, Buffer, BufferSize);

	if (Read > 0)
	{
		AppendCharacters(BufferString.GetCharArray(), reinterpret_cast<const ANSICHAR*>(Buffer), Read);
		//BufferString.AppendChars(reinterpret_cast<const ANSICHAR*>(Buffer), Read);
		
		BufferString = UEmailLibrary::FormatSmtpResponse(BufferString);
		UE_LOG(LogEasyEmail, Verbose, TEXT("Server: %s"), (bSensitiveData ? TEXT("[SENSITIVE DATA]") : *BufferString));
	}

	else
	{
		UE_LOG(LogEasyEmail, Verbose, TEXT("BIO was empty: no response from server. Return code: %d."), Read);
	}


	return BufferString;
}

TArray<FString> FSmtpsSocket::EmptyBuffer()
{
	TArray<FString> FullBuffer;
	FString BufferLine;

	do
	{
		BufferLine = GetBioBuffer();

		if (BufferLine.Len() > 0)
		{
			FullBuffer.Emplace(BufferLine);
		}
	} while (BufferLine.Len() > 0 && BIO_ctrl_pending(OutBio) > 0);

	return FullBuffer;
}

TSharedPtr<FInternetAddr> FSmtpsSocket::ResolveHost(const FString& Host, const uint16 Port)
{
	static TMap<FString, FString> CachedAddresses;

	{ // Cache already solved Hosts
		const FString* const Cache = CachedAddresses.Find(Host);
		if (Cache)
		{
			TSharedPtr<FInternetAddr> Address = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();

			bool bValid = false;

			Address->SetIp(**Cache, bValid);

			if (bValid)
			{
				Address->SetPort(Port);

				UE_LOG(LogEasyEmail, Verbose, TEXT("ResolveHost: Host \"%s\" solved from cache to %s."), *Host, *Address->ToString(true));

				return Address;
			}
		}
	}

#if ENGINE_MAJOR_VERSION <= 4 && ENGINE_MINOR_VERSION <= 22
	const FAddressInfoResult Res = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetAddressInfo(*Host, nullptr, EAddressInfoFlags::Default, ESocketProtocolFamily::None, SOCKTYPE_Unknown);
#else
	const FAddressInfoResult Res = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetAddressInfo(*Host, nullptr, EAddressInfoFlags::Default, NAME_None, SOCKTYPE_Unknown);
#endif

#if ENGINE_MAJOR_VERSION <= 4 && ENGINE_MINOR_VERSION <= 22
	if (Res.Results.Num() < 1)
#else
	if (Res.ReturnCode != ESocketErrors::SE_NO_ERROR || Res.Results.Num() < 1)
#endif
	{
		LastError = FString::Printf(TEXT("Failed to resolve address %s:%d."), *Host, static_cast<int32>(Port));
		return nullptr;
	}

	TSharedPtr<FInternetAddr> ResolvedAddress = Res.Results[0].Address;

	ResolvedAddress->SetPort(Port);

	CachedAddresses.Add(Host, ResolvedAddress->ToString(false));
	
	UE_LOG(LogEasyEmail, Verbose, TEXT("ResolveHost: Host \"%s\" solved to %s."), *Host, *ResolvedAddress->ToString(true));

	return MoveTemp(ResolvedAddress);
}

int32 FSmtpsSocket::GetCodeFromResponse(const FString& Response) const
{
	if (Response.Len() > 3 && Response[0] <= TEXT('9') && Response[0] >= TEXT('0'))
	{
		return (Response[0] - TEXT('0')) * 100 + (Response[1] - TEXT('0')) * 10 + Response[2] - TEXT('0');
	}
	return -1;
}
