/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeContributorInsightsResult.h"

#endif

#include "Model/ContributorInsightsStatus.h"
#include "Model/FailureException.h"

#include "DescribeContributorInsightsResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeContributorInsightsResult {
GENERATED_BODY()

    /**
    *  <p>The name of the table being described.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>The name of the global secondary index being described.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

    /**
    *  <p>List of names of the associated Alpine rules.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FString> contributorInsightsRuleList;

    /**
    *  <p>Current Status contributor insights.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSContributorInsightsStatus contributorInsightsStatus = EAWSContributorInsightsStatus::NOT_SET;

    /**
    *  <p>Timestamp of the last time the status was changed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime lastUpdateDateTime;

    /**
    *  <p>Returns information about the last failure that encountered.</p> <p>The most common exceptions for a FAILED status are:</p> <ul> <li> <p>LimitExceededException - Per-account Amazon CloudWatch Contributor Insights rule limit reached. Please disable Contributor Insights for other tables/indexes OR disable Contributor Insights rules before retrying.</p> </li> <li> <p>AccessDeniedException - Amazon CloudWatch Contributor Insights rules cannot be modified due to insufficient permissions.</p> </li> <li> <p>AccessDeniedException - Failed to create service-linked role for Contributor Insights due to insufficient permissions.</p> </li> <li> <p>InternalServerError - Failed to create Amazon CloudWatch Contributor Insights rules. Please retry request.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FFailureException failureException;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FDescribeContributorInsightsResult &fromAWS(const Aws::DynamoDB::Model::DescribeContributorInsightsResult &awsDescribeContributorInsightsResult) {
        this->tableName = UTF8_TO_TCHAR(awsDescribeContributorInsightsResult.GetTableName().c_str());

        this->indexName = UTF8_TO_TCHAR(awsDescribeContributorInsightsResult.GetIndexName().c_str());

        this->contributorInsightsRuleList.Empty();
        for (const Aws::String& elem : awsDescribeContributorInsightsResult.GetContributorInsightsRuleList()) {
            this->contributorInsightsRuleList.Add(elem.c_str());
        }

        switch(awsDescribeContributorInsightsResult.GetContributorInsightsStatus()) {
            case Aws::DynamoDB::Model::ContributorInsightsStatus::NOT_SET:
                this->contributorInsightsStatus = EAWSContributorInsightsStatus::NOT_SET;
                break;
            case Aws::DynamoDB::Model::ContributorInsightsStatus::ENABLING:
                this->contributorInsightsStatus = EAWSContributorInsightsStatus::ENABLING;
                break;
            case Aws::DynamoDB::Model::ContributorInsightsStatus::ENABLED:
                this->contributorInsightsStatus = EAWSContributorInsightsStatus::ENABLED;
                break;
            case Aws::DynamoDB::Model::ContributorInsightsStatus::DISABLING:
                this->contributorInsightsStatus = EAWSContributorInsightsStatus::DISABLING;
                break;
            case Aws::DynamoDB::Model::ContributorInsightsStatus::DISABLED:
                this->contributorInsightsStatus = EAWSContributorInsightsStatus::DISABLED;
                break;
            case Aws::DynamoDB::Model::ContributorInsightsStatus::FAILED:
                this->contributorInsightsStatus = EAWSContributorInsightsStatus::FAILED;
                break;
            default:
                this->contributorInsightsStatus = EAWSContributorInsightsStatus::NOT_SET;
                break;
        }

        this->lastUpdateDateTime = FDateTime(1970, 1, 1) + FTimespan(awsDescribeContributorInsightsResult.GetLastUpdateDateTime().Millis() * ETimespan::TicksPerMillisecond);

        this->failureException.fromAWS(awsDescribeContributorInsightsResult.GetFailureException());

        return *this;
    }
#endif
};
