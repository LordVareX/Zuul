/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UpdateIdentityProviderResult.h"

#endif

#include "Model/IdentityProviderType.h"

#include "UpdateIdentityProviderResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateIdentityProviderResult {
GENERATED_BODY()

    /**
    *  <p>The identity provider object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FIdentityProviderType identityProvider;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FUpdateIdentityProviderResult &fromAWS(const Aws::CognitoIdentityProvider::Model::UpdateIdentityProviderResult &awsUpdateIdentityProviderResult) {
        this->identityProvider.fromAWS(awsUpdateIdentityProviderResult.GetIdentityProvider());

        return *this;
    }
#endif
};
