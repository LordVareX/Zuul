/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AddCustomAttributesResult.h"

#endif

#include "AddCustomAttributesResult.generated.h"

USTRUCT(BlueprintType)
struct FAddCustomAttributesResult {
    GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAddCustomAttributesResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AddCustomAttributesResult &awsAddCustomAttributesResult) {

        return *this;
    }
#endif
};
