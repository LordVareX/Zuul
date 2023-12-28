/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/UnlinkIdentityRequest.h"

#endif

#include "UnlinkIdentityRequest.generated.h"

USTRUCT(BlueprintType)
struct FUnlinkIdentityRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityId;

    /**
    *  <p>A set of optional name-value pairs that map provider names to provider tokens.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TMap<FString, FString> logins;

    /**
    *  <p>Provider names to unlink from this identity.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TArray<FString> loginsToRemove;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::UnlinkIdentityRequest toAWS() const {
        Aws::CognitoIdentity::Model::UnlinkIdentityRequest awsUnlinkIdentityRequest;

        if (!(this->identityId.IsEmpty())) {
            awsUnlinkIdentityRequest.SetIdentityId(TCHAR_TO_UTF8(*this->identityId));
        }

        for (const TPair<FString, FString>& elem : this->logins) {
            awsUnlinkIdentityRequest.AddLogins(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        for (const FString& elem : this->loginsToRemove) {
            awsUnlinkIdentityRequest.AddLoginsToRemove(TCHAR_TO_UTF8(*elem));
        }

        return awsUnlinkIdentityRequest;
    }

    bool IsEmpty() const {
        return this->identityId.IsEmpty() && this->logins.Num() == 0 && this->loginsToRemove.Num() == 0;
    }
#endif
};
