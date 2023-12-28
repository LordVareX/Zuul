/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CustomSMSLambdaVersionConfigType.h"

#endif

#include "Model/AWSCognitoIdpCustomSMSSenderLambdaVersionType.h"

#include "AWSCognitoIdpCustomSMSLambdaVersionConfigType.generated.h"

USTRUCT(BlueprintType)
struct FAWSCognitoIdpCustomSMSLambdaVersionConfigType {
GENERATED_BODY()

    /**
    *  <p>The Lambda version represents the signature of the "request" attribute in the "event" information Amazon Cognito passes to your custom SMS Lambda function. The only supported value is <code>V1_0</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EAWSCognitoIdpCustomSMSSenderLambdaVersionType lambdaVersion = EAWSCognitoIdpCustomSMSSenderLambdaVersionType::NOT_SET;

    /**
    *  <p>The Lambda Amazon Resource Name of the Lambda function that Amazon Cognito triggers to send SMS notifications to users.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString lambdaArn;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::CustomSMSLambdaVersionConfigType toAWS() const {
        Aws::CognitoIdentityProvider::Model::CustomSMSLambdaVersionConfigType awsCustomSMSLambdaVersionConfigType;

        switch(this->lambdaVersion) {
            case EAWSCognitoIdpCustomSMSSenderLambdaVersionType::V1_0:
                awsCustomSMSLambdaVersionConfigType.SetLambdaVersion(Aws::CognitoIdentityProvider::Model::CustomSMSSenderLambdaVersionType::V1_0);
                break;
            default:
                break;
        }

        if (!(this->lambdaArn.IsEmpty())) {
            awsCustomSMSLambdaVersionConfigType.SetLambdaArn(TCHAR_TO_UTF8(*this->lambdaArn));
        }

        return awsCustomSMSLambdaVersionConfigType;
    }

    bool IsEmpty() const {
        return this->lambdaVersion == EAWSCognitoIdpCustomSMSSenderLambdaVersionType::NOT_SET && this->lambdaArn.IsEmpty();
    }

    FAWSCognitoIdpCustomSMSLambdaVersionConfigType &fromAWS(const Aws::CognitoIdentityProvider::Model::CustomSMSLambdaVersionConfigType &awsCustomSMSLambdaVersionConfigType) {
        switch(awsCustomSMSLambdaVersionConfigType.GetLambdaVersion()) {
            case Aws::CognitoIdentityProvider::Model::CustomSMSSenderLambdaVersionType::NOT_SET:
                this->lambdaVersion = EAWSCognitoIdpCustomSMSSenderLambdaVersionType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::CustomSMSSenderLambdaVersionType::V1_0:
                this->lambdaVersion = EAWSCognitoIdpCustomSMSSenderLambdaVersionType::V1_0;
                break;
            default:
                this->lambdaVersion = EAWSCognitoIdpCustomSMSSenderLambdaVersionType::NOT_SET;
                break;
        }

        this->lambdaArn = UTF8_TO_TCHAR(awsCustomSMSLambdaVersionConfigType.GetLambdaArn().c_str());

        return *this;
    }
#endif
};
