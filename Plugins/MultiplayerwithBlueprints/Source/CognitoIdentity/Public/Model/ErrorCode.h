/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ErrorCode.generated.h"

UENUM(BlueprintType)
enum class EErrorCode : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    AccessDenied        UMETA(DisplayName = "accessdenied"),
    InternalServerError        UMETA(DisplayName = "internalservererror")
};
