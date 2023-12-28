/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/EnableKinesisStreamingDestinationRequest.h"

#endif

#include "AWSDynamoDBEnableKinesisStreamingDestinationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBEnableKinesisStreamingDestinationRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the DynamoDB table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>The ARN for a Kinesis data stream.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString streamArn;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::EnableKinesisStreamingDestinationRequest toAWS() const {
        Aws::DynamoDB::Model::EnableKinesisStreamingDestinationRequest awsEnableKinesisStreamingDestinationRequest;

        if (!(this->tableName.IsEmpty())) {
            awsEnableKinesisStreamingDestinationRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

		if (!(this->streamArn.IsEmpty())) {
            awsEnableKinesisStreamingDestinationRequest.SetStreamArn(TCHAR_TO_UTF8(*this->streamArn));
        }

        return awsEnableKinesisStreamingDestinationRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty() && this->streamArn.IsEmpty();
    }
#endif
};
