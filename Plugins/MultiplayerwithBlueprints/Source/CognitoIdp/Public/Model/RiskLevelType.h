/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "RiskLevelType.generated.h"

UENUM(BlueprintType)
enum class ERiskLevelType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Low        UMETA(DisplayName = "low"),
    Medium        UMETA(DisplayName = "medium"),
    High        UMETA(DisplayName = "high")
};
