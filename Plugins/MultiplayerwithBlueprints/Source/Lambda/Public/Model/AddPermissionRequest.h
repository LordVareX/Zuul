/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/AddPermissionRequest.h"

#endif

#include "Model/AWSLambdaFunctionUrlAuthType.h"

#include "AddPermissionRequest.generated.h"

USTRUCT(BlueprintType)
struct FAddPermissionRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Lambda function, version, or alias.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> - <code>my-function</code> (name-only), <code>my-function:v1</code> (with alias).</p> </li> <li> <p> <b>Function ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:my-function</code>.</p> </li> <li> <p> <b>Partial ARN</b> - <code>123456789012:function:my-function</code>.</p> </li> </ul> <p>You can append a version number or alias to any of the formats. The length constraint applies only to the full ARN. If you specify only the function name, it is limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
    *  <p>A statement identifier that differentiates the statement from others in the same policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString statementId;

    /**
    *  <p>The action that the principal can use on the function. For example, <code>lambda:InvokeFunction</code> or <code>lambda:GetFunction</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString action;

    /**
    *  <p>The AWS service or account that invokes the function. If you specify a service, use <code>SourceArn</code> or <code>SourceAccount</code> to limit who can invoke the function through that service.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString principal;

    /**
    *  <p>For AWS services, the ARN of the AWS resource that invokes the function. For example, an Amazon S3 bucket or Amazon SNS topic.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString sourceArn;

    /**
    *  <p>For AWS services, the ID of the account that owns the resource. Use this instead of <code>SourceArn</code> to grant permission to resources that are owned by another account (for example, all of an account's Amazon S3 buckets). Or use it together with <code>SourceArn</code> to ensure that the resource is owned by the specified account. For example, an Amazon S3 bucket could be deleted by its owner and recreated by another account.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString sourceAccount;

    /**
    *  <p>For Alexa Smart Home functions, a token that must be supplied by the invoker.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString eventSourceToken;

    /**
    *  <p>Specify a version or alias to add permissions to a published version of the function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString qualifier;

    /**
    *  <p>Only update the policy if the revision ID matches the ID that's specified. Use this option to avoid modifying a policy that has changed since you last read it.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString revisionId;

    /**
    *  <p>The identifier for your organization in Organizations. Use this to grant permissions to all the Amazon Web Services accounts under this organization.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString principalOrgID;

    /**
    *  <p>The type of authentication that your function URL uses. Set to <code>AWS_IAM</code> if you want to restrict access to authenticated IAM users only. Set to <code>NONE</code> if you want to bypass IAM authentication to create a public endpoint. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/urls-auth.html">Security and auth model for Lambda function URLs</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSLambdaFunctionUrlAuthType functionUrlAuthType = EAWSLambdaFunctionUrlAuthType::NOT_SET;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::AddPermissionRequest toAWS() const {
        Aws::Lambda::Model::AddPermissionRequest awsAddPermissionRequest;

		if (!(this->functionName.IsEmpty())) {
            awsAddPermissionRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

		if (!(this->statementId.IsEmpty())) {
            awsAddPermissionRequest.SetStatementId(TCHAR_TO_UTF8(*this->statementId));
        }

		if (!(this->action.IsEmpty())) {
            awsAddPermissionRequest.SetAction(TCHAR_TO_UTF8(*this->action));
        }

		if (!(this->principal.IsEmpty())) {
            awsAddPermissionRequest.SetPrincipal(TCHAR_TO_UTF8(*this->principal));
        }

		if (!(this->sourceArn.IsEmpty())) {
            awsAddPermissionRequest.SetSourceArn(TCHAR_TO_UTF8(*this->sourceArn));
        }

		if (!(this->sourceAccount.IsEmpty())) {
            awsAddPermissionRequest.SetSourceAccount(TCHAR_TO_UTF8(*this->sourceAccount));
        }

		if (!(this->eventSourceToken.IsEmpty())) {
            awsAddPermissionRequest.SetEventSourceToken(TCHAR_TO_UTF8(*this->eventSourceToken));
        }

		if (!(this->qualifier.IsEmpty())) {
            awsAddPermissionRequest.SetQualifier(TCHAR_TO_UTF8(*this->qualifier));
        }

		if (!(this->revisionId.IsEmpty())) {
            awsAddPermissionRequest.SetRevisionId(TCHAR_TO_UTF8(*this->revisionId));
        }


        if (!(this->principalOrgID.IsEmpty())) {
            awsAddPermissionRequest.SetPrincipalOrgID(TCHAR_TO_UTF8(*this->principalOrgID));
        }

        switch(this->functionUrlAuthType) {
            case EAWSLambdaFunctionUrlAuthType::NONE:
                awsAddPermissionRequest.SetFunctionUrlAuthType(Aws::Lambda::Model::FunctionUrlAuthType::NONE);
                break;
            case EAWSLambdaFunctionUrlAuthType::AWS_IAM:
                awsAddPermissionRequest.SetFunctionUrlAuthType(Aws::Lambda::Model::FunctionUrlAuthType::AWS_IAM);
                break;
            default:
                break;
        }

        return awsAddPermissionRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && this->statementId.IsEmpty() && this->action.IsEmpty() && this->principal.IsEmpty() && this->sourceArn.IsEmpty() && this->sourceAccount.IsEmpty() && this->eventSourceToken.IsEmpty() && this->qualifier.IsEmpty() && this->revisionId.IsEmpty() && this->principalOrgID.IsEmpty() && this->functionUrlAuthType == EAWSLambdaFunctionUrlAuthType::NOT_SET;
    }
#endif
};
