/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ReturnValue.generated.h"

UENUM(BlueprintType)
enum class EAWSReturnValue : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    NONE        UMETA(DisplayName = "none"),
    ALL_OLD        UMETA(DisplayName = "all old"),
    UPDATED_OLD        UMETA(DisplayName = "updated old"),
    ALL_NEW        UMETA(DisplayName = "all new"),
    UPDATED_NEW        UMETA(DisplayName = "updated new"),
};
