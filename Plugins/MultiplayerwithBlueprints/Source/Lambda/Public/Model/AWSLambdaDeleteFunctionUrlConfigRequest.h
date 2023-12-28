/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/DeleteFunctionUrlConfigRequest.h"

#endif

#include "AWSLambdaDeleteFunctionUrlConfigRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaDeleteFunctionUrlConfigRequest {
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

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::DeleteFunctionUrlConfigRequest toAWS() const {
        Aws::Lambda::Model::DeleteFunctionUrlConfigRequest awsDeleteFunctionUrlConfigRequest;

        if (!(this->functionName.IsEmpty())) {
            awsDeleteFunctionUrlConfigRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

        if (!(this->qualifier.IsEmpty())) {
            awsDeleteFunctionUrlConfigRequest.SetQualifier(TCHAR_TO_UTF8(*this->qualifier));
        }

        return awsDeleteFunctionUrlConfigRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && this->qualifier.IsEmpty();
    }
#endif
};
