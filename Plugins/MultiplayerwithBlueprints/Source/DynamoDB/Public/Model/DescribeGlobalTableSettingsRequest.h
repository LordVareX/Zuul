/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeGlobalTableSettingsRequest.h"

#endif

#include "DescribeGlobalTableSettingsRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeGlobalTableSettingsRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the global table to describe.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString globalTableName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DescribeGlobalTableSettingsRequest toAWS() const {
        Aws::DynamoDB::Model::DescribeGlobalTableSettingsRequest awsDescribeGlobalTableSettingsRequest;

		if (!(this->globalTableName.IsEmpty())) {
            awsDescribeGlobalTableSettingsRequest.SetGlobalTableName(TCHAR_TO_UTF8(*this->globalTableName));
        }

        return awsDescribeGlobalTableSettingsRequest;
    }

    bool IsEmpty() const {
        return this->globalTableName.IsEmpty();
    }
#endif
};
