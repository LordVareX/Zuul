/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AccountTakeoverActionType.h"

#endif

#include "Model/AccountTakeoverEventActionType.h"

#include "AccountTakeoverActionType.generated.h"

USTRUCT(BlueprintType)
struct FAccountTakeoverActionType {
GENERATED_BODY()

    /**
    *  <p>Flag specifying whether to send a notification.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool notify = false;

    /**
    *  <p>The event action.</p> <ul> <li> <p> <code>BLOCK</code> Choosing this action will block the request.</p> </li> <li> <p> <code>MFA_IF_CONFIGURED</code> Throw MFA challenge if user has configured it, else allow the request.</p> </li> <li> <p> <code>MFA_REQUIRED</code> Throw MFA challenge if user has configured it, else block the request.</p> </li> <li> <p> <code>NO_ACTION</code> Allow the user sign-in.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EAccountTakeoverEventActionType eventAction = EAccountTakeoverEventActionType::NOT_SET;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AccountTakeoverActionType toAWS() const {
        Aws::CognitoIdentityProvider::Model::AccountTakeoverActionType awsAccountTakeoverActionType;

        if (!(false)) {
            awsAccountTakeoverActionType.SetNotify(this->notify);
        }

        switch(this->eventAction) {
            case EAccountTakeoverEventActionType::BLOCK:
                awsAccountTakeoverActionType.SetEventAction(Aws::CognitoIdentityProvider::Model::AccountTakeoverEventActionType::BLOCK);
                break;
            case EAccountTakeoverEventActionType::MFA_IF_CONFIGURED:
                awsAccountTakeoverActionType.SetEventAction(Aws::CognitoIdentityProvider::Model::AccountTakeoverEventActionType::MFA_IF_CONFIGURED);
                break;
            case EAccountTakeoverEventActionType::MFA_REQUIRED:
                awsAccountTakeoverActionType.SetEventAction(Aws::CognitoIdentityProvider::Model::AccountTakeoverEventActionType::MFA_REQUIRED);
                break;
            case EAccountTakeoverEventActionType::NO_ACTION:
                awsAccountTakeoverActionType.SetEventAction(Aws::CognitoIdentityProvider::Model::AccountTakeoverEventActionType::NO_ACTION);
                break;
            default:
                break;
        }

        return awsAccountTakeoverActionType;
    }

    bool IsEmpty() const {
        return false && this->eventAction == EAccountTakeoverEventActionType::NOT_SET;
    }

    FAccountTakeoverActionType &fromAWS(const Aws::CognitoIdentityProvider::Model::AccountTakeoverActionType &awsAccountTakeoverActionType) {
        this->notify = awsAccountTakeoverActionType.GetNotify();

        switch(awsAccountTakeoverActionType.GetEventAction()) {
            case Aws::CognitoIdentityProvider::Model::AccountTakeoverEventActionType::NOT_SET:
                this->eventAction = EAccountTakeoverEventActionType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::AccountTakeoverEventActionType::BLOCK:
                this->eventAction = EAccountTakeoverEventActionType::BLOCK;
                break;
            case Aws::CognitoIdentityProvider::Model::AccountTakeoverEventActionType::MFA_IF_CONFIGURED:
                this->eventAction = EAccountTakeoverEventActionType::MFA_IF_CONFIGURED;
                break;
            case Aws::CognitoIdentityProvider::Model::AccountTakeoverEventActionType::MFA_REQUIRED:
                this->eventAction = EAccountTakeoverEventActionType::MFA_REQUIRED;
                break;
            case Aws::CognitoIdentityProvider::Model::AccountTakeoverEventActionType::NO_ACTION:
                this->eventAction = EAccountTakeoverEventActionType::NO_ACTION;
                break;
            default:
                this->eventAction = EAccountTakeoverEventActionType::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
