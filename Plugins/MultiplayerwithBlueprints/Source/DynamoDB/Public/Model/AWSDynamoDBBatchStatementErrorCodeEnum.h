/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSDynamoDBBatchStatementErrorCodeEnum.generated.h"

UENUM(BlueprintType)
enum class EAWSDynamoDBBatchStatementErrorCodeEnum : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ConditionalCheckFailed        UMETA(DisplayName = "conditional check failed"),
    ItemCollectionSizeLimitExceeded        UMETA(DisplayName = "item collection size limit exceeded"),
    RequestLimitExceeded        UMETA(DisplayName = "request limit exceeded"),
    ValidationError        UMETA(DisplayName = "validation error"),
    ProvisionedThroughputExceeded        UMETA(DisplayName = "provisioned throughput exceeded"),
    TransactionConflict        UMETA(DisplayName = "transaction conflict"),
    ThrottlingError        UMETA(DisplayName = "throttling error"),
    InternalServerError        UMETA(DisplayName = "internal server error"),
    ResourceNotFound        UMETA(DisplayName = "resource not found"),
    AccessDenied        UMETA(DisplayName = "access denied"),
    DuplicateItem        UMETA(DisplayName = "duplicate item"),
};
