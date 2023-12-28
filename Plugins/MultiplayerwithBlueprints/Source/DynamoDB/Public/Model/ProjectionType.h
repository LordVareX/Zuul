/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ProjectionType.generated.h"

UENUM(BlueprintType)
enum class EAWSProjectionType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ALL        UMETA(DisplayName = "all"),
    KEYS_ONLY        UMETA(DisplayName = "keys only"),
    INCLUDE        UMETA(DisplayName = "include"),
};
