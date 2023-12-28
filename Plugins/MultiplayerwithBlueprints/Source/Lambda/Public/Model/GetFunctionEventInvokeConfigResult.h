/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/GetFunctionEventInvokeConfigResult.h"

#endif

#include "Model/DestinationConfig.h"

#include "GetFunctionEventInvokeConfigResult.generated.h"

USTRUCT(BlueprintType)
struct FGetFunctionEventInvokeConfigResult {
GENERATED_BODY()

    /**
    *  <p>The date and time that the configuration was last updated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FDateTime lastModified;

    /**
    *  <p>The Amazon Resource Name (ARN) of the function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionArn;

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
    FGetFunctionEventInvokeConfigResult &fromAWS(const Aws::Lambda::Model::GetFunctionEventInvokeConfigResult &awsGetFunctionEventInvokeConfigResult) {
        this->lastModified = FDateTime(1970, 1, 1) + FTimespan(awsGetFunctionEventInvokeConfigResult.GetLastModified().Millis() * ETimespan::TicksPerMillisecond);

        this->functionArn = UTF8_TO_TCHAR(awsGetFunctionEventInvokeConfigResult.GetFunctionArn().c_str());

		this->maximumRetryAttempts = awsGetFunctionEventInvokeConfigResult.GetMaximumRetryAttempts();

		this->maximumEventAgeInSeconds = awsGetFunctionEventInvokeConfigResult.GetMaximumEventAgeInSeconds();

		this->destinationConfig.fromAWS(awsGetFunctionEventInvokeConfigResult.GetDestinationConfig());

        return *this;
    }
#endif
};
