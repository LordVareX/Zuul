/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "StatusType.generated.h"

UENUM(BlueprintType)
enum class EStatusType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Enabled        UMETA(DisplayName = "enabled"),
    Disabled        UMETA(DisplayName = "disabled")
};
