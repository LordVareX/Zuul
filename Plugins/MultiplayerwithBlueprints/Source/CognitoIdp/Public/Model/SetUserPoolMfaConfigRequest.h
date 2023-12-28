/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SetUserPoolMfaConfigRequest.h"

#endif

#include "Model/SmsMfaConfigType.h"
#include "Model/SoftwareTokenMfaConfigType.h"
#include "Model/UserPoolMfaType.h"

#include "SetUserPoolMfaConfigRequest.generated.h"

USTRUCT(BlueprintType)
struct FSetUserPoolMfaConfigRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The SMS text message MFA configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FSmsMfaConfigType smsMfaConfiguration;

    /**
    *  <p>The software token MFA configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FSoftwareTokenMfaConfigType softwareTokenMfaConfiguration;

    /**
    *  <p>The MFA configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EUserPoolMfaType mfaConfiguration = EUserPoolMfaType::NOT_SET;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::SetUserPoolMfaConfigRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::SetUserPoolMfaConfigRequest awsSetUserPoolMfaConfigRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsSetUserPoolMfaConfigRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->smsMfaConfiguration.IsEmpty())) {
            awsSetUserPoolMfaConfigRequest.SetSmsMfaConfiguration(this->smsMfaConfiguration.toAWS());
        }

        if (!(this->softwareTokenMfaConfiguration.IsEmpty())) {
            awsSetUserPoolMfaConfigRequest.SetSoftwareTokenMfaConfiguration(this->softwareTokenMfaConfiguration.toAWS());
        }

        switch(this->mfaConfiguration) {
            case EUserPoolMfaType::OFF:
                awsSetUserPoolMfaConfigRequest.SetMfaConfiguration(Aws::CognitoIdentityProvider::Model::UserPoolMfaType::OFF);
                break;
            case EUserPoolMfaType::ON:
                awsSetUserPoolMfaConfigRequest.SetMfaConfiguration(Aws::CognitoIdentityProvider::Model::UserPoolMfaType::ON);
                break;
            case EUserPoolMfaType::OPTIONAL_:
                awsSetUserPoolMfaConfigRequest.SetMfaConfiguration(Aws::CognitoIdentityProvider::Model::UserPoolMfaType::OPTIONAL_);
                break;
            default:
                break;
        }

        return awsSetUserPoolMfaConfigRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->smsMfaConfiguration.IsEmpty() && this->softwareTokenMfaConfiguration.IsEmpty() && this->mfaConfiguration == EUserPoolMfaType::NOT_SET;
    }
#endif
};
