/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GlobalSignOutResult.h"

#endif

#include "GlobalSignOutResult.generated.h"

USTRUCT(BlueprintType)
struct FGlobalSignOutResult {
    GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FGlobalSignOutResult &fromAWS(const Aws::CognitoIdentityProvider::Model::GlobalSignOutResult &awsGlobalSignOutResult) {

        return *this;
    }
#endif
};
