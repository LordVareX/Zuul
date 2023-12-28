// Copyright Pandores Marketplace 2023. All Rights Reserved.

#include "EmailNodes.h"
#include "Email.h"
#include "EmailLibrary.h"
#include "Misc/Paths.h"
#include "EasyEmail.h"

USendEmailProxy::USendEmailProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	, bFailEmail(false)
{
}

/* static */ USendEmailProxy* USendEmailProxy::SendEmail(
	const ESmtpServerType ServerType,
	const ESmtpConnectionType ConnectionType,
	const FString& ServerAddress,
	const int32 ServerPort,
	const FString& Username,
	const FString& Password,
	const FString& Subject,
	const FString& Sender,
	const TArray<FString>& Receivers,
	const TArray<FString>& CopyCarbon,
	const TArray<FString>& BlindCopyCarbon,
	const FString& MessageContent,
	const TArray<FString>& AttachedFiles
)
{
	USendEmailProxy* const Proxy = NewObject<USendEmailProxy>();

	Proxy->Email = NewObject<UEmail>();

	Proxy->Email->SetServerType	   (ServerType);
	Proxy->Email->SetConnectionType(ConnectionType);
	Proxy->Email->SetServerAddress (ServerAddress);
	Proxy->Email->SetServerPort	   (ServerPort);
	Proxy->Email->SetContent	   (MessageContent, TEXT("text/plain"));
	Proxy->Email->SetCredentials   (Username, Password);
	Proxy->Email->SetSender		   (Sender);
	Proxy->Email->SetSubject	   (Subject);

	for (const auto& Receiver : Receivers)
	{
		Proxy->Email->AddReceiver(Receiver);
	}

	for (const auto& Cc : CopyCarbon)
	{
		Proxy->Email->AddCopyCarbon(Cc);
	}

	for (const auto& Bcc : BlindCopyCarbon)
	{
		Proxy->Email->AddBlindCopyCarbon(Bcc);
	}
	
	for (const auto& AttachedFile : AttachedFiles)
	{
		const FString FileName = FPaths::GetCleanFilename(AttachedFile);
		if (!Proxy->Email->AddFileAsAttachmentWithHeaders(FileName, AttachedFile, UEmailLibrary::GetMimeTypeFromFileName(FileName), TMap<FString, FString>{}))
		{
			UE_LOG(LogEasyEmail, Error, TEXT("Failed to find attachment with path %s. Canceling email."), *FPaths::ConvertRelativePathToFull(AttachedFile));
			Proxy->bFailEmail = true;
			return Proxy;
		}
	}

	Proxy->Email->OnEmailError.AddDynamic(Proxy, &USendEmailProxy::InternalOnEmailError);
	Proxy->Email->OnEmailSent .AddDynamic(Proxy, &USendEmailProxy::InternalOnEmailSent);

	return Proxy;
}

void USendEmailProxy::Activate()
{
	if (bFailEmail)
	{
		InternalOnEmailError(-12);
	}
	else
	{
		Email->Send();
	}
}

void USendEmailProxy::InternalOnEmailSent()
{
	OnEmailSent.Broadcast(0);
	SetReadyToDestroy();
}

void USendEmailProxy::InternalOnEmailError(const int32 ErrorCode)
{
	OnEmailError.Broadcast(ErrorCode);
	SetReadyToDestroy();
}

USimpleSendEmailProxy::USimpleSendEmailProxy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}

/* static */ USimpleSendEmailProxy* USimpleSendEmailProxy::SendEmail(UEmail* const Email)
{
	USimpleSendEmailProxy* const Proxy = NewObject<USimpleSendEmailProxy>();

	if (!Email)
	{
		Proxy->OnEmailError.Broadcast(-10);
		Proxy->SetReadyToDestroy();
	}

	else
	{
		Proxy->Email = Email;
		Proxy->Email->OnEmailError.AddDynamic(Proxy, &USimpleSendEmailProxy::InternalOnEmailError);
		Proxy->Email->OnEmailSent .AddDynamic(Proxy, &USimpleSendEmailProxy::InternalOnEmailSent);

		Proxy->Email->Send();
	}

	return Proxy;
}

void USimpleSendEmailProxy::InternalOnEmailSent()
{
	OnEmailSent.Broadcast(0);
	SetReadyToDestroy();
}

void USimpleSendEmailProxy::InternalOnEmailError(const int32 ErrorCode)
{
	OnEmailError.Broadcast(ErrorCode);
	SetReadyToDestroy();
}

USendEmailWithServerProxy::USendEmailWithServerProxy()
	: Super()
{
	m_ServerType		= (ESmtpServerType::ESMTP);
	m_ConnectionType	= (ESmtpConnectionType::SSL);
	m_ServerPort		= (465);
}

