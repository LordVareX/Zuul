/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListProvisionedConcurrencyConfigsResult.h"

#endif

#include "Model/ProvisionedConcurrencyConfigListItem.h"

#include "ListProvisionedConcurrencyConfigsResult.generated.h"

USTRUCT(BlueprintType)
struct FListProvisionedConcurrencyConfigsResult {
GENERATED_BODY()

    /**
    *  <p>A list of provisioned concurrency configurations.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FProvisionedConcurrencyConfigListItem> provisionedConcurrencyConfigs;

    /**
    *  <p>The pagination token that's included if more results are available.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString nextMarker;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FListProvisionedConcurrencyConfigsResult &fromAWS(const Aws::Lambda::Model::ListProvisionedConcurrencyConfigsResult &awsListProvisionedConcurrencyConfigsResult) {
        this->provisionedConcurrencyConfigs.Empty();
        for (const Aws::Lambda::Model::ProvisionedConcurrencyConfigListItem& elem : awsListProvisionedConcurrencyConfigsResult.GetProvisionedConcurrencyConfigs()) {
            this->provisionedConcurrencyConfigs.Add(FProvisionedConcurrencyConfigListItem().fromAWS(elem));
        }

        this->nextMarker = UTF8_TO_TCHAR(awsListProvisionedConcurrencyConfigsResult.GetNextMarker().c_str());

        return *this;
    }
#endif
};
