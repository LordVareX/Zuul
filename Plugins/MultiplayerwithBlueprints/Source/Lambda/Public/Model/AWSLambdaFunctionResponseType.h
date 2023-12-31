/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSLambdaFunctionResponseType.generated.h"

UENUM(BlueprintType)
enum class EAWSLambdaFunctionResponseType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ReportBatchItemFailures        UMETA(DisplayName = "reportbatchitemfailures"),
};
