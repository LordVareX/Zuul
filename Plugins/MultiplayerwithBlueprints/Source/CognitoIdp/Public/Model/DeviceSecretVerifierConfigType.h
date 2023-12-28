/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DeviceSecretVerifierConfigType.h"

#endif

#include "DeviceSecretVerifierConfigType.generated.h"

USTRUCT(BlueprintType)
struct FDeviceSecretVerifierConfigType {
GENERATED_BODY()

    /**
    *  <p>The password verifier.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString passwordVerifier;

    /**
    *  <p>The salt.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString salt;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::DeviceSecretVerifierConfigType toAWS() const {
        Aws::CognitoIdentityProvider::Model::DeviceSecretVerifierConfigType awsDeviceSecretVerifierConfigType;

        if (!(this->passwordVerifier.IsEmpty())) {
            awsDeviceSecretVerifierConfigType.SetPasswordVerifier(TCHAR_TO_UTF8(*this->passwordVerifier));
        }

        if (!(this->salt.IsEmpty())) {
            awsDeviceSecretVerifierConfigType.SetSalt(TCHAR_TO_UTF8(*this->salt));
        }

        return awsDeviceSecretVerifierConfigType;
    }

    bool IsEmpty() const {
        return this->passwordVerifier.IsEmpty() && this->salt.IsEmpty();
    }
#endif
};
