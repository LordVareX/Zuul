/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListVersionsByFunctionResult.h"

#endif

#include "Model/FunctionConfiguration.h"

#include "ListVersionsByFunctionResult.generated.h"

USTRUCT(BlueprintType)
struct FListVersionsByFunctionResult {
GENERATED_BODY()

    /**
    *  <p>The pagination token that's included if more results are available.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString nextMarker;

    /**
    *  <p>A list of Lambda function versions.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FFunctionConfiguration> versions;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FListVersionsByFunctionResult &fromAWS(const Aws::Lambda::Model::ListVersionsByFunctionResult &awsListVersionsByFunctionResult) {
        this->nextMarker = UTF8_TO_TCHAR(awsListVersionsByFunctionResult.GetNextMarker().c_str());

        this->versions.Empty();
        for (const Aws::Lambda::Model::FunctionConfiguration& elem : awsListVersionsByFunctionResult.GetVersions()) {
            this->versions.Add(FFunctionConfiguration().fromAWS(elem));
        }

        return *this;
    }
#endif
};
