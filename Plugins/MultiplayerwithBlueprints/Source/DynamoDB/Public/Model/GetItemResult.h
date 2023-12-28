/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/GetItemResult.h"

#endif

#include "Model/DynamoDBAttributeValue.h"
#include "Model/ConsumedCapacity.h"

#include "GetItemResult.generated.h"

USTRUCT(BlueprintType)
struct FGetItemResult {
GENERATED_BODY()

    /**
    *  <p>A map of attribute names to <code>AttributeValue</code> objects, as specified by <code>ProjectionExpression</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> item;

    /**
    *  <p>The capacity units consumed by the <code>GetItem</code> operation. The data returned includes the total provisioned throughput consumed, along with statistics for the table and any indexes involved in the operation. <code>ConsumedCapacity</code> is only returned if the <code>ReturnConsumedCapacity</code> parameter was specified. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/ProvisionedThroughputIntro.html">Read/Write Capacity Mode</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FConsumedCapacity consumedCapacity;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FGetItemResult &fromAWS(const Aws::DynamoDB::Model::GetItemResult &awsGetItemResult) {
        this->item.Empty();
        for (const auto& elem : awsGetItemResult.GetItem()) {
            this->item.Add(elem.first.c_str(), FDynamoDBAttributeValue().fromAWS(elem.second));
        }

        this->consumedCapacity.fromAWS(awsGetItemResult.GetConsumedCapacity());

        return *this;
    }
#endif
};
