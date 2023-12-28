/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListFunctionEventInvokeConfigsRequest.h"

#endif

#include "ListFunctionEventInvokeConfigsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListFunctionEventInvokeConfigsRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Lambda function.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> - <code>my-function</code>.</p> </li> <li> <p> <b>Function ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:my-function</code>.</p> </li> <li> <p> <b>Partial ARN</b> - <code>123456789012:function:my-function</code>.</p> </li> </ul> <p>The length constraint applies only to the full ARN. If you specify only the function name, it is limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
    *  <p>Specify the pagination token that's returned by a previous request to retrieve the next page of results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString marker;

    /**
    *  <p>The maximum number of configurations to return.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maxItems = 0;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::ListFunctionEventInvokeConfigsRequest toAWS() const {
        Aws::Lambda::Model::ListFunctionEventInvokeConfigsRequest awsListFunctionEventInvokeConfigsRequest;

		if (!(this->functionName.IsEmpty())) {
            awsListFunctionEventInvokeConfigsRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

		if (!(this->marker.IsEmpty())) {
            awsListFunctionEventInvokeConfigsRequest.SetMarker(TCHAR_TO_UTF8(*this->marker));
        }

        if (!(this->maxItems == 0)) {
            awsListFunctionEventInvokeConfigsRequest.SetMaxItems(this->maxItems);
        }

        return awsListFunctionEventInvokeConfigsRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && this->marker.IsEmpty() && this->maxItems == 0;
    }
#endif
};
