/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/TagResourceRequest.h"

#endif

#include "CognitoIdpTagResourceRequest.generated.h"

USTRUCT(BlueprintType)
struct FCognitoIdpTagResourceRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the user pool to assign the tags to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString resourceArn;

    /**
    *  <p>The tags to assign to the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> tags;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::TagResourceRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::TagResourceRequest awsTagResourceRequest;

        if (!(this->resourceArn.IsEmpty())) {
            awsTagResourceRequest.SetResourceArn(TCHAR_TO_UTF8(*this->resourceArn));
        }

        for (const TPair<FString, FString>& elem : this->tags) {
            awsTagResourceRequest.AddTags(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsTagResourceRequest;
    }

    bool IsEmpty() const {
        return this->resourceArn.IsEmpty() && this->tags.Num() == 0;
    }
#endif
};
