/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeImportRequest.h"

#endif

#include "AWSDynamoDBDescribeImportRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBDescribeImportRequest {
GENERATED_BODY()

    /**
    *  <p> The Amazon Resource Name (ARN) associated with the table you're importing to. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString importArn;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DescribeImportRequest toAWS() const {
        Aws::DynamoDB::Model::DescribeImportRequest awsDescribeImportRequest;

        if (!(this->importArn.IsEmpty())) {
            awsDescribeImportRequest.SetImportArn(TCHAR_TO_UTF8(*this->importArn));
        }

        return awsDescribeImportRequest;
    }

    bool IsEmpty() const {
        return this->importArn.IsEmpty();
    }
#endif
};
