/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "DeviceRememberedStatusType.generated.h"

UENUM(BlueprintType)
enum class EDeviceRememberedStatusType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    remembered        UMETA(DisplayName = "remembered"),
    not_remembered        UMETA(DisplayName = "not remembered")
};
