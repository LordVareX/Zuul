/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/ListTagsForResourceRequest.h"

#endif

#include "CognitoIdentityListTagsForResourceRequest.generated.h"

USTRUCT(BlueprintType)
struct FCognitoIdentityListTagsForResourceRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the user pool that the tags are assigned to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString resourceArn;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::ListTagsForResourceRequest toAWS() const {
        Aws::CognitoIdentity::Model::ListTagsForResourceRequest awsListTagsForResourceRequest;

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
