/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeLimitsRequest.h"

#endif

#include "DescribeLimitsRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeLimitsRequest {
    GENERATED_BODY()

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DescribeLimitsRequest toAWS() const {
        Aws::DynamoDB::Model::DescribeLimitsRequest awsDescribeLimitsRequest;

        return awsDescribeLimitsRequest;
    }

    bool IsEmpty() const {
        return true;
    }
#endif
};
