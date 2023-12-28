// Copyright Pandores Marketplace 2023. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "EmailNodes.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEmailEvent, const int32&, ErrorCode);

class UEmail;

enum class ESmtpConnectionType	: uint8;
enum class ESmtpServerType		: uint8;

/**
 *	Helper node to easily send an email
 **/
UCLASS()
class USendEmailProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	USendEmailProxy(const FObjectInitializer& ObjectInitializer);

	/* Called when the mail has been sent to the server. */
	UPROPERTY(BlueprintAssignable)
	FOnEmailEvent OnEmailSent;

	/* Called when an error occured and the mail wasn't send. */
	UPROPERTY(BlueprintAssignable)
	FOnEmailEvent OnEmailError;

	/**
	 *	Easily send an email to the specified server. 
	 * @param ServerType		The protocol of the server we want to connect to. 
	 * @param ConnectionType	The type of connection we want with the server.
	 * @param ServerAddress		The server's address.
	 * @param ServerPort		The server's port.
	 * @param Username			The username we use to be identified to the ESMTP server.
	 * @param Password			The password of the mail sender. Used only if the server is ESMTP.
	 * @param Subject			The mail's subject.
	 * @param Receivers			The list of receivers of this mail.
	 * @param CopyCarbon		The CC of this mail.
	 * @param BlindCopyCarbon	The BCC of this mail (Invisible CC).
	 * @param MessageContent	The content of the message.
	 * @param AttachedFiles		The file we want to send along the mail as attachments.
	*/
	UFUNCTION(BlueprintCallable, Category = Email, meta = (BlueprintInternalUseOnly = "true", AutoCreateRefTerm = "AttachedFiles, Receivers, CopyCarbon, BlindCopyCarbon", DisplayName = "Send an Email"))
	static USendEmailProxy* SendEmail(
		const ESmtpServerType ServerType, 
		const ESmtpConnectionType ConnectionType, 
		const FString& ServerAddress, 
		const int32 ServerPort, 
		const FString& Username,
		const FString& Password,
		const FString& Subject,
		UPARAM(DisplayName = "Sender (FROM)")			const FString& Sender,
		UPARAM(DisplayName = "Receivers (TO)")			const TArray<FString>& Receivers,
		UPARAM(DisplayName = "Copy Carbon (CC)")		const TArray<FString>& CopyCarbon,
		UPARAM(DisplayName = "Blind Copy Carbon (BCC)") const TArray<FString>& BlindCopyCarbon,
		const FString& MessageContent,
		const TArray<FString>& AttachedFiles
	);

	virtual void Activate();

private:
	UFUNCTION() void InternalOnEmailSent();
	UFUNCTION() void InternalOnEmailError(const int32 ErrorCode);

	UPROPERTY()
	UEmail* Email;

	bool bFailEmail;
};

/**
 *	Helper node to easily send an email
 *  TODO: Make a base class to unify these nodes.
 **/
UCLASS()
class USimpleSendEmailProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	USimpleSendEmailProxy(const FObjectInitializer& ObjectInitializer);

	/* Called when the mail has been sent to the server. */
	UPROPERTY(BlueprintAssignable)
	FOnEmailEvent OnEmailSent;

	/* Called when an error occured and the mail wasn't send. */
	UPROPERTY(BlueprintAssignable)
	FOnEmailEvent OnEmailError;

	/**
	 *	Easily send an email.
	*/
	UFUNCTION(BlueprintCallable, Category = Email, meta = (BlueprintInternalUseOnly = "true", DisplayName = "Send an Email"))
	static USimpleSendEmailProxy* SendEmail(UEmail* const Email);

private:
	UFUNCTION() void InternalOnEmailSent();
	UFUNCTION() void InternalOnEmailError(const int32 ErrorCode);

	UPROPERTY()
	UEmail* Email;

};


/**
 *	Base class for common SMTP send nodes.
 */
UCLASS(Abstract)
class USendEmailWithServerProxy: public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	USendEmailWithServerProxy();

	virtual void Activate();

	/**
	 *	Called when the email has been sent.
	 **/
	UPROPERTY(BlueprintAssignable)
	FOnEmailEvent EmailSent;

	/**
	 *	Called if an error occured when trying to send the email.
	 **/
	UPROPERTY(BlueprintAssignable)
	FOnEmailEvent FailedToSendEmail;

protected:
	template<class ProxyClass>
	FORCEINLINE static ProxyClass* CreateAndInitProxy(
		const FString&			SenderEmailAddress,
		const FString&			Username,
		const FString&			Password,
		const TArray<FString>&	To,
		const TArray<FString>&	CC,
		const TArray<FString>&	BCC,
		const FString&			Subject,
		const FString&			Content,
		const TArray<FString>&	AttachedFiles
	)
	{
		ProxyClass* const Proxy = NewObject<ProxyClass>();

		Proxy->m_Username		= Username;
		Proxy->m_Password		= Password;
		Proxy->m_From			= SenderEmailAddress;
		Proxy->m_To				= To;
		Proxy->m_Cc				= CC;
		Proxy->m_Bcc			= BCC;
		Proxy->m_Subject		= Subject;
		Proxy->m_Content		= Content;
		Proxy->m_Attachments	= AttachedFiles;

		return Proxy;
	}

protected:
	ESmtpServerType		m_ServerType;
	ESmtpConnectionType m_ConnectionType;
	FString				m_ServerAddress;
	int32				m_ServerPort;
						
	FString				m_Username;
	FString				m_Password;
	FString				m_From;
	TArray<FString>		m_To;
	TArray<FString>		m_Cc;
	TArray<FString>     m_Bcc;
	FString				m_Subject;
	FString				m_Content;
	TArray<FString>		m_Attachments;

