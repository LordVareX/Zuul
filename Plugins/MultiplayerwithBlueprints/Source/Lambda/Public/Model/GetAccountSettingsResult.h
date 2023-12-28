/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/GetAccountSettingsResult.h"

#endif

#include "Model/AccountLimit.h"
#include "Model/AccountUsage.h"

#include "GetAccountSettingsResult.generated.h"

USTRUCT(BlueprintType)
struct FGetAccountSettingsResult {
GENERATED_BODY()

    /**
    *  <p>Limits that are related to concurrency and code storage.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAccountLimit accountLimit;

    /**
    *  <p>The number of functions and amount of storage in use.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAccountUsage accountUsage;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FGetAccountSettingsResult &fromAWS(const Aws::Lambda::Model::GetAccountSettingsResult &awsGetAccountSettingsResult) {
        this->accountLimit.fromAWS(awsGetAccountSettingsResult.GetAccountLimit());

        this->accountUsage.fromAWS(awsGetAccountSettingsResult.GetAccountUsage());

        return *this;
    }
#endif
};
