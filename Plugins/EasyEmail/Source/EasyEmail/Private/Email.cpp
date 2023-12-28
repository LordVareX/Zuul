// Copyright Pandores Marketplace 2023. All Rights Reserved.

#include "Email.h"
#include "EasyEmail.h"
#include "SmtpsSocket.h"
#include "Misc/Base64.h"
#include "EmailLibrary.h"
#include "Misc/ScopeLock.h"
#include "IPAddress.h"
#include "Async/TaskGraphInterfaces.h"
#include "Async/AsyncWork.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "Async/Async.h"
#include "Launch/Resources/Version.h"

////////////////////////////////////////////////////////////////
//		
//		Marketplace example.
//		
////////////////////////////////////////////////////////////////
//      UCLASS()
//		class UMyClass
//		{
//			GENERATED_BODY()
//		public:
//			void SendEmail();
//		
//			UFUNCTION() void OnEmailError(const int32 ErroCode) {}
//			UFUNCTION() void OnEmailSent() {}
//		};
//
//		void UMyClass::SendEmail()
//		{
//			UEmail* const Email = UEmail::CreateEmail();
//		
//			// Server config
//			Email->SetServerAddress	(TEXT("smtp.gmail.com"));
//			Email->SetServerPort	(465);
//			Email->SetConnectionType(ESmtpConnectionType::SSL);
//			Email->SetServerType	(ESmtpServerType    ::ESMTP);
//			Email->SetCredentials	(TEXT("MyUsername"), TEXT("MyPassword"));
//		
//			// Email targets
//			Email->SetSender		 (TEXT("myemail@gmail.com"));
//			Email->AddReceiver	     (TEXT("target@gmail.com"));
//			Email->AddBlindCopyCarbon(TEXT("bcc@gmail.com"));
//			Email->AddCopyCarbon	 (TEXT("cc@gmail.com"));
//		
//			// Email content
//			Email->SetSubject       (TEXT("Hello From Unreal"));
//			Email->SetContent       (TEXT("Hello there, this is the Easy Email Plugin."));
//			Email->SetContentCharset(EEmailCharset::utf_8);
//		
//			// Attachments
//			Email->AddFileAsAttachment(TEXT("MyLogo.png"),   TEXT("C:/Users/Me/Logo.png"));										// Auto-detect MIME-Type
//			Email->AddFileAsAttachment(TEXT("MyRawData.bin"),TEXT("C:/Users/Me/binary.bin"), TEXT("application/octet-stream")); // Explicit MIME-Type
//		
//			// Callbacks
//			Email->OnEmailError.AddDynamic(this, &UMyClass::OnEmailError);
//			Email->OnEmailSent .AddDynamic(this, &UMyClass::OnEmailSent);
//		
//			// Finally send the email
//			Email->Send();
//		}
////////////////////////////////////////////////////////////////



#define EXIT_IF_SENDING(...) do {															\
	if (IsEmailSending())																	\
	{																						\
		UE_LOG(LogEasyEmail, Warning, TEXT("Email can't be edited while it is sending."));	\
		return __VA_ARGS__;																	\
	}																						\
 } while (0)

FString UEmail::MimeBoundary = TEXT("=F6C14CEB9B2DDF4AB3F30AC0817D83C0_+e");

/* static */ UEmail* UEmail::CreateEmail()
{
	return NewObject<UEmail>();
}

/* static */ UEmail* UEmail::CreateInitializedEmail(const ESmtpServerType ServerType, const ESmtpConnectionType Connection, const FString& ServerAddress, const int32 Port)
{
	UEmail* const Email = UEmail::CreateEmail();

	Email->SetConnectionType(Connection);
	Email->SetServerType    (ServerType);
	Email->SetServerAddress (ServerAddress);
	Email->SetServerPort    (Port);

	return Email;
}


UEmail::UEmail() 
	: Super()
	, ConnectionType		(ESmtpConnectionType::SSL)
	, ServerType			(ESmtpServerType	::ESMTP)
	, ClientDomain			(TEXT("client.unreal.com"))
	, ContentMime			(TEXT("text/plain"))
	, ContentCharset		(TEXT("UTF-8"))
	, ConcurrentSendingCount(0)
{
	// Default headers
	Headers.Add(TEXT("Content-Type"), TEXT("multipart/mixed; boundary=\"") + MimeBoundary + TEXT("\""));
	Headers.Add(TEXT("MIME-Version"), TEXT("1.0"));

}

