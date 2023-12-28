/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "RecoveryOptionNameType.generated.h"

UENUM(BlueprintType)
enum class EAWSRecoveryOptionNameType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    verified_email        UMETA(DisplayName = "verified email"),
    verified_phone_number        UMETA(DisplayName = "verified phone number"),
    admin_only        UMETA(DisplayName = "admin only")
};
