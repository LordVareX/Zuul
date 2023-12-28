/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListTagsForResourceResult.h"

#endif

#include "CognitoIdpListTagsForResourceResult.generated.h"

USTRUCT(BlueprintType)
struct FCognitoIdpListTagsForResourceResult {
GENERATED_BODY()

    /**
    *  <p>The tags that are assigned to the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> tags;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FCognitoIdpListTagsForResourceResult &fromAWS(const Aws::CognitoIdentityProvider::Model::ListTagsForResourceResult &awsListTagsForResourceResult) {
        this->tags.Empty();
        for (const auto& elem : awsListTagsForResourceResult.GetTags()) {
            this->tags.Add(elem.first.c_str(), elem.second.c_str());
        }

        return *this;
    }
#endif
};
