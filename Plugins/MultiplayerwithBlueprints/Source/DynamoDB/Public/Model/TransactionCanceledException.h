/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/TransactionCanceledException.h"

#endif

#include "Model/CancellationReason.h"

#include "TransactionCanceledException.generated.h"

USTRUCT(BlueprintType)
struct FTransactionCanceledException {
GENERATED_BODY()

    /**
    *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString message;

    /**
    *  <p>A list of cancellation reasons.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FCancellationReason> cancellationReasons;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
#endif
};
