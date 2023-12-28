/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminUserGlobalSignOutResult.h"

#endif

#include "AdminUserGlobalSignOutResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminUserGlobalSignOutResult {
GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminUserGlobalSignOutResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminUserGlobalSignOutResult &awsAdminUserGlobalSignOutResult) {

        return *this;
    }
#endif
};
