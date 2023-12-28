/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/GetFunctionConcurrencyResult.h"

#endif

#include "GetFunctionConcurrencyResult.generated.h"

USTRUCT(BlueprintType)
struct FGetFunctionConcurrencyResult {
    GENERATED_BODY()

    /**
    *  <p>The number of simultaneous executions that are reserved for the function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int reservedConcurrentExecutions = 0;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FGetFunctionConcurrencyResult &fromAWS(const Aws::Lambda::Model::GetFunctionConcurrencyResult &awsGetFunctionConcurrencyResult) {
		this->reservedConcurrentExecutions = awsGetFunctionConcurrencyResult.GetReservedConcurrentExecutions();

        return *this;
    }
#endif
};
