/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminSetUserMFAPreferenceRequest.h"

#endif

#include "Model/SMSMfaSettingsType.h"
#include "Model/SoftwareTokenMfaSettingsType.h"

#include "AdminSetUserMFAPreferenceRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminSetUserMFAPreferenceRequest {
GENERATED_BODY()

    /**
    *  <p>The SMS text message MFA settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FSMSMfaSettingsType SMSMfaSettings;

    /**
    *  <p>The time-based one-time password software token MFA settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FSoftwareTokenMfaSettingsType softwareTokenMfaSettings;

    /**
    *  <p>The user pool username or alias.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    *  <p>The user pool ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminSetUserMFAPreferenceRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminSetUserMFAPreferenceRequest awsAdminSetUserMFAPreferenceRequest;

        if (!(this->SMSMfaSettings.IsEmpty())) {
            awsAdminSetUserMFAPreferenceRequest.SetSMSMfaSettings(this->SMSMfaSettings.toAWS());
        }

        if (!(this->softwareTokenMfaSettings.IsEmpty())) {
            awsAdminSetUserMFAPreferenceRequest.SetSoftwareTokenMfaSettings(this->softwareTokenMfaSettings.toAWS());
        }

        if (!(this->username.IsEmpty())) {
            awsAdminSetUserMFAPreferenceRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminSetUserMFAPreferenceRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        return awsAdminSetUserMFAPreferenceRequest;
    }

    bool IsEmpty() const {
        return this->SMSMfaSettings.IsEmpty() && this->softwareTokenMfaSettings.IsEmpty() && this->username.IsEmpty() && this->userPoolId.IsEmpty();
    }
#endif
};
