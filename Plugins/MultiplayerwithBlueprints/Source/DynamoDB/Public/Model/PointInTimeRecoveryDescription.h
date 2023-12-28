/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/PointInTimeRecoveryDescription.h"

#endif

#include "Model/PointInTimeRecoveryStatus.h"

#include "PointInTimeRecoveryDescription.generated.h"

USTRUCT(BlueprintType)
struct FPointInTimeRecoveryDescription {
GENERATED_BODY()

    /**
    *  <p>The current state of point in time recovery:</p> <ul> <li> <p> <code>ENABLING</code> - Point in time recovery is being enabled.</p> </li> <li> <p> <code>ENABLED</code> - Point in time recovery is enabled.</p> </li> <li> <p> <code>DISABLED</code> - Point in time recovery is disabled.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSPointInTimeRecoveryStatus pointInTimeRecoveryStatus = EAWSPointInTimeRecoveryStatus::NOT_SET;

    /**
    *  <p>Specifies the earliest point in time you can restore your table to. It You can restore your table to any point in time during the last 35 days. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime earliestRestorableDateTime;

    /**
    *  <p> <code>LatestRestorableDateTime</code> is typically 5 minutes before the current time. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime latestRestorableDateTime;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FPointInTimeRecoveryDescription &fromAWS(const Aws::DynamoDB::Model::PointInTimeRecoveryDescription &awsPointInTimeRecoveryDescription) {
        switch(awsPointInTimeRecoveryDescription.GetPointInTimeRecoveryStatus()) {
            case Aws::DynamoDB::Model::PointInTimeRecoveryStatus::NOT_SET:
                this->pointInTimeRecoveryStatus = EAWSPointInTimeRecoveryStatus::NOT_SET;
                break;
            case Aws::DynamoDB::Model::PointInTimeRecoveryStatus::ENABLED:
                this->pointInTimeRecoveryStatus = EAWSPointInTimeRecoveryStatus::ENABLED;
                break;
            case Aws::DynamoDB::Model::PointInTimeRecoveryStatus::DISABLED:
                this->pointInTimeRecoveryStatus = EAWSPointInTimeRecoveryStatus::DISABLED;
                break;
            default:
                this->pointInTimeRecoveryStatus = EAWSPointInTimeRecoveryStatus::NOT_SET;
                break;
            }

        this->earliestRestorableDateTime = FDateTime(1970, 1, 1) + FTimespan(awsPointInTimeRecoveryDescription.GetEarliestRestorableDateTime().Millis() * ETimespan::TicksPerMillisecond);

        this->latestRestorableDateTime = FDateTime(1970, 1, 1) + FTimespan(awsPointInTimeRecoveryDescription.GetLatestRestorableDateTime().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
