/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/InputFormatOptions.h"

#endif

#include "Model/AWSDynamoDBCsvOptions.h"

#include "AWSDynamoDBInputFormatOptions.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBInputFormatOptions {
GENERATED_BODY()

    /**
    *  <p> The options for imported source files in CSV format. The values are Delimiter and HeaderList. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAWSDynamoDBCsvOptions csv;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::InputFormatOptions toAWS() const {
        Aws::DynamoDB::Model::InputFormatOptions awsInputFormatOptions;

        if (!(this->csv.IsEmpty())) {
            awsInputFormatOptions.SetCsv(this->csv.toAWS());
        }

        return awsInputFormatOptions;
    }

    bool IsEmpty() const {
        return this->csv.IsEmpty();
    }

    FAWSDynamoDBInputFormatOptions &fromAWS(const Aws::DynamoDB::Model::InputFormatOptions &awsInputFormatOptions) {
        this->csv.fromAWS(awsInputFormatOptions.GetCsv());

        return *this;
    }
#endif
};
