/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeKinesisStreamingDestinationRequest.h"

#endif

#include "AWSDynamoDBDescribeKinesisStreamingDestinationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBDescribeKinesisStreamingDestinationRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the table being described.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DescribeKinesisStreamingDestinationRequest toAWS() const {
        Aws::DynamoDB::Model::DescribeKinesisStreamingDestinationRequest awsDescribeKinesisStreamingDestinationRequest;

		if (!(this->tableName.IsEmpty())) {
            awsDescribeKinesisStreamingDestinationRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

        return awsDescribeKinesisStreamingDestinationRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty();
    }
#endif
};
