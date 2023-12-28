/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SoftwareTokenMfaSettingsType.h"

#endif

#include "SoftwareTokenMfaSettingsType.generated.h"

USTRUCT(BlueprintType)
struct FSoftwareTokenMfaSettingsType {
GENERATED_BODY()

    /**
    *  <p>Specifies whether software token MFA is enabled.</p>
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
    Aws::CognitoIdentityProvider::Model::SoftwareTokenMfaSettingsType toAWS() const {
        Aws::CognitoIdentityProvider::Model::SoftwareTokenMfaSettingsType awsSoftwareTokenMfaSettingsType;

        if (this->enabled) {
            awsSoftwareTokenMfaSettingsType.SetEnabled(this->enabled);
        }

        if (!(false)) {
            awsSoftwareTokenMfaSettingsType.SetPreferredMfa(this->preferredMfa);
        }

        return awsSoftwareTokenMfaSettingsType;
    }

    bool IsEmpty() const {
        return !this->enabled;
    }
#endif
};
