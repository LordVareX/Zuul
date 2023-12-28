/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DisableKinesisStreamingDestinationRequest.h"

#endif

#include "AWSDynamoDBDisableKinesisStreamingDestinationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBDisableKinesisStreamingDestinationRequest {
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
    Aws::DynamoDB::Model::DisableKinesisStreamingDestinationRequest toAWS() const {
        Aws::DynamoDB::Model::DisableKinesisStreamingDestinationRequest awsDisableKinesisStreamingDestinationRequest;

        if (!(this->tableName.IsEmpty())) {
            awsDisableKinesisStreamingDestinationRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

        if (!(this->streamArn.IsEmpty())) {
            awsDisableKinesisStreamingDestinationRequest.SetStreamArn(TCHAR_TO_UTF8(*this->streamArn));
        }
        return awsDisableKinesisStreamingDestinationRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty() && this->streamArn.IsEmpty();
    }
#endif
};
