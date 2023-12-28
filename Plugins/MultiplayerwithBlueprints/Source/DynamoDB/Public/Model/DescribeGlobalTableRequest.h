/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeGlobalTableRequest.h"

#endif

#include "DescribeGlobalTableRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeGlobalTableRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the global table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString globalTableName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DescribeGlobalTableRequest toAWS() const {
        Aws::DynamoDB::Model::DescribeGlobalTableRequest awsDescribeGlobalTableRequest;

		if (!(this->globalTableName.IsEmpty())) {
            awsDescribeGlobalTableRequest.SetGlobalTableName(TCHAR_TO_UTF8(*this->globalTableName));
        }

        return awsDescribeGlobalTableRequest;
    }

    bool IsEmpty() const {
        return this->globalTableName.IsEmpty();
    }
#endif
};
