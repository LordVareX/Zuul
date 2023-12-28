/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeEndpointsResult.h"

#endif

#include "Model/Endpoint.h"

#include "DescribeEndpointsResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeEndpointsResult {
GENERATED_BODY()

    /**
    *  <p>List of endpoints.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FEndpoint> endpoints;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FDescribeEndpointsResult &fromAWS(const Aws::DynamoDB::Model::DescribeEndpointsResult &awsDescribeEndpointsResult) {
        this->endpoints.Empty();
        for (const Aws::DynamoDB::Model::Endpoint& elem : awsDescribeEndpointsResult.GetEndpoints()) {
            this->endpoints.Add(FEndpoint().fromAWS(elem));
        }

        return *this;
    }
#endif
};
