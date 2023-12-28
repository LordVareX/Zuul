/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/PutFunctionEventInvokeConfigRequest.h"

#endif

#include "Model/DestinationConfig.h"

#include "PutFunctionEventInvokeConfigRequest.generated.h"

USTRUCT(BlueprintType)
struct FPutFunctionEventInvokeConfigRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Lambda function, version, or alias.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> - <code>my-function</code> (name-only), <code>my-function:v1</code> (with alias).</p> </li> <li> <p> <b>Function ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:my-function</code>.</p> </li> <li> <p> <b>Partial ARN</b> - <code>123456789012:function:my-function</code>.</p> </li> </ul> <p>You can append a version number or alias to any of the formats. The length constraint applies only to the full ARN. If you specify only the function name, it is limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
    *  <p>A version number or alias name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString qualifier;

    /**
    *  <p>The maximum number of times to retry when the function returns an error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maximumRetryAttempts = 0;

    /**
    *  <p>The maximum age of a request that Lambda sends to a function for processing.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maximumEventAgeInSeconds = 0;

    /**
    *  <p>A destination for events after they have been sent to a function for processing.</p> <p class="title"> <b>Destinations</b> </p> <ul> <li> <p> <b>Function</b> - The Amazon Resource Name (ARN) of a Lambda function.</p> </li> <li> <p> <b>Queue</b> - The ARN of an SQS queue.</p> </li> <li> <p> <b>Topic</b> - The ARN of an SNS topic.</p> </li> <li> <p> <b>Event Bus</b> - The ARN of an Amazon EventBridge event bus.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FDestinationConfig destinationConfig;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::PutFunctionEventInvokeConfigRequest toAWS() const {
        Aws::Lambda::Model::PutFunctionEventInvokeConfigRequest awsPutFunctionEventInvokeConfigRequest;

		if (!(this->functionName.IsEmpty())) {
            awsPutFunctionEventInvokeConfigRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

		if (!(this->qualifier.IsEmpty())) {
            awsPutFunctionEventInvokeConfigRequest.SetQualifier(TCHAR_TO_UTF8(*this->qualifier));
        }

        if (!(this->maximumRetryAttempts == 0)) {
            awsPutFunctionEventInvokeConfigRequest.SetMaximumRetryAttempts(this->maximumRetryAttempts);
        }

        if (!(this->maximumEventAgeInSeconds == 0)) {
            awsPutFunctionEventInvokeConfigRequest.SetMaximumEventAgeInSeconds(this->maximumEventAgeInSeconds);
        }

        if (!(this->destinationConfig.IsEmpty())) {
            awsPutFunctionEventInvokeConfigRequest.SetDestinationConfig(this->destinationConfig.toAWS());
        }

        return awsPutFunctionEventInvokeConfigRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && this->qualifier.IsEmpty() && this->maximumRetryAttempts == 0 && this->maximumEventAgeInSeconds == 0 && this->destinationConfig.IsEmpty();
    }
#endif
};
