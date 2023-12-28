/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AuthEventType.h"

#endif

#include "Model/EventType.h"
#include "Model/EventResponseType.h"
#include "Model/EventRiskType.h"
#include "Model/ChallengeResponseType.h"
#include "Model/EventContextDataType.h"
#include "Model/EventFeedbackType.h"

#include "AuthEventType.generated.h"

USTRUCT(BlueprintType)
struct FAuthEventType {
GENERATED_BODY()

    /**
    *  <p>The event ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString eventId;

    /**
    *  <p>The event type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EEventType eventType = EEventType::NOT_SET;

    /**
    *  <p>The creation date</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime creationDate;

    /**
    *  <p>The event response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EEventResponseType eventResponse = EEventResponseType::NOT_SET;

    /**
    *  <p>The event risk.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FEventRiskType eventRisk;

    /**
    *  <p>The challenge responses.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FChallengeResponseType> challengeResponses;

    /**
    *  <p>The user context data captured at the time of an event request. It provides additional information about the client from which event the request is received.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FEventContextDataType eventContextData;

    /**
    *  <p>A flag specifying the user feedback captured at the time of an event request is good or bad. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FEventFeedbackType eventFeedback;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAuthEventType &fromAWS(const Aws::CognitoIdentityProvider::Model::AuthEventType &awsAuthEventType) {
        this->eventId = UTF8_TO_TCHAR(awsAuthEventType.GetEventId().c_str());

        switch(awsAuthEventType.GetEventType()) {
            case Aws::CognitoIdentityProvider::Model::EventType::NOT_SET:
                this->eventType = EEventType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::EventType::SignIn:
                this->eventType = EEventType::SignIn;
                break;
            case Aws::CognitoIdentityProvider::Model::EventType::SignUp:
                this->eventType = EEventType::SignUp;
                break;
            case Aws::CognitoIdentityProvider::Model::EventType::ForgotPassword:
                this->eventType = EEventType::ForgotPassword;
                break;
            case Aws::CognitoIdentityProvider::Model::EventType::PasswordChange:
                this->eventType = EEventType::PasswordChange;
                break;
            case Aws::CognitoIdentityProvider::Model::EventType::ResendCode:
                this->eventType = EEventType::ResendCode;
                break;
            default:
                this->eventType = EEventType::NOT_SET;
                break;
        }

        this->creationDate = FDateTime(1970, 1, 1) + FTimespan(awsAuthEventType.GetCreationDate().Millis() * ETimespan::TicksPerMillisecond);

        switch(awsAuthEventType.GetEventResponse()) {
            case Aws::CognitoIdentityProvider::Model::EventResponseType::NOT_SET:
                this->eventResponse = EEventResponseType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::EventResponseType::Pass:
                this->eventResponse = EEventResponseType::Pass;
                break;
            case Aws::CognitoIdentityProvider::Model::EventResponseType::Fail:
                this->eventResponse = EEventResponseType::Fail;
                break;
            case Aws::CognitoIdentityProvider::Model::EventResponseType::InProgress:
                this->eventResponse = EEventResponseType::InProgress;
                break;
            default:
                this->eventResponse = EEventResponseType::NOT_SET;
                break;
        }

        this->eventRisk.fromAWS(awsAuthEventType.GetEventRisk());

        this->challengeResponses.Empty();
        for (const Aws::CognitoIdentityProvider::Model::ChallengeResponseType& elem : awsAuthEventType.GetChallengeResponses()) {
            this->challengeResponses.Add(FChallengeResponseType().fromAWS(elem));
        }

        this->eventContextData.fromAWS(awsAuthEventType.GetEventContextData());

        this->eventFeedback.fromAWS(awsAuthEventType.GetEventFeedback());

        return *this;
    }
#endif
};
