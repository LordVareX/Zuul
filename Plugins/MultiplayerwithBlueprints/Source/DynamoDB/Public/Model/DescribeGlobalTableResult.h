/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeGlobalTableResult.h"

#endif

#include "Model/GlobalTableDescription.h"

#include "DescribeGlobalTableResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeGlobalTableResult {
GENERATED_BODY()

    /**
    *  <p>Contains the details of the global table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FGlobalTableDescription globalTableDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FDescribeGlobalTableResult &fromAWS(const Aws::DynamoDB::Model::DescribeGlobalTableResult &awsDescribeGlobalTableResult) {
        this->globalTableDescription.fromAWS(awsDescribeGlobalTableResult.GetGlobalTableDescription());

        return *this;
    }
#endif
};
