/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GetSigningCertificateResult.h"

#endif

#include "GetSigningCertificateResult.generated.h"

USTRUCT(BlueprintType)
struct FGetSigningCertificateResult {
GENERATED_BODY()

    /**
    *  <p>The signing certificate.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString certificate;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FGetSigningCertificateResult &fromAWS(const Aws::CognitoIdentityProvider::Model::GetSigningCertificateResult &awsGetSigningCertificateResult) {
        this->certificate = UTF8_TO_TCHAR(awsGetSigningCertificateResult.GetCertificate().c_str());

        return *this;
    }
#endif
};
