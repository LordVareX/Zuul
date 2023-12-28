/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "FeedbackValueType.generated.h"

UENUM(BlueprintType)
enum class EFeedbackValueType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Valid        UMETA(DisplayName = "valid"),
    Invalid        UMETA(DisplayName = "invalid")
};
