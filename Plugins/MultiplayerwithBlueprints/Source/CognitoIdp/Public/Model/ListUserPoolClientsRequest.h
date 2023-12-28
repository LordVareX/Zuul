/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListUserPoolClientsRequest.h"

#endif

#include "ListUserPoolClientsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListUserPoolClientsRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool where you want to list user pool clients.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The maximum number of results you want the request to return when listing the user pool clients.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int maxResults = 0;

    /**
    *  <p>An identifier that was returned from the previous call to this operation, which can be used to return the next set of items in the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString nextToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::ListUserPoolClientsRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::ListUserPoolClientsRequest awsListUserPoolClientsRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsListUserPoolClientsRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (this->maxResults != 0) {
            awsListUserPoolClientsRequest.SetMaxResults(this->maxResults);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsListUserPoolClientsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsListUserPoolClientsRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->maxResults == 0 && this->nextToken.IsEmpty();
    }
#endif
};
