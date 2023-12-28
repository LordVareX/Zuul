/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SMSMfaSettingsType.h"

#endif

#include "SMSMfaSettingsType.generated.h"

USTRUCT(BlueprintType)
struct FSMSMfaSettingsType {
GENERATED_BODY()

    /**
    *  <p>Specifies whether SMS text message MFA is enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool enabled = false;

    /**
    *  <p>The preferred MFA method.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool preferredMfa = false;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::SMSMfaSettingsType toAWS() const {
        Aws::CognitoIdentityProvider::Model::SMSMfaSettingsType awsSMSMfaSettingsType;

        if (this->enabled) {
            awsSMSMfaSettingsType.SetEnabled(this->enabled);
        }

        if (!(false)) {
            awsSMSMfaSettingsType.SetPreferredMfa(this->preferredMfa);
        }

        return awsSMSMfaSettingsType;
    }

    bool IsEmpty() const {
        return !this->enabled;
    }
#endif
};
