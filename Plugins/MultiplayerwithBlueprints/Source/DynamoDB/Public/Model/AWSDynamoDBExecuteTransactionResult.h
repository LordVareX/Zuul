/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ExecuteTransactionResult.h"

#endif

#include "Model/ItemResponse.h"
#include "Model/ConsumedCapacity.h"

#include "AWSDynamoDBExecuteTransactionResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBExecuteTransactionResult {
GENERATED_BODY()

    /**
    *  <p> The response to a PartiQL transaction. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FItemResponse> responses;

    /**
    *  <p>The capacity units consumed by the entire operation. The values of the list are ordered according to the ordering of the statements.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FConsumedCapacity> consumedCapacity;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBExecuteTransactionResult &fromAWS(const Aws::DynamoDB::Model::ExecuteTransactionResult &awsExecuteTransactionResult) {
        this->responses.Empty();
        for (const Aws::DynamoDB::Model::ItemResponse& elem : awsExecuteTransactionResult.GetResponses()) {
            this->responses.Add(FItemResponse().fromAWS(elem));
        }

        this->consumedCapacity.Empty();
        for (const Aws::DynamoDB::Model::ConsumedCapacity& elem : awsExecuteTransactionResult.GetConsumedCapacity()) {
            this->consumedCapacity.Add(FConsumedCapacity().fromAWS(elem));
        }

        return *this;
    }
#endif
};
