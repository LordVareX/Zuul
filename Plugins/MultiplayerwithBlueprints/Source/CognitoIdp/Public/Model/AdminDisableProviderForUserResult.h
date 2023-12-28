/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminDisableProviderForUserResult.h"

#endif

#include "AdminDisableProviderForUserResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminDisableProviderForUserResult {
GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminDisableProviderForUserResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminDisableProviderForUserResult &awsAdminDisableProviderForUserResult) {

        return *this;
    }
#endif
};
