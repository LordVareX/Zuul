/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ScalarAttributeType.generated.h"

UENUM(BlueprintType)
enum class EAWSScalarAttributeType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    S        UMETA(DisplayName = "s"),
    N        UMETA(DisplayName = "n"),
    B        UMETA(DisplayName = "b"),
};
