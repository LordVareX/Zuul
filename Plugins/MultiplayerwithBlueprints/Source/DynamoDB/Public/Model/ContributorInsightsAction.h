/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "ContributorInsightsAction.generated.h"

UENUM(BlueprintType)
enum class EAWSContributorInsightsAction : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ENABLE        UMETA(DisplayName = "enable"),
    DISABLE        UMETA(DisplayName = "disable"),
};
