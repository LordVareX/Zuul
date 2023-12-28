/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "DefaultEmailOptionType.generated.h"

UENUM(BlueprintType)
enum class EDefaultEmailOptionType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    CONFIRM_WITH_LINK        UMETA(DisplayName = "confirm with link"),
    CONFIRM_WITH_CODE        UMETA(DisplayName = "confirm with code")
};
