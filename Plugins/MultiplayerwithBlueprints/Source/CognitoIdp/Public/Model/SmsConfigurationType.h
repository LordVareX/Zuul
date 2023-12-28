/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SmsConfigurationType.h"

#endif

#include "SmsConfigurationType.generated.h"

USTRUCT(BlueprintType)
struct FSmsConfigurationType {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the Amazon Simple Notification Service (SNS) caller.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString snsCallerArn;

    /**
    *  <p>The external ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString externalId;

    /**
    *  <p>The Amazon Web Services Region to use with Amazon SNS integration. You can choose the same Region as your user pool, or a supported <b>Legacy Amazon SNS alternate Region</b>. </p> <p> Amazon Cognito resources in the Asia Pacific (Seoul) Amazon Web Services Region must use your Amazon SNS configuration in the Asia Pacific (Tokyo) Region. For more information, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/user-pool-sms-settings.html">SMS message settings for Amazon Cognito user pools</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString snsRegion;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::SmsConfigurationType toAWS() const {
        Aws::CognitoIdentityProvider::Model::SmsConfigurationType awsSmsConfigurationType;

        if (!(this->snsCallerArn.IsEmpty())) {
            awsSmsConfigurationType.SetSnsCallerArn(TCHAR_TO_UTF8(*this->snsCallerArn));
        }

        if (!(this->externalId.IsEmpty())) {
            awsSmsConfigurationType.SetExternalId(TCHAR_TO_UTF8(*this->externalId));
        }


		if (!(this->snsRegion.IsEmpty())) {
            awsSmsConfigurationType.SetSnsRegion(TCHAR_TO_UTF8(*this->snsRegion));
        }

        return awsSmsConfigurationType;
    }

    bool IsEmpty() const {
        return this->snsCallerArn.IsEmpty() && this->externalId.IsEmpty() && this->snsRegion.IsEmpty();
    }

    FSmsConfigurationType &fromAWS(const Aws::CognitoIdentityProvider::Model::SmsConfigurationType &awsSmsConfigurationType) {
        this->snsCallerArn = UTF8_TO_TCHAR(awsSmsConfigurationType.GetSnsCallerArn().c_str());

        this->externalId = UTF8_TO_TCHAR(awsSmsConfigurationType.GetExternalId().c_str());

        this->snsRegion = UTF8_TO_TCHAR(awsSmsConfigurationType.GetSnsRegion().c_str());

        return *this;
    }
#endif
};
