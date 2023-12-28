/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminForgetDeviceRequest.h"

#endif

#include "AdminForgetDeviceRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminForgetDeviceRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The user name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    *  <p>The device key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString deviceKey;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminForgetDeviceRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminForgetDeviceRequest awsAdminForgetDeviceRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminForgetDeviceRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminForgetDeviceRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        if (!(this->deviceKey.IsEmpty())) {
            awsAdminForgetDeviceRequest.SetDeviceKey(TCHAR_TO_UTF8(*this->deviceKey));
        }

        return awsAdminForgetDeviceRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty() && this->deviceKey.IsEmpty();
    }
#endif
};