bool UEmail::IsEmailSending() const
{
	return ConcurrentSendingCount.Load() > 0;
}

void UEmail::Send()
{
	UE_LOG(LogEasyEmail, Log, TEXT("Sending mail."));

	{ // Prevent leaving the thread if we can't succeed anyway.
		const FString QuickCheckResult = QuickCheck();
		if (QuickCheckResult.Len() > 0)
		{
			UE_LOG(LogEasyEmail, Error, TEXT("Failed to send mail: %s"), *QuickCheckResult);
			BroadcastErrorOnGameThread(-2);
			return;
		}
	}

	/**
	 *	Used to track how many times the same mail is being sent and prevent 
	 *  garbage collection.
	 **/
	struct FEmailSendCountHandler
	{
	public:
		FEmailSendCountHandler(const FEmailSendCountHandler& Counter) : Email(Counter.Email) {}
		FEmailSendCountHandler(class UEmail* const InEmail) : Email(InEmail)
		{
			if (Email.IsValid())
			{
#if ENGINE_MAJOR_VERSION <= 4 && ENGINE_MINOR_VERSION <= 22
				++(Email->ConcurrentSendingCount);
#else
				Email->ConcurrentSendingCount.IncrementExchange();
#endif
				if (Email->ConcurrentSendingCount == 1)
				{
					Email->AddToRoot();
				}
			}
		}
		~FEmailSendCountHandler()
		{
			if (Email.IsValid()) {
				if (Email->ConcurrentSendingCount == 1)
				{
					Email->RemoveFromRoot();
				}
#if ENGINE_MAJOR_VERSION <= 4 && ENGINE_MINOR_VERSION <= 22
				--(Email->ConcurrentSendingCount);
#else
				Email->ConcurrentSendingCount.DecrementExchange();
#endif
			}
		}
		UEmail* GetEmail() const
		{
			if (Email.IsValid())
			{
				return Email.Get();
			}
			return nullptr;
		}
	private:
		TSoftObjectPtr<UEmail> Email;
	};

	FEmailSendCountHandler Counter(this);

	// We create the counter outside and do a copy so the counter does 1->2->1.
	// This way, we are sure the counter is never 0 while a Send is running
	// on another thread. The copy is free anyway.

#if ENGINE_MAJOR_VERSION <= 4 && ENGINE_MINOR_VERSION <= 22
	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [Counter]() -> void
#else
	Async(EAsyncExecution::ThreadPool, [Counter]() -> void
#endif
	{
		UEmail* const Email = Counter.GetEmail();
		if (!Email)
		{
			UE_LOG(LogEasyEmail, Warning, TEXT("Failed to send mail: The Email Object has been garbage collected."));
			return;
		}

		const int32 ResponseCode = Email->SendInternal();
		if (ResponseCode == 250)
		{
			Email->BroadcastSuccessOnGameThread();
		}
		else
		{
			UE_LOG(LogEasyEmail, Error, TEXT("Failed to send mail with error code %d."), ResponseCode);
			Email->BroadcastErrorOnGameThread(ResponseCode);
		}

		Email->RemoveFromRoot();
	});
}

