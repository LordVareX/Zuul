/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/ListIdentitiesResult.h"

#endif

#include "Model/IdentityDescription.h"

#include "ListIdentitiesResult.generated.h"

USTRUCT(BlueprintType)
struct FListIdentitiesResult {
GENERATED_BODY()

    /**
    *  <p>An identity pool ID in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolId;

    /**
    *  <p>An object containing a set of identities and associated mappings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TArray<FIdentityDescription> identities;

    /**
    *  <p>A pagination token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString nextToken;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FListIdentitiesResult &fromAWS(const Aws::CognitoIdentity::Model::ListIdentitiesResult &awsListIdentitiesResult) {
        this->identityPoolId = UTF8_TO_TCHAR(awsListIdentitiesResult.GetIdentityPoolId().c_str());

        this->identities.Empty();
        for (const Aws::CognitoIdentity::Model::IdentityDescription& elem : awsListIdentitiesResult.GetIdentities()) {
            this->identities.Add(FIdentityDescription().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListIdentitiesResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
