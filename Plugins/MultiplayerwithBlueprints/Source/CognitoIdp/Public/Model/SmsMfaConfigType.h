/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SmsMfaConfigType.h"

#endif

#include "Model/SmsConfigurationType.h"

#include "SmsMfaConfigType.generated.h"

USTRUCT(BlueprintType)
struct FSmsMfaConfigType {
GENERATED_BODY()

    /**
    *  <p>The SMS authentication message.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString smsAuthenticationMessage;

    /**
    *  <p>The SMS configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FSmsConfigurationType smsConfiguration;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::SmsMfaConfigType toAWS() const {
        Aws::CognitoIdentityProvider::Model::SmsMfaConfigType awsSmsMfaConfigType;

        if (!(this->smsAuthenticationMessage.IsEmpty())) {
            awsSmsMfaConfigType.SetSmsAuthenticationMessage(TCHAR_TO_UTF8(*this->smsAuthenticationMessage));
        }

        if (!(this->smsConfiguration.IsEmpty())) {
            awsSmsMfaConfigType.SetSmsConfiguration(this->smsConfiguration.toAWS());
        }

        return awsSmsMfaConfigType;
    }

    bool IsEmpty() const {
        return this->smsAuthenticationMessage.IsEmpty() && this->smsConfiguration.IsEmpty();
    }

    FSmsMfaConfigType &fromAWS(const Aws::CognitoIdentityProvider::Model::SmsMfaConfigType &awsSmsMfaConfigType) {
        this->smsAuthenticationMessage = UTF8_TO_TCHAR(awsSmsMfaConfigType.GetSmsAuthenticationMessage().c_str());

        this->smsConfiguration.fromAWS(awsSmsMfaConfigType.GetSmsConfiguration());

        return *this;
    }
#endif
};
