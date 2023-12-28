/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/DeadLetterConfig.h"

#endif

#include "DeadLetterConfig.generated.h"

USTRUCT(BlueprintType)
struct FDeadLetterConfig {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of an Amazon SQS queue or Amazon SNS topic.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString targetArn;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::DeadLetterConfig toAWS() const {
        Aws::Lambda::Model::DeadLetterConfig awsDeadLetterConfig;

		if (!(this->targetArn.IsEmpty())) {
            awsDeadLetterConfig.SetTargetArn(TCHAR_TO_UTF8(*this->targetArn));
        }

        return awsDeadLetterConfig;
    }

    bool IsEmpty() const {
        return this->targetArn.IsEmpty();
    }

    FDeadLetterConfig &fromAWS(const Aws::Lambda::Model::DeadLetterConfig &awsDeadLetterConfig) {
        this->targetArn = UTF8_TO_TCHAR(awsDeadLetterConfig.GetTargetArn().c_str());

        return *this;
    }
#endif
};
