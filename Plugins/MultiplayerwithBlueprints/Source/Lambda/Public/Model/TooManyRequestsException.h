/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/TooManyRequestsException.h"

#endif

#include "Model/ThrottleReason.h"

#include "TooManyRequestsException.generated.h"

USTRUCT(BlueprintType)
struct FTooManyRequestsException {
GENERATED_BODY()

    /**
    * <p>The number of seconds the caller should wait before retrying.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString retryAfterSeconds;

    /**
    *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString type;

    /**
    *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString message;

    /**
    *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EThrottleReason reason = EThrottleReason::NOT_SET;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
#endif
};
