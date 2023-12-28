/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSLambdaEndPointType.generated.h"

UENUM(BlueprintType)
enum class EAWSLambdaEndPointType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    KAFKA_BOOTSTRAP_SERVERS        UMETA(DisplayName = "kafka bootstrap servers"),
};
