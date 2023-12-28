/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListCodeSigningConfigsResult.h"

#endif

#include "Model/AWSLambdaCodeSigningConfig.h"

#include "AWSLambdaListCodeSigningConfigsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaListCodeSigningConfigsResult {
GENERATED_BODY()

    /**
    *  <p>The pagination token that's included if more results are available.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString nextMarker;

    /**
    *  <p>The code signing configurations</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FAWSLambdaCodeSigningConfig> codeSigningConfigs;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FAWSLambdaListCodeSigningConfigsResult &fromAWS(const Aws::Lambda::Model::ListCodeSigningConfigsResult &awsListCodeSigningConfigsResult) {
        this->nextMarker = UTF8_TO_TCHAR(awsListCodeSigningConfigsResult.GetNextMarker().c_str());

        this->codeSigningConfigs.Empty();
        for (const Aws::Lambda::Model::CodeSigningConfig& elem : awsListCodeSigningConfigsResult.GetCodeSigningConfigs()) {
            this->codeSigningConfigs.Add(FAWSLambdaCodeSigningConfig().fromAWS(elem));
        }

        return *this;
    }
#endif
};
