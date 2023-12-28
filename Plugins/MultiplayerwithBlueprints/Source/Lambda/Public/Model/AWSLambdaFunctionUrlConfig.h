/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/FunctionUrlConfig.h"

#endif

#include "Model/AWSLambdaCors.h"
#include "Model/AWSLambdaFunctionUrlAuthType.h"

#include "AWSLambdaFunctionUrlConfig.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaFunctionUrlConfig {
GENERATED_BODY()

    /**
    *  <p>The HTTP URL endpoint for your function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionUrl;

    /**
    *  <p>The Amazon Resource Name (ARN) of your function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionArn;

    /**
    *  <p>When the function URL was created, in <a href="https://www.w3.org/TR/NOTE-datetime">ISO-8601 format</a> (YYYY-MM-DDThh:mm:ss.sTZD).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString creationTime;

    /**
    *  <p>When the function URL configuration was last updated, in <a href="https://www.w3.org/TR/NOTE-datetime">ISO-8601 format</a> (YYYY-MM-DDThh:mm:ss.sTZD).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString lastModifiedTime;

    /**
    *  <p>The <a href="https://developer.mozilla.org/en-US/docs/Web/HTTP/CORS">cross-origin resource sharing (CORS)</a> settings for your function URL.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaCors cors;

    /**
    *  <p>The type of authentication that your function URL uses. Set to <code>AWS_IAM</code> if you want to restrict access to authenticated IAM users only. Set to <code>NONE</code> if you want to bypass IAM authentication to create a public endpoint. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/urls-auth.html">Security and auth model for Lambda function URLs</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSLambdaFunctionUrlAuthType authType = EAWSLambdaFunctionUrlAuthType::NOT_SET;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FAWSLambdaFunctionUrlConfig &fromAWS(const Aws::Lambda::Model::FunctionUrlConfig &awsFunctionUrlConfig) {
        this->functionUrl = UTF8_TO_TCHAR(awsFunctionUrlConfig.GetFunctionUrl().c_str());

        this->functionArn = UTF8_TO_TCHAR(awsFunctionUrlConfig.GetFunctionArn().c_str());

        this->creationTime = UTF8_TO_TCHAR(awsFunctionUrlConfig.GetCreationTime().c_str());

        this->lastModifiedTime = UTF8_TO_TCHAR(awsFunctionUrlConfig.GetLastModifiedTime().c_str());

        this->cors.fromAWS(awsFunctionUrlConfig.GetCors());

        switch(awsFunctionUrlConfig.GetAuthType()) {
            case Aws::Lambda::Model::FunctionUrlAuthType::NOT_SET:
                this->authType = EAWSLambdaFunctionUrlAuthType::NOT_SET;
                break;
            case Aws::Lambda::Model::FunctionUrlAuthType::NONE:
                this->authType = EAWSLambdaFunctionUrlAuthType::NONE;
                break;
            case Aws::Lambda::Model::FunctionUrlAuthType::AWS_IAM:
                this->authType = EAWSLambdaFunctionUrlAuthType::AWS_IAM;
                break;
            default:
                this->authType = EAWSLambdaFunctionUrlAuthType::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
