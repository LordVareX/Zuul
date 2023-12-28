/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ConditionalOperator.generated.h"

UENUM(BlueprintType)
enum class EAWSConditionalOperator : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    AND        UMETA(DisplayName = "and"),
    OR        UMETA(DisplayName = "or"),
};
