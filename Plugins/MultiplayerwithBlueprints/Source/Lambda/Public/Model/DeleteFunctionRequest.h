/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/DeleteFunctionRequest.h"

#endif

#include "DeleteFunctionRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteFunctionRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Lambda function or version.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> - <code>my-function</code> (name-only), <code>my-function:1</code> (with version).</p> </li> <li> <p> <b>Function ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:my-function</code>.</p> </li> <li> <p> <b>Partial ARN</b> - <code>123456789012:function:my-function</code>.</p> </li> </ul> <p>You can append a version number or alias to any of the formats. The length constraint applies only to the full ARN. If you specify only the function name, it is limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
    *  <p>Specify a version to delete. You can't delete a version that's referenced by an alias.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString qualifier;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::DeleteFunctionRequest toAWS() const {
        Aws::Lambda::Model::DeleteFunctionRequest awsDeleteFunctionRequest;

		if (!(this->functionName.IsEmpty())) {
            awsDeleteFunctionRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

		if (!(this->qualifier.IsEmpty())) {
            awsDeleteFunctionRequest.SetQualifier(TCHAR_TO_UTF8(*this->qualifier));
        }

        return awsDeleteFunctionRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && this->qualifier.IsEmpty();
    }
#endif
};
