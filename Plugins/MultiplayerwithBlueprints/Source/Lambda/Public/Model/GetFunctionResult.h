/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/GetFunctionResult.h"

#endif

#include "Model/FunctionConfiguration.h"
#include "Model/FunctionCodeLocation.h"
#include "Model/Concurrency.h"

#include "GetFunctionResult.generated.h"

USTRUCT(BlueprintType)
struct FGetFunctionResult {
GENERATED_BODY()

    /**
    *  <p>The configuration of the function or version.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FFunctionConfiguration configuration;

    /**
    *  <p>The deployment package of the function or version.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FFunctionCodeLocation code;

    /**
    *  <p>The function's <a href="https://docs.aws.amazon.com/lambda/latest/dg/tagging.html">tags</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TMap<FString, FString> tags;

    /**
    *  <p>The function's <a href="https://docs.aws.amazon.com/lambda/latest/dg/concurrent-executions.html">reserved concurrency</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FConcurrency concurrency;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FGetFunctionResult &fromAWS(const Aws::Lambda::Model::GetFunctionResult &awsGetFunctionResult) {
        this->configuration.fromAWS(awsGetFunctionResult.GetConfiguration());

        this->code.fromAWS(awsGetFunctionResult.GetCode());

        this->tags.Empty();
        for (const auto& elem : awsGetFunctionResult.GetTags()) {
            this->tags.Add(elem.first.c_str(), elem.second.c_str());
        }

        this->concurrency.fromAWS(awsGetFunctionResult.GetConcurrency());

        return *this;
    }
#endif
};
