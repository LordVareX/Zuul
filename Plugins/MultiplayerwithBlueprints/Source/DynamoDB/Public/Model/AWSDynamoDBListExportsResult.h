/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ListExportsResult.h"

#endif

#include "Model/AWSDynamoDBExportSummary.h"

#include "AWSDynamoDBListExportsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBListExportsResult {
GENERATED_BODY()

    /**
    *  <p>A list of <code>ExportSummary</code> objects.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FAWSDynamoDBExportSummary> exportSummaries;

    /**
    *  <p>If this value is returned, there are additional results to be displayed. To retrieve them, call <code>ListExports</code> again, with <code>NextToken</code> set to this value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString nextToken;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBListExportsResult &fromAWS(const Aws::DynamoDB::Model::ListExportsResult &awsListExportsResult) {
        this->exportSummaries.Empty();
        for (const Aws::DynamoDB::Model::ExportSummary& elem : awsListExportsResult.GetExportSummaries()) {
            this->exportSummaries.Add(FAWSDynamoDBExportSummary().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListExportsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
