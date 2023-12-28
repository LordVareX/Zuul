/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AccountTakeoverActionsType.h"

#endif

#include "Model/AccountTakeoverActionType.h"

#include "AccountTakeoverActionsType.generated.h"

USTRUCT(BlueprintType)
struct FAccountTakeoverActionsType {
GENERATED_BODY()

    /**
    *  <p>Action to take for a low risk.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAccountTakeoverActionType lowAction;

    /**
    *  <p>Action to take for a medium risk.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAccountTakeoverActionType mediumAction;

    /**
    *  <p>Action to take for a high risk.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAccountTakeoverActionType highAction;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AccountTakeoverActionsType toAWS() const {
        Aws::CognitoIdentityProvider::Model::AccountTakeoverActionsType awsAccountTakeoverActionsType;

        if (!(this->lowAction.IsEmpty())) {
            awsAccountTakeoverActionsType.SetLowAction(this->lowAction.toAWS());
        }

        if (!(this->mediumAction.IsEmpty())) {
            awsAccountTakeoverActionsType.SetMediumAction(this->mediumAction.toAWS());
        }

        if (!(this->highAction.IsEmpty())) {
            awsAccountTakeoverActionsType.SetHighAction(this->highAction.toAWS());
        }

        return awsAccountTakeoverActionsType;
    }

    bool IsEmpty() const {
        return this->lowAction.IsEmpty() && this->mediumAction.IsEmpty() && this->highAction.IsEmpty();
    }

    FAccountTakeoverActionsType &fromAWS(const Aws::CognitoIdentityProvider::Model::AccountTakeoverActionsType &awsAccountTakeoverActionsType) {
        this->lowAction.fromAWS(awsAccountTakeoverActionsType.GetLowAction());

        this->mediumAction.fromAWS(awsAccountTakeoverActionsType.GetMediumAction());

        this->highAction.fromAWS(awsAccountTakeoverActionsType.GetHighAction());

        return *this;
    }
#endif
};
