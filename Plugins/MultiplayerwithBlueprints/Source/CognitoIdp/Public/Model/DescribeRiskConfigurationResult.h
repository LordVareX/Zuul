/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DescribeRiskConfigurationResult.h"

#endif

#include "Model/RiskConfigurationType.h"

#include "DescribeRiskConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeRiskConfigurationResult {
GENERATED_BODY()

    /**
    *  <p>The risk configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FRiskConfigurationType riskConfiguration;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FDescribeRiskConfigurationResult &fromAWS(const Aws::CognitoIdentityProvider::Model::DescribeRiskConfigurationResult &awsDescribeRiskConfigurationResult) {
        this->riskConfiguration.fromAWS(awsDescribeRiskConfigurationResult.GetRiskConfiguration());

        return *this;
    }
#endif
};
