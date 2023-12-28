/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/ListIdentitiesRequest.h"

#endif

#include "ListIdentitiesRequest.generated.h"

USTRUCT(BlueprintType)
struct FListIdentitiesRequest {
GENERATED_BODY()

    /**
    *  <p>An identity pool ID in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolId;

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

    /**
    *  <p>An optional boolean parameter that allows you to hide disabled identities. If omitted, the ListIdentities API will include disabled identities in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    bool hideDisabled = false;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::ListIdentitiesRequest toAWS() const {
        Aws::CognitoIdentity::Model::ListIdentitiesRequest awsListIdentitiesRequest;

        if (!(this->identityPoolId.IsEmpty())) {
            awsListIdentitiesRequest.SetIdentityPoolId(TCHAR_TO_UTF8(*this->identityPoolId));
        }

        if (this->maxResults != 0) {
            awsListIdentitiesRequest.SetMaxResults(this->maxResults);
        }

        if (!(this->nextToken.IsEmpty())) {
        awsListIdentitiesRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        if (!(false)) {
        awsListIdentitiesRequest.SetHideDisabled(this->hideDisabled);
        }

        return awsListIdentitiesRequest;
    }

    bool IsEmpty() const {
        return this->identityPoolId.IsEmpty() && this->maxResults == 0 && this->nextToken.IsEmpty() && false;
    }
#endif
};
