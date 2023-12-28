/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/NotifyConfigurationType.h"

#endif

#include "Model/NotifyEmailType.h"

#include "NotifyConfigurationType.generated.h"

USTRUCT(BlueprintType)
struct FNotifyConfigurationType {
GENERATED_BODY()

    /**
    *  <p>The email address that is sending the email. It must be either individually verified with Amazon SES, or from a domain that has been verified with Amazon SES.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString from;

    /**
    *  <p>The destination to which the receiver of an email should reply to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString replyTo;

    /**
    *  <p>The Amazon Resource Name (ARN) of the identity that is associated with the sending authorization policy. It permits Amazon Cognito to send for the email address specified in the <code>From</code> parameter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString sourceArn;

    /**
    *  <p>Email template used when a detected risk event is blocked.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FNotifyEmailType blockEmail;

    /**
    *  <p>The email template used when a detected risk event is allowed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FNotifyEmailType noActionEmail;

    /**
    *  <p>The MFA email template used when MFA is challenged as part of a detected risk.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FNotifyEmailType mfaEmail;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::NotifyConfigurationType toAWS() const {
        Aws::CognitoIdentityProvider::Model::NotifyConfigurationType awsNotifyConfigurationType;

        if (!(this->from.IsEmpty())) {
            awsNotifyConfigurationType.SetFrom(TCHAR_TO_UTF8(*this->from));
        }

        if (!(this->replyTo.IsEmpty())) {
            awsNotifyConfigurationType.SetReplyTo(TCHAR_TO_UTF8(*this->replyTo));
        }

        if (!(this->sourceArn.IsEmpty())) {
            awsNotifyConfigurationType.SetSourceArn(TCHAR_TO_UTF8(*this->sourceArn));
        }

        if (!(this->blockEmail.IsEmpty())) {
            awsNotifyConfigurationType.SetBlockEmail(this->blockEmail.toAWS());
        }

        if (!(this->noActionEmail.IsEmpty())) {
            awsNotifyConfigurationType.SetNoActionEmail(this->noActionEmail.toAWS());
        }

        if (!(this->mfaEmail.IsEmpty())) {
            awsNotifyConfigurationType.SetMfaEmail(this->mfaEmail.toAWS());
        }

        return awsNotifyConfigurationType;
    }

    bool IsEmpty() const {
        return this->from.IsEmpty() && this->replyTo.IsEmpty() && this->sourceArn.IsEmpty() && this->blockEmail.IsEmpty() && this->noActionEmail.IsEmpty() && this->mfaEmail.IsEmpty();
    }

    FNotifyConfigurationType &fromAWS(const Aws::CognitoIdentityProvider::Model::NotifyConfigurationType &awsNotifyConfigurationType) {
        this->from = UTF8_TO_TCHAR(awsNotifyConfigurationType.GetFrom().c_str());

        this->replyTo = UTF8_TO_TCHAR(awsNotifyConfigurationType.GetReplyTo().c_str());

        this->sourceArn = UTF8_TO_TCHAR(awsNotifyConfigurationType.GetSourceArn().c_str());

        this->blockEmail.fromAWS(awsNotifyConfigurationType.GetBlockEmail());

        this->noActionEmail.fromAWS(awsNotifyConfigurationType.GetNoActionEmail());

        this->mfaEmail.fromAWS(awsNotifyConfigurationType.GetMfaEmail());

        return *this;
    }
#endif
};
