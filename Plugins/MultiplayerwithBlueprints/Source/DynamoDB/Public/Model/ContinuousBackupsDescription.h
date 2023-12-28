/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ContinuousBackupsDescription.h"

#endif

#include "Model/ContinuousBackupsStatus.h"
#include "Model/PointInTimeRecoveryDescription.h"

#include "ContinuousBackupsDescription.generated.h"

USTRUCT(BlueprintType)
struct FContinuousBackupsDescription {
GENERATED_BODY()

    /**
    *  <p> <code>ContinuousBackupsStatus</code> can be one of the following states: ENABLED, DISABLED</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSContinuousBackupsStatus continuousBackupsStatus = EAWSContinuousBackupsStatus::NOT_SET;

    /**
    *  <p>The description of the point in time recovery settings applied to the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FPointInTimeRecoveryDescription pointInTimeRecoveryDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FContinuousBackupsDescription &fromAWS(const Aws::DynamoDB::Model::ContinuousBackupsDescription &awsContinuousBackupsDescription) {
        switch(awsContinuousBackupsDescription.GetContinuousBackupsStatus()) {
            case Aws::DynamoDB::Model::ContinuousBackupsStatus::NOT_SET:
                this->continuousBackupsStatus = EAWSContinuousBackupsStatus::NOT_SET;
                break;
            case Aws::DynamoDB::Model::ContinuousBackupsStatus::ENABLED:
                this->continuousBackupsStatus = EAWSContinuousBackupsStatus::ENABLED;
                break;
            case Aws::DynamoDB::Model::ContinuousBackupsStatus::DISABLED:
                this->continuousBackupsStatus = EAWSContinuousBackupsStatus::DISABLED;
                break;
            default:
                this->continuousBackupsStatus = EAWSContinuousBackupsStatus::NOT_SET;
                break;
        }

        this->pointInTimeRecoveryDescription.fromAWS(awsContinuousBackupsDescription.GetPointInTimeRecoveryDescription());

        return *this;
    }
#endif
};
