/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UpdateUserPoolDomainResult.h"

#endif

#include "UpdateUserPoolDomainResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateUserPoolDomainResult {
GENERATED_BODY()

    /**
    *  <p>The Amazon CloudFront endpoint that Amazon Cognito set up when you added the custom domain to your user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString cloudFrontDomain;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FUpdateUserPoolDomainResult &fromAWS(const Aws::CognitoIdentityProvider::Model::UpdateUserPoolDomainResult &awsUpdateUserPoolDomainResult) {
        this->cloudFrontDomain = UTF8_TO_TCHAR(awsUpdateUserPoolDomainResult.GetCloudFrontDomain().c_str());

        return *this;
    }
#endif
};
