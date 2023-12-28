/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListLayerVersionsResult.h"

#endif

#include "Model/LayerVersionsListItem.h"

#include "ListLayerVersionsResult.generated.h"

USTRUCT(BlueprintType)
struct FListLayerVersionsResult {
GENERATED_BODY()

    /**
    *  <p>A pagination token returned when the response doesn't contain all versions.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString nextMarker;

    /**
    *  <p>A list of versions.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FLayerVersionsListItem> layerVersions;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FListLayerVersionsResult &fromAWS(const Aws::Lambda::Model::ListLayerVersionsResult &awsListLayerVersionsResult) {
        this->nextMarker = UTF8_TO_TCHAR(awsListLayerVersionsResult.GetNextMarker().c_str());

        this->layerVersions.Empty();
        for (const Aws::Lambda::Model::LayerVersionsListItem& elem : awsListLayerVersionsResult.GetLayerVersions()) {
            this->layerVersions.Add(FLayerVersionsListItem().fromAWS(elem));
        }

        return *this;
    }
#endif
};
