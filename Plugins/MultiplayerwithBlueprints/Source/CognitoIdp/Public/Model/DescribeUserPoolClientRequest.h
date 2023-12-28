/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DescribeUserPoolClientRequest.h"

#endif

#include "DescribeUserPoolClientRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeUserPoolClientRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool you want to describe.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The app client ID of the app associated with the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientId;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::DescribeUserPoolClientRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::DescribeUserPoolClientRequest awsDescribeUserPoolClientRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsDescribeUserPoolClientRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->clientId.IsEmpty())) {
            awsDescribeUserPoolClientRequest.SetClientId(TCHAR_TO_UTF8(*this->clientId));
        }

        return awsDescribeUserPoolClientRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->clientId.IsEmpty();
    }
#endif
};
