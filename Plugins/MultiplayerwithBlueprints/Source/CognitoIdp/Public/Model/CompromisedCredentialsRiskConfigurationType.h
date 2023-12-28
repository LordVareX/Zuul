/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CompromisedCredentialsRiskConfigurationType.h"

#endif

#include "Model/EventFilterType.h"
#include "Model/CompromisedCredentialsActionsType.h"

#include "CompromisedCredentialsRiskConfigurationType.generated.h"

USTRUCT(BlueprintType)
struct FCompromisedCredentialsRiskConfigurationType {
GENERATED_BODY()

    /**
    *  <p>Perform the action for these events. The default is to perform all events if no event filter is specified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<EEventFilterType> eventFilter;

    /**
    *  <p>The compromised credentials risk configuration actions.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FCompromisedCredentialsActionsType actions;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::CompromisedCredentialsRiskConfigurationType toAWS() const {
        Aws::CognitoIdentityProvider::Model::CompromisedCredentialsRiskConfigurationType awsCompromisedCredentialsRiskConfigurationType;

        for (const EEventFilterType& elem : this->eventFilter) {
            switch(elem) {
                case EEventFilterType::SIGN_IN:
                    awsCompromisedCredentialsRiskConfigurationType.AddEventFilter(Aws::CognitoIdentityProvider::Model::EventFilterType::SIGN_IN);
                    break;
                case EEventFilterType::PASSWORD_CHANGE:
                    awsCompromisedCredentialsRiskConfigurationType.AddEventFilter(Aws::CognitoIdentityProvider::Model::EventFilterType::PASSWORD_CHANGE);
                    break;
                case EEventFilterType::SIGN_UP:
                    awsCompromisedCredentialsRiskConfigurationType.AddEventFilter(Aws::CognitoIdentityProvider::Model::EventFilterType::SIGN_UP);
                    break;
                default:
                    break;
            };
        }

        if (!(this->actions.IsEmpty())) {
            awsCompromisedCredentialsRiskConfigurationType.SetActions(this->actions.toAWS());
        }

        return awsCompromisedCredentialsRiskConfigurationType;
    }

    bool IsEmpty() const {
        return this->eventFilter.Num() == 0 && this->actions.IsEmpty();
    }

    FCompromisedCredentialsRiskConfigurationType &fromAWS(const Aws::CognitoIdentityProvider::Model::CompromisedCredentialsRiskConfigurationType &awsCompromisedCredentialsRiskConfigurationType) {
        this->eventFilter.Empty();
        for (const Aws::CognitoIdentityProvider::Model::EventFilterType& elem : awsCompromisedCredentialsRiskConfigurationType.GetEventFilter()) {
            switch(elem) {
                case Aws::CognitoIdentityProvider::Model::EventFilterType::NOT_SET:
                    this->eventFilter.Add(EEventFilterType::NOT_SET);
                    break;
                case Aws::CognitoIdentityProvider::Model::EventFilterType::SIGN_IN:
                    this->eventFilter.Add(EEventFilterType::SIGN_IN);
                    break;
                case Aws::CognitoIdentityProvider::Model::EventFilterType::PASSWORD_CHANGE:
                    this->eventFilter.Add(EEventFilterType::PASSWORD_CHANGE);
                    break;
                case Aws::CognitoIdentityProvider::Model::EventFilterType::SIGN_UP:
                    this->eventFilter.Add(EEventFilterType::SIGN_UP);
                    break;
                default:
                   this->eventFilter.Add(EEventFilterType::NOT_SET);
                   break;
            };
        }

        this->actions.fromAWS(awsCompromisedCredentialsRiskConfigurationType.GetActions());

        return *this;
    }
#endif
};
