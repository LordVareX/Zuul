/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/NotifyEmailType.h"

#endif

#include "NotifyEmailType.generated.h"

USTRUCT(BlueprintType)
struct FNotifyEmailType {
GENERATED_BODY()

    /**
    *  <p>The subject.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString subject;

    /**
    *  <p>The HTML body.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString htmlBody;

    /**
    *  <p>The text body.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString textBody;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::NotifyEmailType toAWS() const {
        Aws::CognitoIdentityProvider::Model::NotifyEmailType awsNotifyEmailType;

        if (!(this->subject.IsEmpty())) {
            awsNotifyEmailType.SetSubject(TCHAR_TO_UTF8(*this->subject));
        }

        if (!(this->htmlBody.IsEmpty())) {
            awsNotifyEmailType.SetHtmlBody(TCHAR_TO_UTF8(*this->htmlBody));
        }

        if (!(this->textBody.IsEmpty())) {
            awsNotifyEmailType.SetTextBody(TCHAR_TO_UTF8(*this->textBody));
        }

        return awsNotifyEmailType;
    }

    bool IsEmpty() const {
        return this->subject.IsEmpty() && this->htmlBody.IsEmpty() && this->textBody.IsEmpty();
    }

    FNotifyEmailType &fromAWS(const Aws::CognitoIdentityProvider::Model::NotifyEmailType &awsNotifyEmailType) {
        this->subject = UTF8_TO_TCHAR(awsNotifyEmailType.GetSubject().c_str());

        this->htmlBody = UTF8_TO_TCHAR(awsNotifyEmailType.GetHtmlBody().c_str());

        this->textBody = UTF8_TO_TCHAR(awsNotifyEmailType.GetTextBody().c_str());

        return *this;
    }
#endif
};
