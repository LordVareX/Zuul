/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/CsvOptions.h"

#endif

#include "AWSDynamoDBCsvOptions.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBCsvOptions {
GENERATED_BODY()

    /**
    *  <p> The delimiter used for separating items in the CSV file being imported. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString delimiter;

    /**
    *  <p> List of the headers used to specify a common header for all source CSV files being imported. If this field is specified then the first line of each CSV file is treated as data instead of the header. If this field is not specified the the first line of each CSV file is treated as the header. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FString> headerList;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::CsvOptions toAWS() const {
        Aws::DynamoDB::Model::CsvOptions awsCsvOptions;

        if (!(this->delimiter.IsEmpty())) {
            awsCsvOptions.SetDelimiter(TCHAR_TO_UTF8(*this->delimiter));
        }

        for (const FString& elem : this->headerList) {
            awsCsvOptions.AddHeaderList(TCHAR_TO_UTF8(*elem));
        }

        return awsCsvOptions;
    }

    bool IsEmpty() const {
        return this->delimiter.IsEmpty() && this->headerList.Num() == 0;
    }

    FAWSDynamoDBCsvOptions &fromAWS(const Aws::DynamoDB::Model::CsvOptions &awsCsvOptions) {
        this->delimiter = UTF8_TO_TCHAR(awsCsvOptions.GetDelimiter().c_str());

        this->headerList.Empty();
        for (const Aws::String& elem : awsCsvOptions.GetHeaderList()) {
            this->headerList.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        return *this;
    }
#endif
};
