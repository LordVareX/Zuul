/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/GetPolicyResult.h"

#endif

#include "GetPolicyResult.generated.h"

USTRUCT(BlueprintType)
struct FGetPolicyResult {
GENERATED_BODY()

    /**
    *  <p>The resource-based policy.</p>
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
    FGetPolicyResult &fromAWS(const Aws::Lambda::Model::GetPolicyResult &awsGetPolicyResult) {
        this->policy = UTF8_TO_TCHAR(awsGetPolicyResult.GetPolicy().c_str());

        this->revisionId = UTF8_TO_TCHAR(awsGetPolicyResult.GetRevisionId().c_str());

        return *this;
    }
#endif
};
