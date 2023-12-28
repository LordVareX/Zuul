/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeEndpointsRequest.h"

#endif

#include "DescribeEndpointsRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeEndpointsRequest {
    GENERATED_BODY()

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DescribeEndpointsRequest toAWS() const {
        Aws::DynamoDB::Model::DescribeEndpointsRequest awsDescribeEndpointsRequest;

        return awsDescribeEndpointsRequest;
    }

    bool IsEmpty() const {
        return true;
    }
#endif
};
