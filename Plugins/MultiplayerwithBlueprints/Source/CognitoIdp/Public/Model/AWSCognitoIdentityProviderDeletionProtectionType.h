/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSCognitoIdentityProviderDeletionProtectionType.generated.h"

UENUM(BlueprintType)
enum class EAWSCognitoIdentityProviderDeletionProtectionType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ACTIVE        UMETA(DisplayName = "active"),
    INACTIVE        UMETA(DisplayName = "inactive"),
};
