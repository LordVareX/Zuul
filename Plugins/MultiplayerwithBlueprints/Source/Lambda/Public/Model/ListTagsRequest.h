/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListTagsRequest.h"

#endif

#include "ListTagsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListTagsRequest {
GENERATED_BODY()

    /**
    *  <p>The function's Amazon Resource Name (ARN).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString resource;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::ListTagsRequest toAWS() const {
        Aws::Lambda::Model::ListTagsRequest awsListTagsRequest;

		if (!(this->resource.IsEmpty())) {
            awsListTagsRequest.SetResource(TCHAR_TO_UTF8(*this->resource));
        }

        return awsListTagsRequest;
    }

    bool IsEmpty() const {
        return this->resource.IsEmpty();
    }
#endif
};
