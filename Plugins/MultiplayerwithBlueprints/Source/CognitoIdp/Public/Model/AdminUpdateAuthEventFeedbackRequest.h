/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminUpdateAuthEventFeedbackRequest.h"

#endif

#include "Model/FeedbackValueType.h"

#include "AdminUpdateAuthEventFeedbackRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminUpdateAuthEventFeedbackRequest {
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
    *  <p>The authentication event ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString eventId;

    /**
    *  <p>The authentication event feedback value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EFeedbackValueType feedbackValue = EFeedbackValueType::NOT_SET;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminUpdateAuthEventFeedbackRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminUpdateAuthEventFeedbackRequest awsAdminUpdateAuthEventFeedbackRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminUpdateAuthEventFeedbackRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminUpdateAuthEventFeedbackRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        if (!(this->eventId.IsEmpty())) {
            awsAdminUpdateAuthEventFeedbackRequest.SetEventId(TCHAR_TO_UTF8(*this->eventId));
        }

        switch(this->feedbackValue) {
            case EFeedbackValueType::Valid:
                awsAdminUpdateAuthEventFeedbackRequest.SetFeedbackValue(Aws::CognitoIdentityProvider::Model::FeedbackValueType::Valid);
                break;
            case EFeedbackValueType::Invalid:
                awsAdminUpdateAuthEventFeedbackRequest.SetFeedbackValue(Aws::CognitoIdentityProvider::Model::FeedbackValueType::Invalid);
                break;
            default:
                break;
        }

        return awsAdminUpdateAuthEventFeedbackRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty() && this->eventId.IsEmpty() && this->feedbackValue == EFeedbackValueType::NOT_SET;
    }
#endif
};