int32 UEmail::SendInternal()
{
	const double Start = FPlatformTime::Seconds();

	int32 LastServerResponse = -1;

	if (!LoadAttachments())
	{
		UE_LOG(LogEasyEmail, Error, TEXT("Failed to send mail: Failed to load attachments."));
		return LastServerResponse;
	}

	UE_LOG(LogEasyEmail, Log, TEXT("Attachments loaded in %f seconds."), FPlatformTime::Seconds() - Start);

	// For debugging purpose
	constexpr bool bCancelOnInvalidResponse = true;

	const bool bIsSsl = ConnectionType == ESmtpConnectionType::SSL;

	UE_LOG(LogEasyEmail, Verbose, TEXT("Creating socket for a connection of type %s. Is SSL: %d."), *UEmailLibrary::SmtpConnectionTypeEnumToString(ConnectionType), bIsSsl);

	FSmtpsSocket SecureSocket(bIsSsl);	

	if (SecureSocket.HasError())
	{
		UE_LOG(LogEasyEmail, Error, TEXT("Failed to initialize SMTP Socket: %s."), *SecureSocket.GetLastError());
		return LastServerResponse;
	}

	UE_LOG(LogEasyEmail, Verbose, TEXT("SMTP Socket created."));
	

	//////////////////////////////////////////////////////////////////////////////////////////////
	//
	//	CONNECTION
	//
	//////////////////////////////////////////////////////////////////////////////////////////////
	{
		FString Greetings;

		LastServerResponse = SecureSocket.Connect(ServerAddress, ServerPort, Greetings);
		if (LastServerResponse != 220)
		{
			if (SecureSocket.HasError())
			{
				UE_LOG(LogEasyEmail, Error, TEXT("Error while trying to connect to host: %s."), 
					*SecureSocket.GetLastError());
			}
			else
			{
				UE_LOG(LogEasyEmail, Error, TEXT("Invalid server response: %s. Expected code 220."), *Greetings);
			}
			return LastServerResponse;
		}
		
		UE_LOG(LogEasyEmail, Verbose, TEXT("Server Greetings: %s."), *Greetings);
	}

	UE_LOG(LogEasyEmail, Verbose, TEXT("SmtpsSocket Connected."));

	FString Response;

	//////////////////////////////////////////////////////////////////////////////////////////////
	//
	//	HELO
	//
	//////////////////////////////////////////////////////////////////////////////////////////////
	LastServerResponse = SecureSocket.SendCommand(GetHelloCommand() + TEXT(" ") + ClientDomain + TEXT("\r\n"), Response);
	if (LastServerResponse != 250)
	{
		UE_LOG(LogEasyEmail, Error, TEXT("Invalid response for %s: %s."), *GetHelloCommand(), *Response);
		return LastServerResponse;
	}

	SecureSocket.EmptyBuffer();

	//////////////////////////////////////////////////////////////////////////////////////////////
	//
	//	STARTTLS
	//
	//////////////////////////////////////////////////////////////////////////////////////////////
	if (ConnectionType == ESmtpConnectionType::StartTLS)
	{
		LastServerResponse = SecureSocket.SendCommand(TEXT("STARTTLS\r\n"), Response);
		if (LastServerResponse != 220 && bCancelOnInvalidResponse)
		{
			UE_LOG(LogEasyEmail, Error, TEXT("Invalid response for STARTTLS: %s. Expected code 220."), *Response);
			return LastServerResponse;
		}
		
		UE_LOG(LogEasyEmail, Verbose, TEXT("Upgrading socket to SSL."));

		SecureSocket.UpgradeSSL();

		if (SecureSocket.HasError())
		{
			UE_LOG(LogEasyEmail, Error, TEXT("Failed to upgrade socket to SSL: %s"), *SecureSocket.GetLastError());
			return -5;
		}
	}


	//////////////////////////////////////////////////////////////////////////////////////////////
	//
	//	AUTH
	//
	//////////////////////////////////////////////////////////////////////////////////////////////
	if (ServerType == ESmtpServerType::ESMTP)
	{
		bool bShouldRetryAuth = false;
		do
		{
			if (ConnectionType == ESmtpConnectionType::NoEncryption)
			{
				UE_LOG(LogEasyEmail, Warning, TEXT("SendEmail: Authentifying without encryption. Consider using an encrypted connection."));
			}

			LastServerResponse = SecureSocket.SendCommand(FString::Printf(TEXT("AUTH LOGIN\r\n")), Response);

			// Some servers expect an EHLO again as Outlook.
			if (LastServerResponse == 503)
			{
				bShouldRetryAuth = true;

				LastServerResponse = SecureSocket.SendCommand(GetHelloCommand() + TEXT(" ") + ClientDomain + TEXT("\r\n"), Response);
				if (LastServerResponse != 250)
				{
					UE_LOG(LogEasyEmail, Error, TEXT("Invalid response for %s: %s. Expected 250."), *GetHelloCommand(), *Response);
					return LastServerResponse;
				}

				SecureSocket.EmptyBuffer();
			}

			// Unexpected response code: error.
			else if (LastServerResponse != 334 && bCancelOnInvalidResponse)
			{
				UE_LOG(LogEasyEmail, Error, TEXT("Invalid response for AUTH: %s. Expected 334."), *Response);
				return LastServerResponse;
			}

			// Auth passed, no need to retry.
			else
			{
				bShouldRetryAuth = false;
			}
		} while (bShouldRetryAuth);

		const FString Base64Auth = FBase64::Encode(Username);

		LastServerResponse = SecureSocket.SendCommand(FString::Printf(TEXT("%s\r\n"), *Base64Auth), Response);
		if (LastServerResponse != 334 && bCancelOnInvalidResponse)
		{
			UE_LOG(LogEasyEmail, Error, TEXT("Invalid response for Username: %s. Expected 334."), *Response);
			return LastServerResponse;
		}

		const FString Base64Password = FBase64::Encode(Password);

		LastServerResponse = SecureSocket.SendCommand(FString::Printf(TEXT("%s\r\n"), *Base64Password), Response, true);
		if (LastServerResponse != 235 && bCancelOnInvalidResponse)
		{
			UE_LOG(LogEasyEmail, Error, TEXT("Invalid response for Password: %s. Expected 235."), *Response);
			return LastServerResponse;
		}
	}

	else
	{
		UE_LOG(LogEasyEmail, Verbose, TEXT("Skipping AUTH command as SMTP is specified."))
	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	//
	//	MAIL FROM
	//
	//////////////////////////////////////////////////////////////////////////////////////////////

	LastServerResponse = SecureSocket.SendCommand(FString::Printf(TEXT("MAIL FROM: <%s>\r\n"), *From), Response);
	if (LastServerResponse != 250 && bCancelOnInvalidResponse)
	{
		UE_LOG(LogEasyEmail, Error, TEXT("Invalid response for MAIL FROM: %s. Expected 250."), *Response);
		return LastServerResponse;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	//
	//	RCPT TO
	//
	//////////////////////////////////////////////////////////////////////////////////////////////
	for (const auto& Receiver : To)
	{
		LastServerResponse = SecureSocket.SendCommand(FString::Printf(TEXT("RCPT TO: <%s>\r\n"), *Receiver), Response);
		if (LastServerResponse != 250 && bCancelOnInvalidResponse)
		{
			UE_LOG(LogEasyEmail, Error, TEXT("Invalid response for RCPT TO: %s Expected 250."), *Response);
			return LastServerResponse;
		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	//
	//	RCPT BCC
	//
	//////////////////////////////////////////////////////////////////////////////////////////////
	for (const auto& BlindCopy : Bcc)
	{
		LastServerResponse = SecureSocket.SendCommand(FString::Printf(TEXT("RCPT TO: <%s>\r\n"), *BlindCopy), Response);
		if (LastServerResponse != 250 && bCancelOnInvalidResponse)
		{
			UE_LOG(LogEasyEmail, Error, TEXT("Invalid response for RCPT BCC: %s Expected 250."), *Response);
			return LastServerResponse;
		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	//
	//	RCPT CC
	//
	//////////////////////////////////////////////////////////////////////////////////////////////
	for (const auto& Copy : Cc)
	{
		LastServerResponse = SecureSocket.SendCommand(FString::Printf(TEXT("RCPT TO: <%s>\r\n"), *Copy), Response);
		if (LastServerResponse != 250 && bCancelOnInvalidResponse)
		{
			UE_LOG(LogEasyEmail, Error, TEXT("Invalid response for RCPT CC: %s Expected 250."), *Response);
			return LastServerResponse;
		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	//
	//	DATA
	//
	//////////////////////////////////////////////////////////////////////////////////////////////
	LastServerResponse = SecureSocket.SendCommand(TEXT("DATA\r\n"), Response);
	if (LastServerResponse != 354 && bCancelOnInvalidResponse)
	{
		UE_LOG(LogEasyEmail, Error, TEXT("Invalid response for DATA: %s Expected 354."), *Response);
		return LastServerResponse;
	}

	LastServerResponse = SendData(SecureSocket, Response);
	if (LastServerResponse != 250 && bCancelOnInvalidResponse)
	{
		UE_LOG(LogEasyEmail, Error, TEXT("Invalid response for DATA-Content: %s Expected 250."), *Response);
		return LastServerResponse;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	//
	//	QUIT
	//
	//////////////////////////////////////////////////////////////////////////////////////////////
	SecureSocket.SendCommand(TEXT("QUIT\r\n"), Response); // Dismiss QUIT response.

	UE_LOG(LogEasyEmail, Verbose, TEXT("SMTP Socket: Connection closed."));

	const double End = FPlatformTime::Seconds();

	UE_LOG(LogEasyEmail, Log, TEXT("Email sent in %f seconds."), End - Start);

	return LastServerResponse;
}

FString UEmail::QuickCheck() const
{
	if (From.IsEmpty())
	{
		return TEXT("Missing sender.");
	}

	if (To.Num() < 0)
	{
		return TEXT("Missing receiver.");
	}

	if (ServerAddress.IsEmpty())
	{
		return TEXT("Server Address is empty.");
	}

	return TEXT("");
}

bool UEmail::LoadAttachments()
{
	FScopeLock Lock(&AttachmentsMutex);

	for (FEmailAttachment& Attachment : Attachments)
	{
		if (Attachment.bIsFile)
		{
			// We won't need to reload it if we send the mail again.
			Attachment.bIsFile = false;

			TArray<uint8> Data;
			if (!FFileHelper::LoadFileToArray(Data, *Attachment.FileName))
			{
				UE_LOG(LogEasyEmail, Error, TEXT("LoadAttachments: Failed to load file %s."), *Attachment.FileName);
				return false;
			}

			Attachment.Data = FBase64::Encode(Data);
		}
	}

	return true;
}

void UEmail::RemoveAttachmentFromCache(const FString& DisplayName)
{
	EXIT_IF_SENDING();

	for (FEmailAttachment& Attachment : Attachments)
	{
		if (Attachment.DisplayName == DisplayName)
		{
			Attachment.bIsFile = true;
			Attachment.Data = TEXT("");
			return;
		}
	}
}

void UEmail::AddCopyCarbon(const FString& EmailAddress)
{
	EXIT_IF_SENDING();

	Cc.Emplace(EmailAddress);
}

void UEmail::AddBlindCopyCarbon(const FString& EmailAddress)
{
	EXIT_IF_SENDING();

	Bcc.Emplace(EmailAddress);
}

void UEmail::SetSender(const FString& EmailSender)
{
	EXIT_IF_SENDING();

	From = EmailSender;
}

void UEmail::AddReceiver(const FString& EmailReceiver)
{
	EXIT_IF_SENDING();

	To.Emplace(EmailReceiver);
}

void UEmail::SetHeader(const FString& HeaderName, const FString& HeaderValue)
{
	EXIT_IF_SENDING();

	Headers.Emplace(HeaderName, HeaderValue);
}

void UEmail::SetServerPort(const int32 Port)
{
	EXIT_IF_SENDING();

	if (Port < 0 || Port > 65535)
	{
		UE_LOG(LogEasyEmail, Warning, TEXT("Invalid port %d. Port must be between 0 and 65335."), Port);
		return;
	}
	ServerPort = static_cast<uint16>(Port);
}

void UEmail::SetServerAddress(const FString& Address)
{
	EXIT_IF_SENDING();

	ServerAddress = Address;
}

void UEmail::SetConnectionType(const ESmtpConnectionType Connection)
{
	EXIT_IF_SENDING();

	if (Connection == ESmtpConnectionType::StartTLS && ServerType == ESmtpServerType::SMTP)
	{
		UE_LOG(LogEasyEmail, Warning, TEXT("Connection of type TLS is not compatible with Server of type SMTP. SMTP doesn't support STARTTLS command and will fail. You have to set the server to ESMTP to make it work."));
	}

	ConnectionType = Connection;
}

void UEmail::SetServerType(const ESmtpServerType Server)
{
	EXIT_IF_SENDING();

	if (ConnectionType == ESmtpConnectionType::StartTLS && Server == ESmtpServerType::SMTP)
	{
		UE_LOG(LogEasyEmail, Warning, TEXT("Connection of type TLS is not compatible with Server of type SMTP. SMTP doesn't support STARTTLS command and will fail. You have to set the server to ESMTP to make it work."));
	}

	ServerType = Server;
}

void UEmail::SetContent(const FString& EmailContent, const FString& MimeType)
{
	EXIT_IF_SENDING();

	Content     = EmailContent;
	ContentMime = MimeType;
}

void UEmail::SetCredentials(const FString& InUsername, const FString& InPassword)
{
	EXIT_IF_SENDING();

	Username = InUsername;
	Password = InPassword;
}

int32 UEmail::SendData(FSmtpsSocket& Socket, FString& OutResponse)
{
	Socket.Send(FString::Printf(TEXT("From: \"%s\" <%s>\r\n"), *GetEmailAddressFriendlyName(From), *From));

	{
		FString ToData = TEXT("To: ");
		for (int32 i = 0; i < To.Num(); ++i)
		{
			const FString& Copy = To[i];
			ToData += FString::Printf(TEXT("\"%s\" <%s>"), *GetEmailAddressFriendlyName(Copy), *Copy);
			if (i < To.Num() - 1)
			{
				ToData += TEXT(", ");
			}
		}
		Socket.Send(ToData + TEXT("\r\n"));
	}

	{
		FString CopyHeader = TEXT("Cc: ");
		for (int32 i = 0; i < Cc.Num(); ++i)
		{
			const FString& Copy = Cc[i];
			CopyHeader += FString::Printf(TEXT("\"%s\" <%s>"), *GetEmailAddressFriendlyName(Copy), *Copy);
			if (i < Cc.Num() - 1)
			{
				CopyHeader += TEXT(", ");
			}
		}
		Socket.Send(CopyHeader + TEXT("\r\n"));
	}

	for (const auto & Header : Headers)
	{
		Socket.Send(Header.Key + TEXT(": ") + Header.Value + TEXT("\r\n"));
	}

	if (Content.Len() > 0)
	{
		Socket.Send(TEXT("\r\n"));
		Socket.Send(TEXT("--") + MimeBoundary + TEXT("\r\n"));
		Socket.Send(TEXT("Content-Type: ") + ContentMime + TEXT("; charset=") + ContentCharset + TEXT("\r\n"));
		Socket.Send(TEXT("\r\n"));
		Socket.Send(Content, false, false, false);
		Socket.Send(TEXT("\r\n"));
	}

	UE_LOG(LogEasyEmail, Log, TEXT("Email has %d attachment(s)."), Attachments.Num());
		
	int32 i = Attachments.Num();
	for (const auto& Attachment : Attachments)
	{
		Socket.Send(TEXT("--") + MimeBoundary + TEXT("\r\n"));
		Socket.Send(TEXT("Content-Type: ") + Attachment.MimeType + TEXT("; name=\"") + Attachment.DisplayName + TEXT("\"\r\n"));
		Socket.Send(TEXT("Content-Disposition: attachment; filename=\"") + Attachment.DisplayName + TEXT("\"\r\n"));
		Socket.Send(TEXT("Content-Transfer-Encoding: ") + UEmailLibrary::ContentEncodingTransfertEnumToString(Attachment.Encoding) + TEXT("\r\n"));
		for (const auto& Header : Attachment.Headers)
		{
			Socket.Send(FString::Printf(TEXT("%s: %s\r\n"), *Header.Key, *Header.Value));
		}
		Socket.Send(TEXT("\r\n"));
		if (Attachment.Encoding == EContentTransfertEncoding::BASE64)
		{
			Socket.Send(Attachment.Data);
		}
		else
		{
			Socket.Send(Attachment.Data, false, false, false);
		}
		Socket.Send(TEXT("\r\n"));
	}	

	return Socket.SendCommand(TEXT("\n\r\n.\r\n"), OutResponse);
}

void UEmail::SetContentCharset(const EEmailCharset Charset)
{
	EXIT_IF_SENDING();

	ContentCharset = UEmailLibrary::EmailCharsetEnumToString(Charset);
}

void UEmail::SetSubject(const FString& Subject)
{
	EXIT_IF_SENDING();

	Headers.Add(TEXT("Subject"), Subject);
}

void UEmail::SetClientDomain(const FString& Domain)
{
	EXIT_IF_SENDING();

	ClientDomain = Domain;
}

bool UEmail::AddFileAsAttachment(const FString& DisplayName, const FString& Path, const FString& MimeType)
{
	return AddFileAsAttachmentWithHeaders(DisplayName, Path, MimeType, {});
}

bool UEmail::AddFileAsAttachmentWithHeaders(const FString& DisplayName, const FString& Path, const FString& MimeType, TMap<FString, FString> AttachmentHeaders = {})
{
	// We don't use the attachment mutex here because it may block the game thread.
	EXIT_IF_SENDING(false);

	if (!FPaths::FileExists(Path))
	{
		UE_LOG(LogEasyEmail, Warning, TEXT("AddFileAsAttachment: File %s doesn't exist."), *Path);
		return false;
	}

	FEmailAttachment NewAttachment;

	NewAttachment.Headers		= MoveTemp(AttachmentHeaders);
	NewAttachment.MimeType		= MimeType.Len() > 0 ? MimeType : UEmailLibrary::GetMimeTypeFromFileName(Path);
	NewAttachment.bIsFile		= true;
	NewAttachment.FileName		= Path;
	NewAttachment.DisplayName	= DisplayName.Replace(TEXT("\""), TEXT(" "), ESearchCase::CaseSensitive);
	NewAttachment.Encoding		= EContentTransfertEncoding::BASE64;

	Attachments.Emplace(NewAttachment);

	return true;
}

void UEmail::AddDataAsAttachment(const FString& DisplayName, const FString& MimeType, const FString& Data, const EContentTransfertEncoding Encoding)
{
	AddDataAsAttachmentWithHeaders(DisplayName, MimeType, Data, Encoding, {});
}

void UEmail::AddDataAsAttachmentWithHeaders(const FString& DisplayName, const FString& MimeType, const FString& Data, const EContentTransfertEncoding Encoding, TMap<FString, FString> AttachmentHeaders = {})
{
	// We don't use the attachment mutex here because it may block the game thread.
	EXIT_IF_SENDING();

	FEmailAttachment NewAttachment;

	NewAttachment.Headers       = MoveTemp(AttachmentHeaders);
	NewAttachment.MimeType		= MimeType.Len() > 0 ? MimeType : UEmailLibrary::DefaultMimeType;
	NewAttachment.bIsFile		= false;
	NewAttachment.Data			= Encoding == EContentTransfertEncoding::BASE64 ? FBase64::Encode(Data) : Data;
	NewAttachment.DisplayName	= DisplayName.Replace(TEXT("\""), TEXT(" "), ESearchCase::CaseSensitive);
	NewAttachment.Encoding		= Encoding;

	Attachments.Emplace(NewAttachment);
}

void UEmail::RemoveAttachment(const FString& DisplayName)
{
	EXIT_IF_SENDING();

	for (int32 i = 0; i < Attachments.Num(); ++i)
	{
		if (Attachments[i].DisplayName == DisplayName)
		{
			Attachments.RemoveAt(i);
			return;
		}
	}

	UE_LOG(LogEasyEmail, Warning, TEXT("RemoveAttachment(): Failed to find attachment %s."), *DisplayName);
}

FString UEmail::GetHelloCommand() const
{
	return ServerType == ESmtpServerType::SMTP ? TEXT("HELO") : TEXT("EHLO");
}

FString UEmail::GetEmailAddressFriendlyName(const FString& EmailAddress) const
{
	const auto ToUpper = [](const TCHAR Char) -> TCHAR
	{
		if (Char >= TEXT('a') && Char <= TEXT('z'))
		{
			return Char - TEXT('a') + TEXT('A');
		}
		return Char;
	};

	FString Name;

	EmailAddress.Split(TEXT("@"), &Name, nullptr, ESearchCase::CaseSensitive, ESearchDir::FromEnd);

	const int32 Length = Name.Len();

	static const TSet<TCHAR> WhiteSpacedChars =
	{
		TEXT('.'),
		TEXT('_'),
		TEXT('='),
		TEXT('-')
	};

	for (int32 i = 0; i < Length; ++i)
	{
		TCHAR& CurrentChar    = Name[i];
		TCHAR* const NextChar = (i + 1) < Length ? &Name[i+1] : nullptr;
		if (WhiteSpacedChars.Contains(CurrentChar))
		{
			CurrentChar = TEXT(' ');
			if (NextChar)
			{
				*NextChar = ToUpper(*NextChar);
			}
		}
	}

	if (Name.Len())
	{
		Name[0] = ToUpper(Name[0]);
	}

	return Name;
}

void UEmail::BroadcastSuccessOnGameThread()
{
	TWeakObjectPtr<UEmail> Email = MakeWeakObjectPtr(this);
	AsyncTask(ENamedThreads::GameThread, [Email]() -> void 
	{
		if (!Email.IsStale() && Email->IsValidLowLevel())
		{
			Email->OnEmailSent.Broadcast();
		}
		else
		{
			UE_LOG(LogEasyEmail, Warning, TEXT("Email: Failed to call callback because the email object has been garbage collected."))
		}
	});
}

void UEmail::BroadcastErrorOnGameThread(const int32 LastServerResponse)
{
	AsyncTask(ENamedThreads::GameThread, [Email = MakeWeakObjectPtr(this), LastServerResponse]() -> void
	{
		if (!Email.IsStale() && Email->IsValidLowLevel())
		{
			Email->OnEmailError.Broadcast(LastServerResponse);
		}
		else
		{
			UE_LOG(LogEasyEmail, Warning, TEXT("Email: Failed to call callback because the email object has been garbage collected."))
		}
	});
}

#undef EXIT_IF_SENDING
