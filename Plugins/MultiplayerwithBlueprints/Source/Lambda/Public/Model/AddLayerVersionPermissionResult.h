/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/AddLayerVersionPermissionResult.h"

#endif

#include "AddLayerVersionPermissionResult.generated.h"

USTRUCT(BlueprintType)
struct FAddLayerVersionPermissionResult {
GENERATED_BODY()

    /**
    *  <p>The permission statement.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString statement;

    /**
    *  <p>A unique identifier for the current revision of the policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString revisionId;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FAddLayerVersionPermissionResult &fromAWS(const Aws::Lambda::Model::AddLayerVersionPermissionResult &awsAddLayerVersionPermissionResult) {
        this->statement = UTF8_TO_TCHAR(awsAddLayerVersionPermissionResult.GetStatement().c_str());

        this->revisionId = UTF8_TO_TCHAR(awsAddLayerVersionPermissionResult.GetRevisionId().c_str());

        return *this;
    }
#endif
};
