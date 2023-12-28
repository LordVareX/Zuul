/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CompromisedCredentialsActionsType.h"

#endif

#include "Model/CompromisedCredentialsEventActionType.h"

#include "CompromisedCredentialsActionsType.generated.h"

USTRUCT(BlueprintType)
struct FCompromisedCredentialsActionsType {
    GENERATED_BODY()

    /**
    *  <p>The event action.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    ECompromisedCredentialsEventActionType eventAction = ECompromisedCredentialsEventActionType::NOT_SET;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::CompromisedCredentialsActionsType toAWS() const {
        Aws::CognitoIdentityProvider::Model::CompromisedCredentialsActionsType awsCompromisedCredentialsActionsType;

        switch(this->eventAction) {
            case ECompromisedCredentialsEventActionType::BLOCK:
                awsCompromisedCredentialsActionsType.SetEventAction(Aws::CognitoIdentityProvider::Model::CompromisedCredentialsEventActionType::BLOCK);
                break;
            case ECompromisedCredentialsEventActionType::NO_ACTION:
                awsCompromisedCredentialsActionsType.SetEventAction(Aws::CognitoIdentityProvider::Model::CompromisedCredentialsEventActionType::NO_ACTION);
                break;
            default:
                break;
        };

        return awsCompromisedCredentialsActionsType;
    }

    bool IsEmpty() const {
        return this->eventAction == ECompromisedCredentialsEventActionType::NOT_SET;
    }

    FCompromisedCredentialsActionsType &fromAWS(const Aws::CognitoIdentityProvider::Model::CompromisedCredentialsActionsType &awsCompromisedCredentialsActionsType) {
        switch(awsCompromisedCredentialsActionsType.GetEventAction()) {
            case Aws::CognitoIdentityProvider::Model::CompromisedCredentialsEventActionType::NOT_SET:
                this->eventAction = ECompromisedCredentialsEventActionType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::CompromisedCredentialsEventActionType::BLOCK:
                this->eventAction = ECompromisedCredentialsEventActionType::BLOCK;
                break;
            case Aws::CognitoIdentityProvider::Model::CompromisedCredentialsEventActionType::NO_ACTION:
                this->eventAction = ECompromisedCredentialsEventActionType::NO_ACTION;
                break;
            default:
                this->eventAction = ECompromisedCredentialsEventActionType::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
