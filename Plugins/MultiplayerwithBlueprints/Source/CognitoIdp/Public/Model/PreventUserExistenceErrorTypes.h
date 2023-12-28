/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "PreventUserExistenceErrorTypes.generated.h"

UENUM(BlueprintType)
enum class EAWSPreventUserExistenceErrorTypes : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    LEGACY        UMETA(DisplayName = "legacy"),
    ENABLED        UMETA(DisplayName = "enabled")
};
