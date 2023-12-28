/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/GetLayerVersionPolicyResult.h"

#endif

#include "GetLayerVersionPolicyResult.generated.h"

USTRUCT(BlueprintType)
struct FGetLayerVersionPolicyResult {
GENERATED_BODY()

    /**
    *  <p>The policy document.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString policy;

    /**
    *  <p>A unique identifier for the current revision of the policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString revisionId;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FGetLayerVersionPolicyResult &fromAWS(const Aws::Lambda::Model::GetLayerVersionPolicyResult &awsGetLayerVersionPolicyResult) {
        this->policy = UTF8_TO_TCHAR(awsGetLayerVersionPolicyResult.GetPolicy().c_str());

        this->revisionId = UTF8_TO_TCHAR(awsGetLayerVersionPolicyResult.GetRevisionId().c_str());

        return *this;
    }
#endif
};
