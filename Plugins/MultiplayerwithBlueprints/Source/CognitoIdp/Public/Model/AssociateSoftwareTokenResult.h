/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AssociateSoftwareTokenResult.h"

#endif

#include "AssociateSoftwareTokenResult.generated.h"

USTRUCT(BlueprintType)
struct FAssociateSoftwareTokenResult {
GENERATED_BODY()

    /**
    *  <p>A unique generated shared secret code that is used in the TOTP algorithm to generate a one time code.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString secretCode;

    /**
    *  <p>The session which should be passed both ways in challenge-response calls to the service. This allows authentication of the user as part of the MFA setup process.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString session;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAssociateSoftwareTokenResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AssociateSoftwareTokenResult &awsAssociateSoftwareTokenResult) {
        this->secretCode = UTF8_TO_TCHAR(awsAssociateSoftwareTokenResult.GetSecretCode().c_str());

        this->session = UTF8_TO_TCHAR(awsAssociateSoftwareTokenResult.GetSession().c_str());

        return *this;
    }
#endif
};
