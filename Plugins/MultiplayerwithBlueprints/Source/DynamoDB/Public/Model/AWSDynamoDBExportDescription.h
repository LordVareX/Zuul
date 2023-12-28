/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ExportDescription.h"

#endif

#include "Model/AWSDynamoDBExportStatus.h"
#include "Model/AWSDynamoDBS3SseAlgorithm.h"
#include "Model/AWSDynamoDBExportFormat.h"

#include "AWSDynamoDBExportDescription.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBExportDescription {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the table export.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString exportArn;

    /**
    *  <p>Export can be in one of the following states: IN_PROGRESS, COMPLETED, or FAILED.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBExportStatus exportStatus = EAWSDynamoDBExportStatus::NOT_SET;

    /**
    *  <p>The time at which the export task began.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime startTime;

    /**
    *  <p>The time at which the export task completed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime endTime;

    /**
    *  <p>The name of the manifest file for the export task.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString exportManifest;

    /**
    *  <p>The Amazon Resource Name (ARN) of the table that was exported.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableArn;

    /**
    *  <p>Unique ID of the table that was exported.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableId;

    /**
    *  <p>Point in time from which table data was exported.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime exportTime;

    /**
    *  <p>The client token that was provided for the export task. A client token makes calls to <code>ExportTableToPointInTimeInput</code> idempotent, meaning that multiple identical calls have the same effect as one single call.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString clientToken;

    /**
    *  <p>The name of the Amazon S3 bucket containing the export.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString s3Bucket;

    /**
    *  <p>The ID of the AWS account that owns the bucket containing the export.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString s3BucketOwner;

    /**
    *  <p>The Amazon S3 bucket prefix used as the file name and path of the exported snapshot.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString s3Prefix;

    /**
    *  <p>Type of encryption used on the bucket where export data is stored. Valid values for <code>S3SseAlgorithm</code> are:</p> <ul> <li> <p> <code>AES256</code> - server-side encryption with Amazon S3 managed keys</p> </li> <li> <p> <code>KMS</code> - server-side encryption with AWS KMS managed keys</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBS3SseAlgorithm s3SseAlgorithm = EAWSDynamoDBS3SseAlgorithm::NOT_SET;

    /**
    *  <p>The ID of the AWS KMS managed key used to encrypt the S3 bucket where export data is stored (if applicable).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString s3SseKmsKeyId;

    /**
    *  <p>Status code for the result of the failed export.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString failureCode;

    /**
    *  <p>Export failure reason description.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString failureMessage;

    /**
    *  <p>The format of the exported data. Valid values for <code>ExportFormat</code> are <code>DYNAMODB_JSON</code> or <code>ION</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBExportFormat exportFormat = EAWSDynamoDBExportFormat::NOT_SET;

    /**
    *  <p>The billable size of the table export.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 billedSizeBytes = 0;

    /**
    *  <p>The number of items exported.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 itemCount = 0;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBExportDescription &fromAWS(const Aws::DynamoDB::Model::ExportDescription &awsExportDescription) {
        this->exportArn = UTF8_TO_TCHAR(awsExportDescription.GetExportArn().c_str());

        switch(awsExportDescription.GetExportStatus()) {
            case Aws::DynamoDB::Model::ExportStatus::NOT_SET:
                this->exportStatus = EAWSDynamoDBExportStatus::NOT_SET;
                break;
            case Aws::DynamoDB::Model::ExportStatus::IN_PROGRESS:
                this->exportStatus = EAWSDynamoDBExportStatus::IN_PROGRESS;
                break;
            case Aws::DynamoDB::Model::ExportStatus::COMPLETED:
                this->exportStatus = EAWSDynamoDBExportStatus::COMPLETED;
                break;
            case Aws::DynamoDB::Model::ExportStatus::FAILED:
                this->exportStatus = EAWSDynamoDBExportStatus::FAILED;
                break;
            default:
                this->exportStatus = EAWSDynamoDBExportStatus::NOT_SET;
                break;
        }

        this->startTime = FDateTime(1970, 1, 1) + FTimespan(awsExportDescription.GetStartTime().Millis() * ETimespan::TicksPerMillisecond);

        this->endTime = FDateTime(1970, 1, 1) + FTimespan(awsExportDescription.GetEndTime().Millis() * ETimespan::TicksPerMillisecond);

        this->exportManifest = UTF8_TO_TCHAR(awsExportDescription.GetExportManifest().c_str());

        this->tableArn = UTF8_TO_TCHAR(awsExportDescription.GetTableArn().c_str());

        this->tableId = UTF8_TO_TCHAR(awsExportDescription.GetTableId().c_str());

        this->exportTime = FDateTime(1970, 1, 1) + FTimespan(awsExportDescription.GetExportTime().Millis() * ETimespan::TicksPerMillisecond);

        this->clientToken = UTF8_TO_TCHAR(awsExportDescription.GetClientToken().c_str());

        this->s3Bucket = UTF8_TO_TCHAR(awsExportDescription.GetS3Bucket().c_str());

        this->s3BucketOwner = UTF8_TO_TCHAR(awsExportDescription.GetS3BucketOwner().c_str());

        this->s3Prefix = UTF8_TO_TCHAR(awsExportDescription.GetS3Prefix().c_str());

        switch(awsExportDescription.GetS3SseAlgorithm()) {
            case Aws::DynamoDB::Model::S3SseAlgorithm::NOT_SET:
                this->s3SseAlgorithm = EAWSDynamoDBS3SseAlgorithm::NOT_SET;
                break;
            case Aws::DynamoDB::Model::S3SseAlgorithm::AES256:
                this->s3SseAlgorithm = EAWSDynamoDBS3SseAlgorithm::AES256;
                break;
            case Aws::DynamoDB::Model::S3SseAlgorithm::KMS:
                this->s3SseAlgorithm = EAWSDynamoDBS3SseAlgorithm::KMS;
                break;
            default:
                this->s3SseAlgorithm = EAWSDynamoDBS3SseAlgorithm::NOT_SET;
                break;
        }

        this->s3SseKmsKeyId = UTF8_TO_TCHAR(awsExportDescription.GetS3SseKmsKeyId().c_str());

        this->failureCode = UTF8_TO_TCHAR(awsExportDescription.GetFailureCode().c_str());

        this->failureMessage = UTF8_TO_TCHAR(awsExportDescription.GetFailureMessage().c_str());

        switch(awsExportDescription.GetExportFormat()) {
            case Aws::DynamoDB::Model::ExportFormat::NOT_SET:
                this->exportFormat = EAWSDynamoDBExportFormat::NOT_SET;
                break;
            case Aws::DynamoDB::Model::ExportFormat::DYNAMODB_JSON:
                this->exportFormat = EAWSDynamoDBExportFormat::DYNAMODB_JSON;
                break;
            case Aws::DynamoDB::Model::ExportFormat::ION:
                this->exportFormat = EAWSDynamoDBExportFormat::ION;
                break;
            default:
                this->exportFormat = EAWSDynamoDBExportFormat::NOT_SET;
                break;
        }

        this->billedSizeBytes = (int64)awsExportDescription.GetBilledSizeBytes();

        this->itemCount = (int64)awsExportDescription.GetItemCount();

        return *this;
    }
#endif
};
