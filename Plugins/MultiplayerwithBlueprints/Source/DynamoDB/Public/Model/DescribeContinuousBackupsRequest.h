/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeContinuousBackupsRequest.h"

#endif

#include "DescribeContinuousBackupsRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeContinuousBackupsRequest {
GENERATED_BODY()

    /**
    *  <p>Name of the table for which the customer wants to check the continuous backups and point in time recovery settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DescribeContinuousBackupsRequest toAWS() const {
        Aws::DynamoDB::Model::DescribeContinuousBackupsRequest awsDescribeContinuousBackupsRequest;

		if (!(this->tableName.IsEmpty())) {
            awsDescribeContinuousBackupsRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

        return awsDescribeContinuousBackupsRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty();
    }
#endif
};
