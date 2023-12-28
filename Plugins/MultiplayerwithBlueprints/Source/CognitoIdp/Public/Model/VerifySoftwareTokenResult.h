/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/VerifySoftwareTokenResult.h"

#endif

#include "Model/VerifySoftwareTokenResponseType.h"

#include "VerifySoftwareTokenResult.generated.h"

USTRUCT(BlueprintType)
struct FVerifySoftwareTokenResult {
GENERATED_BODY()

    /**
    *  <p>The status of the verify software token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EVerifySoftwareTokenResponseType status = EVerifySoftwareTokenResponseType::NOT_SET;

    /**
    *  <p>The session which should be passed both ways in challenge-response calls to the service.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString session;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FVerifySoftwareTokenResult &fromAWS(const Aws::CognitoIdentityProvider::Model::VerifySoftwareTokenResult &awsVerifySoftwareTokenResult) {
        switch(awsVerifySoftwareTokenResult.GetStatus()) {
            case Aws::CognitoIdentityProvider::Model::VerifySoftwareTokenResponseType::NOT_SET:
                this->status = EVerifySoftwareTokenResponseType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::VerifySoftwareTokenResponseType::SUCCESS:
                this->status = EVerifySoftwareTokenResponseType::SUCCESS;
                break;
            case Aws::CognitoIdentityProvider::Model::VerifySoftwareTokenResponseType::ERROR_:
                this->status = EVerifySoftwareTokenResponseType::ERROR_;
                break;
            default:
                this->status = EVerifySoftwareTokenResponseType::NOT_SET;
                break;
        }

        this->session = UTF8_TO_TCHAR(awsVerifySoftwareTokenResult.GetSession().c_str());

        return *this;
    }
#endif
};
