/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AnalyticsConfigurationType.h"

#endif

#include "AnalyticsConfigurationType.generated.h"

USTRUCT(BlueprintType)
struct FAnalyticsConfigurationType {
GENERATED_BODY()

    /**
    *  <p>The application ID for an Amazon Pinpoint application.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString applicationId;

    /**
    *  <p>The Amazon Resource Name (ARN) of an Amazon Pinpoint project. You can use the Amazon Pinpoint project for Pinpoint integration with the chosen User Pool Client. Amazon Cognito publishes events to the pinpoint project declared by the app ARN.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString applicationArn;

    /**
    *  <p>The ARN of an IAM role that authorizes Amazon Cognito to publish events to Amazon Pinpoint analytics.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString roleArn;

    /**
    *  <p>The external ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString externalId;

    /**
    *  <p>If <code>UserDataShared</code> is <code>true</code>, Amazon Cognito will include user data in the events it publishes to Amazon Pinpoint analytics.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool userDataShared = false;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AnalyticsConfigurationType toAWS() const {
        Aws::CognitoIdentityProvider::Model::AnalyticsConfigurationType awsAnalyticsConfigurationType;

        if (!(this->applicationId.IsEmpty())) {
            awsAnalyticsConfigurationType.SetApplicationId(TCHAR_TO_UTF8(*this->applicationId));
        }

        if (!(this->applicationArn.IsEmpty())) {
            awsAnalyticsConfigurationType.SetApplicationArn(TCHAR_TO_UTF8(*this->applicationArn));
        }

        if (!(this->roleArn.IsEmpty())) {
            awsAnalyticsConfigurationType.SetRoleArn(TCHAR_TO_UTF8(*this->roleArn));
        }

        if (!(this->externalId.IsEmpty())) {
            awsAnalyticsConfigurationType.SetExternalId(TCHAR_TO_UTF8(*this->externalId));
        }

        if (!(false)) {
            awsAnalyticsConfigurationType.SetUserDataShared(this->userDataShared);
        }

        return awsAnalyticsConfigurationType;
    }

    bool IsEmpty() const {
        return this->applicationId.IsEmpty() && this->applicationArn.IsEmpty() && this->roleArn.IsEmpty() && this->externalId.IsEmpty() && false;
    }

    FAnalyticsConfigurationType &fromAWS(const Aws::CognitoIdentityProvider::Model::AnalyticsConfigurationType &awsAnalyticsConfigurationType) {
        this->applicationId = UTF8_TO_TCHAR(awsAnalyticsConfigurationType.GetApplicationId().c_str());

        this->applicationArn = UTF8_TO_TCHAR(awsAnalyticsConfigurationType.GetApplicationArn().c_str());

        this->roleArn = UTF8_TO_TCHAR(awsAnalyticsConfigurationType.GetRoleArn().c_str());

        this->externalId = UTF8_TO_TCHAR(awsAnalyticsConfigurationType.GetExternalId().c_str());

        this->userDataShared = awsAnalyticsConfigurationType.GetUserDataShared();

        return *this;
    }
#endif
};
