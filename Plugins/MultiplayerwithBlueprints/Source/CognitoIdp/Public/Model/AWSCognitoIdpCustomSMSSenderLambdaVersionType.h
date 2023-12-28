/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSCognitoIdpCustomSMSSenderLambdaVersionType.generated.h"

UENUM(BlueprintType)
enum class EAWSCognitoIdpCustomSMSSenderLambdaVersionType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    V1_0        UMETA(DisplayName = "v1.0"),
};
