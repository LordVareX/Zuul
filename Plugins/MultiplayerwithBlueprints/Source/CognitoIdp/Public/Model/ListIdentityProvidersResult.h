/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListIdentityProvidersResult.h"

#endif

#include "Model/ProviderDescription.h"

#include "ListIdentityProvidersResult.generated.h"

USTRUCT(BlueprintType)
struct FListIdentityProvidersResult {
GENERATED_BODY()

    /**
    *  <p>A list of identity provider objects.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FProviderDescription> providers;

    /**
    *  <p>A pagination token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString nextToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FListIdentityProvidersResult &fromAWS(const Aws::CognitoIdentityProvider::Model::ListIdentityProvidersResult &awsListIdentityProvidersResult) {
        this->providers.Empty();
        for (const Aws::CognitoIdentityProvider::Model::ProviderDescription& elem : awsListIdentityProvidersResult.GetProviders()) {
            this->providers.Add(FProviderDescription().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListIdentityProvidersResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
