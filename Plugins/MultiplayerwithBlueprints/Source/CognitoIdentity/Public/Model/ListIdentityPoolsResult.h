/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/ListIdentityPoolsResult.h"

#endif

#include "Model/IdentityPoolShortDescription.h"

#include "ListIdentityPoolsResult.generated.h"

USTRUCT(BlueprintType)
struct FListIdentityPoolsResult {
GENERATED_BODY()

    /**
    *  <p>The identity pools returned by the ListIdentityPools action.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TArray<FIdentityPoolShortDescription> identityPools;

    /**
    *  <p>A pagination token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString nextToken;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FListIdentityPoolsResult &fromAWS(const Aws::CognitoIdentity::Model::ListIdentityPoolsResult &awsListIdentityPoolsResult) {
        this->identityPools.Empty();
        for (const Aws::CognitoIdentity::Model::IdentityPoolShortDescription& elem : awsListIdentityPoolsResult.GetIdentityPools()) {
            this->identityPools.Add(FIdentityPoolShortDescription().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListIdentityPoolsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
