/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "RoleMappingType.generated.h"

UENUM(BlueprintType)
enum class ERoleMappingType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Token        UMETA(DisplayName = "token"),
    Rules        UMETA(DisplayName = "rules")
};
