/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "StreamViewType.generated.h"

UENUM(BlueprintType)
enum class EAWSStreamViewType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    NEW_IMAGE        UMETA(DisplayName = "new image"),
    OLD_IMAGE        UMETA(DisplayName = "old image"),
    NEW_AND_OLD_IMAGES        UMETA(DisplayName = "new and old images"),
    KEYS_ONLY        UMETA(DisplayName = "keys only"),
};
