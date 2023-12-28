/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AccountTakeoverRiskConfigurationType.h"

#endif

#include "Model/NotifyConfigurationType.h"
#include "Model/AccountTakeoverActionsType.h"

#include "AccountTakeoverRiskConfigurationType.generated.h"

USTRUCT(BlueprintType)
struct FAccountTakeoverRiskConfigurationType {
GENERATED_BODY()

    /**
    *  <p>The notify configuration used to construct email notifications.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FNotifyConfigurationType notifyConfiguration;

    /**
    *  <p>Account takeover risk configuration actions</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAccountTakeoverActionsType actions;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AccountTakeoverRiskConfigurationType toAWS() const {
        Aws::CognitoIdentityProvider::Model::AccountTakeoverRiskConfigurationType awsAccountTakeoverRiskConfigurationType;

        if (!(this->notifyConfiguration.IsEmpty())) {
            awsAccountTakeoverRiskConfigurationType.SetNotifyConfiguration(this->notifyConfiguration.toAWS());
        }

        if (!(this->actions.IsEmpty())) {
            awsAccountTakeoverRiskConfigurationType.SetActions(this->actions.toAWS());
        }

        return awsAccountTakeoverRiskConfigurationType;
    }

    bool IsEmpty() const {
        return this->notifyConfiguration.IsEmpty() && this->actions.IsEmpty();
    }

    FAccountTakeoverRiskConfigurationType &fromAWS(const Aws::CognitoIdentityProvider::Model::AccountTakeoverRiskConfigurationType &awsAccountTakeoverRiskConfigurationType) {
        this->notifyConfiguration.fromAWS(awsAccountTakeoverRiskConfigurationType.GetNotifyConfiguration());

        this->actions.fromAWS(awsAccountTakeoverRiskConfigurationType.GetActions());

        return *this;
    }
#endif
};
