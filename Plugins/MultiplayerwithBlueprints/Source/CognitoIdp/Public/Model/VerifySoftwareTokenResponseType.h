/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "VerifySoftwareTokenResponseType.generated.h"

UENUM(BlueprintType)
enum class EVerifySoftwareTokenResponseType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    SUCCESS        UMETA(DisplayName = "success"),
    ERROR_        UMETA(DisplayName = "error ")
};
