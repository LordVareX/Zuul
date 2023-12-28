/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/GlobalSecondaryIndexDescription.h"

#endif

#include "Model/DynamoDBKeySchemaElement.h"
#include "Model/Projection.h"
#include "Model/IndexStatus.h"
#include "Model/ProvisionedThroughputDescription.h"

#include "GlobalSecondaryIndexDescription.generated.h"

USTRUCT(BlueprintType)
struct FGlobalSecondaryIndexDescription {
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
    *  <p>The current state of the global secondary index:</p> <ul> <li> <p> <code>CREATING</code> - The index is being created.</p> </li> <li> <p> <code>UPDATING</code> - The index is being updated.</p> </li> <li> <p> <code>DELETING</code> - The index is being deleted.</p> </li> <li> <p> <code>ACTIVE</code> - The index is ready for use.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSIndexStatus indexStatus = EAWSIndexStatus::NOT_SET;

    /**
    *  <p>Indicates whether the index is currently backfilling. <i>Backfilling</i> is the process of reading items from the table and determining whether they can be added to the index. (Not all items will qualify: For example, a partition key cannot have any duplicate values.) If an item can be added to the index, DynamoDB will do so. After all items have been processed, the backfilling operation is complete and <code>Backfilling</code> is false.</p> <note> <p>For indexes that were created during a <code>CreateTable</code> operation, the <code>Backfilling</code> attribute does not appear in the <code>DescribeTable</code> output.</p> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    bool backfilling = false;

    /**
    *  <p>Represents the provisioned throughput settings for the specified global secondary index.</p> <p>For current minimum and maximum provisioned throughput values, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Limits.html">Limits</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FProvisionedThroughputDescription provisionedThroughput;

    /**
    *  <p>The total size of the specified index, in bytes. DynamoDB updates this value approximately every six hours. Recent changes might not be reflected in this value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 indexSizeBytes = 0;

    /**
    *  <p>The number of items in the specified index. DynamoDB updates this value approximately every six hours. Recent changes might not be reflected in this value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 itemCount = 0;

    /**
    *  <p>The Amazon Resource Name (ARN) that uniquely identifies the index.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexArn;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FGlobalSecondaryIndexDescription &fromAWS(const Aws::DynamoDB::Model::GlobalSecondaryIndexDescription &awsGlobalSecondaryIndexDescription) {
        this->indexName = UTF8_TO_TCHAR(awsGlobalSecondaryIndexDescription.GetIndexName().c_str());

        this->keySchema.Empty();
        for (const Aws::DynamoDB::Model::KeySchemaElement& elem : awsGlobalSecondaryIndexDescription.GetKeySchema()) {
            this->keySchema.Add(FDynamoDBKeySchemaElement().fromAWS(elem));
        }

        this->projection.fromAWS(awsGlobalSecondaryIndexDescription.GetProjection());
        

        switch(awsGlobalSecondaryIndexDescription.GetIndexStatus()) {
            case Aws::DynamoDB::Model::IndexStatus::NOT_SET:
                this->indexStatus = EAWSIndexStatus::NOT_SET;
                break;
            case Aws::DynamoDB::Model::IndexStatus::CREATING:
                this->indexStatus = EAWSIndexStatus::CREATING;
                break;
            case Aws::DynamoDB::Model::IndexStatus::UPDATING:
                this->indexStatus = EAWSIndexStatus::UPDATING;
                break;
            case Aws::DynamoDB::Model::IndexStatus::DELETING:
                this->indexStatus = EAWSIndexStatus::DELETING;
                break;
            case Aws::DynamoDB::Model::IndexStatus::ACTIVE:
                this->indexStatus = EAWSIndexStatus::ACTIVE;
                break;
            default:
                this->indexStatus = EAWSIndexStatus::NOT_SET;
                break;
        }

        this->backfilling = awsGlobalSecondaryIndexDescription.GetBackfilling();

        this->provisionedThroughput.fromAWS(awsGlobalSecondaryIndexDescription.GetProvisionedThroughput());

        this->indexSizeBytes = (int64)awsGlobalSecondaryIndexDescription.GetIndexSizeBytes();

        this->itemCount = (int64)awsGlobalSecondaryIndexDescription.GetItemCount();

        this->indexArn = UTF8_TO_TCHAR(awsGlobalSecondaryIndexDescription.GetIndexArn().c_str());

        return *this;
    }
#endif
};
