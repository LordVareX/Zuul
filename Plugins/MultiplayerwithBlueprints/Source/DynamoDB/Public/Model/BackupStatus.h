/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "BackupStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSBackupStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    CREATING        UMETA(DisplayName = "creating"),
    DELETED        UMETA(DisplayName = "deleted"),
    AVAILABLE        UMETA(DisplayName = "available"),
};
