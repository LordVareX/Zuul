/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "AmbiguousRoleResolutionType.generated.h"

UENUM(BlueprintType)
enum class EAmbiguousRoleResolutionType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    AuthenticatedRole        UMETA(DisplayName = "authenticatedrole"),
    Deny        UMETA(DisplayName = "deny")
};
