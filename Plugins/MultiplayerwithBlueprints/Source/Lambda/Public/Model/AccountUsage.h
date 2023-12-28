/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/AccountUsage.h"

#endif

#include "AccountUsage.generated.h"

USTRUCT(BlueprintType)
struct FAccountUsage {
GENERATED_BODY()

    /**
    *  <p>The amount of storage space, in bytes, that's being used by deployment packages and layer archives.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int64 totalCodeSize = 0;

    /**
    *  <p>The number of Lambda functions.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int64 functionCount = 0;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FAccountUsage &fromAWS(const Aws::Lambda::Model::AccountUsage &awsAccountUsage) {
        this->totalCodeSize = (int64)awsAccountUsage.GetTotalCodeSize();

        this->functionCount = (int64)awsAccountUsage.GetFunctionCount();

        return *this;
    }
#endif
};
