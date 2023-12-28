/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "MappingRuleMatchType.generated.h"

UENUM(BlueprintType)
enum class EMappingRuleMatchType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Equals        UMETA(DisplayName = "equals"),
    Contains        UMETA(DisplayName = "contains"),
    StartsWith        UMETA(DisplayName = "startswith"),
    NotEqual        UMETA(DisplayName = "notequal")
};
