/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/PutFunctionConcurrencyResult.h"

#endif

#include "PutFunctionConcurrencyResult.generated.h"

USTRUCT(BlueprintType)
struct FPutFunctionConcurrencyResult {
GENERATED_BODY()

    /**
    *  <p>The number of concurrent executions that are reserved for this function. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/concurrent-executions.html">Managing Concurrency</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int reservedConcurrentExecutions = 0;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FPutFunctionConcurrencyResult &fromAWS(const Aws::Lambda::Model::PutFunctionConcurrencyResult &awsPutFunctionConcurrencyResult) {
		this->reservedConcurrentExecutions = awsPutFunctionConcurrencyResult.GetReservedConcurrentExecutions();

        return *this;
    }
#endif
};
