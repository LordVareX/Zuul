/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminListGroupsForUserRequest.h"

#endif

#include "AdminListGroupsForUserRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminListGroupsForUserRequest {
GENERATED_BODY()

    /**
    *  <p>The username for the user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    *  <p>The user pool ID for the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The limit of the request to list groups.</p>
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
    Aws::CognitoIdentityProvider::Model::AdminListGroupsForUserRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminListGroupsForUserRequest awsAdminListGroupsForUserRequest;

        if (!(this->username.IsEmpty())) {
            awsAdminListGroupsForUserRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminListGroupsForUserRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (this->limit != 0) {
            awsAdminListGroupsForUserRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsAdminListGroupsForUserRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsAdminListGroupsForUserRequest;
    }

    bool IsEmpty() const {
        return this->username.IsEmpty() && this->userPoolId.IsEmpty() && this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
