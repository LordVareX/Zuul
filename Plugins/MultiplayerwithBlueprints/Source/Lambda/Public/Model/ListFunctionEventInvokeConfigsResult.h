/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListFunctionEventInvokeConfigsResult.h"

#endif

#include "Model/FunctionEventInvokeConfig.h"

#include "ListFunctionEventInvokeConfigsResult.generated.h"

USTRUCT(BlueprintType)
struct FListFunctionEventInvokeConfigsResult {
GENERATED_BODY()

    /**
    *  <p>A list of configurations.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FFunctionEventInvokeConfig> functionEventInvokeConfigs;

    /**
    *  <p>The pagination token that's included if more results are available.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString nextMarker;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FListFunctionEventInvokeConfigsResult &fromAWS(const Aws::Lambda::Model::ListFunctionEventInvokeConfigsResult &awsListFunctionEventInvokeConfigsResult) {
        this->functionEventInvokeConfigs.Empty();
        for (const Aws::Lambda::Model::FunctionEventInvokeConfig& elem : awsListFunctionEventInvokeConfigsResult.GetFunctionEventInvokeConfigs()) {
            this->functionEventInvokeConfigs.Add(FFunctionEventInvokeConfig().fromAWS(elem));
        }

        this->nextMarker = UTF8_TO_TCHAR(awsListFunctionEventInvokeConfigsResult.GetNextMarker().c_str());

        return *this;
    }
#endif
};
