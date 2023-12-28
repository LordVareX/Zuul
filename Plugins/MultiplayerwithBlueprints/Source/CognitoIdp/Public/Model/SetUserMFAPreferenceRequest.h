/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SetUserMFAPreferenceRequest.h"

#endif

#include "Model/SMSMfaSettingsType.h"
#include "Model/SoftwareTokenMfaSettingsType.h"

#include "SetUserMFAPreferenceRequest.generated.h"

USTRUCT(BlueprintType)
struct FSetUserMFAPreferenceRequest {
GENERATED_BODY()

    /**
    *  <p>The SMS text message multi-factor authentication (MFA) settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FSMSMfaSettingsType sMSMfaSettings;

    /**
    *  <p>The time-based one-time password software token MFA settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FSoftwareTokenMfaSettingsType softwareTokenMfaSettings;

    /**
    *  <p>The access token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString accessToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::SetUserMFAPreferenceRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::SetUserMFAPreferenceRequest awsSetUserMFAPreferenceRequest;

        if (!(this->sMSMfaSettings.IsEmpty())) {
            awsSetUserMFAPreferenceRequest.SetSMSMfaSettings(this->sMSMfaSettings.toAWS());
        }

        if (!(this->softwareTokenMfaSettings.IsEmpty())) {
            awsSetUserMFAPreferenceRequest.SetSoftwareTokenMfaSettings(this->softwareTokenMfaSettings.toAWS());
        }

        if (!(this->accessToken.IsEmpty())) {
            awsSetUserMFAPreferenceRequest.SetAccessToken(TCHAR_TO_UTF8(*this->accessToken));
        }

        return awsSetUserMFAPreferenceRequest;
    }

    bool IsEmpty() const {
        return this->sMSMfaSettings.IsEmpty() && this->softwareTokenMfaSettings.IsEmpty() && this->accessToken.IsEmpty();
    }
#endif
};
