/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeregisterComputeResult.h"

#endif

#include "AWSGameLiftDeregisterComputeResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftDeregisterComputeResult {
GENERATED_BODY()

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAWSGameLiftDeregisterComputeResult &fromAWS(const Aws::GameLift::Model::DeregisterComputeResult &awsDeregisterComputeResult) {
        return *this;
    }
#endif
};
