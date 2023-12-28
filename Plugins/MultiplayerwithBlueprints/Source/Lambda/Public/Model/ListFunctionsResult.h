/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListFunctionsResult.h"

#endif

#include "Model/FunctionConfiguration.h"

#include "ListFunctionsResult.generated.h"

USTRUCT(BlueprintType)
struct FListFunctionsResult {
GENERATED_BODY()

    /**
    *  <p>The pagination token that's included if more results are available.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString nextMarker;

    /**
    *  <p>A list of Lambda functions.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FFunctionConfiguration> functions;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FListFunctionsResult &fromAWS(const Aws::Lambda::Model::ListFunctionsResult &awsListFunctionsResult) {
        this->nextMarker = UTF8_TO_TCHAR(awsListFunctionsResult.GetNextMarker().c_str());

        this->functions.Empty();
        for (const Aws::Lambda::Model::FunctionConfiguration& elem : awsListFunctionsResult.GetFunctions()) {
            this->functions.Add(FFunctionConfiguration().fromAWS(elem));
        }

        return *this;
    }
#endif
};
