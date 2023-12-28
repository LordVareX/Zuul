/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminDisableUserResult.h"

#endif

#include "AdminDisableUserResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminDisableUserResult {
GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminDisableUserResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminDisableUserResult &awsAdminDisableUserResult) {

        return *this;
    }
#endif
};
