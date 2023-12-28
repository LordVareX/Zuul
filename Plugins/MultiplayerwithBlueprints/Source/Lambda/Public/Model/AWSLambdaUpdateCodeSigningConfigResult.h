/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/UpdateCodeSigningConfigResult.h"

#endif

#include "Model/AWSLambdaCodeSigningConfig.h"

#include "AWSLambdaUpdateCodeSigningConfigResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaUpdateCodeSigningConfigResult {
GENERATED_BODY()

    /**
    *  <p>The code signing configuration</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaCodeSigningConfig codeSigningConfig;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FAWSLambdaUpdateCodeSigningConfigResult &fromAWS(const Aws::Lambda::Model::UpdateCodeSigningConfigResult &awsUpdateCodeSigningConfigResult) {
        this->codeSigningConfig.fromAWS(awsUpdateCodeSigningConfigResult.GetCodeSigningConfig());

        return *this;
    }
#endif
};
