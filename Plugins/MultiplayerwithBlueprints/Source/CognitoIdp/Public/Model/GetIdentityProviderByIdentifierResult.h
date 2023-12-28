/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GetIdentityProviderByIdentifierResult.h"

#endif

#include "Model/IdentityProviderType.h"

#include "GetIdentityProviderByIdentifierResult.generated.h"

USTRUCT(BlueprintType)
struct FGetIdentityProviderByIdentifierResult {
GENERATED_BODY()

    /**
    *  <p>The identity provider object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FIdentityProviderType identityProvider;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FGetIdentityProviderByIdentifierResult &fromAWS(const Aws::CognitoIdentityProvider::Model::GetIdentityProviderByIdentifierResult &awsGetIdentityProviderByIdentifierResult) {
        this->identityProvider.fromAWS(awsGetIdentityProviderByIdentifierResult.GetIdentityProvider());

        return *this;
    }
#endif
};
