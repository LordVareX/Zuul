/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteLocationResult.h"

#endif

#include "AWSGameLiftDeleteLocationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftDeleteLocationResult {
GENERATED_BODY()

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAWSGameLiftDeleteLocationResult &fromAWS(const Aws::GameLift::Model::DeleteLocationResult &awsDeleteLocationResult) {
        return *this;
    }
#endif
};
