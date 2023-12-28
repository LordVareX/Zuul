/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/GetCodeSigningConfigResult.h"

#endif

#include "Model/AWSLambdaCodeSigningConfig.h"

#include "AWSLambdaGetCodeSigningConfigResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaGetCodeSigningConfigResult {
GENERATED_BODY()

    /**
    *  <p>The code signing configuration</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaCodeSigningConfig codeSigningConfig;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FAWSLambdaGetCodeSigningConfigResult &fromAWS(const Aws::Lambda::Model::GetCodeSigningConfigResult &awsGetCodeSigningConfigResult) {
        this->codeSigningConfig.fromAWS(awsGetCodeSigningConfigResult.GetCodeSigningConfig());

        return *this;
    }
#endif
};
