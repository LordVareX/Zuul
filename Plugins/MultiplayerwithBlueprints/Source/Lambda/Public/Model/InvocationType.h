/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "InvocationType.generated.h"

UENUM(BlueprintType)
enum class EAWSInvocationType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Event        UMETA(DisplayName = "event"),
    RequestResponse        UMETA(DisplayName = "requestresponse"),
    DryRun        UMETA(DisplayName = "dryrun"),
};
