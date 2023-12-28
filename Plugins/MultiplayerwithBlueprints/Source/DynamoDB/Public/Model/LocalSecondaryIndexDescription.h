/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/LocalSecondaryIndexDescription.h"

#endif

#include "Model/DynamoDBKeySchemaElement.h"
#include "Model/Projection.h"

#include "LocalSecondaryIndexDescription.generated.h"

USTRUCT(BlueprintType)
struct FLocalSecondaryIndexDescription {
GENERATED_BODY()

    /**
    *  <p>Represents the name of the local secondary index.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

    /**
    *  <p>The complete key schema for the local secondary index, consisting of one or more pairs of attribute names and key types:</p> <ul> <li> <p> <code>HASH</code> - partition key</p> </li> <li> <p> <code>RANGE</code> - sort key</p> </li> </ul> <note> <p>The partition key of an item is also known as its <i>hash attribute</i>. The term "hash attribute" derives from DynamoDB' usage of an internal hash function to evenly distribute data items across partitions, based on their partition key values.</p> <p>The sort key of an item is also known as its <i>range attribute</i>. The term "range attribute" derives from the way DynamoDB stores items with the same partition key physically close together, in sorted order by the sort key value.</p> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FDynamoDBKeySchemaElement> keySchema;

    /**
    *  <p>Represents attributes that are copied (projected) from the table into the global secondary index. These are in addition to the primary key attributes and index key attributes, which are automatically projected. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FProjection projection;

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
    FLocalSecondaryIndexDescription &fromAWS(const Aws::DynamoDB::Model::LocalSecondaryIndexDescription &awsLocalSecondaryIndexDescription) {
        this->indexName = UTF8_TO_TCHAR(awsLocalSecondaryIndexDescription.GetIndexName().c_str());

        this->keySchema.Empty();
        for (const Aws::DynamoDB::Model::KeySchemaElement& elem : awsLocalSecondaryIndexDescription.GetKeySchema()) {
            this->keySchema.Add(FDynamoDBKeySchemaElement().fromAWS(elem));
        }

        this->projection.fromAWS(awsLocalSecondaryIndexDescription.GetProjection());

        this->indexSizeBytes = (int64)awsLocalSecondaryIndexDescription.GetIndexSizeBytes();

        this->itemCount = (int64)awsLocalSecondaryIndexDescription.GetItemCount();

        this->indexArn = UTF8_TO_TCHAR(awsLocalSecondaryIndexDescription.GetIndexArn().c_str());

        return *this;
    }
#endif
};
