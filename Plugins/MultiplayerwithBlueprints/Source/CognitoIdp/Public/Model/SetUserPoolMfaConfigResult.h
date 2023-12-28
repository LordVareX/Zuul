/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SetUserPoolMfaConfigResult.h"

#endif

#include "Model/SmsMfaConfigType.h"
#include "Model/SoftwareTokenMfaConfigType.h"
#include "Model/UserPoolMfaType.h"

#include "SetUserPoolMfaConfigResult.generated.h"

USTRUCT(BlueprintType)
struct FSetUserPoolMfaConfigResult {
GENERATED_BODY()

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
    FSetUserPoolMfaConfigResult &fromAWS(const Aws::CognitoIdentityProvider::Model::SetUserPoolMfaConfigResult &awsSetUserPoolMfaConfigResult) {
        this->smsMfaConfiguration.fromAWS(awsSetUserPoolMfaConfigResult.GetSmsMfaConfiguration());

        this->softwareTokenMfaConfiguration.fromAWS(awsSetUserPoolMfaConfigResult.GetSoftwareTokenMfaConfiguration());

        switch(awsSetUserPoolMfaConfigResult.GetMfaConfiguration()) {
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
