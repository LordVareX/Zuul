/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GetGroupRequest.h"

#endif

#include "GetGroupRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetGroupRequest {
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
    Aws::CognitoIdentityProvider::Model::GetGroupRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::GetGroupRequest awsGetGroupRequest;

        if (!(this->groupName.IsEmpty())) {
            awsGetGroupRequest.SetGroupName(TCHAR_TO_UTF8(*this->groupName));
        }

        if (!(this->userPoolId.IsEmpty())) {
            awsGetGroupRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        return awsGetGroupRequest;
    }

    bool IsEmpty() const {
        return this->groupName.IsEmpty() && this->userPoolId.IsEmpty();
    }
#endif
};
