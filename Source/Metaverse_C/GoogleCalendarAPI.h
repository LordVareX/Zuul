// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "GoogleCalendarAPI.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class METAVERSE_C_API UGoogleCalendarAPI : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Google Calendar API")
    static void AuthenticateAndFetchCalendar();

private:
    static FString ClientID;
    static FString ClientSecret;
    static FString RedirectURI;
    static FString AuthorizationCode;
    static FString AccessToken;

    static void OpenGoogleAuthorizationPage();
    static void ExchangeAuthorizationCodeForAccessToken();
    static void OnAccessTokenResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
    static void FetchCalendarData();
    static void OnCalendarDataResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	
};
