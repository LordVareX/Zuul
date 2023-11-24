// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Http.h"
#include "Json.h"
#include "FirebaseFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class METAVERSE_C_API UFirebaseFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Firebase")
    static void GetFirebaseData(const FString& FirebaseURL, const FString& APIKey);

private:
    static void OnGetResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	
};
