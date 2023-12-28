/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DescribeUserPoolDomainRequest.h"

#endif

#include "DescribeUserPoolDomainRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeUserPoolDomainRequest {
GENERATED_BODY()

    /**
    *  <p>The domain string.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString domain;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::DescribeUserPoolDomainRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::DescribeUserPoolDomainRequest awsDescribeUserPoolDomainRequest;

        if (!(this->domain.IsEmpty())) {
            awsDescribeUserPoolDomainRequest.SetDomain(TCHAR_TO_UTF8(*this->domain));
        }

        return awsDescribeUserPoolDomainRequest;
    }

    bool IsEmpty() const {
        return this->domain.IsEmpty();
    }
#endif
};
