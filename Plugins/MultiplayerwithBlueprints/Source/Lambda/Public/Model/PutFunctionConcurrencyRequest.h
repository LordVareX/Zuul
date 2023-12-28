/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/PutFunctionConcurrencyRequest.h"

#endif

#include "PutFunctionConcurrencyRequest.generated.h"

USTRUCT(BlueprintType)
struct FPutFunctionConcurrencyRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Lambda function.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> - <code>my-function</code>.</p> </li> <li> <p> <b>Function ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:my-function</code>.</p> </li> <li> <p> <b>Partial ARN</b> - <code>123456789012:function:my-function</code>.</p> </li> </ul> <p>The length constraint applies only to the full ARN. If you specify only the function name, it is limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
    *  <p>The number of simultaneous executions to reserve for the function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int reservedConcurrentExecutions = 0;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::PutFunctionConcurrencyRequest toAWS() const {
        Aws::Lambda::Model::PutFunctionConcurrencyRequest awsPutFunctionConcurrencyRequest;

		if (!(this->functionName.IsEmpty())) {
            awsPutFunctionConcurrencyRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

        if (!(this->reservedConcurrentExecutions == 0)) {
            awsPutFunctionConcurrencyRequest.SetReservedConcurrentExecutions(this->reservedConcurrentExecutions);
        }

        return awsPutFunctionConcurrencyRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && this->reservedConcurrentExecutions == 0;
    }
#endif
};
