/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "RiskDecisionType.generated.h"

UENUM(BlueprintType)
enum class ERiskDecisionType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    NoRisk        UMETA(DisplayName = "norisk"),
    AccountTakeover        UMETA(DisplayName = "accounttakeover"),
    Block        UMETA(DisplayName = "block")
};
