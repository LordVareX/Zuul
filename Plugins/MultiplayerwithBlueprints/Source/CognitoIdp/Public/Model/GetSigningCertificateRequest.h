/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GetSigningCertificateRequest.h"

#endif

#include "GetSigningCertificateRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetSigningCertificateRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::GetSigningCertificateRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::GetSigningCertificateRequest awsGetSigningCertificateRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsGetSigningCertificateRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        return awsGetSigningCertificateRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty();
    }
#endif
};
