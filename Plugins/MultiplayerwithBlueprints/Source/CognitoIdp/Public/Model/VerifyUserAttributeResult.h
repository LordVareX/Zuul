/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/VerifyUserAttributeResult.h"

#endif

#include "VerifyUserAttributeResult.generated.h"

USTRUCT(BlueprintType)
struct FVerifyUserAttributeResult {
    GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FVerifyUserAttributeResult &fromAWS(const Aws::CognitoIdentityProvider::Model::VerifyUserAttributeResult &awsVerifyUserAttributeResult) {

        return *this;
    }
#endif
};
