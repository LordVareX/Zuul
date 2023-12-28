/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListUsersInGroupRequest.h"

#endif

#include "ListUsersInGroupRequest.generated.h"

USTRUCT(BlueprintType)
struct FListUsersInGroupRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The name of the group.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString groupName;

    /**
    *  <p>The limit of the request to list users.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int limit = 0;

    /**
    *  <p>An identifier that was returned from the previous call to this operation, which can be used to return the next set of items in the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString nextToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::ListUsersInGroupRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::ListUsersInGroupRequest awsListUsersInGroupRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsListUsersInGroupRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->groupName.IsEmpty())) {
            awsListUsersInGroupRequest.SetGroupName(TCHAR_TO_UTF8(*this->groupName));
        }

        if (this->limit != 0) {
            awsListUsersInGroupRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsListUsersInGroupRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsListUsersInGroupRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->groupName.IsEmpty() && this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
