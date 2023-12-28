// Copyright Pandores Marketplace 2023. All Rights Reserved.

#pragma once

#include "Containers/UnrealString.h"
#include "IPAddress.h"

typedef struct ssl_ctx_st SSL_CTX;
typedef struct ssl_st SSL;
typedef struct bio_st BIO;


/**
 *	SSL socket with commands to talk to a SMTP server. 
 *  Operations are blocking.
 *  If the socket rises an error, we have to create a new one.
 **/
class FSmtpsSocket
{
public:
	FSmtpsSocket(const bool bStartWithSSL  = false);
	FSmtpsSocket(const FSmtpsSocket& Other) = delete;
	~FSmtpsSocket();

	int32 Connect(const FString& ServerAddress, const uint16 Port, FString& OutGreetings);

	FORCEINLINE FString GetLastError() { return LastError; }
	FORCEINLINE bool HasError() const  { return LastError.Len() > 0; } 

	/**
	 *	Sends the command to the SMTP server.
	 **/
	int SendCommand(const FString& Command, FString & OutResponse, const bool bSensitiveData = false);

	bool Send(const FString& Data, const bool bSensitiveData = false, const bool bSplitted = false, const bool bAllowSplit = true);
	
	/**
	 *	Empties the buffer. Used for the EHLO command.
	 **/
	TArray<FString> EmptyBuffer();

	/* Upgrade the connection to an SSL connection. */
	void UpgradeSSL();

private:
	TSharedPtr<FInternetAddr> ResolveHost(const FString& Host, const uint16 Port);

	/**
	 * @param bSensitiveData If the data is sensitive and shouldn't be printed to log
	*/
	FString GetBioBuffer(const bool bSensitiveData = false);

	int32 GetCodeFromResponse(const FString& Response) const;

	void InitForSSL();
	void InitNoSSL();

private:
	FString LastError;

private:
	BIO*		SslBio; // Only for upgraded connections
	BIO*		Bio;
	BIO*		OutBio;
	SSL_CTX*	Context;
	SSL*		Ssl;
	bool		bIsSsl;
};

