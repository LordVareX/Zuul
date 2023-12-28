/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeLimitsResult.h"

#endif

#include "DescribeLimitsResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeLimitsResult {
GENERATED_BODY()

    /**
    *  <p>The maximum total read capacity units that your account allows you to provision across all of your tables in this Region.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 accountMaxReadCapacityUnits = 0;

    /**
    *  <p>The maximum total write capacity units that your account allows you to provision across all of your tables in this Region.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 accountMaxWriteCapacityUnits = 0;

    /**
    *  <p>The maximum read capacity units that your account allows you to provision for a new table that you are creating in this Region, including the read capacity units provisioned for its global secondary indexes (GSIs).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 tableMaxReadCapacityUnits = 0;

    /**
    *  <p>The maximum write capacity units that your account allows you to provision for a new table that you are creating in this Region, including the write capacity units provisioned for its global secondary indexes (GSIs).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 tableMaxWriteCapacityUnits = 0;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FDescribeLimitsResult &fromAWS(const Aws::DynamoDB::Model::DescribeLimitsResult &awsDescribeLimitsResult) {
        this->accountMaxReadCapacityUnits = (int64)awsDescribeLimitsResult.GetAccountMaxReadCapacityUnits();

        this->accountMaxWriteCapacityUnits = (int64)awsDescribeLimitsResult.GetAccountMaxWriteCapacityUnits();

        this->tableMaxReadCapacityUnits = (int64)awsDescribeLimitsResult.GetTableMaxReadCapacityUnits();

        this->tableMaxWriteCapacityUnits = (int64)awsDescribeLimitsResult.GetTableMaxWriteCapacityUnits();

        return *this;
    }
#endif
};
