/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSLambdaSnapStartOptimizationStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSLambdaSnapStartOptimizationStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    On        UMETA(DisplayName = "on"),
    Off        UMETA(DisplayName = "off"),
};
