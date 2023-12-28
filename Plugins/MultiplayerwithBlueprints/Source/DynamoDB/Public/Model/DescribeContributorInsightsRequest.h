/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeContributorInsightsRequest.h"

#endif

#include "DescribeContributorInsightsRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeContributorInsightsRequest {
    GENERATED_BODY()

    /**
    *  <p>The name of the table to describe.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>The name of the global secondary index to describe, if applicable.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DescribeContributorInsightsRequest toAWS() const {
        Aws::DynamoDB::Model::DescribeContributorInsightsRequest awsDescribeContributorInsightsRequest;

		if (!(this->tableName.IsEmpty())) {
            awsDescribeContributorInsightsRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

		if (!(this->indexName.IsEmpty())) {
            awsDescribeContributorInsightsRequest.SetIndexName(TCHAR_TO_UTF8(*this->indexName));
        }

        return awsDescribeContributorInsightsRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty() && this->indexName.IsEmpty();
    }
#endif
};
