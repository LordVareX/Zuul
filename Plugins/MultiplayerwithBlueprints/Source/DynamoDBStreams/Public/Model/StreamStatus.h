/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "StreamStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSStreamStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ENABLING        UMETA(DisplayName = "enabling"),
    ENABLED        UMETA(DisplayName = "enabled"),
    DISABLING        UMETA(DisplayName = "disabling"),
    DISABLED        UMETA(DisplayName = "disabled"),
};
