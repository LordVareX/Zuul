/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "LogType.generated.h"

UENUM(BlueprintType)
enum class EAWSLogType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    None        UMETA(DisplayName = "none"),
    Tail        UMETA(DisplayName = "tail"),
};
