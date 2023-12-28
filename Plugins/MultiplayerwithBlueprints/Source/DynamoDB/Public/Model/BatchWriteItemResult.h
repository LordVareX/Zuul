/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/BatchWriteItemResult.h"

#endif

#include "Model/WriteRequest.h"
#include "Model/ItemCollectionMetrics.h"
#include "Model/ConsumedCapacity.h"

#include "BatchWriteItemResult.generated.h"

USTRUCT(BlueprintType)
struct FBatchWriteItemResult {
GENERATED_BODY()

    /**
    *  <p>A map of tables and requests against those tables that were not processed. The <code>UnprocessedItems</code> value is in the same form as <code>RequestItems</code>, so you can provide this value directly to a subsequent <code>BatchGetItem</code> operation. For more information, see <code>RequestItems</code> in the Request Parameters section.</p> <p>Each <code>UnprocessedItems</code> entry consists of a table name and, for that table, a list of operations to perform (<code>DeleteRequest</code> or <code>PutRequest</code>).</p> <ul> <li> <p> <code>DeleteRequest</code> - Perform a <code>DeleteItem</code> operation on the specified item. The item to be deleted is identified by a <code>Key</code> subelement:</p> <ul> <li> <p> <code>Key</code> - A map of primary key attribute values that uniquely identify the item. Each entry in this map consists of an attribute name and an attribute value.</p> </li> </ul> </li> <li> <p> <code>PutRequest</code> - Perform a <code>PutItem</code> operation on the specified item. The item to be put is identified by an <code>Item</code> subelement:</p> <ul> <li> <p> <code>Item</code> - A map of attributes and their values. Each entry in this map consists of an attribute name and an attribute value. Attribute values must not be null; string and binary type attributes must have lengths greater than zero; and set type attributes must not be empty. Requests that contain empty values will be rejected with a <code>ValidationException</code> exception.</p> <p>If you specify any attributes that are part of an index key, then the data types for those attributes must match those of the schema in the table's attribute definition.</p> </li> </ul> </li> </ul> <p>If there are no unprocessed items remaining, the response contains an empty <code>UnprocessedItems</code> map.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString unprocessedItems;

    /**
    *  <p>A list of tables that were processed by <code>BatchWriteItem</code> and, for each table, information about any item collections that were affected by individual <code>DeleteItem</code> or <code>PutItem</code> operations.</p> <p>Each entry consists of the following subelements:</p> <ul> <li> <p> <code>ItemCollectionKey</code> - The partition key value of the item collection. This is the same as the partition key value of the item.</p> </li> <li> <p> <code>SizeEstimateRangeGB</code> - An estimate of item collection size, expressed in GB. This is a two-element array containing a lower bound and an upper bound for the estimate. The estimate includes the size of all the items in the table, plus the size of all attributes projected into all of the local secondary indexes on the table. Use this estimate to measure whether a local secondary index is approaching its size limit.</p> <p>The estimate is subject to change over time; therefore, do not rely on the precision or accuracy of the estimate.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString itemCollectionMetrics;

    /**
    *  <p>The capacity units consumed by the entire <code>BatchWriteItem</code> operation.</p> <p>Each element consists of:</p> <ul> <li> <p> <code>TableName</code> - The table that consumed the provisioned throughput.</p> </li> <li> <p> <code>CapacityUnits</code> - The total number of capacity units consumed.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FConsumedCapacity> consumedCapacity;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FBatchWriteItemResult &fromAWS(const Aws::DynamoDB::Model::BatchWriteItemResult &awsBatchWriteItemResult) {
        {
            Aws::Utils::Json::JsonValue jsonValue;
            for (const auto& elem : awsBatchWriteItemResult.GetUnprocessedItems()) {
                Aws::Utils::Array<Aws::Utils::Json::JsonValue> jsonArray1(elem.second.size());
                int i = 0;
                for (const Aws::DynamoDB::Model::WriteRequest& elem1 : elem.second) {
                    jsonArray1[i++] = elem1.Jsonize();
                }
                jsonValue.WithArray(elem.first, jsonArray1);
            }
            this->unprocessedItems = UTF8_TO_TCHAR(jsonValue.View().WriteReadable().c_str());
        }

        {
            Aws::Utils::Json::JsonValue jsonValue;
            for (const auto& elem : awsBatchWriteItemResult.GetItemCollectionMetrics()) {
                Aws::Utils::Array<Aws::Utils::Json::JsonValue> jsonArray1(elem.second.size());
                int i = 0;
                for (const Aws::DynamoDB::Model::ItemCollectionMetrics& elem1 : elem.second) {
                    jsonArray1[i++] = elem1.Jsonize();
                }
                jsonValue.WithArray(elem.first, jsonArray1);
            }
            this->itemCollectionMetrics = UTF8_TO_TCHAR(jsonValue.View().WriteReadable().c_str());
        }

        this->consumedCapacity.Empty();
        for (const Aws::DynamoDB::Model::ConsumedCapacity& elem : awsBatchWriteItemResult.GetConsumedCapacity()) {
            this->consumedCapacity.Add(FConsumedCapacity().fromAWS(elem));
        }

        return *this;
    }
#endif
};
