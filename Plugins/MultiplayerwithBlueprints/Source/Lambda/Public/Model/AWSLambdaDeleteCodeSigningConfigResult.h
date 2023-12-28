/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/DeleteCodeSigningConfigResult.h"

#endif

#include "AWSLambdaDeleteCodeSigningConfigResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaDeleteCodeSigningConfigResult {
GENERATED_BODY()

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FAWSLambdaDeleteCodeSigningConfigResult &fromAWS(const Aws::Lambda::Model::DeleteCodeSigningConfigResult &awsDeleteCodeSigningConfigResult) {
        return *this;
    }
#endif
};
