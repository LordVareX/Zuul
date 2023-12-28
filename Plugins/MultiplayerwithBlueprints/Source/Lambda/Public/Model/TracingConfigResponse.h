/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/TracingConfigResponse.h"

#endif

#include "Model/TracingMode.h"

#include "TracingConfigResponse.generated.h"

USTRUCT(BlueprintType)
struct FTracingConfigResponse {
GENERATED_BODY()

    /**
    *  <p>The tracing mode.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSTracingMode mode = EAWSTracingMode::NOT_SET;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FTracingConfigResponse &fromAWS(const Aws::Lambda::Model::TracingConfigResponse &awsTracingConfigResponse) {
        switch(awsTracingConfigResponse.GetMode()) {
            case Aws::Lambda::Model::TracingMode::NOT_SET:
                this->mode = EAWSTracingMode::NOT_SET;
                break;
            case Aws::Lambda::Model::TracingMode::Active:
                this->mode = EAWSTracingMode::Active;
                break;
            case Aws::Lambda::Model::TracingMode::PassThrough:
                this->mode = EAWSTracingMode::PassThrough;
                break;
            default:
                this->mode = EAWSTracingMode::NOT_SET;
                break;
            }

        return *this;
    }
#endif
};
