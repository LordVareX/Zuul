/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GroupType.h"

#endif

#include "GroupType.generated.h"

USTRUCT(BlueprintType)
struct FGroupType {
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
    *  <p>A nonnegative integer value that specifies the precedence of this group relative to the other groups that a user can belong to in the user pool. If a user belongs to two or more groups, it is the group with the highest precedence whose role ARN will be used in the <code>cognito:roles</code> and <code>cognito:preferred_role</code> claims in the user's tokens. Groups with higher <code>Precedence</code> values take precedence over groups with lower <code>Precedence</code> values or with null <code>Precedence</code> values.</p> <p>Two groups can have the same <code>Precedence</code> value. If this happens, neither group takes precedence over the other. If two groups with the same <code>Precedence</code> have the same role ARN, that role is used in the <code>cognito:preferred_role</code> claim in tokens for users in each group. If the two groups have different role ARNs, the <code>cognito:preferred_role</code> claim is not set in users' tokens.</p> <p>The default <code>Precedence</code> value is null.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int precedence = 0;

    /**
    *  <p>The date the group was last modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime lastModifiedDate;

    /**
    *  <p>The date the group was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime creationDate;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FGroupType &fromAWS(const Aws::CognitoIdentityProvider::Model::GroupType &awsGroupType) {
        this->groupName = UTF8_TO_TCHAR(awsGroupType.GetGroupName().c_str());

        this->userPoolId = UTF8_TO_TCHAR(awsGroupType.GetUserPoolId().c_str());

        this->description = UTF8_TO_TCHAR(awsGroupType.GetDescription().c_str());

        this->roleArn = UTF8_TO_TCHAR(awsGroupType.GetRoleArn().c_str());

        this->precedence = awsGroupType.GetPrecedence();

        this->lastModifiedDate = FDateTime(1970, 1, 1) + FTimespan(awsGroupType.GetLastModifiedDate().Millis() * ETimespan::TicksPerMillisecond);

        this->creationDate = FDateTime(1970, 1, 1) + FTimespan(awsGroupType.GetCreationDate().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
