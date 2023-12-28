/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CustomDomainConfigType.h"

#endif

#include "CustomDomainConfigType.generated.h"

USTRUCT(BlueprintType)
struct FCustomDomainConfigType {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of an AWS Certificate Manager SSL certificate. You use this certificate for the subdomain of your custom domain.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString certificateArn;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::CustomDomainConfigType toAWS() const {
        Aws::CognitoIdentityProvider::Model::CustomDomainConfigType awsCustomDomainConfigType;

        if (!(this->certificateArn.IsEmpty())) {
            awsCustomDomainConfigType.SetCertificateArn(TCHAR_TO_UTF8(*this->certificateArn));
        }

        return awsCustomDomainConfigType;
    }

    bool IsEmpty() const {
        return this->certificateArn.IsEmpty();
    }
    FCustomDomainConfigType &fromAWS(const Aws::CognitoIdentityProvider::Model::CustomDomainConfigType &awsCustomDomainConfigType) {
        this->certificateArn = UTF8_TO_TCHAR(awsCustomDomainConfigType.GetCertificateArn().c_str());

        return *this;
    }
#endif
};
