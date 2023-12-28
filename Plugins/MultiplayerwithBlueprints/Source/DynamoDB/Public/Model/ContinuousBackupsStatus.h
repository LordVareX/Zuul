/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ContinuousBackupsStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSContinuousBackupsStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ENABLED        UMETA(DisplayName = "enabled"),
    DISABLED        UMETA(DisplayName = "disabled"),
};
