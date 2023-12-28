/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UpdateGroupRequest.h"

#endif

#include "UpdateGroupRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateGroupRequest {
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

    /**
    *  <p>A string containing the new description of the group.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString description;

    /**
    *  <p>The new role ARN for the group. This is used for setting the <code>cognito:roles</code> and <code>cognito:preferred_role</code> claims in the token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString roleArn;

    /**
    *  <p>The new precedence value for the group. For more information about this parameter, see .</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int precedence = 0;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::UpdateGroupRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::UpdateGroupRequest awsUpdateGroupRequest;

        if (!(this->groupName.IsEmpty())) {
            awsUpdateGroupRequest.SetGroupName(TCHAR_TO_UTF8(*this->groupName));
        }

        if (!(this->userPoolId.IsEmpty())) {
            awsUpdateGroupRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->description.IsEmpty())) {
            awsUpdateGroupRequest.SetDescription(TCHAR_TO_UTF8(*this->description));
        }

        if (!(this->roleArn.IsEmpty())) {
            awsUpdateGroupRequest.SetRoleArn(TCHAR_TO_UTF8(*this->roleArn));
        }

        if (!(this->precedence == 0)) {
            awsUpdateGroupRequest.SetPrecedence(this->precedence);
        }

        return awsUpdateGroupRequest;
    }

    bool IsEmpty() const {
        return this->groupName.IsEmpty() && this->userPoolId.IsEmpty() && this->description.IsEmpty() && this->roleArn.IsEmpty() && this->precedence == 0;
    }
#endif
};
