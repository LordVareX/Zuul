/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CustomEmailLambdaVersionConfigType.h"

#endif

#include "Model/AWSCognitoIdpCustomEmailSenderLambdaVersionType.h"

#include "AWSCognitoIdpCustomEmailLambdaVersionConfigType.generated.h"

USTRUCT(BlueprintType)
struct FAWSCognitoIdpCustomEmailLambdaVersionConfigType {
GENERATED_BODY()

    /**
    *  <p>The Lambda version represents the signature of the "request" attribute in the "event" information Amazon Cognito passes to your custom email Lambda function. The only supported value is <code>V1_0</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EAWSCognitoIdpCustomEmailSenderLambdaVersionType lambdaVersion = EAWSCognitoIdpCustomEmailSenderLambdaVersionType::NOT_SET;

    /**
    *  <p>The Lambda Amazon Resource Name of the Lambda function that Amazon Cognito triggers to send email notifications to users.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString lambdaArn;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::CustomEmailLambdaVersionConfigType toAWS() const {
        Aws::CognitoIdentityProvider::Model::CustomEmailLambdaVersionConfigType awsCustomEmailLambdaVersionConfigType;

        switch(this->lambdaVersion) {
            case EAWSCognitoIdpCustomEmailSenderLambdaVersionType::V1_0:
                awsCustomEmailLambdaVersionConfigType.SetLambdaVersion(Aws::CognitoIdentityProvider::Model::CustomEmailSenderLambdaVersionType::V1_0);
                break;
            default:
                break;
        }

        if (!(this->lambdaArn.IsEmpty())) {
            awsCustomEmailLambdaVersionConfigType.SetLambdaArn(TCHAR_TO_UTF8(*this->lambdaArn));
        }

        return awsCustomEmailLambdaVersionConfigType;
    }

    bool IsEmpty() const {
        return this->lambdaVersion == EAWSCognitoIdpCustomEmailSenderLambdaVersionType::NOT_SET && this->lambdaArn.IsEmpty();
    }

    FAWSCognitoIdpCustomEmailLambdaVersionConfigType &fromAWS(const Aws::CognitoIdentityProvider::Model::CustomEmailLambdaVersionConfigType &awsCustomEmailLambdaVersionConfigType) {
        switch(awsCustomEmailLambdaVersionConfigType.GetLambdaVersion()) {
            case Aws::CognitoIdentityProvider::Model::CustomEmailSenderLambdaVersionType::NOT_SET:
                this->lambdaVersion = EAWSCognitoIdpCustomEmailSenderLambdaVersionType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::CustomEmailSenderLambdaVersionType::V1_0:
                this->lambdaVersion = EAWSCognitoIdpCustomEmailSenderLambdaVersionType::V1_0;
                break;
            default:
                this->lambdaVersion = EAWSCognitoIdpCustomEmailSenderLambdaVersionType::NOT_SET;
                break;
        }

        this->lambdaArn = UTF8_TO_TCHAR(awsCustomEmailLambdaVersionConfigType.GetLambdaArn().c_str());

        return *this;
    }
#endif
};
