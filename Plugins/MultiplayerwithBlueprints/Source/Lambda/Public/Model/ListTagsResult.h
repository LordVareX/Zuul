/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListTagsResult.h"

#endif

#include "ListTagsResult.generated.h"

USTRUCT(BlueprintType)
struct FListTagsResult {
GENERATED_BODY()

    /**
    *  <p>The function's tags.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TMap<FString, FString> tags;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FListTagsResult &fromAWS(const Aws::Lambda::Model::ListTagsResult &awsListTagsResult) {
        this->tags.Empty();
        for (const auto& elem : awsListTagsResult.GetTags()) {
            this->tags.Add(elem.first.c_str(), elem.second.c_str());
        }

        return *this;
    }
#endif
};
