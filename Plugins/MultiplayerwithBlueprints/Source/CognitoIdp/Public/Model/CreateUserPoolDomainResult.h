/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CreateUserPoolDomainResult.h"

#endif

#include "CreateUserPoolDomainResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateUserPoolDomainResult {
GENERATED_BODY()

    /**
    *  <p>The Amazon CloudFront endpoint that you use as the target of the alias that you set up with your Domain Name Service (DNS) provider.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString cloudFrontDomain;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FCreateUserPoolDomainResult &fromAWS(const Aws::CognitoIdentityProvider::Model::CreateUserPoolDomainResult &awsCreateUserPoolDomainResult) {
        this->cloudFrontDomain = UTF8_TO_TCHAR(awsCreateUserPoolDomainResult.GetCloudFrontDomain().c_str());

        return *this;
    }
#endif
};
