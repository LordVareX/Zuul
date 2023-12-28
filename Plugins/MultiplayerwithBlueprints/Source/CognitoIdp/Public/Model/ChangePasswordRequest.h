/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ChangePasswordRequest.h"

#endif

#include "ChangePasswordRequest.generated.h"

USTRUCT(BlueprintType)
struct FChangePasswordRequest {
GENERATED_BODY()

    /**
    *  <p>The old password.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString previousPassword;

    /**
    *  <p>The new password.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString proposedPassword;

    /**
    *  <p>The access token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString accessToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::ChangePasswordRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::ChangePasswordRequest awsChangePasswordRequest;

        if (!(this->previousPassword.IsEmpty())) {
            awsChangePasswordRequest.SetPreviousPassword(TCHAR_TO_UTF8(*this->previousPassword));
        }

        if (!(this->proposedPassword.IsEmpty())) {
            awsChangePasswordRequest.SetProposedPassword(TCHAR_TO_UTF8(*this->proposedPassword));
        }

        if (!(this->accessToken.IsEmpty())) {
            awsChangePasswordRequest.SetAccessToken(TCHAR_TO_UTF8(*this->accessToken));
        }

        return awsChangePasswordRequest;
    }

    bool IsEmpty() const {
        return this->previousPassword.IsEmpty() && this->proposedPassword.IsEmpty() && this->accessToken.IsEmpty();
    }
#endif
};
