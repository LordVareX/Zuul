/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/Endpoint.h"

#endif

#include "Endpoint.generated.h"

USTRUCT(BlueprintType)
struct FEndpoint {
GENERATED_BODY()

    /**
    *  <p>IP address of the endpoint.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString address;

    /**
    *  <p>Endpoint cache time to live (TTL) value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 cachePeriodInMinutes = 0;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FEndpoint &fromAWS(const Aws::DynamoDB::Model::Endpoint &awsEndpoint) {
        this->address = UTF8_TO_TCHAR(awsEndpoint.GetAddress().c_str());

        this->cachePeriodInMinutes = (int64)awsEndpoint.GetCachePeriodInMinutes();

        return *this;
    }
#endif
};
