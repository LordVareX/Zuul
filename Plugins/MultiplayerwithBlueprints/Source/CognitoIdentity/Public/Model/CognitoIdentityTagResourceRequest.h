/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/TagResourceRequest.h"

#endif

#include "CognitoIdentityTagResourceRequest.generated.h"

USTRUCT(BlueprintType)
struct FCognitoIdentityTagResourceRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the identity pool to assign the tags to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString resourceArn;

    /**
    *  <p>The tags to assign to the identity pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TMap<FString, FString> tags;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::TagResourceRequest toAWS() const {
        Aws::CognitoIdentity::Model::TagResourceRequest awsTagResourceRequest;

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
