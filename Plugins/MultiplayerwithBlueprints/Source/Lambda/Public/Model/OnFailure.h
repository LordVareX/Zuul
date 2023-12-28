/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/OnFailure.h"

#endif

#include "OnFailure.generated.h"

USTRUCT(BlueprintType)
struct FOnFailure {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the destination resource.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString destination;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::OnFailure toAWS() const {
        Aws::Lambda::Model::OnFailure awsOnFailure;

		if (!(this->destination.IsEmpty())) {
            awsOnFailure.SetDestination(TCHAR_TO_UTF8(*this->destination));
        }

        return awsOnFailure;
    }

    bool IsEmpty() const {
        return this->destination.IsEmpty();
    }

    FOnFailure &fromAWS(const Aws::Lambda::Model::OnFailure &awsOnFailure) {
        this->destination = UTF8_TO_TCHAR(awsOnFailure.GetDestination().c_str());

        return *this;
    }
#endif
};
