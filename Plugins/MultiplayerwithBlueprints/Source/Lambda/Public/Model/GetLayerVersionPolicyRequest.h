/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/GetLayerVersionPolicyRequest.h"

#endif

#include "GetLayerVersionPolicyRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetLayerVersionPolicyRequest {
GENERATED_BODY()

    /**
    *  <p>The name or Amazon Resource Name (ARN) of the layer.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString layerName;

    /**
    *  <p>The version number.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int64 versionNumber = 0;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::GetLayerVersionPolicyRequest toAWS() const {
        Aws::Lambda::Model::GetLayerVersionPolicyRequest awsGetLayerVersionPolicyRequest;

		if (!(this->layerName.IsEmpty())) {
            awsGetLayerVersionPolicyRequest.SetLayerName(TCHAR_TO_UTF8(*this->layerName));
        }

        if (this->versionNumber >= 0) {
            awsGetLayerVersionPolicyRequest.SetVersionNumber(this->versionNumber);
        }

        return awsGetLayerVersionPolicyRequest;
    }

    bool IsEmpty() const {
        return this->layerName.IsEmpty() && this->versionNumber < 0;
    }
#endif
};
