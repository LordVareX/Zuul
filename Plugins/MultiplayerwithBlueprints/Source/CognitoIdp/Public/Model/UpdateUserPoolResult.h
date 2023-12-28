/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UpdateUserPoolResult.h"

#endif

#include "UpdateUserPoolResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateUserPoolResult {
    GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FUpdateUserPoolResult &fromAWS(const Aws::CognitoIdentityProvider::Model::UpdateUserPoolResult &awsUpdateUserPoolResult) {

        return *this;
    }
#endif
};
