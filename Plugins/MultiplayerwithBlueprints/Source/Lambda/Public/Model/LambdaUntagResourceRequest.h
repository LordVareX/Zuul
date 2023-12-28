/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/UntagResourceRequest.h"

#endif

#include "LambdaUntagResourceRequest.generated.h"

USTRUCT(BlueprintType)
struct FLambdaUntagResourceRequest {
GENERATED_BODY()

    /**
    *  <p>The function's Amazon Resource Name (ARN).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString resource;

    /**
    *  <p>A list of tag keys to remove from the function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FString> tagKeys;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::UntagResourceRequest toAWS() const {
        Aws::Lambda::Model::UntagResourceRequest awsUntagResourceRequest;

		if (!(this->resource.IsEmpty())) {
            awsUntagResourceRequest.SetResource(TCHAR_TO_UTF8(*this->resource));
        }

        for (const FString& elem : this->tagKeys) {
            awsUntagResourceRequest.AddTagKeys(TCHAR_TO_UTF8(*elem));
        }

        return awsUntagResourceRequest;
    }

    bool IsEmpty() const {
        return this->resource.IsEmpty() && this->tagKeys.Num() == 0;
    }
#endif
};
