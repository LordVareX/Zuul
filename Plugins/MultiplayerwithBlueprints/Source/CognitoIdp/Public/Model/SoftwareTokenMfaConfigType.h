/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SoftwareTokenMfaConfigType.h"

#endif

#include "SoftwareTokenMfaConfigType.generated.h"

USTRUCT(BlueprintType)
struct FSoftwareTokenMfaConfigType {
    GENERATED_BODY()

    /**
    *  <p>Specifies whether software token MFA is enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool enabled = false;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::SoftwareTokenMfaConfigType toAWS() const {
        Aws::CognitoIdentityProvider::Model::SoftwareTokenMfaConfigType awsSoftwareTokenMfaConfigType;

        if (!(false)) {
            awsSoftwareTokenMfaConfigType.SetEnabled(this->enabled);
        }

        return awsSoftwareTokenMfaConfigType;
    }

    bool IsEmpty() const {
        return false;
    }

    FSoftwareTokenMfaConfigType &fromAWS(const Aws::CognitoIdentityProvider::Model::SoftwareTokenMfaConfigType &awsSoftwareTokenMfaConfigType) {
        this->enabled = awsSoftwareTokenMfaConfigType.GetEnabled();

        return *this;
    }
#endif
};
