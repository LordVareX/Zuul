/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "EmailSendingAccountType.generated.h"

UENUM(BlueprintType)
enum class EEmailSendingAccountType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    COGNITO_DEFAULT        UMETA(DisplayName = "cognito default"),
    DEVELOPER        UMETA(DisplayName = "developer")
};
