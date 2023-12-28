/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ChangePasswordResult.h"

#endif

#include "ChangePasswordResult.generated.h"

USTRUCT(BlueprintType)
struct FChangePasswordResult {
    GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FChangePasswordResult &fromAWS(const Aws::CognitoIdentityProvider::Model::ChangePasswordResult &awsChangePasswordResult) {

        return *this;
    }
#endif
};
