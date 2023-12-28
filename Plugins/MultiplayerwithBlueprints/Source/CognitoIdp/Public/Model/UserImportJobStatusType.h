/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "UserImportJobStatusType.generated.h"

UENUM(BlueprintType)
enum class EUserImportJobStatusType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Created        UMETA(DisplayName = "created"),
    Pending        UMETA(DisplayName = "pending"),
    InProgress        UMETA(DisplayName = "inprogress"),
    Stopping        UMETA(DisplayName = "stopping"),
    Expired        UMETA(DisplayName = "expired"),
    Stopped        UMETA(DisplayName = "stopped"),
    Failed        UMETA(DisplayName = "failed"),
    Succeeded        UMETA(DisplayName = "succeeded")
};
