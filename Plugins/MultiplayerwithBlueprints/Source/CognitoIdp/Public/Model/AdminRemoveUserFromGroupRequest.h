/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminRemoveUserFromGroupRequest.h"

#endif

#include "AdminRemoveUserFromGroupRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminRemoveUserFromGroupRequest {
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
    Aws::CognitoIdentityProvider::Model::AdminRemoveUserFromGroupRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminRemoveUserFromGroupRequest awsAdminRemoveUserFromGroupRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminRemoveUserFromGroupRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminRemoveUserFromGroupRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        if (!(this->groupName.IsEmpty())) {
            awsAdminRemoveUserFromGroupRequest.SetGroupName(TCHAR_TO_UTF8(*this->groupName));
        }

        return awsAdminRemoveUserFromGroupRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty() && this->groupName.IsEmpty();
    }
#endif
};
