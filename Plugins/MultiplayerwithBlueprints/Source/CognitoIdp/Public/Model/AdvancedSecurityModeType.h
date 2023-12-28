/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "AdvancedSecurityModeType.generated.h"

UENUM(BlueprintType)
enum class EAdvancedSecurityModeType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    OFF        UMETA(DisplayName = "off"),
    AUDIT        UMETA(DisplayName = "audit"),
    ENFORCED        UMETA(DisplayName = "enforced")
};
