/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/GlobalSecondaryIndexInfo.h"

#endif

#include "Model/DynamoDBKeySchemaElement.h"
#include "Model/Projection.h"
#include "Model/ProvisionedThroughput.h"

#include "GlobalSecondaryIndexInfo.generated.h"

USTRUCT(BlueprintType)
struct FGlobalSecondaryIndexInfo {
GENERATED_BODY()

    /**
    *  <p>The name of the global secondary index.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

    /**
    *  <p>The complete key schema for a global secondary index, which consists of one or more pairs of attribute names and key types:</p> <ul> <li> <p> <code>HASH</code> - partition key</p> </li> <li> <p> <code>RANGE</code> - sort key</p> </li> </ul> <note> <p>The partition key of an item is also known as its <i>hash attribute</i>. The term "hash attribute" derives from DynamoDB' usage of an internal hash function to evenly distribute data items across partitions, based on their partition key values.</p> <p>The sort key of an item is also known as its <i>range attribute</i>. The term "range attribute" derives from the way DynamoDB stores items with the same partition key physically close together, in sorted order by the sort key value.</p> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FDynamoDBKeySchemaElement> keySchema;

    /**
    *  <p>Represents attributes that are copied (projected) from the table into the global secondary index. These are in addition to the primary key attributes and index key attributes, which are automatically projected. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FProjection projection;

    /**
    *  <p>Represents the provisioned throughput settings for the specified global secondary index. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FProvisionedThroughput provisionedThroughput;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FGlobalSecondaryIndexInfo &fromAWS(const Aws::DynamoDB::Model::GlobalSecondaryIndexInfo &awsGlobalSecondaryIndexInfo) {
        this->indexName = UTF8_TO_TCHAR(awsGlobalSecondaryIndexInfo.GetIndexName().c_str());

        this->keySchema.Empty();
        for (const Aws::DynamoDB::Model::KeySchemaElement& elem : awsGlobalSecondaryIndexInfo.GetKeySchema()) {
            this->keySchema.Add(FDynamoDBKeySchemaElement().fromAWS(elem));
        }

        this->projection.fromAWS(awsGlobalSecondaryIndexInfo.GetProjection());

        this->provisionedThroughput.fromAWS(awsGlobalSecondaryIndexInfo.GetProvisionedThroughput());

        return *this;
    }
#endif
};
