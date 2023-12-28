/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/CreateCodeSigningConfigResult.h"

#endif

#include "Model/AWSLambdaCodeSigningConfig.h"

#include "AWSLambdaCreateCodeSigningConfigResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaCreateCodeSigningConfigResult {
GENERATED_BODY()

    /**
    *  <p>The code signing configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaCodeSigningConfig codeSigningConfig;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FAWSLambdaCreateCodeSigningConfigResult &fromAWS(const Aws::Lambda::Model::CreateCodeSigningConfigResult &awsCreateCodeSigningConfigResult) {
        this->codeSigningConfig.fromAWS(awsCreateCodeSigningConfigResult.GetCodeSigningConfig());

        return *this;
    }
#endif
};
