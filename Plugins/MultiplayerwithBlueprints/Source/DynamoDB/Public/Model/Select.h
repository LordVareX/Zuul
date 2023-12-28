/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "Select.generated.h"

UENUM(BlueprintType)
enum class EAWSSelect : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ALL_ATTRIBUTES        UMETA(DisplayName = "all attributes"),
    ALL_PROJECTED_ATTRIBUTES        UMETA(DisplayName = "all projected attributes"),
    SPECIFIC_ATTRIBUTES        UMETA(DisplayName = "specific attributes"),
    COUNT        UMETA(DisplayName = "count"),
};