private:
	UFUNCTION() void OnEmailSent();
	UFUNCTION() void OnEmailFailedToSend(const int32 Error);

	UPROPERTY()
	UEmail* Email;
};

/**
 *	Send an email with GMail.
 */
UCLASS()
class USendEmailWithGmailProxy : public USendEmailWithServerProxy
{
	GENERATED_BODY()
public:
	USendEmailWithGmailProxy();

	/**
	 * Send an email. The configuration is automatically set for Gmail.
	 * @param SenderEmailAddress The email address we want to sent the email with.
	 * @param Username			 The username to authenticate to the server.
	 * @param Password			 The password to authenticate to the server.
	 * @param To				 The email address we want to send to.
	 * @param CC				 The email address we want to add as CC.
	 * @param BCC				 The email address we want to add as BCC.
	 * @param Subject			 The subject of this email.
	 * @param Content			 The content of this email.
	 * @param AttachedFiles		 The files attached to this email.
	*/
	UFUNCTION(BlueprintCallable, Category = Email, meta = (AutoCreateRefTerm = "CC, BCC, AttachedFiles", BlueprintInternalUseOnly = "true", DisplayName = "Send an Email - GMAIL"))
	static USendEmailWithGmailProxy* SendEmailWithGmail(
		const FString&			SenderEmailAddress,
		const FString&			Username,
		const FString&			Password,
		const TArray<FString>&	To,
		const TArray<FString>&	CC,
		const TArray<FString>&	BCC,
		const FString&			Subject,
		const FString&			Content,
		const TArray<FString>&	AttachedFiles
	);
};

/**
 *	Send an email with Yahoo.
 */
UCLASS()
class USendEmailWithYahooProxy : public USendEmailWithServerProxy
{
	GENERATED_BODY()
public:
	USendEmailWithYahooProxy();


	/**
	 * Send an email. The configuration is automatically set for Yahoo.
	 * @param SenderEmailAddress The email address we want to sent the email with.
	 * @param Username			 The username to authenticate to the server.
	 * @param Password			 The password to authenticate to the server.
	 * @param To				 The email address we want to send to.
	 * @param CC				 The email address we want to add as CC.
	 * @param BCC				 The email address we want to add as BCC.
	 * @param Subject			 The subject of this email.
	 * @param Content			 The content of this email.
	 * @param AttachedFiles		 The files attached to this email.
	*/
	UFUNCTION(BlueprintCallable, Category = Email, meta = (AutoCreateRefTerm = "CC, BCC, AttachedFiles", BlueprintInternalUseOnly = "true", DisplayName = "Send an Email - YAHOO"))
	static USendEmailWithYahooProxy* SendEmailWithYahoo(
		const FString&			SenderEmailAddress,
		const FString&			Username,
		const FString&			Password,
		const TArray<FString>&	To,
		const TArray<FString>&	CC,
		const TArray<FString>&	BCC,
		const FString&			Subject,
		const FString&			Content,
		const TArray<FString>&	AttachedFiles
	);
};


/**
 *	Send an email with Outlook.
 */
UCLASS()
class USendEmailWithOutlookProxy : public USendEmailWithServerProxy
{
	GENERATED_BODY()
public:
	USendEmailWithOutlookProxy();

	/**
	 * Send an email. The configuration is automatically set for Outlook.
	 * @param SenderEmailAddress The email address we want to sent the email with.
	 * @param Username			 The username to authenticate to the server.
	 * @param Password			 The password to authenticate to the server.
	 * @param To				 The email address we want to send to.
	 * @param CC				 The email address we want to add as CC.
	 * @param BCC				 The email address we want to add as BCC.
	 * @param Subject			 The subject of this email.
	 * @param Content			 The content of this email.
	 * @param AttachedFiles		 The files attached to this email.
	*/
	UFUNCTION(BlueprintCallable, Category = Email, meta = (AutoCreateRefTerm = "CC, BCC, AttachedFiles", BlueprintInternalUseOnly = "true", DisplayName = "Send an Email - OUTLOOK"))
	static USendEmailWithOutlookProxy* SendEmailWithOutlook(
		const FString&			SenderEmailAddress,
		const FString&			Username,
		const FString&			Password,
		const TArray<FString>&	To,
		const TArray<FString>&	CC,
		const TArray<FString>&	BCC,
		const FString&			Subject,
		const FString&			Content,
		const TArray<FString>&	AttachedFiles
	);
};

/**
 *	Send an email with Hotmail.
 */
UCLASS()
class USendEmailWithHotmailProxy : public USendEmailWithServerProxy
{
	GENERATED_BODY()
public:
	USendEmailWithHotmailProxy();

	/**
	 * Send an email. The configuration is automatically set for Hotmail.
	 * @param SenderEmailAddress The email address we want to sent the email with.
	 * @param Username			 The username to authenticate to the server.
	 * @param Password			 The password to authenticate to the server.
	 * @param To				 The email address we want to send to.
	 * @param CC				 The email address we want to add as CC.
	 * @param BCC				 The email address we want to add as BCC.
	 * @param Subject			 The subject of this email.
	 * @param Content			 The content of this email.
	 * @param AttachedFiles		 The files attached to this email.
	*/
	UFUNCTION(BlueprintCallable, Category = Email, meta = (AutoCreateRefTerm = "CC, BCC, AttachedFiles", BlueprintInternalUseOnly = "true", DisplayName = "Send an Email - HOTMAIL"))
	static USendEmailWithHotmailProxy* SendEmailWithHotmail(
		const FString& SenderEmailAddress,
		const FString& Username,
		const FString& Password,
		const TArray<FString>& To,
		const TArray<FString>& CC,
		const TArray<FString>& BCC,
		const FString& Subject,
		const FString& Content,
		const TArray<FString>& AttachedFiles
	);
};


