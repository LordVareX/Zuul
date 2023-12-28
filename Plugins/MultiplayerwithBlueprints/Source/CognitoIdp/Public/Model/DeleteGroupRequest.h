/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DeleteGroupRequest.h"

#endif

#include "DeleteGroupRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteGroupRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the group.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString groupName;

    /**
    *  <p>The user pool ID for the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::DeleteGroupRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::DeleteGroupRequest awsDeleteGroupRequest;

        if (!(this->groupName.IsEmpty())) {
            awsDeleteGroupRequest.SetGroupName(TCHAR_TO_UTF8(*this->groupName));
        }

        if (!(this->userPoolId.IsEmpty())) {
            awsDeleteGroupRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        return awsDeleteGroupRequest;
    }

    bool IsEmpty() const {
        return this->groupName.IsEmpty() && this->userPoolId.IsEmpty();
    }
#endif
};
