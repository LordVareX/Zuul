/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ExportSummary.h"

#endif

#include "Model/AWSDynamoDBExportStatus.h"

#include "AWSDynamoDBExportSummary.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBExportSummary {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the export.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString exportArn;

    /**
    *  <p>Export can be in one of the following states: IN_PROGRESS, COMPLETED, or FAILED.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBExportStatus exportStatus = EAWSDynamoDBExportStatus::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBExportSummary &fromAWS(const Aws::DynamoDB::Model::ExportSummary &awsExportSummary) {
        this->exportArn = UTF8_TO_TCHAR(awsExportSummary.GetExportArn().c_str());

        switch(awsExportSummary.GetExportStatus()) {
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

        return *this;
    }
#endif
};
