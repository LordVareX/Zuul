/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CreateIdentityProviderResult.h"

#endif

#include "Model/IdentityProviderType.h"

#include "CreateIdentityProviderResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateIdentityProviderResult {
GENERATED_BODY()

    /**
    *  <p>The newly created identity provider object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FIdentityProviderType identityProvider;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FCreateIdentityProviderResult &fromAWS(const Aws::CognitoIdentityProvider::Model::CreateIdentityProviderResult &awsCreateIdentityProviderResult) {
        this->identityProvider.fromAWS(awsCreateIdentityProviderResult.GetIdentityProvider());

        return *this;
    }
#endif
};
