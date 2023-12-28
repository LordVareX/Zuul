/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/GetLayerVersionByArnRequest.h"

#endif

#include "GetLayerVersionByArnRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetLayerVersionByArnRequest {
GENERATED_BODY()

    /**
    *  <p>The ARN of the layer version.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString arn;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::GetLayerVersionByArnRequest toAWS() const {
        Aws::Lambda::Model::GetLayerVersionByArnRequest awsGetLayerVersionByArnRequest;

		if (!(this->arn.IsEmpty())) {
            awsGetLayerVersionByArnRequest.SetArn(TCHAR_TO_UTF8(*this->arn));
        }

        return awsGetLayerVersionByArnRequest;
    }

    bool IsEmpty() const {
        return this->arn.IsEmpty();
    }
#endif
};
