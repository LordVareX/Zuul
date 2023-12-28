/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/RevokeTokenResult.h"

#endif

#include "AWSCognitoIdentityProviderRevokeTokenResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSCognitoIdentityProviderRevokeTokenResult {
GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:

    FAWSCognitoIdentityProviderRevokeTokenResult &fromAWS(const Aws::CognitoIdentityProvider::Model::RevokeTokenResult &awsRevokeTokenResult) {
        return *this;
    }
#endif
};
