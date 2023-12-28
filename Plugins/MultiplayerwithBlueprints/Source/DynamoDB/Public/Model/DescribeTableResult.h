/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeTableResult.h"

#endif

#include "Model/TableDescription.h"

#include "DescribeTableResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeTableResult {
GENERATED_BODY()

    /**
    *  <p>The properties of the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FTableDescription table;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FDescribeTableResult &fromAWS(const Aws::DynamoDB::Model::DescribeTableResult &awsDescribeTableResult) {
        this->table.fromAWS(awsDescribeTableResult.GetTable());

        return *this;
    }
#endif
};
