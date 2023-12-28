/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeExportResult.h"

#endif

#include "Model/AWSDynamoDBExportDescription.h"

#include "AWSDynamoDBDescribeExportResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBDescribeExportResult {
GENERATED_BODY()

    /**
    *  <p>Represents the properties of the export.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAWSDynamoDBExportDescription exportDescription;
    
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBDescribeExportResult &fromAWS(const Aws::DynamoDB::Model::DescribeExportResult &awsDescribeExportResult) {
        this->exportDescription.fromAWS(awsDescribeExportResult.GetExportDescription());

        return *this;
    }
#endif
};
