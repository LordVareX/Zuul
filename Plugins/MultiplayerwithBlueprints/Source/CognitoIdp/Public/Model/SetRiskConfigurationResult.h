/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SetRiskConfigurationResult.h"

#endif

#include "Model/RiskConfigurationType.h"

#include "SetRiskConfigurationResult.generated.h"

USTRUCT(BlueprintType)
struct FSetRiskConfigurationResult {
    GENERATED_BODY()

    /**
    *  <p>The risk configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FRiskConfigurationType riskConfiguration;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FSetRiskConfigurationResult &fromAWS(const Aws::CognitoIdentityProvider::Model::SetRiskConfigurationResult &awsSetRiskConfigurationResult) {
        this->riskConfiguration.fromAWS(awsSetRiskConfigurationResult.GetRiskConfiguration());

        return *this;
    }
#endif
};
