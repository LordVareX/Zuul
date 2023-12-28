/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ImportTableDescription.h"

#endif

#include "Model/AWSDynamoDBImportStatus.h"
#include "Model/AWSDynamoDBS3BucketSource.h"
#include "Model/AWSDynamoDBInputFormat.h"
#include "Model/AWSDynamoDBInputFormatOptions.h"
#include "Model/AWSDynamoDBInputCompressionType.h"
#include "Model/AWSDynamoDBTableCreationParameters.h"

#include "AWSDynamoDBImportTableDescription.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBImportTableDescription {
GENERATED_BODY()

    /**
    *  <p> The Amazon Resource Number (ARN) corresponding to the import request. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString importArn;

    /**
    *  <p> The status of the import. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBImportStatus importStatus = EAWSDynamoDBImportStatus::NOT_SET;

    /**
    *  <p> The Amazon Resource Number (ARN) of the table being imported into. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableArn;

    /**
    *  <p> The table id corresponding to the table created by import table process. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableId;

    /**
    *  <p> The client token that was provided for the import task. Reusing the client token on retry makes a call to <code>ImportTable</code> idempotent. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString clientToken;

    /**
    *  <p> Values for the S3 bucket the source file is imported from. Includes bucket name (required), key prefix (optional) and bucket account owner ID (optional). </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAWSDynamoDBS3BucketSource s3BucketSource;

    /**
    *  <p> The number of errors occurred on importing the source file into the target table. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 errorCount = 0;

    /**
    *  <p> The Amazon Resource Number (ARN) of the Cloudwatch Log Group associated with the target table. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString cloudWatchLogGroupArn;

    /**
    *  <p> The format of the source data going into the target table. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBInputFormat inputFormat = EAWSDynamoDBInputFormat::NOT_SET;

    /**
    *  <p> The format options for the data that was imported into the target table. There is one value, CsvOption. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAWSDynamoDBInputFormatOptions inputFormatOptions;

    /**
    *  <p> The compression options for the data that has been imported into the target table. The values are NONE, GZIP, or ZSTD. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBInputCompressionType inputCompressionType = EAWSDynamoDBInputCompressionType::NOT_SET;

    /**
    *  <p> The parameters for the new table that is being imported into. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAWSDynamoDBTableCreationParameters tableCreationParameters;

    /**
    *  <p> The time when this import task started. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime startTime;

    /**
    *  <p> The time at which the creation of the table associated with this import task completed. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime endTime;

    /**
    *  <p> The total size of data processed from the source file, in Bytes. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 processedSizeBytes = 0;

    /**
    *  <p> The total number of items processed from the source file. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 processedItemCount = 0;

    /**
    *  <p> The number of items successfully imported into the new table. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 importedItemCount = 0;

    /**
    *  <p> The error code corresponding to the failure that the import job ran into during execution. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString failureCode;

    /**
    *  <p> The error message corresponding to the failure that the import job ran into during execution. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString failureMessage;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBImportTableDescription &fromAWS(const Aws::DynamoDB::Model::ImportTableDescription &awsImportTableDescription) {
        this->importArn = UTF8_TO_TCHAR(awsImportTableDescription.GetImportArn().c_str());

        switch(awsImportTableDescription.GetImportStatus()) {
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

        this->tableArn = UTF8_TO_TCHAR(awsImportTableDescription.GetTableArn().c_str());

        this->tableId = UTF8_TO_TCHAR(awsImportTableDescription.GetTableId().c_str());

        this->clientToken = UTF8_TO_TCHAR(awsImportTableDescription.GetClientToken().c_str());

        this->s3BucketSource.fromAWS(awsImportTableDescription.GetS3BucketSource());

        this->errorCount = (int64)awsImportTableDescription.GetErrorCount();

        this->cloudWatchLogGroupArn = UTF8_TO_TCHAR(awsImportTableDescription.GetCloudWatchLogGroupArn().c_str());

        switch(awsImportTableDescription.GetInputFormat()) {
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

        this->inputFormatOptions.fromAWS(awsImportTableDescription.GetInputFormatOptions());

        switch(awsImportTableDescription.GetInputCompressionType()) {
            case Aws::DynamoDB::Model::InputCompressionType::NOT_SET:
                this->inputCompressionType = EAWSDynamoDBInputCompressionType::NOT_SET;
                break;
            case Aws::DynamoDB::Model::InputCompressionType::GZIP:
                this->inputCompressionType = EAWSDynamoDBInputCompressionType::GZIP;
                break;
            case Aws::DynamoDB::Model::InputCompressionType::ZSTD:
                this->inputCompressionType = EAWSDynamoDBInputCompressionType::ZSTD;
                break;
            case Aws::DynamoDB::Model::InputCompressionType::NONE:
                this->inputCompressionType = EAWSDynamoDBInputCompressionType::NONE;
                break;
            default:
                this->inputCompressionType = EAWSDynamoDBInputCompressionType::NOT_SET;
                break;
        }

        this->tableCreationParameters.fromAWS(awsImportTableDescription.GetTableCreationParameters());

        this->startTime = FDateTime(1970, 1, 1) + FTimespan(awsImportTableDescription.GetStartTime().Millis() * ETimespan::TicksPerMillisecond);

        this->endTime = FDateTime(1970, 1, 1) + FTimespan(awsImportTableDescription.GetEndTime().Millis() * ETimespan::TicksPerMillisecond);

        this->processedSizeBytes = (int64)awsImportTableDescription.GetProcessedSizeBytes();

        this->processedItemCount = (int64)awsImportTableDescription.GetProcessedItemCount();

        this->importedItemCount = (int64)awsImportTableDescription.GetImportedItemCount();

        this->failureCode = UTF8_TO_TCHAR(awsImportTableDescription.GetFailureCode().c_str());

        this->failureMessage = UTF8_TO_TCHAR(awsImportTableDescription.GetFailureMessage().c_str());

        return *this;
    }
#endif
};
