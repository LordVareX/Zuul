/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminGetUserRequest.h"

#endif

#include "AdminGetUserRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminGetUserRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool where you want to get information about the user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The user name of the user you wish to retrieve.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminGetUserRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminGetUserRequest awsAdminGetUserRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminGetUserRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminGetUserRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        return awsAdminGetUserRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty();
    }
#endif
};
