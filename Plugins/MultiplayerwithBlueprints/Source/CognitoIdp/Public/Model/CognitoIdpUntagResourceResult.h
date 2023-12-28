/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UntagResourceResult.h"

#endif

#include "CognitoIdpUntagResourceResult.generated.h"

USTRUCT(BlueprintType)
struct FCognitoIdpUntagResourceResult {
    GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FCognitoIdpUntagResourceResult &fromAWS(const Aws::CognitoIdentityProvider::Model::UntagResourceResult &awsUntagResourceResult) {

        return *this;
    }
#endif
};
