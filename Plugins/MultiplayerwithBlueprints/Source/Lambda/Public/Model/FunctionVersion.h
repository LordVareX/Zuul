/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "FunctionVersion.generated.h"

UENUM(BlueprintType)
enum class EAWSFunctionVersion : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ALL        UMETA(DisplayName = "all"),
};
