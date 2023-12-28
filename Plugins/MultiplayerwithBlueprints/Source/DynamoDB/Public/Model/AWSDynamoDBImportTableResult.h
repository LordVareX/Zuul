/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ImportTableResult.h"

#endif

#include "Model/AWSDynamoDBImportTableDescription.h"

#include "AWSDynamoDBImportTableResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBImportTableResult {
GENERATED_BODY()

    /**
    *  <p> Represents the properties of the table created for the import, and parameters of the import. The import parameters include import status, how many items were processed, and how many errors were encountered. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAWSDynamoDBImportTableDescription importTableDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBImportTableResult &fromAWS(const Aws::DynamoDB::Model::ImportTableResult &awsImportTableResult) {
        this->importTableDescription.fromAWS(awsImportTableResult.GetImportTableDescription());

        return *this;
    }
#endif
};
