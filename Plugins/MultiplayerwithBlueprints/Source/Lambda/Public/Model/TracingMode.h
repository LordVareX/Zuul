/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "TracingMode.generated.h"

UENUM(BlueprintType)
enum class EAWSTracingMode : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Active        UMETA(DisplayName = "active"),
    PassThrough        UMETA(DisplayName = "passthrough"),
};
