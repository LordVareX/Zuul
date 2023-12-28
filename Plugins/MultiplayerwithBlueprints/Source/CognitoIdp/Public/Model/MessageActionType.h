/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "MessageActionType.generated.h"

UENUM(BlueprintType)
enum class EMessageActionType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    RESEND        UMETA(DisplayName = "resend"),
    SUPPRESS        UMETA(DisplayName = "suppress")
};
