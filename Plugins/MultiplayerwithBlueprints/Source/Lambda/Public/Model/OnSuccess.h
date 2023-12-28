/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/OnSuccess.h"

#endif

#include "OnSuccess.generated.h"

USTRUCT(BlueprintType)
struct FOnSuccess {
    GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the destination resource.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString destination;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::OnSuccess toAWS() const {
        Aws::Lambda::Model::OnSuccess awsOnSuccess;

		if (!(this->destination.IsEmpty())) {
            awsOnSuccess.SetDestination(TCHAR_TO_UTF8(*this->destination));
        }

        return awsOnSuccess;
    }

    bool IsEmpty() const {
        return this->destination.IsEmpty();
    }

    FOnSuccess &fromAWS(const Aws::Lambda::Model::OnSuccess &awsOnSuccess) {
        this->destination = UTF8_TO_TCHAR(awsOnSuccess.GetDestination().c_str());

        return *this;
    }
#endif
};
