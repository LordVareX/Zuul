/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminDisableUserRequest.h"

#endif

#include "AdminDisableUserRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminDisableUserRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool where you want to disable the user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The user name of the user you wish to disable.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminDisableUserRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminDisableUserRequest awsAdminDisableUserRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminDisableUserRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminDisableUserRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        return awsAdminDisableUserRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty();
    }
#endif
};
