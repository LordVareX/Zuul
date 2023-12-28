/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeExportRequest.h"

#endif

#include "AWSDynamoDBDescribeExportRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBDescribeExportRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) associated with the export.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString exportArn;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DescribeExportRequest toAWS() const {
        Aws::DynamoDB::Model::DescribeExportRequest awsDescribeExportRequest;

		if (!(this->exportArn.IsEmpty())) {
            awsDescribeExportRequest.SetExportArn(TCHAR_TO_UTF8(*this->exportArn));
        }

        return awsDescribeExportRequest;
    }

    bool IsEmpty() const {
        return this->exportArn.IsEmpty();
    }
#endif
};
