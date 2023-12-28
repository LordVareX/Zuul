/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListUserPoolsRequest.h"

#endif

#include "ListUserPoolsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListUserPoolsRequest {
GENERATED_BODY()

    /**
    *  <p>An identifier that was returned from the previous call to this operation, which can be used to return the next set of items in the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString nextToken;

    /**
    *  <p>The maximum number of results you want the request to return when listing the user pools.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int maxResults = 0;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::ListUserPoolsRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::ListUserPoolsRequest awsListUserPoolsRequest;

        if (!(this->nextToken.IsEmpty())) {
            awsListUserPoolsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        if (this->maxResults != 0) {
            awsListUserPoolsRequest.SetMaxResults(this->maxResults);
        }

        return awsListUserPoolsRequest;
    }

    bool IsEmpty() const {
        return this->nextToken.IsEmpty() && this->maxResults == 0;
    }
#endif
};
