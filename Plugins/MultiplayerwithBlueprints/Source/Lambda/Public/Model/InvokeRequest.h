/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"
#include "Containers/UnrealString.h"
#include "Misc/Base64.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/InvokeRequest.h"
#include "aws/core/utils/json/JsonSerializer.h"
#include "aws/core/utils/memory/stl/AWSStringStream.h"
#include "aws/core/utils/HashingUtils.h"

#endif

#include "LambdaGlobals.h"
#include "Model/InvocationType.h"
#include "Model/LogType.h"

#include "InvokeRequest.generated.h"

USTRUCT(BlueprintType)
struct FInvokeRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Lambda function, version, or alias.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> - <code>my-function</code> (name-only), <code>my-function:v1</code> (with alias).</p> </li> <li> <p> <b>Function ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:my-function</code>.</p> </li> <li> <p> <b>Partial ARN</b> - <code>123456789012:function:my-function</code>.</p> </li> </ul> <p>You can append a version number or alias to any of the formats. The length constraint applies only to the full ARN. If you specify only the function name, it is limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
    *  <p>Choose from the following options.</p> <ul> <li> <p> <code>RequestResponse</code> (default) - Invoke the function synchronously. Keep the connection open until the function returns a response or times out. The API response includes the function response and additional data.</p> </li> <li> <p> <code>Event</code> - Invoke the function asynchronously. Send events that fail multiple times to the function's dead-letter queue (if it's configured). The API response only includes a status code.</p> </li> <li> <p> <code>DryRun</code> - Validate parameter values and verify that the user or role has permission to invoke the function.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSInvocationType invocationType = EAWSInvocationType::NOT_SET;

    /**
    *  <p>Set to <code>Tail</code> to include the execution log in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSLogType logType = EAWSLogType::NOT_SET;

    /**
    *  <p>Up to 3583 bytes of base64-encoded data about the invoking client to pass to the function in the context object.</p>
    *  base64-encoded
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString clientContext;

    /**
    *  <p>Specify a version or alias to invoke a published version of the function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString qualifier;

    /**
    * Set the body stream to use for the request.
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString body;

    /**
    * Set the content type.
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString contentType;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::InvokeRequest toAWS() const {
        Aws::Lambda::Model::InvokeRequest awsInvokeRequest;

		if (!(this->functionName.IsEmpty())) {
            awsInvokeRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

        switch(this->invocationType) {
            case EAWSInvocationType::Event:
                awsInvokeRequest.SetInvocationType(Aws::Lambda::Model::InvocationType::Event);
                break;
            case EAWSInvocationType::RequestResponse:
                awsInvokeRequest.SetInvocationType(Aws::Lambda::Model::InvocationType::RequestResponse);
                break;
            case EAWSInvocationType::DryRun:
                awsInvokeRequest.SetInvocationType(Aws::Lambda::Model::InvocationType::DryRun);
                break;
            default:
                break;
            }

        switch(this->logType) {
            case EAWSLogType::None:
                awsInvokeRequest.SetLogType(Aws::Lambda::Model::LogType::None);
                break;
            case EAWSLogType::Tail:
                awsInvokeRequest.SetLogType(Aws::Lambda::Model::LogType::Tail);
                break;
            default:
                break;
            }

		if (!(this->clientContext.IsEmpty())) {
		    Aws::String awsClientContext = TCHAR_TO_UTF8(*this->clientContext);
            awsInvokeRequest.SetClientContext(Aws::Utils::HashingUtils::Base64Encode(Aws::Utils::ByteBuffer((unsigned char *)awsClientContext.c_str(), awsClientContext.length())));
        }

		if (!(this->qualifier.IsEmpty())) {
            awsInvokeRequest.SetQualifier(TCHAR_TO_UTF8(*this->qualifier));
        }

		if (!(this->body.IsEmpty())) {
            std::shared_ptr<Aws::IOStream> payload = Aws::MakeShared<Aws::StringStream>("InvokeRequest");
            *payload << TCHAR_TO_UTF8(*this->body);
            awsInvokeRequest.SetBody(payload);
            Aws::Utils::Json::JsonValue jsonPayload(TCHAR_TO_UTF8(*this->body));
        }

        if (!(this->contentType.IsEmpty())) {
            awsInvokeRequest.SetContentType(TCHAR_TO_UTF8(*this->contentType));
        }

        return awsInvokeRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && this->invocationType == EAWSInvocationType::NOT_SET && this->logType == EAWSLogType::NOT_SET && this->clientContext.IsEmpty() && this->qualifier.IsEmpty() && this->body.IsEmpty() && this->contentType.IsEmpty();
    }
#endif
};
