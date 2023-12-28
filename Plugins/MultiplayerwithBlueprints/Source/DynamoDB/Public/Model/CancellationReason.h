/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/CancellationReason.h"

#endif

#include "Model/DynamoDBAttributeValue.h"

#include "CancellationReason.generated.h"

USTRUCT(BlueprintType)
struct FCancellationReason {
    GENERATED_BODY()

    /**
     * <p>Item in the request which caused the transaction to get cancelled.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> item;

    /**
     * <p>Status code for the result of the cancelled transaction.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString code;

    /**
     * <p>Cancellation reason message description.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString message;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:

#endif
};
