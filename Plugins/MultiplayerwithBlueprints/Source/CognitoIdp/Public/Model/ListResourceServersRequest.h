/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListResourceServersRequest.h"

#endif

#include "ListResourceServersRequest.generated.h"

USTRUCT(BlueprintType)
struct FListResourceServersRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The maximum number of resource servers to return.</p>
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
    Aws::CognitoIdentityProvider::Model::ListResourceServersRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::ListResourceServersRequest awsListResourceServersRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsListResourceServersRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->maxResults == 0)) {
            awsListResourceServersRequest.SetMaxResults(this->maxResults);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsListResourceServersRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsListResourceServersRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->maxResults == 0 && this->nextToken.IsEmpty();
    }
#endif
};
