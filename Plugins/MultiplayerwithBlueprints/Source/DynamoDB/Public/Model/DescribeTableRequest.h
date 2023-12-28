/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeTableRequest.h"

#endif

#include "DescribeTableRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeTableRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the table to describe.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DescribeTableRequest toAWS() const {
        Aws::DynamoDB::Model::DescribeTableRequest awsDescribeTableRequest;

		if (!(this->tableName.IsEmpty())) {
            awsDescribeTableRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

        return awsDescribeTableRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty();
    }
#endif
};
