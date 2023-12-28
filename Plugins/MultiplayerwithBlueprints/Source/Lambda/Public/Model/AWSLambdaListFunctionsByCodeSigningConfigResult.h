/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListFunctionsByCodeSigningConfigResult.h"

#endif

#include "AWSLambdaListFunctionsByCodeSigningConfigResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaListFunctionsByCodeSigningConfigResult {
GENERATED_BODY()

    /**
    *  <p>The pagination token that's included if more results are available.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString nextMarker;

    /**
    *  <p>The function ARNs. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FString> functionArns;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FAWSLambdaListFunctionsByCodeSigningConfigResult &fromAWS(const Aws::Lambda::Model::ListFunctionsByCodeSigningConfigResult &awsListFunctionsByCodeSigningConfigResult) {
        this->nextMarker = UTF8_TO_TCHAR(awsListFunctionsByCodeSigningConfigResult.GetNextMarker().c_str());

        this->functionArns.Empty();
        for (const Aws::String& elem : awsListFunctionsByCodeSigningConfigResult.GetFunctionArns()) {
            this->functionArns.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        return *this;
    }
#endif
};
