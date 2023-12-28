/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/GetFunctionConcurrencyRequest.h"

#endif

#include "GetFunctionConcurrencyRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetFunctionConcurrencyRequest {
    GENERATED_BODY()

    /**
    *  <p>The name of the Lambda function.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> - <code>my-function</code>.</p> </li> <li> <p> <b>Function ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:my-function</code>.</p> </li> <li> <p> <b>Partial ARN</b> - <code>123456789012:function:my-function</code>.</p> </li> </ul> <p>The length constraint applies only to the full ARN. If you specify only the function name, it is limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::GetFunctionConcurrencyRequest toAWS() const {
        Aws::Lambda::Model::GetFunctionConcurrencyRequest awsGetFunctionConcurrencyRequest;

		if (!(this->functionName.IsEmpty())) {
            awsGetFunctionConcurrencyRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

        return awsGetFunctionConcurrencyRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty();
    }
#endif
};
