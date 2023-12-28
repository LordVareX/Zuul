/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeTimeToLiveResult.h"

#endif

#include "Model/TimeToLiveDescription.h"

#include "DescribeTimeToLiveResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeTimeToLiveResult {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FTimeToLiveDescription timeToLiveDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FDescribeTimeToLiveResult &fromAWS(const Aws::DynamoDB::Model::DescribeTimeToLiveResult &awsDescribeTimeToLiveResult) {
        this->timeToLiveDescription.fromAWS(awsDescribeTimeToLiveResult.GetTimeToLiveDescription());

        return *this;
    }
#endif
};
