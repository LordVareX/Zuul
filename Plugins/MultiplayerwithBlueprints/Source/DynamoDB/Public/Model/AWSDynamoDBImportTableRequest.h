/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ImportTableRequest.h"

#endif

#include "Model/AWSDynamoDBS3BucketSource.h"
#include "Model/AWSDynamoDBInputFormat.h"
#include "Model/AWSDynamoDBInputFormatOptions.h"
#include "Model/AWSDynamoDBInputCompressionType.h"
#include "Model/AWSDynamoDBTableCreationParameters.h"

#include "AWSDynamoDBImportTableRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBImportTableRequest {
GENERATED_BODY()

    /**
    *  <p>Providing a <code>ClientToken</code> makes the call to <code>ImportTableInput</code> idempotent, meaning that multiple identical calls have the same effect as one single call.</p> <p>A client token is valid for 8 hours after the first request that uses it is completed. After 8 hours, any request with the same client token is treated as a new request. Do not resubmit the same request with the same client token for more than 8 hours, or the result might not be idempotent.</p> <p>If you submit a request with the same client token but a change in other parameters within the 8-hour idempotency window, DynamoDB returns an <code>IdempotentParameterMismatch</code> exception.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString clientToken;

    /**
    *  <p> The S3 bucket that provides the source for the import. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAWSDynamoDBS3BucketSource s3BucketSource;

    /**
    *  <p> The format of the source data. Valid values for <code>ImportFormat</code> are <code>CSV</code>, <code>DYNAMODB_JSON</code> or <code>ION</code>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBInputFormat inputFormat = EAWSDynamoDBInputFormat::NOT_SET;

    /**
    *  <p> Additional properties that specify how the input is formatted, </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAWSDynamoDBInputFormatOptions inputFormatOptions;

    /**
    *  <p> Type of compression to be used on the input coming from the imported table. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBInputCompressionType inputCompressionType = EAWSDynamoDBInputCompressionType::NOT_SET;

    /**
    *  <p>Parameters for the table to import the data into. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAWSDynamoDBTableCreationParameters tableCreationParameters;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ImportTableRequest toAWS() const {
        Aws::DynamoDB::Model::ImportTableRequest awsImportTableRequest;

        if (!(this->clientToken.IsEmpty())) {
            awsImportTableRequest.SetClientToken(TCHAR_TO_UTF8(*this->clientToken));
        }

        if (!(this->s3BucketSource.IsEmpty())) {
            awsImportTableRequest.SetS3BucketSource(this->s3BucketSource.toAWS());
        }

        switch(this->inputFormat) {
            case EAWSDynamoDBInputFormat::DYNAMODB_JSON:
                awsImportTableRequest.SetInputFormat(Aws::DynamoDB::Model::InputFormat::DYNAMODB_JSON);
                break;
            case EAWSDynamoDBInputFormat::ION:
                awsImportTableRequest.SetInputFormat(Aws::DynamoDB::Model::InputFormat::ION);
                break;
            case EAWSDynamoDBInputFormat::CSV:
                awsImportTableRequest.SetInputFormat(Aws::DynamoDB::Model::InputFormat::CSV);
                break;
            default:
                break;
        }

        if (!(this->inputFormatOptions.IsEmpty())) {
            awsImportTableRequest.SetInputFormatOptions(this->inputFormatOptions.toAWS());
        }

        switch(this->inputCompressionType) {
            case EAWSDynamoDBInputCompressionType::GZIP:
                awsImportTableRequest.SetInputCompressionType(Aws::DynamoDB::Model::InputCompressionType::GZIP);
                break;
            case EAWSDynamoDBInputCompressionType::ZSTD:
                awsImportTableRequest.SetInputCompressionType(Aws::DynamoDB::Model::InputCompressionType::ZSTD);
                break;
            case EAWSDynamoDBInputCompressionType::NONE:
                awsImportTableRequest.SetInputCompressionType(Aws::DynamoDB::Model::InputCompressionType::NONE);
                break;
            default:
                break;
        }

        if (!(this->tableCreationParameters.IsEmpty())) {
            awsImportTableRequest.SetTableCreationParameters(this->tableCreationParameters.toAWS());
        }

        return awsImportTableRequest;
    }

    bool IsEmpty() const {
        return this->clientToken.IsEmpty() && this->s3BucketSource.IsEmpty() && this->inputFormat == EAWSDynamoDBInputFormat::NOT_SET && this->inputFormatOptions.IsEmpty() && this->inputCompressionType == EAWSDynamoDBInputCompressionType::NOT_SET && this->tableCreationParameters.IsEmpty();
    }
#endif
};
