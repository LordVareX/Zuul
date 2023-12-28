/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DescribeResourceServerRequest.h"

#endif

#include "DescribeResourceServerRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeResourceServerRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool that hosts the resource server.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The identifier for the resource server</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString identifier;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::DescribeResourceServerRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::DescribeResourceServerRequest awsDescribeResourceServerRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsDescribeResourceServerRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->identifier.IsEmpty())) {
            awsDescribeResourceServerRequest.SetIdentifier(TCHAR_TO_UTF8(*this->identifier));
        }

        return awsDescribeResourceServerRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->identifier.IsEmpty();
    }
#endif
};
