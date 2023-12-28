/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/EventRiskType.h"

#endif

#include "Model/RiskDecisionType.h"
#include "Model/RiskLevelType.h"

#include "EventRiskType.generated.h"

USTRUCT(BlueprintType)
struct FEventRiskType {
GENERATED_BODY()

    /**
    *  <p>The risk decision.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    ERiskDecisionType riskDecision = ERiskDecisionType::NOT_SET;

    /**
    *  <p>The risk level.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    ERiskLevelType riskLevel = ERiskLevelType::NOT_SET;

    /**
    *  <p>Indicates whether compromised credentials were detected during an authentication event.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool compromisedCredentialsDetected = false;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FEventRiskType &fromAWS(const Aws::CognitoIdentityProvider::Model::EventRiskType &awsEventRiskType) {
        switch(awsEventRiskType.GetRiskDecision()) {
            case Aws::CognitoIdentityProvider::Model::RiskDecisionType::NOT_SET:
                this->riskDecision = ERiskDecisionType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::RiskDecisionType::NoRisk:
                this->riskDecision = ERiskDecisionType::NoRisk;
                break;
            case Aws::CognitoIdentityProvider::Model::RiskDecisionType::AccountTakeover:
                this->riskDecision = ERiskDecisionType::AccountTakeover;
                break;
            case Aws::CognitoIdentityProvider::Model::RiskDecisionType::Block:
                this->riskDecision = ERiskDecisionType::Block;
                break;
            default:
                this->riskDecision = ERiskDecisionType::NOT_SET;
                break;
        }

        switch(awsEventRiskType.GetRiskLevel()) {
            case Aws::CognitoIdentityProvider::Model::RiskLevelType::NOT_SET:
                this->riskLevel = ERiskLevelType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::RiskLevelType::Low:
                this->riskLevel = ERiskLevelType::Low;
                break;
            case Aws::CognitoIdentityProvider::Model::RiskLevelType::Medium:
                this->riskLevel = ERiskLevelType::Medium;
                break;
            case Aws::CognitoIdentityProvider::Model::RiskLevelType::High:
                this->riskLevel = ERiskLevelType::High;
                break;
            default:
                this->riskLevel = ERiskLevelType::NOT_SET;
                break;
        }

        this->compromisedCredentialsDetected = awsEventRiskType.GetCompromisedCredentialsDetected();

        return *this;
    }
#endif
};
