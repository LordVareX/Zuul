/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/Concurrency.h"

#endif

#include "Concurrency.generated.h"

USTRUCT(BlueprintType)
struct FConcurrency {
GENERATED_BODY()

    /**
    *  <p>The number of concurrent executions that are reserved for this function. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/concurrent-executions.html">Managing Concurrency</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int reservedConcurrentExecutions = 0;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FConcurrency &fromAWS(const Aws::Lambda::Model::Concurrency &awsConcurrency) {
		this->reservedConcurrentExecutions = awsConcurrency.GetReservedConcurrentExecutions();

        return *this;
    }
#endif
};
