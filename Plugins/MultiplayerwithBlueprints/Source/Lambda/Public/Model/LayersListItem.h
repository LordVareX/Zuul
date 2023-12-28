/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/LayersListItem.h"

#endif

#include "Model/LayerVersionsListItem.h"

#include "LayersListItem.generated.h"

USTRUCT(BlueprintType)
struct FLayersListItem {
GENERATED_BODY()

    /**
    *  <p>The name of the layer.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString layerName;

    /**
    *  <p>The Amazon Resource Name (ARN) of the function layer.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString layerArn;

    /**
    *  <p>The newest version of the layer.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FLayerVersionsListItem latestMatchingVersion;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FLayersListItem &fromAWS(const Aws::Lambda::Model::LayersListItem &awsLayersListItem) {
        this->layerName = UTF8_TO_TCHAR(awsLayersListItem.GetLayerName().c_str());

        this->layerArn = UTF8_TO_TCHAR(awsLayersListItem.GetLayerArn().c_str());

        this->latestMatchingVersion.fromAWS(awsLayersListItem.GetLatestMatchingVersion());

        return *this;
    }
#endif
};
