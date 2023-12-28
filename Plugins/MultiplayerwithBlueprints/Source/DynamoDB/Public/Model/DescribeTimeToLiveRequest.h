/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeTimeToLiveRequest.h"

#endif

#include "DescribeTimeToLiveRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeTimeToLiveRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the table to be described.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DescribeTimeToLiveRequest toAWS() const {
        Aws::DynamoDB::Model::DescribeTimeToLiveRequest awsDescribeTimeToLiveRequest;

		if (!(this->tableName.IsEmpty())) {
            awsDescribeTimeToLiveRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

        return awsDescribeTimeToLiveRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty();
    }
#endif
};
