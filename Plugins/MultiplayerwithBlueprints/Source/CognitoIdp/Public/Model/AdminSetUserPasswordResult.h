/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminSetUserPasswordResult.h"

#endif

#include "AdminSetUserPasswordResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminSetUserPasswordResult {
GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminSetUserPasswordResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminSetUserPasswordResult &awsAdminSetUserPasswordResult) {

        return *this;
    }
#endif
};
