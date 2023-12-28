/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CreateGroupRequest.h"

#endif

#include "CreateGroupRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateGroupRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the group. Must be unique.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString groupName;

    /**
    *  <p>The user pool ID for the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>A string containing the description of the group.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString description;

    /**
    *  <p>The role ARN for the group.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString roleArn;

    /**
    *  <p>A nonnegative integer value that specifies the precedence of this group relative to the other groups that a user can belong to in the user pool. Zero is the highest precedence value. Groups with lower <code>Precedence</code> values take precedence over groups with higher or null <code>Precedence</code> values. If a user belongs to two or more groups, it is the group with the lowest precedence value whose role ARN will be used in the <code>cognito:roles</code> and <code>cognito:preferred_role</code> claims in the user's tokens.</p> <p>Two groups can have the same <code>Precedence</code> value. If this happens, neither group takes precedence over the other. If two groups with the same <code>Precedence</code> have the same role ARN, that role is used in the <code>cognito:preferred_role</code> claim in tokens for users in each group. If the two groups have different role ARNs, the <code>cognito:preferred_role</code> claim is not set in users' tokens.</p> <p>The default <code>Precedence</code> value is null.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int precedence = 0;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::CreateGroupRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::CreateGroupRequest awsCreateGroupRequest;

        if (!(this->groupName.IsEmpty())) {
            awsCreateGroupRequest.SetGroupName(TCHAR_TO_UTF8(*this->groupName));
        }

        if (!(this->userPoolId.IsEmpty())) {
            awsCreateGroupRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->description.IsEmpty())) {
            awsCreateGroupRequest.SetDescription(TCHAR_TO_UTF8(*this->description));
        }

        if (!(this->roleArn.IsEmpty())) {
            awsCreateGroupRequest.SetRoleArn(TCHAR_TO_UTF8(*this->roleArn));
        }

        if (this->precedence != 0) {
            awsCreateGroupRequest.SetPrecedence(this->precedence);
        }

        return awsCreateGroupRequest;
    }

    bool IsEmpty() const {
        return this->groupName.IsEmpty() && this->userPoolId.IsEmpty() && this->description.IsEmpty() && this->roleArn.IsEmpty() && this->precedence == 0;
    }
#endif
};
