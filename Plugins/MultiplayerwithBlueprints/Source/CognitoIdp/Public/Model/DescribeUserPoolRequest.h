/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DescribeUserPoolRequest.h"

#endif

#include "DescribeUserPoolRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeUserPoolRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool you want to describe.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::DescribeUserPoolRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::DescribeUserPoolRequest awsDescribeUserPoolRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsDescribeUserPoolRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        return awsDescribeUserPoolRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty();
    }
#endif
};
