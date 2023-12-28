/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/UpdateItemResult.h"

#endif

#include "Model/DynamoDBAttributeValue.h"
#include "Model/ConsumedCapacity.h"
#include "Model/ItemCollectionMetrics.h"

#include "UpdateItemResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateItemResult {
GENERATED_BODY()

    /**
    *  <p>A map of attribute values as they appear before or after the <code>UpdateItem</code> operation, as determined by the <code>ReturnValues</code> parameter.</p> <p>The <code>Attributes</code> map is only present if <code>ReturnValues</code> was specified as something other than <code>NONE</code> in the request. Each element represents one attribute.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> attributes;

    /**
    *  <p>The capacity units consumed by the <code>UpdateItem</code> operation. The data returned includes the total provisioned throughput consumed, along with statistics for the table and any indexes involved in the operation. <code>ConsumedCapacity</code> is only returned if the <code>ReturnConsumedCapacity</code> parameter was specified. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/ProvisionedThroughputIntro.html">Provisioned Throughput</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FConsumedCapacity consumedCapacity;

    /**
    *  <p>Information about item collections, if any, that were affected by the <code>UpdateItem</code> operation. <code>ItemCollectionMetrics</code> is only returned if the <code>ReturnItemCollectionMetrics</code> parameter was specified. If the table does not have any local secondary indexes, this information is not returned in the response.</p> <p>Each <code>ItemCollectionMetrics</code> element consists of:</p> <ul> <li> <p> <code>ItemCollectionKey</code> - The partition key value of the item collection. This is the same as the partition key value of the item itself.</p> </li> <li> <p> <code>SizeEstimateRangeGB</code> - An estimate of item collection size, in gigabytes. This value is a two-element array containing a lower bound and an upper bound for the estimate. The estimate includes the size of all the items in the table, plus the size of all attributes projected into all of the local secondary indexes on that table. Use this estimate to measure whether a local secondary index is approaching its size limit.</p> <p>The estimate is subject to change over time; therefore, do not rely on the precision or accuracy of the estimate.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FItemCollectionMetrics itemCollectionMetrics;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FUpdateItemResult &fromAWS(const Aws::DynamoDB::Model::UpdateItemResult &awsUpdateItemResult) {
        this->attributes.Empty();
        for (const auto& elem : awsUpdateItemResult.GetAttributes()) {
            this->attributes.Add(elem.first.c_str(), FDynamoDBAttributeValue().fromAWS(elem.second));
        }

        this->consumedCapacity.fromAWS(awsUpdateItemResult.GetConsumedCapacity());

        this->itemCollectionMetrics.fromAWS(awsUpdateItemResult.GetItemCollectionMetrics());

        return *this;
    }
#endif
};
