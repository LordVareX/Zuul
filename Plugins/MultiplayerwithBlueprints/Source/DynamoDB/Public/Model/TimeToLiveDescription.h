/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/TimeToLiveDescription.h"

#endif

#include "Model/TimeToLiveStatus.h"

#include "TimeToLiveDescription.generated.h"

USTRUCT(BlueprintType)
struct FTimeToLiveDescription {
GENERATED_BODY()

    /**
    *  <p> The TTL status for the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSTimeToLiveStatus timeToLiveStatus = EAWSTimeToLiveStatus::NOT_SET;

    /**
    *  <p> The name of the TTL attribute for items in the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString attributeName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:

    FTimeToLiveDescription &fromAWS(const Aws::DynamoDB::Model::TimeToLiveDescription &awsTimeToLiveDescription) {
        switch(awsTimeToLiveDescription.GetTimeToLiveStatus()) {
            case Aws::DynamoDB::Model::TimeToLiveStatus::NOT_SET:
                this->timeToLiveStatus = EAWSTimeToLiveStatus::NOT_SET;
                break;
            case Aws::DynamoDB::Model::TimeToLiveStatus::ENABLING:
                this->timeToLiveStatus = EAWSTimeToLiveStatus::ENABLING;
                break;
            case Aws::DynamoDB::Model::TimeToLiveStatus::DISABLING:
                this->timeToLiveStatus = EAWSTimeToLiveStatus::DISABLING;
                break;
            case Aws::DynamoDB::Model::TimeToLiveStatus::ENABLED:
                this->timeToLiveStatus = EAWSTimeToLiveStatus::ENABLED;
                break;
            case Aws::DynamoDB::Model::TimeToLiveStatus::DISABLED:
                this->timeToLiveStatus = EAWSTimeToLiveStatus::DISABLED;
                break;
            default:
                this->timeToLiveStatus = EAWSTimeToLiveStatus::NOT_SET;
                break;
            }

        this->attributeName = UTF8_TO_TCHAR(awsTimeToLiveDescription.GetAttributeName().c_str());

        return *this;
    }
#endif
};
