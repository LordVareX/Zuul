/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/TracingConfig.h"

#endif

#include "Model/TracingMode.h"

#include "TracingConfig.generated.h"

USTRUCT(BlueprintType)
struct FTracingConfig {
GENERATED_BODY()

    /**
    *  <p>The tracing mode.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSTracingMode mode = EAWSTracingMode::NOT_SET;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::TracingConfig toAWS() const {
        Aws::Lambda::Model::TracingConfig awsTracingConfig;

        switch(this->mode) {
            case EAWSTracingMode::Active:
                awsTracingConfig.SetMode(Aws::Lambda::Model::TracingMode::Active);
                break;
            case EAWSTracingMode::PassThrough:
                awsTracingConfig.SetMode(Aws::Lambda::Model::TracingMode::PassThrough);
                break;
            default:
                break;
            }

        return awsTracingConfig;
    }

    bool IsEmpty() const {
        return this->mode == EAWSTracingMode::NOT_SET;
    }
#endif
};
