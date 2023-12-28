/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GetUserPoolMfaConfigResult.h"

#endif

#include "Model/SmsMfaConfigType.h"
#include "Model/SoftwareTokenMfaConfigType.h"
#include "Model/UserPoolMfaType.h"

#include "GetUserPoolMfaConfigResult.generated.h"

USTRUCT(BlueprintType)

struct FGetUserPoolMfaConfigResult {
    GENERATED_BODY()

    /**
    *  <p>The SMS text message multi-factor (MFA) configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FSmsMfaConfigType smsMfaConfiguration;

    /**
    *  <p>The software token multi-factor (MFA) configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FSoftwareTokenMfaConfigType softwareTokenMfaConfiguration;

    /**
    *  <p>The multi-factor (MFA) configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EUserPoolMfaType mfaConfiguration = EUserPoolMfaType::NOT_SET;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    public:
        FGetUserPoolMfaConfigResult &fromAWS(const Aws::CognitoIdentityProvider::Model::GetUserPoolMfaConfigResult &awsGetUserPoolMfaConfigResult) {
            this->smsMfaConfiguration.fromAWS(awsGetUserPoolMfaConfigResult.GetSmsMfaConfiguration());

            this->softwareTokenMfaConfiguration.fromAWS(awsGetUserPoolMfaConfigResult.GetSoftwareTokenMfaConfiguration());

            switch(awsGetUserPoolMfaConfigResult.GetMfaConfiguration()) {
                case Aws::CognitoIdentityProvider::Model::UserPoolMfaType::NOT_SET:
                    this->mfaConfiguration = EUserPoolMfaType::NOT_SET;
                    break;
                case Aws::CognitoIdentityProvider::Model::UserPoolMfaType::OFF:
                    this->mfaConfiguration = EUserPoolMfaType::OFF;
                    break;
                case Aws::CognitoIdentityProvider::Model::UserPoolMfaType::ON:
                    this->mfaConfiguration = EUserPoolMfaType::ON;
                    break;
                case Aws::CognitoIdentityProvider::Model::UserPoolMfaType::OPTIONAL_:
                    this->mfaConfiguration = EUserPoolMfaType::OPTIONAL_;
                    break;
                default:
                    this->mfaConfiguration = EUserPoolMfaType::NOT_SET;
                    break;
            }

            return *this;
        }
#endif
};
