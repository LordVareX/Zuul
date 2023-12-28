/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListFunctionUrlConfigsResult.h"

#endif

#include "Model/AWSLambdaFunctionUrlConfig.h"

#include "AWSLambdaListFunctionUrlConfigsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaListFunctionUrlConfigsResult {
GENERATED_BODY()

    /**
    *  <p>A list of function URL configurations.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FAWSLambdaFunctionUrlConfig> functionUrlConfigs;

    /**
    *  <p>The pagination token that's included if more results are available.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString nextMarker;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FAWSLambdaListFunctionUrlConfigsResult &fromAWS(const Aws::Lambda::Model::ListFunctionUrlConfigsResult &awsListFunctionUrlConfigsResult) {
        this->functionUrlConfigs.Empty();
        for (const Aws::Lambda::Model::FunctionUrlConfig& elem : awsListFunctionUrlConfigsResult.GetFunctionUrlConfigs()) {
            this->functionUrlConfigs.Add(FAWSLambdaFunctionUrlConfig().fromAWS(elem));
        }

        this->nextMarker = UTF8_TO_TCHAR(awsListFunctionUrlConfigsResult.GetNextMarker().c_str());

        return *this;
    }
#endif
};
