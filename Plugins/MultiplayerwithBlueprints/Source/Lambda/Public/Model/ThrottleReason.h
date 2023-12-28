/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ThrottleReason.generated.h"

UENUM(BlueprintType)
enum class EThrottleReason : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ConcurrentInvocationLimitExceeded        UMETA(DisplayName = "Concurrent Invocation Limit Exceeded"),
    FunctionInvocationRateLimitExceeded        UMETA(DisplayName = "Function Invocation Rate Limit Exceeded"),
    ReservedFunctionConcurrentInvocationLimitExceeded        UMETA(DisplayName = "Reserved Function Concurrent Invocation Limit Exceeded"),
    ReservedFunctionInvocationRateLimitExceeded        UMETA(DisplayName = "Reserved Function Invocation Rate Limit Exceeded"),
    CallerRateLimitExceeded        UMETA(DisplayName = "Caller Rate Limit Exceeded"),
};
