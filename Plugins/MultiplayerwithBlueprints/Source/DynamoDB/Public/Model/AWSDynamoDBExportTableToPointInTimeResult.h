/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ExportTableToPointInTimeResult.h"

#endif

#include "Model/AWSDynamoDBExportDescription.h"

#include "AWSDynamoDBExportTableToPointInTimeResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBExportTableToPointInTimeResult {
GENERATED_BODY()

    /**
    *  <p>Contains a description of the table export.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAWSDynamoDBExportDescription exportDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBExportTableToPointInTimeResult &fromAWS(const Aws::DynamoDB::Model::ExportTableToPointInTimeResult &awsExportTableToPointInTimeResult) {
        this->exportDescription.fromAWS(awsExportTableToPointInTimeResult.GetExportDescription());

        return *this;
    }
#endif
};