void USendEmailWithServerProxy::Activate()
{
	Email = NewObject<UEmail>();

	Email->SetServerType	(m_ServerType);
	Email->SetConnectionType(m_ConnectionType);
	Email->SetServerAddress	(m_ServerAddress);
	Email->SetServerPort	(m_ServerPort);
	Email->SetContent		(m_Content, TEXT("text/plain"));
	Email->SetCredentials	(m_Username, m_Password);
	Email->SetSender		(m_From);
	Email->SetSubject		(m_Subject);

	for (const auto& Receiver : m_To)
	{
		Email->AddReceiver(Receiver);
	}

	for (const auto& Cc : m_Cc)
	{
		Email->AddCopyCarbon(Cc);
	}

	for (const auto& Bcc : m_Bcc)
	{
		Email->AddBlindCopyCarbon(Bcc);
	}

	for (const auto& AttachedFile : m_Attachments)
	{
		const FString FileName = FPaths::GetCleanFilename(AttachedFile);
		if (!Email->AddFileAsAttachment(FileName, AttachedFile, UEmailLibrary::GetMimeTypeFromFileName(FileName)))
		{
			UE_LOG(LogEasyEmail, Error, TEXT("Failed to find attachment with path %s. Canceling email."), *FPaths::ConvertRelativePathToFull(AttachedFile));
			
			OnEmailFailedToSend(-12);
			return;
		}
	}

	Email->OnEmailError.AddDynamic(this, &USendEmailWithServerProxy::OnEmailFailedToSend);
	Email->OnEmailSent .AddDynamic(this, &USendEmailWithServerProxy::OnEmailSent);

	Email->Send();
}

void USendEmailWithServerProxy::OnEmailSent()
{
	EmailSent.Broadcast(0);
	SetReadyToDestroy();
}

void USendEmailWithServerProxy::OnEmailFailedToSend(const int32 Error)
{
	FailedToSendEmail.Broadcast(Error);
	SetReadyToDestroy();
}

USendEmailWithGmailProxy::USendEmailWithGmailProxy()
	: Super()
{
	m_ServerAddress = (TEXT("smtp.gmail.com"));
}

/* static */ USendEmailWithGmailProxy* USendEmailWithGmailProxy::SendEmailWithGmail(
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
	return CreateAndInitProxy<USendEmailWithGmailProxy>(SenderEmailAddress, Username, Password, To, CC, BCC, Subject, Content, AttachedFiles);
}

USendEmailWithYahooProxy::USendEmailWithYahooProxy()
	: Super()
{
	m_ServerAddress = (TEXT("smtp.mail.yahoo.com"));
}

/* static */ USendEmailWithYahooProxy* USendEmailWithYahooProxy::SendEmailWithYahoo(
	const FString& SenderEmailAddress,
	const FString& Username,
	const FString& Password,
	const TArray<FString>& To,
	const TArray<FString>& CC,
	const TArray<FString>& BCC,
	const FString& Subject,
	const FString& Content,
	const TArray<FString>& AttachedFiles
)
{
	return CreateAndInitProxy<USendEmailWithYahooProxy>(SenderEmailAddress, Username, Password, To, CC, BCC, Subject, Content, AttachedFiles);
}

USendEmailWithOutlookProxy::USendEmailWithOutlookProxy()
	: Super()
{
	m_ServerType		= (ESmtpServerType::ESMTP);
	m_ConnectionType	= (ESmtpConnectionType::StartTLS);
	m_ServerAddress		= (TEXT("smtp-mail.outlook.com"));
	m_ServerPort		= (587);
}

/* static */ USendEmailWithOutlookProxy* USendEmailWithOutlookProxy::SendEmailWithOutlook(
	const FString& SenderEmailAddress,
	const FString& Username,
	const FString& Password,
	const TArray<FString>& To,
	const TArray<FString>& CC,
	const TArray<FString>& BCC,
	const FString& Subject,
	const FString& Content,
	const TArray<FString>& AttachedFiles
)
{
	return CreateAndInitProxy<USendEmailWithOutlookProxy>(SenderEmailAddress, Username, Password, To, CC, BCC, Subject, Content, AttachedFiles);
}

USendEmailWithHotmailProxy::USendEmailWithHotmailProxy()
	: Super()
{
	m_ServerType	 = (ESmtpServerType::ESMTP);
	m_ConnectionType = (ESmtpConnectionType::SSL);
	m_ServerAddress	 = (TEXT("smtp.live.com"));
}

/* static */ USendEmailWithHotmailProxy* USendEmailWithHotmailProxy::SendEmailWithHotmail(
	const FString& SenderEmailAddress,
	const FString& Username,
	const FString& Password,
	const TArray<FString>& To,
	const TArray<FString>& CC,
	const TArray<FString>& BCC,
	const FString& Subject,
	const FString& Content,
	const TArray<FString>& AttachedFiles
)
{
	return CreateAndInitProxy<USendEmailWithHotmailProxy>(SenderEmailAddress, Username, Password, To, CC, BCC, Subject, Content, AttachedFiles);
}


