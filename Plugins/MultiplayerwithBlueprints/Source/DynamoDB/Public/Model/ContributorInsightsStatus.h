/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "ContributorInsightsStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSContributorInsightsStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ENABLING        UMETA(DisplayName = "enabling"),
    ENABLED        UMETA(DisplayName = "enabled"),
    DISABLING        UMETA(DisplayName = "disabling"),
    DISABLED        UMETA(DisplayName = "disabled"),
    FAILED        UMETA(DisplayName = "failed"),
};
