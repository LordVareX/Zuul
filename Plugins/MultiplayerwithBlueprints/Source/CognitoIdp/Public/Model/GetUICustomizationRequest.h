/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GetUICustomizationRequest.h"

#endif

#include "GetUICustomizationRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetUICustomizationRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The client ID for the client app.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientId;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::GetUICustomizationRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::GetUICustomizationRequest awsGetUICustomizationRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsGetUICustomizationRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->clientId.IsEmpty())) {
            awsGetUICustomizationRequest.SetClientId(TCHAR_TO_UTF8(*this->clientId));
        }

        return awsGetUICustomizationRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->clientId.IsEmpty();
    }
#endif
};
