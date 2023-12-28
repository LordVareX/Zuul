/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListIdentityProvidersRequest.h"

#endif

#include "ListIdentityProvidersRequest.generated.h"

USTRUCT(BlueprintType)
struct FListIdentityProvidersRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The maximum number of identity providers to return.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int maxResults = 0;

    /**
    *  <p>A pagination token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString nextToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::ListIdentityProvidersRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::ListIdentityProvidersRequest awsListIdentityProvidersRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsListIdentityProvidersRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (this->maxResults != 0) {
            awsListIdentityProvidersRequest.SetMaxResults(this->maxResults);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsListIdentityProvidersRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsListIdentityProvidersRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->maxResults == 0 && this->nextToken.IsEmpty();
    }
#endif
};
