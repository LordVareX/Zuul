/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListLayersResult.h"

#endif

#include "Model/LayersListItem.h"

#include "ListLayersResult.generated.h"

USTRUCT(BlueprintType)
struct FListLayersResult {
GENERATED_BODY()

    /**
    *  <p>A pagination token returned when the response doesn't contain all layers.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString nextMarker;

    /**
    *  <p>A list of function layers.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FLayersListItem> layers;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FListLayersResult &fromAWS(const Aws::Lambda::Model::ListLayersResult &awsListLayersResult) {
        this->nextMarker = UTF8_TO_TCHAR(awsListLayersResult.GetNextMarker().c_str());

        for (const Aws::Lambda::Model::LayersListItem& elem : awsListLayersResult.GetLayers()) {
            this->layers.Empty();
            this->layers.Add(FLayersListItem().fromAWS(elem));
        }

        return *this;
    }
#endif
};
