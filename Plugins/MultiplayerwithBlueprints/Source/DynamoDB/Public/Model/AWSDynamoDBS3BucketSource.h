/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/S3BucketSource.h"

#endif

#include "AWSDynamoDBS3BucketSource.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBS3BucketSource {
GENERATED_BODY()

    /**
    *  <p> The account number of the S3 bucket that is being imported from. If the bucket is owned by the requester this is optional. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString s3BucketOwner;

    /**
    *  <p> The S3 bucket that is being imported from. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString s3Bucket;

    /**
    *  <p> The key prefix shared by all S3 Objects that are being imported. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString s3KeyPrefix;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::S3BucketSource toAWS() const {
        Aws::DynamoDB::Model::S3BucketSource awsS3BucketSource;

        if (!(this->s3BucketOwner.IsEmpty())) {
            awsS3BucketSource.SetS3BucketOwner(TCHAR_TO_UTF8(*this->s3BucketOwner));
        }

        if (!(this->s3Bucket.IsEmpty())) {
            awsS3BucketSource.SetS3Bucket(TCHAR_TO_UTF8(*this->s3Bucket));
        }

        if (!(this->s3KeyPrefix.IsEmpty())) {
            awsS3BucketSource.SetS3KeyPrefix(TCHAR_TO_UTF8(*this->s3KeyPrefix));
        }

        return awsS3BucketSource;
    }

    bool IsEmpty() const {
        return this->s3BucketOwner.IsEmpty() && this->s3Bucket.IsEmpty() && this->s3KeyPrefix.IsEmpty();
    }

    FAWSDynamoDBS3BucketSource &fromAWS(const Aws::DynamoDB::Model::S3BucketSource &awsS3BucketSource) {
        this->s3BucketOwner = UTF8_TO_TCHAR(awsS3BucketSource.GetS3BucketOwner().c_str());

        this->s3Bucket = UTF8_TO_TCHAR(awsS3BucketSource.GetS3Bucket().c_str());

        this->s3KeyPrefix = UTF8_TO_TCHAR(awsS3BucketSource.GetS3KeyPrefix().c_str());

        return *this;
    }
#endif
};
