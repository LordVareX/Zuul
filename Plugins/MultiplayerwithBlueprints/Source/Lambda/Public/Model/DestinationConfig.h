/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/DestinationConfig.h"

#endif

#include "Model/OnSuccess.h"
#include "Model/OnFailure.h"

#include "DestinationConfig.generated.h"

USTRUCT(BlueprintType)
struct FDestinationConfig {
GENERATED_BODY()

    /**
    *  <p>The destination configuration for successful invocations.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FOnSuccess onSuccess;

    /**
    *  <p>The destination configuration for failed invocations.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FOnFailure onFailure;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::DestinationConfig toAWS() const {
        Aws::Lambda::Model::DestinationConfig awsDestinationConfig;

        if (!(this->onSuccess.IsEmpty())) {
            awsDestinationConfig.SetOnSuccess(this->onSuccess.toAWS());
        }

        if (!(this->onFailure.IsEmpty())) {
            awsDestinationConfig.SetOnFailure(this->onFailure.toAWS());
        }

        return awsDestinationConfig;
    }

    bool IsEmpty() const {
        return this->onSuccess.IsEmpty() && this->onFailure.IsEmpty();
    }

    FDestinationConfig &fromAWS(const Aws::Lambda::Model::DestinationConfig &awsDestinationConfig) {
        this->onSuccess.fromAWS(awsDestinationConfig.GetOnSuccess());
        
        this->onFailure.fromAWS(awsDestinationConfig.GetOnFailure());

        return *this;
    }
#endif
};
