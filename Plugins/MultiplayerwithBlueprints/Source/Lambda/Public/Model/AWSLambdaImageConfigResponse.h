/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ImageConfigResponse.h"

#endif

#include "Model/AWSLambdaImageConfig.h"
#include "Model/AWSLambdaImageConfigError.h"

#include "AWSLambdaImageConfigResponse.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaImageConfigResponse {
GENERATED_BODY()

    /**
    *  <p>Configuration values that override the container image Dockerfile.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaImageConfig imageConfig;

    /**
    *  <p>Error response to GetFunctionConfiguration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaImageConfigError error;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FAWSLambdaImageConfigResponse &fromAWS(const Aws::Lambda::Model::ImageConfigResponse &awsImageConfigResponse) {
        this->imageConfig.fromAWS(awsImageConfigResponse.GetImageConfig());

        this->error.fromAWS(awsImageConfigResponse.GetError());

        return *this;
    }
#endif
};
