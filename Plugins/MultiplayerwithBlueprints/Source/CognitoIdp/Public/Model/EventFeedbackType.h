/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/EventFeedbackType.h"

#endif

#include "Model/FeedbackValueType.h"

#include "EventFeedbackType.generated.h"

USTRUCT(BlueprintType)
struct FEventFeedbackType {
GENERATED_BODY()

    /**
    *  <p>The event feedback value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EFeedbackValueType feedbackValue = EFeedbackValueType::NOT_SET;

    /**
    *  <p>The provider.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString provider;

    /**
    *  <p>The event feedback date.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime feedbackDate;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FEventFeedbackType &fromAWS(const Aws::CognitoIdentityProvider::Model::EventFeedbackType &awsEventFeedbackType) {
        switch(awsEventFeedbackType.GetFeedbackValue()) {
            case Aws::CognitoIdentityProvider::Model::FeedbackValueType::NOT_SET:
                this->feedbackValue = EFeedbackValueType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::FeedbackValueType::Valid:
                this->feedbackValue = EFeedbackValueType::Valid;
                break;
            case Aws::CognitoIdentityProvider::Model::FeedbackValueType::Invalid:
                this->feedbackValue = EFeedbackValueType::Invalid;
                break;
            default:
                this->feedbackValue = EFeedbackValueType::NOT_SET;
                break;
        }

        this->provider = UTF8_TO_TCHAR(awsEventFeedbackType.GetProvider().c_str());

        this->feedbackDate = FDateTime(1970, 1, 1) + FTimespan(awsEventFeedbackType.GetFeedbackDate().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
