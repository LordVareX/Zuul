/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ExportTableToPointInTimeRequest.h"

#endif

#include "Model/AWSDynamoDBS3SseAlgorithm.h"
#include "Model/AWSDynamoDBExportFormat.h"

#include "AWSDynamoDBExportTableToPointInTimeRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBExportTableToPointInTimeRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) associated with the table to export.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableArn;

    /**
    *  <p>Time in the past from which to export table data. The table export will be a snapshot of the table's state at this point in time.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime exportTime;

    /**
    *  <p>Providing a <code>ClientToken</code> makes the call to <code>ExportTableToPointInTimeInput</code> idempotent, meaning that multiple identical calls have the same effect as one single call.</p> <p>A client token is valid for 8 hours after the first request that uses it is completed. After 8 hours, any request with the same client token is treated as a new request. Do not resubmit the same request with the same client token for more than 8 hours, or the result might not be idempotent.</p> <p>If you submit a request with the same client token but a change in other parameters within the 8-hour idempotency window, DynamoDB returns an <code>IdempotentParameterMismatch</code> exception.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString clientToken;

    /**
    *  <p>The name of the Amazon S3 bucket to export the snapshot to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString s3Bucket;

    /**
    *  <p>The ID of the AWS account that owns the bucket the export will be stored in.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString s3BucketOwner;

    /**
    *  <p>The Amazon S3 bucket prefix to use as the file name and path of the exported snapshot.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString s3Prefix;

    /**
    *  <p>Type of encryption used on the bucket where export data will be stored. Valid values for <code>S3SseAlgorithm</code> are:</p> <ul> <li> <p> <code>AES256</code> - server-side encryption with Amazon S3 managed keys</p> </li> <li> <p> <code>KMS</code> - server-side encryption with AWS KMS managed keys</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBS3SseAlgorithm s3SseAlgorithm = EAWSDynamoDBS3SseAlgorithm::NOT_SET;

    /**
    *  <p>The ID of the AWS KMS managed key used to encrypt the S3 bucket where export data will be stored (if applicable).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString s3SseKmsKeyId;

    /**
    *  <p>The format for the exported data. Valid values for <code>ExportFormat</code> are <code>DYNAMODB_JSON</code> or <code>ION</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBExportFormat exportFormat = EAWSDynamoDBExportFormat::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ExportTableToPointInTimeRequest toAWS() const {
        Aws::DynamoDB::Model::ExportTableToPointInTimeRequest awsExportTableToPointInTimeRequest;

		if (!(this->tableArn.IsEmpty())) {
            awsExportTableToPointInTimeRequest.SetTableArn(TCHAR_TO_UTF8(*this->tableArn));
        }

        if (!(this->exportTime.ToUnixTimestamp() <= 0)) {
            awsExportTableToPointInTimeRequest.SetExportTime(Aws::Utils::DateTime((int64_t)((this->exportTime - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        if (!(this->clientToken.IsEmpty())) {
            awsExportTableToPointInTimeRequest.SetClientToken(TCHAR_TO_UTF8(*this->clientToken));
        }

		if (!(this->s3Bucket.IsEmpty())) {
            awsExportTableToPointInTimeRequest.SetS3Bucket(TCHAR_TO_UTF8(*this->s3Bucket));
        }

		if (!(this->s3BucketOwner.IsEmpty())) {
            awsExportTableToPointInTimeRequest.SetS3BucketOwner(TCHAR_TO_UTF8(*this->s3BucketOwner));
        }

		if (!(this->s3Prefix.IsEmpty())) {
            awsExportTableToPointInTimeRequest.SetS3Prefix(TCHAR_TO_UTF8(*this->s3Prefix));
        }

		switch(this->s3SseAlgorithm) {
            case EAWSDynamoDBS3SseAlgorithm::AES256:
                awsExportTableToPointInTimeRequest.SetS3SseAlgorithm(Aws::DynamoDB::Model::S3SseAlgorithm::AES256);
                break;
            case EAWSDynamoDBS3SseAlgorithm::KMS:
                awsExportTableToPointInTimeRequest.SetS3SseAlgorithm(Aws::DynamoDB::Model::S3SseAlgorithm::KMS);
                break;
            default:
                break;
		}

		if (!(this->s3SseKmsKeyId.IsEmpty())) {
            awsExportTableToPointInTimeRequest.SetS3SseKmsKeyId(TCHAR_TO_UTF8(*this->s3SseKmsKeyId));
        }

		switch(this->exportFormat) {
            case EAWSDynamoDBExportFormat::DYNAMODB_JSON:
                awsExportTableToPointInTimeRequest.SetExportFormat(Aws::DynamoDB::Model::ExportFormat::DYNAMODB_JSON);
                break;
            case EAWSDynamoDBExportFormat::ION:
                awsExportTableToPointInTimeRequest.SetExportFormat(Aws::DynamoDB::Model::ExportFormat::ION);
                break;
            default:
                break;
		}

		return awsExportTableToPointInTimeRequest;
    }

    bool IsEmpty() const {
        return this->tableArn.IsEmpty() && exportTime.ToUnixTimestamp() <= 0 && this->clientToken.IsEmpty() && this->s3Bucket.IsEmpty() && this->s3BucketOwner.IsEmpty() && this->s3Prefix.IsEmpty() && s3SseAlgorithm == EAWSDynamoDBS3SseAlgorithm::NOT_SET && this->s3SseKmsKeyId.IsEmpty() && exportFormat == EAWSDynamoDBExportFormat::NOT_SET;
    }
#endif
};
