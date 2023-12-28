// Copyright Pandores Marketplace 2023. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Email.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEmailSent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEmailError, const int32, ErrorCode);

/**
 * Character encoding.
 "*/
UENUM(BlueprintType)
enum class EEmailCharset : uint8
{
	big5 = 0		UMETA(DisplayName="big5",			Tooltip="Chinese Traditional (Big5)"),
	euc_kr			UMETA(DisplayName="euc-kr",			Tooltip="Korean (EUC)"),
	iso_8859_1		UMETA(DisplayName="iso-8859-1",		Tooltip="Western Alphabet (ISO)"),
	iso_8859_2		UMETA(DisplayName="iso-8859-2",		Tooltip="Central European Alphabet(ISO)"),
	iso_8859_3		UMETA(DisplayName="iso-8859-3",		Tooltip="Latin 3 Alphabet (ISO)"),
	iso_8859_4		UMETA(DisplayName="iso-8859-4",		Tooltip="Baltic Alphabet (ISO)"),
	iso_8859_5		UMETA(DisplayName="iso-8859-5",		Tooltip="Cyrillic Alphabet (ISO)"),
	iso_8859_6		UMETA(DisplayName="iso-8859-6",		Tooltip="Arabic Alphabet (ISO)"),
	iso_8859_7		UMETA(DisplayName="iso-8859-7",		Tooltip="Greek Alphabet (ISO)"),
	iso_8859_8		UMETA(DisplayName="iso-8859-8",		Tooltip="Hebrew Alphabet (ISO)"),
	koi8_r			UMETA(DisplayName="koi8-r",			Tooltip="Cyrillic Alphabet (KOI8-R)"),
	shift_jis		UMETA(DisplayName="shift-jis",		Tooltip="Japanese (Shift-JIS)"),
	x_euc			UMETA(DisplayName="x-euc",			Tooltip="Japanese (EUC)"),
	utf_8			UMETA(DisplayName="utf-8",			Tooltip="Universal Alphabet (UTF-8)"),
	windows_1250	UMETA(DisplayName="windows-1250",	Tooltip="Central European Alphabet (Windows)"),
	windows_1251	UMETA(DisplayName="windows-1251",	Tooltip="Cyrillic Alphabet (Windows)"),
	windows_1252	UMETA(DisplayName="windows-1252",	Tooltip="Western Alphabet (Windows)"),
	windows_1253	UMETA(DisplayName="windows-1253",	Tooltip="Greek Alphabet (Windows)"),
	windows_1254	UMETA(DisplayName="windows-1254",	Tooltip="Turkish Alphabet (Windows)"),
	windows_1255	UMETA(DisplayName="windows-1255",	Tooltip="Hebrew Alphabet (Windows)"),
	windows_1256	UMETA(DisplayName="windows-1256",	Tooltip="Arabic Alphabet (Windows)"),
	windows_1257	UMETA(DisplayName="windows-1257",	Tooltip="Baltic Alphabet (Windows)"),
	windows_1258	UMETA(DisplayName="windows-1258",	Tooltip="Vietnamese Alphabet (Windows)"),
	windows_874		UMETA(DisplayName="windows-874",	Tooltip="Thai (Windows)")
};

/**
 *	An attachment's Content-Transfert-Encoding
 **/
UENUM(BlueprintType)
enum class EContentTransfertEncoding : uint8
{
	BASE64,
	QUOTED_PRINTABLE UMETA(DisplayName = "QUOTED-PRINTABLE"),
	_8BIT			 UMETA(DisplayName = "8BIT"),
	_7BIT			 UMETA(DisplayName = "7BIT"),
	BINARY,
	xtoken			 UMETA(DisplayName = "x-token")
};


/* The SMTP protocol of a server. */
UENUM(BlueprintType)
enum class ESmtpServerType : uint8
{
	SMTP  UMETA(DisplayName="SMTP",  ToolTip="SMTP servers don't support the AUTH command."),
	ESMTP UMETA(DisplayName="ESMTP", ToolTip="ESMTP (Enhanced SMTP) is the most common server type. Supports the AUTH command.")
};

