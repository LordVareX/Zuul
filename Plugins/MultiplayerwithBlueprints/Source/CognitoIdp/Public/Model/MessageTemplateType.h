/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/MessageTemplateType.h"

#endif

#include "MessageTemplateType.generated.h"

USTRUCT(BlueprintType)
struct FMessageTemplateType {
GENERATED_BODY()

    /**
    *  <p>The message template for SMS messages.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString SMSMessage;

    /**
    *  <p>The message template for email messages.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString emailMessage;

    /**
    *  <p>The subject line for email messages.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString emailSubject;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::MessageTemplateType toAWS() const {
        Aws::CognitoIdentityProvider::Model::MessageTemplateType awsMessageTemplateType;

        if (!(this->SMSMessage.IsEmpty())) {
            awsMessageTemplateType.SetSMSMessage(TCHAR_TO_UTF8(*this->SMSMessage));
        }

        if (!(this->emailMessage.IsEmpty())) {
            awsMessageTemplateType.SetEmailMessage(TCHAR_TO_UTF8(*this->emailMessage));
        }

        if (!(this->emailSubject.IsEmpty())) {
            awsMessageTemplateType.SetEmailSubject(TCHAR_TO_UTF8(*this->emailSubject));
        }

        return awsMessageTemplateType;
    }

    bool IsEmpty() const {
        return this->SMSMessage.IsEmpty() && this->emailMessage.IsEmpty() && this->emailSubject.IsEmpty();
    }

    FMessageTemplateType &fromAWS(const Aws::CognitoIdentityProvider::Model::MessageTemplateType &awsMessageTemplateType) {
        this->SMSMessage = UTF8_TO_TCHAR(awsMessageTemplateType.GetSMSMessage().c_str());

        this->emailMessage = UTF8_TO_TCHAR(awsMessageTemplateType.GetEmailMessage().c_str());

        this->emailSubject = UTF8_TO_TCHAR(awsMessageTemplateType.GetEmailSubject().c_str());

        return *this;
    }
#endif
};
