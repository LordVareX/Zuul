/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "EventSourcePosition.generated.h"

UENUM(BlueprintType)
enum class ES3EventSourcePosition : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    TRIM_HORIZON        UMETA(DisplayName = "trim horizon"),
    LATEST        UMETA(DisplayName = "latest"),
    AT_TIMESTAMP        UMETA(DisplayName = "at timestamp"),
};
