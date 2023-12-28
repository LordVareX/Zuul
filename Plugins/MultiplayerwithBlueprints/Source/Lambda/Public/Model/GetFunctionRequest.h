/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/GetFunctionRequest.h"

#endif

#include "GetFunctionRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetFunctionRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Lambda function, version, or alias.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> - <code>my-function</code> (name-only), <code>my-function:v1</code> (with alias).</p> </li> <li> <p> <b>Function ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:my-function</code>.</p> </li> <li> <p> <b>Partial ARN</b> - <code>123456789012:function:my-function</code>.</p> </li> </ul> <p>You can append a version number or alias to any of the formats. The length constraint applies only to the full ARN. If you specify only the function name, it is limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
    *  <p>Specify a version or alias to get details about a published version of the function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString qualifier;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::GetFunctionRequest toAWS() const {
        Aws::Lambda::Model::GetFunctionRequest awsGetFunctionRequest;

		if (!(this->functionName.IsEmpty())) {
            awsGetFunctionRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

		if (!(this->qualifier.IsEmpty())) {
            awsGetFunctionRequest.SetQualifier(TCHAR_TO_UTF8(*this->qualifier));
        }

        return awsGetFunctionRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && this->qualifier.IsEmpty();
    }
#endif
};
