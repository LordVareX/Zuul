/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ImportSummary.h"

#endif

#include "Model/AWSDynamoDBImportStatus.h"
#include "Model/AWSDynamoDBS3BucketSource.h"
#include "Model/AWSDynamoDBInputFormat.h"

#include "AWSDynamoDBImportSummary.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBImportSummary {
GENERATED_BODY()

    /**
    *  <p> The Amazon Resource Number (ARN) corresponding to the import request. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString importArn;

    /**
    *  <p> The status of the import operation. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBImportStatus importStatus = EAWSDynamoDBImportStatus::NOT_SET;

    /**
    *  <p> The Amazon Resource Number (ARN) of the table being imported into. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableArn;

    /**
    *  <p> The path and S3 bucket of the source file that is being imported. This includes the S3Bucket (required), S3KeyPrefix (optional) and S3BucketOwner (optional if the bucket is owned by the requester). </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAWSDynamoDBS3BucketSource s3BucketSource;

    /**
    *  <p> The Amazon Resource Number (ARN) of the Cloudwatch Log Group associated with this import task. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString cloudWatchLogGroupArn;

    /**
    *  <p> The format of the source data. Valid values are <code>CSV</code>, <code>DYNAMODB_JSON</code> or <code>ION</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBInputFormat inputFormat = EAWSDynamoDBInputFormat::NOT_SET;

    /**
    *  <p> The time at which this import task began. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime startTime;

    /**
    *  <p> The time at which this import task ended. (Does this include the successful complete creation of the table it was imported to?) </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime endTime;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBImportSummary &fromAWS(const Aws::DynamoDB::Model::ImportSummary &awsImportSummary) {
        this->importArn = UTF8_TO_TCHAR(awsImportSummary.GetImportArn().c_str());

        switch(awsImportSummary.GetImportStatus()) {
            case Aws::DynamoDB::Model::ImportStatus::NOT_SET:
                this->importStatus = EAWSDynamoDBImportStatus::NOT_SET;
                break;
            case Aws::DynamoDB::Model::ImportStatus::IN_PROGRESS:
                this->importStatus = EAWSDynamoDBImportStatus::IN_PROGRESS;
                break;
            case Aws::DynamoDB::Model::ImportStatus::COMPLETED:
                this->importStatus = EAWSDynamoDBImportStatus::COMPLETED;
                break;
            case Aws::DynamoDB::Model::ImportStatus::CANCELLING:
                this->importStatus = EAWSDynamoDBImportStatus::CANCELLING;
                break;
            case Aws::DynamoDB::Model::ImportStatus::CANCELLED:
                this->importStatus = EAWSDynamoDBImportStatus::CANCELLED;
                break;
            case Aws::DynamoDB::Model::ImportStatus::FAILED:
                this->importStatus = EAWSDynamoDBImportStatus::FAILED;
                break;
            default:
                this->importStatus = EAWSDynamoDBImportStatus::NOT_SET;
                break;
        }

        this->tableArn = UTF8_TO_TCHAR(awsImportSummary.GetTableArn().c_str());

        this->s3BucketSource.fromAWS(awsImportSummary.GetS3BucketSource());

        this->cloudWatchLogGroupArn = UTF8_TO_TCHAR(awsImportSummary.GetCloudWatchLogGroupArn().c_str());

        switch(awsImportSummary.GetInputFormat()) {
            case Aws::DynamoDB::Model::InputFormat::NOT_SET:
                this->inputFormat = EAWSDynamoDBInputFormat::NOT_SET;
                break;
            case Aws::DynamoDB::Model::InputFormat::DYNAMODB_JSON:
                this->inputFormat = EAWSDynamoDBInputFormat::DYNAMODB_JSON;
                break;
            case Aws::DynamoDB::Model::InputFormat::ION:
                this->inputFormat = EAWSDynamoDBInputFormat::ION;
                break;
            case Aws::DynamoDB::Model::InputFormat::CSV:
                this->inputFormat = EAWSDynamoDBInputFormat::CSV;
                break;
            default:
                this->inputFormat = EAWSDynamoDBInputFormat::NOT_SET;
                break;
        }

        this->startTime = FDateTime(1970, 1, 1) + FTimespan(awsImportSummary.GetStartTime().Millis() * ETimespan::TicksPerMillisecond);

        this->endTime = FDateTime(1970, 1, 1) + FTimespan(awsImportSummary.GetEndTime().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
