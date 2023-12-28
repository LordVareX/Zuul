/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminAddUserToGroupRequest.h"

#endif

#include "AdminAddUserToGroupRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminAddUserToGroupRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The username for the user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    *  <p>The group name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString groupName;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminAddUserToGroupRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminAddUserToGroupRequest awsAdminAddUserToGroupRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminAddUserToGroupRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminAddUserToGroupRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        if (!(this->groupName.IsEmpty())) {
            awsAdminAddUserToGroupRequest.SetGroupName(TCHAR_TO_UTF8(*this->groupName));
        }

        return awsAdminAddUserToGroupRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty() && this->groupName.IsEmpty();
    }
#endif
};
