/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminUserGlobalSignOutRequest.h"

#endif

#include "AdminUserGlobalSignOutRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminUserGlobalSignOutRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The user name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminUserGlobalSignOutRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminUserGlobalSignOutRequest awsAdminUserGlobalSignOutRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminUserGlobalSignOutRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminUserGlobalSignOutRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        return awsAdminUserGlobalSignOutRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty();
    }
#endif
};
