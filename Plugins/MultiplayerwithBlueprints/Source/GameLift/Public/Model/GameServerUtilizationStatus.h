/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "GameServerUtilizationStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSGameServerUtilizationStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    AVAILABLE        UMETA(DisplayName = "available"),
    UTILIZED        UMETA(DisplayName = "utilized")
};
