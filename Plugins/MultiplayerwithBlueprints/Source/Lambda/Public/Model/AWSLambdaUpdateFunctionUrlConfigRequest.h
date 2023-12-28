/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/UpdateFunctionUrlConfigRequest.h"

#endif

#include "Model/AWSLambdaFunctionUrlAuthType.h"
#include "Model/AWSLambdaCors.h"

#include "AWSLambdaUpdateFunctionUrlConfigRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaUpdateFunctionUrlConfigRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Lambda function.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> – <code>my-function</code>.</p> </li> <li> <p> <b>Function ARN</b> – <code>arn:aws:lambda:us-west-2:123456789012:function:my-function</code>.</p> </li> <li> <p> <b>Partial ARN</b> – <code>123456789012:function:my-function</code>.</p> </li> </ul> <p>The length constraint applies only to the full ARN. If you specify only the function name, it is limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
    *  <p>The alias name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString qualifier;

    /**
    *  <p>The type of authentication that your function URL uses. Set to <code>AWS_IAM</code> if you want to restrict access to authenticated IAM users only. Set to <code>NONE</code> if you want to bypass IAM authentication to create a public endpoint. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/urls-auth.html">Security and auth model for Lambda function URLs</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSLambdaFunctionUrlAuthType authType = EAWSLambdaFunctionUrlAuthType::NOT_SET;

    /**
    *  <p>The <a href="https://developer.mozilla.org/en-US/docs/Web/HTTP/CORS">cross-origin resource sharing (CORS)</a> settings for your function URL.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaCors cors;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::UpdateFunctionUrlConfigRequest toAWS() const {
        Aws::Lambda::Model::UpdateFunctionUrlConfigRequest awsUpdateFunctionUrlConfigRequest;

        if (!(this->functionName.IsEmpty())) {
            awsUpdateFunctionUrlConfigRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

        if (!(this->qualifier.IsEmpty())) {
            awsUpdateFunctionUrlConfigRequest.SetQualifier(TCHAR_TO_UTF8(*this->qualifier));
        }

        switch(this->authType) {
            case EAWSLambdaFunctionUrlAuthType::NONE:
                awsUpdateFunctionUrlConfigRequest.SetAuthType(Aws::Lambda::Model::FunctionUrlAuthType::NONE);
                break;
            case EAWSLambdaFunctionUrlAuthType::AWS_IAM:
                awsUpdateFunctionUrlConfigRequest.SetAuthType(Aws::Lambda::Model::FunctionUrlAuthType::AWS_IAM);
                break;
            default:
                break;
        }

        if (!(this->cors.IsEmpty())) {
            awsUpdateFunctionUrlConfigRequest.SetCors(this->cors.toAWS());
        }

        return awsUpdateFunctionUrlConfigRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && this->qualifier.IsEmpty() && this->authType == EAWSLambdaFunctionUrlAuthType::NOT_SET && this->cors.IsEmpty();
    }
#endif
};
