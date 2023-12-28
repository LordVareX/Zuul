/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "BackupTypeFilter.generated.h"

UENUM(BlueprintType)
enum class EAWSBackupTypeFilter : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    USER        UMETA(DisplayName = "user"),
    SYSTEM        UMETA(DisplayName = "system"),
    AWS_BACKUP        UMETA(DisplayName = "aws backup"),
    ALL        UMETA(DisplayName = "all"),
};
