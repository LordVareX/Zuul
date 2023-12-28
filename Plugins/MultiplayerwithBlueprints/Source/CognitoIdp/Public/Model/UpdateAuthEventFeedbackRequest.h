/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UpdateAuthEventFeedbackRequest.h"

#endif

#include "Model/FeedbackValueType.h"

#include "UpdateAuthEventFeedbackRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateAuthEventFeedbackRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The user pool username.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    *  <p>The event ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString eventId;

    /**
    *  <p>The feedback token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString feedbackToken;

    /**
    *  <p>The authentication event feedback value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EFeedbackValueType feedbackValue = EFeedbackValueType::NOT_SET;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::UpdateAuthEventFeedbackRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::UpdateAuthEventFeedbackRequest awsUpdateAuthEventFeedbackRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsUpdateAuthEventFeedbackRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsUpdateAuthEventFeedbackRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        if (!(this->eventId.IsEmpty())) {
            awsUpdateAuthEventFeedbackRequest.SetEventId(TCHAR_TO_UTF8(*this->eventId));
        }

        if (!(this->feedbackToken.IsEmpty())) {
            awsUpdateAuthEventFeedbackRequest.SetFeedbackToken(TCHAR_TO_UTF8(*this->feedbackToken));
        }

        switch(this->feedbackValue) {
            case EFeedbackValueType::Valid:
                awsUpdateAuthEventFeedbackRequest.SetFeedbackValue(Aws::CognitoIdentityProvider::Model::FeedbackValueType::Valid);
                break;
            case EFeedbackValueType::Invalid:
                awsUpdateAuthEventFeedbackRequest.SetFeedbackValue(Aws::CognitoIdentityProvider::Model::FeedbackValueType::Invalid);
                break;
            default:
                break;
        }

        return awsUpdateAuthEventFeedbackRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty() && this->eventId.IsEmpty() && this->feedbackToken.IsEmpty() && this->feedbackValue == EFeedbackValueType::NOT_SET;
    }
#endif
};
