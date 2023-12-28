/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ConsumedCapacity.h"

#endif

#include "Model/Capacity.h"
#include "Model/Capacity.h"
#include "Model/Capacity.h"

#include "ConsumedCapacity.generated.h"

USTRUCT(BlueprintType)
struct FConsumedCapacity {
GENERATED_BODY()

    /**
    *  <p>The name of the table that was affected by the operation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>The total number of capacity units consumed by the operation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    float capacityUnits = 0.0f;

    /**
    *  <p>The total number of read capacity units consumed by the operation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    float readCapacityUnits = 0.0f;

    /**
    *  <p>The total number of write capacity units consumed by the operation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    float writeCapacityUnits = 0.0f;

    /**
    *  <p>The amount of throughput consumed on the table affected by the operation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FCapacity table;

    /**
    *  <p>The amount of throughput consumed on each local index affected by the operation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FCapacity> localSecondaryIndexes;

    /**
    *  <p>The amount of throughput consumed on each global index affected by the operation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FCapacity> globalSecondaryIndexes;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FConsumedCapacity &fromAWS(const Aws::DynamoDB::Model::ConsumedCapacity &awsConsumedCapacity) {
        this->tableName = UTF8_TO_TCHAR(awsConsumedCapacity.GetTableName().c_str());

        this->capacityUnits = (float)awsConsumedCapacity.GetCapacityUnits();

        this->readCapacityUnits = (float)awsConsumedCapacity.GetReadCapacityUnits();

        this->writeCapacityUnits = (float)awsConsumedCapacity.GetWriteCapacityUnits();

        this->table.fromAWS(awsConsumedCapacity.GetTable());
        
        this->localSecondaryIndexes.Empty();
        for (const auto& elem : awsConsumedCapacity.GetLocalSecondaryIndexes()) {
            this->localSecondaryIndexes.Add(elem.first.c_str(), FCapacity().fromAWS(elem.second));
        }

        this->globalSecondaryIndexes.Empty();
        for (const auto& elem : awsConsumedCapacity.GetGlobalSecondaryIndexes()) {
            this->globalSecondaryIndexes.Add(elem.first.c_str(), FCapacity().fromAWS(elem.second));
        }

        return *this;
    }
#endif
};
