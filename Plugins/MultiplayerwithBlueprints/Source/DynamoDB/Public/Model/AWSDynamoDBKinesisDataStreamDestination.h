/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/KinesisDataStreamDestination.h"

#endif

#include "Model/AWSDynamoDBDestinationStatus.h"

#include "AWSDynamoDBKinesisDataStreamDestination.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBKinesisDataStreamDestination {
GENERATED_BODY()

    /**
    *  <p>The ARN for a specific Kinesis data stream.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString streamArn;

    /**
    *  <p>The current status of replication.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBDestinationStatus destinationStatus = EAWSDynamoDBDestinationStatus::NOT_SET;

    /**
    *  <p>The human-readable string that corresponds to the replica status.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString destinationStatusDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBKinesisDataStreamDestination &fromAWS(const Aws::DynamoDB::Model::KinesisDataStreamDestination &awsKinesisDataStreamDestination) {
        this->streamArn = UTF8_TO_TCHAR(awsKinesisDataStreamDestination.GetStreamArn().c_str());

        switch(awsKinesisDataStreamDestination.GetDestinationStatus()) {
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

        this->destinationStatusDescription = UTF8_TO_TCHAR(awsKinesisDataStreamDestination.GetDestinationStatusDescription().c_str());

        return *this;
    }
#endif
};
