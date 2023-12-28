/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DisableKinesisStreamingDestinationResult.h"

#endif

#include "Model/AWSDynamoDBDestinationStatus.h"

#include "AWSDynamoDBDisableKinesisStreamingDestinationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBDisableKinesisStreamingDestinationResult {
GENERATED_BODY()

    /**
    *  <p>The name of the table being modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>The ARN for the specific Kinesis data stream.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString streamArn;

    /**
    *  <p>The current status of the replication.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBDestinationStatus destinationStatus = EAWSDynamoDBDestinationStatus::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBDisableKinesisStreamingDestinationResult &fromAWS(const Aws::DynamoDB::Model::DisableKinesisStreamingDestinationResult &awsDisableKinesisStreamingDestinationResult) {
        this->tableName = UTF8_TO_TCHAR(awsDisableKinesisStreamingDestinationResult.GetTableName().c_str());

        this->streamArn = UTF8_TO_TCHAR(awsDisableKinesisStreamingDestinationResult.GetStreamArn().c_str());

        switch(awsDisableKinesisStreamingDestinationResult.GetDestinationStatus()) {
            case Aws::DynamoDB::Model::DestinationStatus::NOT_SET:
                this->destinationStatus = EAWSDynamoDBDestinationStatus::NOT_SET;
                break;
            case Aws::DynamoDB::Model::DestinationStatus::ENABLING:
                this->destinationStatus = EAWSDynamoDBDestinationStatus::ENABLING;
                break;
            case Aws::DynamoDB::Model::DestinationStatus::ACTIVE:
                this->destinationStatus = EAWSDynamoDBDestinationStatus::ACTIVE;
                break;
            case Aws::DynamoDB::Model::DestinationStatus::DISABLING:
                this->destinationStatus = EAWSDynamoDBDestinationStatus::DISABLING;
                break;
            case Aws::DynamoDB::Model::DestinationStatus::DISABLED:
                this->destinationStatus = EAWSDynamoDBDestinationStatus::DISABLED;
                break;
            case Aws::DynamoDB::Model::DestinationStatus::ENABLE_FAILED:
                this->destinationStatus = EAWSDynamoDBDestinationStatus::ENABLE_FAILED;
                break;
            default:
                this->destinationStatus = EAWSDynamoDBDestinationStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
