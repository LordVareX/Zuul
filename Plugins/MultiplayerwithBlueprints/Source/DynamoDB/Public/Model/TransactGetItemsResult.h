/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/TransactGetItemsResult.h"

#endif

#include "Model/ConsumedCapacity.h"
#include "Model/ItemResponse.h"

#include "TransactGetItemsResult.generated.h"

USTRUCT(BlueprintType)
struct FTransactGetItemsResult {
GENERATED_BODY()

    /**
    *  <p>If the <i>ReturnConsumedCapacity</i> value was <code>TOTAL</code>, this is an array of <code>ConsumedCapacity</code> objects, one for each table addressed by <code>TransactGetItem</code> objects in the <i>TransactItems</i> parameter. These <code>ConsumedCapacity</code> objects report the read-capacity units consumed by the <code>TransactGetItems</code> call in that table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FConsumedCapacity> consumedCapacity;

    /**
    *  <p>An ordered array of up to 25 <code>ItemResponse</code> objects, each of which corresponds to the <code>TransactGetItem</code> object in the same position in the <i>TransactItems</i> array. Each <code>ItemResponse</code> object contains a Map of the name-value pairs that are the projected attributes of the requested item.</p> <p>If a requested item could not be retrieved, the corresponding <code>ItemResponse</code> object is Null, or if the requested item has no projected attributes, the corresponding <code>ItemResponse</code> object is an empty Map. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FItemResponse> responses;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FTransactGetItemsResult &fromAWS(const Aws::DynamoDB::Model::TransactGetItemsResult &awsTransactGetItemsResult) {
        this->consumedCapacity.Empty();
        for (const Aws::DynamoDB::Model::ConsumedCapacity& elem : awsTransactGetItemsResult.GetConsumedCapacity()) {
            this->consumedCapacity.Add(FConsumedCapacity().fromAWS(elem));
        }

        this->responses.Empty();
        for (const Aws::DynamoDB::Model::ItemResponse& elem : awsTransactGetItemsResult.GetResponses()) {
            this->responses.Add(FItemResponse().fromAWS(elem));
        }

        return *this;
    }
#endif
};
