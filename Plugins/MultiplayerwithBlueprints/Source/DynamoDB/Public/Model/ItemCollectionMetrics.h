/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ItemCollectionMetrics.h"

#endif

#include "Model/DynamoDBAttributeValue.h"

#include "ItemCollectionMetrics.generated.h"

USTRUCT(BlueprintType)
struct FItemCollectionMetrics {
GENERATED_BODY()

    /**
    *  <p>The partition key value of the item collection. This value is the same as the partition key value of the item.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> itemCollectionKey;

    /**
    *  <p>An estimate of item collection size, in gigabytes. This value is a two-element array containing a lower bound and an upper bound for the estimate. The estimate includes the size of all the items in the table, plus the size of all attributes projected into all of the local secondary indexes on that table. Use this estimate to measure whether a local secondary index is approaching its size limit.</p> <p>The estimate is subject to change over time; therefore, do not rely on the precision or accuracy of the estimate.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<float> sizeEstimateRangeGB;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FItemCollectionMetrics &fromAWS(const Aws::DynamoDB::Model::ItemCollectionMetrics &awsItemCollectionMetrics) {
        this->itemCollectionKey.Empty();
        for (const auto& elem : awsItemCollectionMetrics.GetItemCollectionKey()) {
            this->itemCollectionKey.Add(elem.first.c_str(), FDynamoDBAttributeValue().fromAWS(elem.second));
        }

        this->sizeEstimateRangeGB.Empty();
        for (const double& elem : awsItemCollectionMetrics.GetSizeEstimateRangeGB()) {
            this->sizeEstimateRangeGB.Add(elem);
        }

        return *this;
    }
#endif
};