/* The type of connection established with the SMTP server. */
UENUM(BlueprintType)
enum class ESmtpConnectionType : uint8
{
	NoEncryption UMETA(DisplayName="No Encryption", Tooltip="Doesn't use encryption. Keep in mind that the data sent can be caught and read by anybody. Don't send sensitive information without encryption. Port Standard: 25."),
	SSL			 UMETA(DisplayName="SSL",			Tooltip="Use encryption from the beginning of the connection. Port Standard: 465."),
	StartTLS	 UMETA(DisplayName="StartTLS",		Tooltip="Establish a non-encrypted handshake and update later the connection with STARTTLS command to SSL/TLS (encrypted) before the AUTH command. Port Standard: 587.")
};

/* A mail attachment. Can be either raw or a file. */
struct FEmailAttachment
{
public:
	FEmailAttachment()
		: Encoding(EContentTransfertEncoding::BINARY)
		, bIsFile(false)
	{};

	TMap<FString, FString> Headers;
	FString DisplayName;
	FString FileName;
	FString Data;
	FString MimeType;
	EContentTransfertEncoding Encoding;
	bool bIsFile;
};

/**
 *	An email.
 **/
UCLASS(BlueprintType)
class EASYEMAIL_API UEmail : public UObject
{
	GENERATED_BODY()
private:
	friend struct FEmailSendCountHandler;

public:
	UEmail();

