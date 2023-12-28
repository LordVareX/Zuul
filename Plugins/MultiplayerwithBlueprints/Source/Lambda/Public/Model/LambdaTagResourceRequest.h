/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/TagResourceRequest.h"

#endif

#include "LambdaTagResourceRequest.generated.h"

USTRUCT(BlueprintType)
struct FLambdaTagResourceRequest {
GENERATED_BODY()

    /**
    *  <p>The function's Amazon Resource Name (ARN).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString resource;

    /**
    *  <p>A list of tags to apply to the function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TMap<FString, FString> tags;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::TagResourceRequest toAWS() const {
        Aws::Lambda::Model::TagResourceRequest awsTagResourceRequest;

		if (!(this->resource.IsEmpty())) {
            awsTagResourceRequest.SetResource(TCHAR_TO_UTF8(*this->resource));
        }

        for (const TPair<FString, FString>& elem : this->tags) {
            awsTagResourceRequest.AddTags(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsTagResourceRequest;
    }

    bool IsEmpty() const {
        return this->resource.IsEmpty() && this->tags.Num() == 0;
    }
#endif
};
