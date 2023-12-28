/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/QueryResult.h"

#endif

#include "Model/DynamoDBAttributeValue.h"
#include "Model/ConsumedCapacity.h"

#include "QueryResult.generated.h"

USTRUCT(BlueprintType)
struct FQueryResult {
GENERATED_BODY()

    /**
    *  <p>An array of item attributes that match the query criteria. Each element in this array consists of an attribute name and the value for that attribute.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FString> items;

    /**
    *  <p>The number of items in the response.</p> <p>If you used a <code>QueryFilter</code> in the request, then <code>Count</code> is the number of items returned after the filter was applied, and <code>ScannedCount</code> is the number of matching items before the filter was applied.</p> <p>If you did not use a filter in the request, then <code>Count</code> and <code>ScannedCount</code> are the same.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int count = 0;

    /**
    *  <p>The number of items evaluated, before any <code>QueryFilter</code> is applied. A high <code>ScannedCount</code> value with few, or no, <code>Count</code> results indicates an inefficient <code>Query</code> operation. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/QueryAndScan.html#Count">Count and ScannedCount</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p> <p>If you did not use a filter in the request, then <code>ScannedCount</code> is the same as <code>Count</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int scannedCount = 0;

    /**
    *  <p>The primary key of the item where the operation stopped, inclusive of the previous result set. Use this value to start a new operation, excluding this value in the new request.</p> <p>If <code>LastEvaluatedKey</code> is empty, then the "last page" of results has been processed and there is no more data to be retrieved.</p> <p>If <code>LastEvaluatedKey</code> is not empty, it does not necessarily mean that there is more data in the result set. The only way to know when you have reached the end of the result set is when <code>LastEvaluatedKey</code> is empty.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> lastEvaluatedKey;

    /**
    *  <p>The capacity units consumed by the <code>Query</code> operation. The data returned includes the total provisioned throughput consumed, along with statistics for the table and any indexes involved in the operation. <code>ConsumedCapacity</code> is only returned if the <code>ReturnConsumedCapacity</code> parameter was specified. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/ProvisionedThroughputIntro.html">Provisioned Throughput</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FConsumedCapacity consumedCapacity;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FQueryResult &fromAWS(const Aws::DynamoDB::Model::QueryResult &awsQueryResult) {
        this->items.Empty();
        for (const Aws::Map<Aws::String, Aws::DynamoDB::Model::AttributeValue>& elem : awsQueryResult.GetItems()) {
            Aws::Utils::Json::JsonValue json;
            for (const auto& elem1 : elem) {
                json.WithObject(elem1.first, elem1.second.Jsonize());
            }
            this->items.Add(UTF8_TO_TCHAR(json.View().WriteReadable().c_str()));
        }

		this->count = awsQueryResult.GetCount();

		this->scannedCount = awsQueryResult.GetScannedCount();

        this->lastEvaluatedKey.Empty();
        for (const auto& elem : awsQueryResult.GetLastEvaluatedKey()) {
            this->lastEvaluatedKey.Add(elem.first.c_str(), FDynamoDBAttributeValue().fromAWS(elem.second));
        }

        this->consumedCapacity.fromAWS(awsQueryResult.GetConsumedCapacity());

        return *this;
    }
#endif
};
