/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/SnapStartResponse.h"

#endif

#include "Model/AWSLambdaSnapStartApplyOn.h"
#include "Model/AWSLambdaSnapStartOptimizationStatus.h"

#include "AWSLambdaSnapStartResponse.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaSnapStartResponse {
GENERATED_BODY()

    /**
    *  <p>When set to <code>PublishedVersions</code>, Lambda creates a snapshot of the execution environment when you publish a function version.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSLambdaSnapStartApplyOn applyOn = EAWSLambdaSnapStartApplyOn::NOT_SET;

    /**
    *  <p>When you provide a <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-versions.html#versioning-versions-using">qualified Amazon Resource Name (ARN)</a>, this response element indicates whether SnapStart is activated for the specified function version.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSLambdaSnapStartOptimizationStatus optimizationStatus = EAWSLambdaSnapStartOptimizationStatus::NOT_SET;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FAWSLambdaSnapStartResponse &fromAWS(const Aws::Lambda::Model::SnapStartResponse &awsSnapStartResponse) {
        switch(awsSnapStartResponse.GetApplyOn()) {
            case Aws::Lambda::Model::SnapStartApplyOn::NOT_SET:
                this->applyOn = EAWSLambdaSnapStartApplyOn::NOT_SET;
                break;
            case Aws::Lambda::Model::SnapStartApplyOn::PublishedVersions:
                this->applyOn = EAWSLambdaSnapStartApplyOn::PublishedVersions;
                break;
            case Aws::Lambda::Model::SnapStartApplyOn::None:
                this->applyOn = EAWSLambdaSnapStartApplyOn::None;
                break;
            default:
                this->applyOn = EAWSLambdaSnapStartApplyOn::NOT_SET;
                break;
        }

        switch(awsSnapStartResponse.GetOptimizationStatus()) {
            case Aws::Lambda::Model::SnapStartOptimizationStatus::NOT_SET:
                this->optimizationStatus = EAWSLambdaSnapStartOptimizationStatus::NOT_SET;
                break;
            case Aws::Lambda::Model::SnapStartOptimizationStatus::On:
                this->optimizationStatus = EAWSLambdaSnapStartOptimizationStatus::On;
                break;
            case Aws::Lambda::Model::SnapStartOptimizationStatus::Off:
                this->optimizationStatus = EAWSLambdaSnapStartOptimizationStatus::Off;
                break;
            default:
                this->optimizationStatus = EAWSLambdaSnapStartOptimizationStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
