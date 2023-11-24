// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Http.h"
#include "Json.h"
#include "FirebaseWrapper.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class METAVERSE_C_API UFirebaseWrapper : public UObject
{
	GENERATED_BODY()

public:
    UFirebaseWrapper();

    // Function to make a GET request to Firebase
    UFUNCTION(BlueprintCallable)
    void GetFirebaseData();

    // Function to handle HTTP request completion
    void OnGetResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

    // Other functions for POST, PUT, DELETE requests...

private:
    // Firebase credentials and URLs
    FString FirebaseURL;
    FString FirebaseAPIKey;

    // Function to construct headers for authentication if needed
    TSharedRef<IHttpRequest> CreateRequest(const FString& Url, const FString& Verb);
	
};
