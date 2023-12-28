/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminUpdateDeviceStatusRequest.h"

#endif

#include "Model/DeviceRememberedStatusType.h"

#include "AdminUpdateDeviceStatusRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminUpdateDeviceStatusRequest {
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

    /**
    *  <p>The status indicating whether a device has been remembered or not.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EDeviceRememberedStatusType deviceRememberedStatus = EDeviceRememberedStatusType::NOT_SET;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminUpdateDeviceStatusRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminUpdateDeviceStatusRequest awsAdminUpdateDeviceStatusRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminUpdateDeviceStatusRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminUpdateDeviceStatusRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        if (!(this->deviceKey.IsEmpty())) {
            awsAdminUpdateDeviceStatusRequest.SetDeviceKey(TCHAR_TO_UTF8(*this->deviceKey));
        }

        switch(this->deviceRememberedStatus) {
            case EDeviceRememberedStatusType::remembered:
                awsAdminUpdateDeviceStatusRequest.SetDeviceRememberedStatus(Aws::CognitoIdentityProvider::Model::DeviceRememberedStatusType::remembered);
                break;
            case EDeviceRememberedStatusType::not_remembered:
                awsAdminUpdateDeviceStatusRequest.SetDeviceRememberedStatus(Aws::CognitoIdentityProvider::Model::DeviceRememberedStatusType::not_remembered);
                break;
            default:
                break;
        }

        return awsAdminUpdateDeviceStatusRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty() && this->deviceKey.IsEmpty() && this->deviceRememberedStatus == EDeviceRememberedStatusType::NOT_SET;
    }
#endif
};
