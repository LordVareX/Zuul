/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "LastUpdateStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSLastUpdateStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Successful        UMETA(DisplayName = "successful"),
    Failed        UMETA(DisplayName = "failed"),
    InProgress        UMETA(DisplayName = "inprogress"),
};
