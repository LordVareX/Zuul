/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/TransactWriteItemsResult.h"

#endif

#include "Model/ConsumedCapacity.h"
#include "Model/ItemCollectionMetrics.h"

#include "TransactWriteItemsResult.generated.h"

USTRUCT(BlueprintType)
struct FTransactWriteItemsResult {
GENERATED_BODY()

    /**
    *  <p>The capacity units consumed by the entire <code>TransactWriteItems</code> operation. The values of the list are ordered according to the ordering of the <code>TransactItems</code> request parameter. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FConsumedCapacity> consumedCapacity;

    /**
    *  <p>A list of tables that were processed by <code>TransactWriteItems</code> and, for each table, information about any item collections that were affected by individual <code>UpdateItem</code>, <code>PutItem</code>, or <code>DeleteItem</code> operations. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FString> itemCollectionMetrics;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FTransactWriteItemsResult &fromAWS(const Aws::DynamoDB::Model::TransactWriteItemsResult &awsTransactWriteItemsResult) {
        this->consumedCapacity.Empty();
        for (const Aws::DynamoDB::Model::ConsumedCapacity& elem : awsTransactWriteItemsResult.GetConsumedCapacity()) {
            this->consumedCapacity.Add(FConsumedCapacity().fromAWS(elem));
        }

        this->itemCollectionMetrics.Empty();
        for (const auto& elem : awsTransactWriteItemsResult.GetItemCollectionMetrics()) {
            Aws::Utils::Array<Aws::Utils::Json::JsonValue> jsonArray(elem.second.size());
            int i = 0;
            for (const Aws::DynamoDB::Model::ItemCollectionMetrics& elem1 : elem.second) {
                jsonArray[i++] = elem1.Jsonize();
            }
            this->itemCollectionMetrics.Add(elem.first.c_str(), UTF8_TO_TCHAR(Aws::Utils::Json::JsonValue().AsArray(jsonArray).View().WriteReadable().c_str()));
        }

        return *this;
    }
#endif
};
