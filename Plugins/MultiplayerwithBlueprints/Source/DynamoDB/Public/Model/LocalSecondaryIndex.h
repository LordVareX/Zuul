/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/LocalSecondaryIndex.h"

#endif

#include "Model/DynamoDBKeySchemaElement.h"
#include "Model/Projection.h"

#include "LocalSecondaryIndex.generated.h"

USTRUCT(BlueprintType)
struct FLocalSecondaryIndex {
GENERATED_BODY()

    /**
    *  <p>The name of the local secondary index. The name must be unique among all other indexes on this table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

    /**
    *  <p>The complete key schema for the local secondary index, consisting of one or more pairs of attribute names and key types:</p> <ul> <li> <p> <code>HASH</code> - partition key</p> </li> <li> <p> <code>RANGE</code> - sort key</p> </li> </ul> <note> <p>The partition key of an item is also known as its <i>hash attribute</i>. The term "hash attribute" derives from DynamoDB' usage of an internal hash function to evenly distribute data items across partitions, based on their partition key values.</p> <p>The sort key of an item is also known as its <i>range attribute</i>. The term "range attribute" derives from the way DynamoDB stores items with the same partition key physically close together, in sorted order by the sort key value.</p> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FDynamoDBKeySchemaElement> keySchema;

    /**
    *  <p>Represents attributes that are copied (projected) from the table into the local secondary index. These are in addition to the primary key attributes and index key attributes, which are automatically projected. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FProjection projection;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::LocalSecondaryIndex toAWS() const {
        Aws::DynamoDB::Model::LocalSecondaryIndex awsLocalSecondaryIndex;

		if (!(this->indexName.IsEmpty())) {
            awsLocalSecondaryIndex.SetIndexName(TCHAR_TO_UTF8(*this->indexName));
        }

        for (const FDynamoDBKeySchemaElement& elem : this->keySchema) {
            awsLocalSecondaryIndex.AddKeySchema(elem.toAWS());
        }

        if (!(this->projection.IsEmpty())) {
            awsLocalSecondaryIndex.SetProjection(this->projection.toAWS());
        }

        return awsLocalSecondaryIndex;
    }

    bool IsEmpty() const {
        return this->indexName.IsEmpty() && this->keySchema.Num() == 0 && this->projection.IsEmpty();
    }
#endif
};
