/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminEnableUserResult.h"

#endif

#include "AdminEnableUserResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminEnableUserResult {
GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminEnableUserResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminEnableUserResult &awsAdminEnableUserResult) {

        return *this;
    }
#endif
};
