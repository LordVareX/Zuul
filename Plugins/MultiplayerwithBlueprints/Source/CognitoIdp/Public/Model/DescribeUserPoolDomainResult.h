/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DescribeUserPoolDomainResult.h"

#endif

#include "Model/DomainDescriptionType.h"

#include "DescribeUserPoolDomainResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeUserPoolDomainResult {
GENERATED_BODY()

    /**
    *  <p>A domain description object containing information about the domain.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDomainDescriptionType domainDescription;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FDescribeUserPoolDomainResult &fromAWS(const Aws::CognitoIdentityProvider::Model::DescribeUserPoolDomainResult &awsDescribeUserPoolDomainResult) {
        this->domainDescription.fromAWS(awsDescribeUserPoolDomainResult.GetDomainDescription());

        return *this;
    }
#endif
};
