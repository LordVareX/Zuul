/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/Capacity.h"

#endif

#include "Capacity.generated.h"

USTRUCT(BlueprintType)
struct FCapacity {
GENERATED_BODY()

    /**
    *  <p>The total number of read capacity units consumed on a table or an index.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    float readCapacityUnits = 0.0f;

    /**
    *  <p>The total number of write capacity units consumed on a table or an index.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    float writeCapacityUnits = 0.0f;

    /**
    *  <p>The total number of capacity units consumed on a table or an index.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    float capacityUnits = 0.0f;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FCapacity &fromAWS(const Aws::DynamoDB::Model::Capacity &awsCapacity) {
        this->readCapacityUnits = (float)awsCapacity.GetReadCapacityUnits();

        this->writeCapacityUnits = (float)awsCapacity.GetWriteCapacityUnits();

        this->capacityUnits = (float)awsCapacity.GetCapacityUnits();

        return *this;
    }
#endif
};
