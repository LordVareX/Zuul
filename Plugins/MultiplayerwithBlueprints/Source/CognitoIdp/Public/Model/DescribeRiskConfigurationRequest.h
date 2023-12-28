/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DescribeRiskConfigurationRequest.h"

#endif

#include "DescribeRiskConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeRiskConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The app client ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientId;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::DescribeRiskConfigurationRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::DescribeRiskConfigurationRequest awsDescribeRiskConfigurationRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsDescribeRiskConfigurationRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->clientId.IsEmpty())) {
            awsDescribeRiskConfigurationRequest.SetClientId(TCHAR_TO_UTF8(*this->clientId));
        }

        return awsDescribeRiskConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->clientId.IsEmpty();
    }
#endif
};
