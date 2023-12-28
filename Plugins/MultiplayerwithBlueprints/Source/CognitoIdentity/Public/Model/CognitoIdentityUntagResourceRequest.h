/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/UntagResourceRequest.h"

#endif

#include "CognitoIdentityUntagResourceRequest.generated.h"

USTRUCT(BlueprintType)
struct FCognitoIdentityUntagResourceRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the identity pool that the tags are assigned to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString resourceArn;

    /**
    *  <p>The keys of the tags to remove from the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TArray<FString> tagKeys;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::UntagResourceRequest toAWS() const {
        Aws::CognitoIdentity::Model::UntagResourceRequest awsUntagResourceRequest;

        if (!(this->resourceArn.IsEmpty())) {
            awsUntagResourceRequest.SetResourceArn(TCHAR_TO_UTF8(*this->resourceArn));
        }

        for (const FString& elem : this->tagKeys) {
            awsUntagResourceRequest.AddTagKeys(TCHAR_TO_UTF8(*elem));
        }

        return awsUntagResourceRequest;
    }

    bool IsEmpty() const {
        return this->resourceArn.IsEmpty() && this->tagKeys.Num() == 0;
    }
#endif
};
