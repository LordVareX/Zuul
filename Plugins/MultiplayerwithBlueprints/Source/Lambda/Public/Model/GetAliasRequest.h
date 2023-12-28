/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/GetAliasRequest.h"

#endif

#include "GetAliasRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetAliasRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Lambda function.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> - <code>MyFunction</code>.</p> </li> <li> <p> <b>Function ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:MyFunction</code>.</p> </li> <li> <p> <b>Partial ARN</b> - <code>123456789012:function:MyFunction</code>.</p> </li> </ul> <p>The length constraint applies only to the full ARN. If you specify only the function name, it is limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
    *  <p>The name of the alias.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString name;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::GetAliasRequest toAWS() const {
        Aws::Lambda::Model::GetAliasRequest awsGetAliasRequest;

		if (!(this->functionName.IsEmpty())) {
            awsGetAliasRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

		if (!(this->name.IsEmpty())) {
            awsGetAliasRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        return awsGetAliasRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && this->name.IsEmpty();
    }
#endif
};
