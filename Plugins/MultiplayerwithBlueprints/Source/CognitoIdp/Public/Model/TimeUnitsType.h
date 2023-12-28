/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "TimeUnitsType.generated.h"

UENUM(BlueprintType)
enum class EAWSTimeUnitsType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    seconds        UMETA(DisplayName = "seconds"),
    minutes        UMETA(DisplayName = "minutes"),
    hours        UMETA(DisplayName = "hours"),
    days        UMETA(DisplayName = "days"),
};
