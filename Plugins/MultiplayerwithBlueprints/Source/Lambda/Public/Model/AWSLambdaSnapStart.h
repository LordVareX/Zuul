/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/SnapStart.h"

#endif

#include "Model/AWSLambdaSnapStartApplyOn.h"

#include "AWSLambdaSnapStart.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaSnapStart {
GENERATED_BODY()

    /**
    *  <p>Set to <code>PublishedVersions</code> to create a snapshot of the initialized execution environment when you publish a function version.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSLambdaSnapStartApplyOn applyOn = EAWSLambdaSnapStartApplyOn::NOT_SET;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::SnapStart toAWS() const {
        Aws::Lambda::Model::SnapStart awsSnapStart;

        switch(this->applyOn) {
            case EAWSLambdaSnapStartApplyOn::PublishedVersions:
                awsSnapStart.SetApplyOn(Aws::Lambda::Model::SnapStartApplyOn::PublishedVersions);
                break;
            case EAWSLambdaSnapStartApplyOn::None:
                awsSnapStart.SetApplyOn(Aws::Lambda::Model::SnapStartApplyOn::None);
                break;
            default:
                break;
        }

        return awsSnapStart;
    }

    bool IsEmpty() const {
        return this->applyOn == EAWSLambdaSnapStartApplyOn::NOT_SET;
    }
#endif
};
