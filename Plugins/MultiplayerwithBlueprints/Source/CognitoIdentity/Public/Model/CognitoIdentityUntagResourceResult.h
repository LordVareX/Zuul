/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/UntagResourceResult.h"

#endif

#include "CognitoIdentityUntagResourceResult.generated.h"

USTRUCT(BlueprintType)
struct FCognitoIdentityUntagResourceResult {
    GENERATED_BODY()

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FCognitoIdentityUntagResourceResult &fromAWS(const Aws::CognitoIdentity::Model::UntagResourceResult &awsUntagResourceResult) {

        return *this;
    }
#endif
};
