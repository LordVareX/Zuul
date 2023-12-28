/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeKinesisStreamingDestinationResult.h"

#endif

#include "Model/AWSDynamoDBKinesisDataStreamDestination.h"

#include "AWSDynamoDBDescribeKinesisStreamingDestinationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBDescribeKinesisStreamingDestinationResult {
GENERATED_BODY()

    /**
    *  <p>The name of the table being described.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>The list of replica structures for the table being described.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FAWSDynamoDBKinesisDataStreamDestination> kinesisDataStreamDestinations;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBDescribeKinesisStreamingDestinationResult &fromAWS(const Aws::DynamoDB::Model::DescribeKinesisStreamingDestinationResult &awsDescribeKinesisStreamingDestinationResult) {
        this->tableName = UTF8_TO_TCHAR(awsDescribeKinesisStreamingDestinationResult.GetTableName().c_str());

        this->kinesisDataStreamDestinations.Empty();
        for (const Aws::DynamoDB::Model::KinesisDataStreamDestination& elem : awsDescribeKinesisStreamingDestinationResult.GetKinesisDataStreamDestinations()) {
            this->kinesisDataStreamDestinations.Add(FAWSDynamoDBKinesisDataStreamDestination().fromAWS(elem));
        }

        return *this;
    }
#endif
};
