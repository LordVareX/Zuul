/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/UpdateTimeToLiveRequest.h"

#endif

#include "Model/TimeToLiveSpecification.h"

#include "UpdateTimeToLiveRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateTimeToLiveRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the table to be configured.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>Represents the settings used to enable or disable Time to Live for the specified table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FTimeToLiveSpecification timeToLiveSpecification;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::UpdateTimeToLiveRequest toAWS() const {
        Aws::DynamoDB::Model::UpdateTimeToLiveRequest awsUpdateTimeToLiveRequest;

		if (!(this->tableName.IsEmpty())) {
            awsUpdateTimeToLiveRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

        if (!(this->timeToLiveSpecification.IsEmpty())) {
            awsUpdateTimeToLiveRequest.SetTimeToLiveSpecification(this->timeToLiveSpecification.toAWS());
        }

        return awsUpdateTimeToLiveRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty() && this->timeToLiveSpecification.IsEmpty();
    }
#endif
};
