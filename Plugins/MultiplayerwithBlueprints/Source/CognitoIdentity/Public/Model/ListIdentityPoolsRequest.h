/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/ListIdentityPoolsRequest.h"

#endif

#include "ListIdentityPoolsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListIdentityPoolsRequest {
GENERATED_BODY()

    /**
    *  <p>The maximum number of identities to return.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    int maxResults = 0;

    /**
    *  <p>A pagination token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString nextToken;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::ListIdentityPoolsRequest toAWS() const {
        Aws::CognitoIdentity::Model::ListIdentityPoolsRequest awsListIdentityPoolsRequest;

        if (this->maxResults != 0) {
            awsListIdentityPoolsRequest.SetMaxResults(this->maxResults);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsListIdentityPoolsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsListIdentityPoolsRequest;
    }

    bool IsEmpty() const {
        return this->maxResults == 0 && this->nextToken.IsEmpty();
    }
#endif
};
