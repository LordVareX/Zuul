/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "GlobalTableStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSGlobalTableStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    CREATING        UMETA(DisplayName = "creating"),
    ACTIVE        UMETA(DisplayName = "active"),
    DELETING        UMETA(DisplayName = "deleting"),
    UPDATING        UMETA(DisplayName = "updating"),
};
