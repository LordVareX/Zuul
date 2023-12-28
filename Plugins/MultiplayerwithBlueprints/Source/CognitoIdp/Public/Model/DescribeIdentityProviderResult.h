/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DescribeIdentityProviderResult.h"

#endif

#include "Model/IdentityProviderType.h"

#include "DescribeIdentityProviderResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeIdentityProviderResult {
GENERATED_BODY()

    /**
    *  <p>The identity provider that was deleted.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FIdentityProviderType identityProvider;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FDescribeIdentityProviderResult &fromAWS(const Aws::CognitoIdentityProvider::Model::DescribeIdentityProviderResult &awsDescribeIdentityProviderResult) {
        this->identityProvider.fromAWS(awsDescribeIdentityProviderResult.GetIdentityProvider());

        return *this;
    }
#endif
};
