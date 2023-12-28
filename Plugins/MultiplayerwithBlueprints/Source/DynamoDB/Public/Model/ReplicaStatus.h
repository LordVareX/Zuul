/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ReplicaStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSReplicaStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    CREATING        UMETA(DisplayName = "creating"),
    CREATION_FAILED        UMETA(DisplayName = "creation failed"),
    UPDATING        UMETA(DisplayName = "updating"),
    DELETING        UMETA(DisplayName = "deleting"),
    ACTIVE        UMETA(DisplayName = "active"),
    REGION_DISABLED        UMETA(DisplayName = "region disabled"),
    INACCESSIBLE_ENCRYPTION_CREDENTIALS        UMETA(DisplayName = "inaccessible encryption credentials"),
};
