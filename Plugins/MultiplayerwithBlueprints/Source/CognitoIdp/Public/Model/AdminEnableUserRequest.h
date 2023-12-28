/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminEnableUserRequest.h"

#endif

#include "AdminEnableUserRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminEnableUserRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool where you want to enable the user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The user name of the user you wish to enable.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminEnableUserRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminEnableUserRequest awsAdminEnableUserRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminEnableUserRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminEnableUserRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        return awsAdminEnableUserRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty();
    }
#endif
};
