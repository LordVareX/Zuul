/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/VerificationMessageTemplateType.h"

#endif

#include "Model/DefaultEmailOptionType.h"

#include "VerificationMessageTemplateType.generated.h"

USTRUCT(BlueprintType)
struct FVerificationMessageTemplateType {
GENERATED_BODY()

    /**
    *  <p>The SMS message template.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString smsMessage;

    /**
    *  <p>The email message template.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString emailMessage;

    /**
    *  <p>The subject line for the email message template.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString emailSubject;

    /**
    *  <p>The email message template for sending a confirmation link to the user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString emailMessageByLink;

    /**
    *  <p>The subject line for the email message template for sending a confirmation link to the user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString emailSubjectByLink;

    /**
    *  <p>The default email option.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EDefaultEmailOptionType defaultEmailOption = EDefaultEmailOptionType::NOT_SET;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::VerificationMessageTemplateType toAWS() const {
        Aws::CognitoIdentityProvider::Model::VerificationMessageTemplateType awsVerificationMessageTemplateType;

        if (!(this->smsMessage.IsEmpty())) {
            awsVerificationMessageTemplateType.SetSmsMessage(TCHAR_TO_UTF8(*this->smsMessage));
        }

        if (!(this->emailMessage.IsEmpty())) {
            awsVerificationMessageTemplateType.SetEmailMessage(TCHAR_TO_UTF8(*this->emailMessage));
        }

        if (!(this->emailSubject.IsEmpty())) {
            awsVerificationMessageTemplateType.SetEmailSubject(TCHAR_TO_UTF8(*this->emailSubject));
        }

        if (!(this->emailMessageByLink.IsEmpty())) {
            awsVerificationMessageTemplateType.SetEmailMessageByLink(TCHAR_TO_UTF8(*this->emailMessageByLink));
        }

        if (!(this->emailSubjectByLink.IsEmpty())) {
            awsVerificationMessageTemplateType.SetEmailSubjectByLink(TCHAR_TO_UTF8(*this->emailSubjectByLink));
        }

        switch(this->defaultEmailOption) {
            case EDefaultEmailOptionType::CONFIRM_WITH_LINK:
                awsVerificationMessageTemplateType.SetDefaultEmailOption(Aws::CognitoIdentityProvider::Model::DefaultEmailOptionType::CONFIRM_WITH_LINK);
                break;
            case EDefaultEmailOptionType::CONFIRM_WITH_CODE:
                awsVerificationMessageTemplateType.SetDefaultEmailOption(Aws::CognitoIdentityProvider::Model::DefaultEmailOptionType::CONFIRM_WITH_CODE);
                break;
            default:
                break;
        }

        return awsVerificationMessageTemplateType;
    }

    bool IsEmpty() const {
        return this->smsMessage.IsEmpty() && this->emailMessage.IsEmpty() && this->emailSubject.IsEmpty() && this->emailMessageByLink.IsEmpty() && this->emailSubjectByLink.IsEmpty() && this->defaultEmailOption == EDefaultEmailOptionType::NOT_SET;
    }

    FVerificationMessageTemplateType &fromAWS(const Aws::CognitoIdentityProvider::Model::VerificationMessageTemplateType &awsVerificationMessageTemplateType) {
        this->smsMessage = UTF8_TO_TCHAR(awsVerificationMessageTemplateType.GetSmsMessage().c_str());

        this->emailMessage = UTF8_TO_TCHAR(awsVerificationMessageTemplateType.GetEmailMessage().c_str());

        this->emailSubject = UTF8_TO_TCHAR(awsVerificationMessageTemplateType.GetEmailSubject().c_str());

        this->emailMessageByLink = UTF8_TO_TCHAR(awsVerificationMessageTemplateType.GetEmailMessageByLink().c_str());

        this->emailSubjectByLink = UTF8_TO_TCHAR(awsVerificationMessageTemplateType.GetEmailSubjectByLink().c_str());

        switch(awsVerificationMessageTemplateType.GetDefaultEmailOption()) {
            case Aws::CognitoIdentityProvider::Model::DefaultEmailOptionType::NOT_SET:
                this->defaultEmailOption = EDefaultEmailOptionType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::DefaultEmailOptionType::CONFIRM_WITH_LINK:
                this->defaultEmailOption = EDefaultEmailOptionType::CONFIRM_WITH_LINK;
                break;
            case Aws::CognitoIdentityProvider::Model::DefaultEmailOptionType::CONFIRM_WITH_CODE:
                this->defaultEmailOption = EDefaultEmailOptionType::CONFIRM_WITH_CODE;
                break;
            default:
                this->defaultEmailOption = EDefaultEmailOptionType::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
