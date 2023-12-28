/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/TagResourceResult.h"

#endif

#include "CognitoIdentityTagResourceResult.generated.h"

USTRUCT(BlueprintType)
struct FCognitoIdentityTagResourceResult {
    GENERATED_BODY()

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FCognitoIdentityTagResourceResult &fromAWS(const Aws::CognitoIdentity::Model::TagResourceResult &awsTagResourceResult) {

        return *this;
    }
#endif
};
