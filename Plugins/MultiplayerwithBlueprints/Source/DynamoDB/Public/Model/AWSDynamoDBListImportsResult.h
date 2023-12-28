/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ListImportsResult.h"

#endif

#include "Model/AWSDynamoDBImportSummary.h"

#include "AWSDynamoDBListImportsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBListImportsResult {
GENERATED_BODY()

    /**
    *  <p> A list of <code>ImportSummary</code> objects. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FAWSDynamoDBImportSummary> importSummaryList;

    /**
    *  <p> If this value is returned, there are additional results to be displayed. To retrieve them, call <code>ListImports</code> again, with <code>NextToken</code> set to this value. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString nextToken;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBListImportsResult &fromAWS(const Aws::DynamoDB::Model::ListImportsResult &awsListImportsResult) {
        this->importSummaryList.Empty();
        for (const Aws::DynamoDB::Model::ImportSummary& elem : awsListImportsResult.GetImportSummaryList()) {
            this->importSummaryList.Add(FAWSDynamoDBImportSummary().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListImportsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
