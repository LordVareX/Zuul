/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/TagResourceResult.h"

#endif

#include "CognitoIdpTagResourceResult.generated.h"

USTRUCT(BlueprintType)
struct FCognitoIdpTagResourceResult {
    GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FCognitoIdpTagResourceResult &fromAWS(const Aws::CognitoIdentityProvider::Model::TagResourceResult &awsTagResourceResult) {

        return *this;
    }
#endif
};
