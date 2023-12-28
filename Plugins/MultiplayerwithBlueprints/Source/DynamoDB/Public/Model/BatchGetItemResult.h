/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/core/utils/json/JsonSerializer.h"
#include "aws/core/utils/Array.h"
#include "aws/dynamodb/model/BatchGetItemResult.h"

#endif

#include "Model/DynamoDBAttributeValue.h"
#include "Model/KeysAndAttributes.h"
#include "Model/ConsumedCapacity.h"

#include "BatchGetItemResult.generated.h"

USTRUCT(BlueprintType)
struct FBatchGetItemResult {
GENERATED_BODY()

    /**
    *  <p>A map of table name to a list of items. Each object in <code>Responses</code> consists of a table name, along with a map of attribute data consisting of the data type and attribute value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString responses;

    /**
    *  <p>A map of tables and their respective keys that were not processed with the current response. The <code>UnprocessedKeys</code> value is in the same form as <code>RequestItems</code>, so the value can be provided directly to a subsequent <code>BatchGetItem</code> operation. For more information, see <code>RequestItems</code> in the Request Parameters section.</p> <p>Each element consists of:</p> <ul> <li> <p> <code>Keys</code> - An array of primary key attribute values that define specific items in the table.</p> </li> <li> <p> <code>ProjectionExpression</code> - One or more attributes to be retrieved from the table or index. By default, all attributes are returned. If a requested attribute is not found, it does not appear in the result.</p> </li> <li> <p> <code>ConsistentRead</code> - The consistency of a read operation. If set to <code>true</code>, then a strongly consistent read is used; otherwise, an eventually consistent read is used.</p> </li> </ul> <p>If there are no unprocessed keys remaining, the response contains an empty <code>UnprocessedKeys</code> map.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FKeysAndAttributes> unprocessedKeys;

    /**
    *  <p>The read capacity units consumed by the entire <code>BatchGetItem</code> operation.</p> <p>Each element consists of:</p> <ul> <li> <p> <code>TableName</code> - The table that consumed the provisioned throughput.</p> </li> <li> <p> <code>CapacityUnits</code> - The total number of capacity units consumed.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FConsumedCapacity> consumedCapacity;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FBatchGetItemResult &fromAWS(const Aws::DynamoDB::Model::BatchGetItemResult &awsBatchGetItemResult) {
        {
            Aws::Utils::Json::JsonValue jsonValue;
            for (const auto& elem : awsBatchGetItemResult.GetResponses()) {
                Aws::Utils::Array<Aws::Utils::Json::JsonValue> jsonArray1(elem.second.size());
                int i = 0;
                for (const Aws::Map<Aws::String, Aws::DynamoDB::Model::AttributeValue>& elem1 : elem.second) {
                    Aws::Utils::Json::JsonValue jsonValue2;
                    for (const auto& elem2 : elem1) {
                        Aws::Utils::Json::JsonValue jsonValue3 = elem2.second.Jsonize();
                        jsonValue2.WithObject(elem2.first, jsonValue3);
                    }
                    jsonArray1[i++] = jsonValue2;
                }
                jsonValue.WithArray(elem.first, jsonArray1);
            }
            this->responses = UTF8_TO_TCHAR(jsonValue.View().WriteReadable().c_str());
        }

        this->unprocessedKeys.Empty();
        for (const auto& elem : awsBatchGetItemResult.GetUnprocessedKeys()) {
            this->unprocessedKeys.Add(elem.first.c_str(), FKeysAndAttributes().fromAWS(elem.second));
        }

        this->consumedCapacity.Empty();
        for (const Aws::DynamoDB::Model::ConsumedCapacity& elem : awsBatchGetItemResult.GetConsumedCapacity()) {
            this->consumedCapacity.Add(FConsumedCapacity().fromAWS(elem));
        }

        return *this;
    }
#endif
};
