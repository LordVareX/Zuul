/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/UpdateTimeToLiveResult.h"

#endif

#include "Model/TimeToLiveSpecification.h"

#include "UpdateTimeToLiveResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateTimeToLiveResult {
GENERATED_BODY()

    /**
    *  <p>Represents the output of an <code>UpdateTimeToLive</code> operation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FTimeToLiveSpecification timeToLiveSpecification;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FUpdateTimeToLiveResult &fromAWS(const Aws::DynamoDB::Model::UpdateTimeToLiveResult &awsUpdateTimeToLiveResult) {
        this->timeToLiveSpecification.fromAWS(awsUpdateTimeToLiveResult.GetTimeToLiveSpecification());

        return *this;
    }
#endif
};
