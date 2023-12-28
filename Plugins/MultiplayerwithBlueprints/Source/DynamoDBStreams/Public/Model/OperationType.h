/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "OperationType.generated.h"

UENUM(BlueprintType)
enum class EAWSOperationType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    INSERT        UMETA(DisplayName = "insert"),
    MODIFY        UMETA(DisplayName = "modify"),
    REMOVE        UMETA(DisplayName = "remove"),
};
