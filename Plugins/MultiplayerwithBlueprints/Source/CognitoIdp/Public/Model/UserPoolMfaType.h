/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "UserPoolMfaType.generated.h"

UENUM(BlueprintType)
enum class EUserPoolMfaType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    OFF        UMETA(DisplayName = "off"),
    ON        UMETA(DisplayName = "on"),
    OPTIONAL_        UMETA(DisplayName = "optional")
};
