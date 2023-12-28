/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/ListTagsForResourceResult.h"

#endif

#include "CognitoIdentityListTagsForResourceResult.generated.h"

USTRUCT(BlueprintType)
struct FCognitoIdentityListTagsForResourceResult {
GENERATED_BODY()

    /**
    *  <p>The tags that are assigned to the identity pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TMap<FString, FString> tags;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FCognitoIdentityListTagsForResourceResult &fromAWS(const Aws::CognitoIdentity::Model::ListTagsForResourceResult &awsListTagsForResourceResult) {
        for (const auto& elem : awsListTagsForResourceResult.GetTags()) {
            this->tags.Add(elem.first.c_str(), elem.second.c_str());
        }

        return *this;
    }
#endif
};
