/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminDeleteUserRequest.h"

#endif

#include "AdminDeleteUserRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminDeleteUserRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool where you want to delete the user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The user name of the user you wish to delete.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminDeleteUserRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminDeleteUserRequest awsAdminDeleteUserRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminDeleteUserRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminDeleteUserRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        return awsAdminDeleteUserRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty();
    }
#endif
};
