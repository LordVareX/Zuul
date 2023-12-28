// Copyright Pandores Marketplace 2023. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EmailLibrary.generated.h"

enum class EContentTransfertEncoding	: uint8;
enum class ESmtpConnectionType			: uint8;
enum class EEmailCharset				: uint8;

/**
 *	Helper library for mails.
 **/
UCLASS()
class EASYEMAIL_API UEmailLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	/**
	 *   Returns the MIME-Type associated with this type of file.
	 **/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Email)
	static FString GetMimeTypeFromFileName(const FString& FileName);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Email)
	static UPARAM(DisplayName = "Gmail SMTP address")		FString GetGmailSmtpAddress();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Email)
	static UPARAM(DisplayName = "Outlook SMTP address")		FString GetOutlookSmtpAddress();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Email)
	static UPARAM(DisplayName = "Office365 SMTP address")	FString GetOffice365SmtpAddress();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Email)
	static UPARAM(DisplayName = "YahooEmail SMTP address")	FString GetYahooEmailSmtpAddress();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Email)
	static UPARAM(DisplayName = "Hotmail SMTP address")		FString GetHotmailSmtpAddress();

	/* Returns the standard port associated with this type of connection */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Email)
	static int32 GetDefaultPortForConnection(const ESmtpConnectionType Connection);

	static FString SmtpConnectionTypeEnumToString(const ESmtpConnectionType Connection);

	static FString ContentEncodingTransfertEnumToString(const EContentTransfertEncoding Encoding);
	
	static FString EmailCharsetEnumToString(const EEmailCharset Charset);

	/* The default MIME-Type used for unknown file extension */
	static const FString DefaultMimeType;
	
	/* Replaces Line Feed and Carriage Return with display equivalents. */
	static FString FormatSmtpResponse(const FString & Response);

};

