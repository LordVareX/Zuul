/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListGroupsRequest.h"

#endif

#include "ListGroupsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListGroupsRequest {
GENERATED_BODY()

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
    Aws::CognitoIdentityProvider::Model::ListGroupsRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::ListGroupsRequest awsListGroupsRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsListGroupsRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (this->limit != 0) {
            awsListGroupsRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsListGroupsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsListGroupsRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
