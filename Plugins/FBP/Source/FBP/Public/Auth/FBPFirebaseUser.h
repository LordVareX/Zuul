// Copyright (c) 2022 King Wai Mark

#pragma once


#include "CoreMinimal.h"
#include "FBPFirebaseUser.generated.h"


USTRUCT(BlueprintType)
struct FBPFirebaseUser
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Auth - Firebase Plugin by KWM")
	FString Uid;

	UPROPERTY(BlueprintReadOnly, Category = "Auth - Firebase Plugin by KWM")
	FString Email;

	UPROPERTY(BlueprintReadOnly, Category = "Auth - Firebase Plugin by KWM")
	FString PhoneNumber;

	UPROPERTY(BlueprintReadOnly, Category = "Auth - Firebase Plugin by KWM")
	FString PhotoUrl;

	UPROPERTY(BlueprintReadOnly, Category = "Auth - Firebase Plugin by KWM")
	FString ProviderId;



	UPROPERTY(BlueprintReadOnly, Category = "Auth - Firebase Plugin by KWM")
	int CreationTimestamp = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Auth - Firebase Plugin by KWM")
	int LastSignedIn = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Auth - Firebase Plugin by KWM")
	bool IsEmailVerified = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "Auth - Firebase Plugin by KWM")
	bool IsAnonymous = false;
};