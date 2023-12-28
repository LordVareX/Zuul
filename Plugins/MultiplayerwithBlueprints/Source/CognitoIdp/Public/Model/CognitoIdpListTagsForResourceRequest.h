/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListTagsForResourceRequest.h"

#endif

#include "CognitoIdpListTagsForResourceRequest.generated.h"

USTRUCT(BlueprintType)
struct FCognitoIdpListTagsForResourceRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the user pool that the tags are assigned to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString resourceArn;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::ListTagsForResourceRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::ListTagsForResourceRequest awsListTagsForResourceRequest;

        if (!(this->resourceArn.IsEmpty())) {
            awsListTagsForResourceRequest.SetResourceArn(TCHAR_TO_UTF8(*this->resourceArn));
        }

        return awsListTagsForResourceRequest;
    }

    bool IsEmpty() const {
        return this->resourceArn.IsEmpty();
    }
#endif
};
