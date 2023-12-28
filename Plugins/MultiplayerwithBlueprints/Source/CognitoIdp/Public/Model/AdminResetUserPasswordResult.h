/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminResetUserPasswordResult.h"

#endif

#include "AdminResetUserPasswordResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminResetUserPasswordResult {
GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminResetUserPasswordResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminResetUserPasswordResult &awsAdminResetUserPasswordResult) {

        return *this;
    }
#endif
};