	/* Creates am email. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Email)
	static UPARAM(DisplayName="New Email") UEmail* CreateEmail();

	/* Creates an email with the specified parameters */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Email)
	static UPARAM(DisplayName="New Email") UEmail* CreateInitializedEmail(const ESmtpServerType ServerType, const ESmtpConnectionType Connection, const FString& ServerAddress, const int32 Port);

	/* Send this Email. */
	UFUNCTION(BlueprintCallable, Category = Email, DisplayName = "Send Email")
	void Send();

	/**
	 * Add a CC to the email.
	 * @param EmailAddress The new CC.
	*/
	UFUNCTION(BlueprintCallable, Category = Email)
	void AddCopyCarbon(const FString& EmailAddress);

	/**
	 * Add a BCC to the email.
	 * BCC are like CC but can't be seen by others.
	 * @param EmailAddress The BCC address.
	*/
	UFUNCTION(BlueprintCallable, Category = Email)
	void AddBlindCopyCarbon(const FString& EmailAddress);

	/**
	 * Add a receiver to this email.
	*/
	UFUNCTION(BlueprintCallable, Category = Email)
	void AddReceiver(const FString & EmailReceiver);
	
	/**
	 * Define the email address sending this email.
	*/
	UFUNCTION(BlueprintCallable, Category = Email)
	void SetSender(const FString& EmailSender);

	/* Set an header of the mail. This is not the header of the content. */
	UFUNCTION(BlueprintCallable, Category = Email)
	void SetHeader(const FString & HeaderName, const FString & HeaderValue);

	UFUNCTION(BlueprintCallable, Category = Email)
	void SetServerPort(const int32 Port);

	UFUNCTION(BlueprintCallable, Category = Email)
	void SetServerAddress(const FString & Address);

	/* Email charset for encoding */
	UFUNCTION(BlueprintCallable, Category = Email)
	void SetContentCharset(const EEmailCharset Charset);

	/* The content of this email */
	UFUNCTION(BlueprintCallable, Category = Email)
	void SetContent(const FString & EmailContent, const FString& MimeType = TEXT("text/plain"));

	/* The credentials used to identifiate to the SMTP server */
	UFUNCTION(BlueprintCallable, Category = Email)
	void SetCredentials(const FString& InUsername, const FString& InPassword);

	/* How we are supposed to encrypt this connection */
	UFUNCTION(BlueprintCallable, Category = Email)
	void SetConnectionType(const ESmtpConnectionType Connection);

	/* Sets the type of server we want to connect to. */
	UFUNCTION(BlueprintCallable, Category = Email)
	void SetServerType(const ESmtpServerType Server);

	/* Set the domain specified during the HELLO command. */
	UFUNCTION(BlueprintCallable, Category = Email)
	void SetClientDomain(const FString& Domain);

	/**
	 *	Add a file as an attachment. The file is only loaded just before we send it.
	 *  Once the file is loaded, the content is cached and won't be loaded again.
	 *  @return True if the file exists.
	 **/
	UFUNCTION(BlueprintCallable, Category = Email, Meta = (AutoCreateRefTerm = "AttachmentHeaders"))
	UPARAM(DisplayName = "Success") bool AddFileAsAttachmentWithHeaders(const FString& DisplayName, const FString& Path, const FString& MimeType, TMap<FString, FString> AttachmentHeaders);

	/**
	 *	Add a file as an attachment. The file is only loaded just before we send it.
	 *  Once the file is loaded, the content is cached and won't be loaded again.
	 *  @return True if the file exists.
	 **/
	UFUNCTION(BlueprintCallable, Category = Email, Meta = (AutoCreateRefTerm = "AttachmentHeaders"))
	UPARAM(DisplayName = "Success") bool AddFileAsAttachment(const FString& DisplayName, const FString& Path, const FString& MimeType = TEXT(""));

	/**
	 * Add the data as an attachment. If the encoding is set to Base64, the data is automatically encoded to base64.
	 * Be careful to what data is passed here, it may break the mail if it contains non-utf8 characters. Binary data should be added with the BASE64 encoding.
	 */
	UFUNCTION(BlueprintCallable, Category = Email, Meta = (AutoCreateRefTerm = "AttachmentHeaders"))
	void AddDataAsAttachmentWithHeaders(const FString& DisplayName, const FString& MimeType, const FString& Data, const EContentTransfertEncoding Encoding, TMap<FString, FString> AttachmentHeaders);

	/**
	 * Add the data as an attachment. If the encoding is set to Base64, the data is automatically encoded to base64.
	 * Be carefull to what data is passed here, it may break the mail if it contains non-utf8 characters. Binary data should be added with the BASE64 encoding.
	 */
	UFUNCTION(BlueprintCallable, Category = Email, Meta = (AutoCreateRefTerm = "AttachmentHeaders"))
	void AddDataAsAttachment(const FString& DisplayName, const FString& MimeType, const FString& Data, const EContentTransfertEncoding Encoding = EContentTransfertEncoding::BASE64);

	/**
	 * Removes the specified argument.
	*/
	UFUNCTION(BlueprintCallable, Category = Email)
	void RemoveAttachment(const FString&DisplayName);

	/**
	 * Removes the specified attachment from the cache.
	 * Sending the email will reload the file.
	*/
	UFUNCTION(BlueprintCallable, Category = Email)
	void RemoveAttachmentFromCache(const FString& DisplayName);

	/* Set the subject of this mail. This is the same as calling SetHeader with the key name "subject" */
	UFUNCTION(BlueprintCallable, Category = Email)
	void SetSubject(const FString& Subject);

	/* Called when the email has been sent. */
	UPROPERTY(BlueprintAssignable, DisplayName="On Email Sent")
	FOnEmailSent OnEmailSent;

	/* Called when an error occured while sending the email */
	UPROPERTY(BlueprintAssignable, DisplayName="On Email Send Error")
	FOnEmailError OnEmailError;

	/* Returns if the mail is currently being sent. If this is true, all attempts to edit this email will fail. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Email)
	UPARAM(DisplayName = "Is Sending") bool IsEmailSending() const;

private:
	// Send data through the socket.
	int32 SendData(class FSmtpsSocket& Socket, FString& OutResponse);

	// Filter out requests that can't succeed anyway.
	FString QuickCheck() const;

	// Send the mail synchronously, blocking the thread for the whole operation.
	int32 SendInternal();

	// Load attachments synchronously, blocking the thread for the whole operation.
	bool LoadAttachments();

	static FString MimeBoundary;

	void BroadcastSuccessOnGameThread();
	
	void BroadcastErrorOnGameThread(const int32 LastServerResponse);

	FString GetHelloCommand() const;

	FString GetEmailAddressFriendlyName(const FString& EmailAddress) const;

private:
	ESmtpConnectionType ConnectionType;
	ESmtpServerType ServerType;
	FString ClientDomain;
	TMap<FString, FString> Headers;
	FString Username;
	FString Password;
	FString ServerAddress;
	uint16  ServerPort;
	FString Content;
	FString ContentMime;
	FString ContentCharset;
	FString From;
	TArray<FString> To;
	TArray<FString> Cc;
	TArray<FString> Bcc;
	TArray<FEmailAttachment> Attachments;

private:
	TAtomic<int32> ConcurrentSendingCount;

	FCriticalSection AttachmentsMutex;
};
