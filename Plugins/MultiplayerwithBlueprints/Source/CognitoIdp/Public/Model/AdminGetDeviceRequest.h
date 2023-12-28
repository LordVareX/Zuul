/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminGetDeviceRequest.h"

#endif

#include "AdminGetDeviceRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminGetDeviceRequest {
GENERATED_BODY()

    /**
    *  <p>The device key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString deviceKey;

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

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminGetDeviceRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminGetDeviceRequest awsAdminGetDeviceRequest;

        if (!(this->deviceKey.IsEmpty())) {
            awsAdminGetDeviceRequest.SetDeviceKey(TCHAR_TO_UTF8(*this->deviceKey));
        }

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminGetDeviceRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminGetDeviceRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        return awsAdminGetDeviceRequest;
    }

    bool IsEmpty() const {
        return this->deviceKey.IsEmpty() && this->userPoolId.IsEmpty() && this->username.IsEmpty();
    }
#endif
};
