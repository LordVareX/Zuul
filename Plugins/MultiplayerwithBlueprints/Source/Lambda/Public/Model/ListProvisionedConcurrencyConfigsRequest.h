/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListProvisionedConcurrencyConfigsRequest.h"

#endif

#include "ListProvisionedConcurrencyConfigsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListProvisionedConcurrencyConfigsRequest {
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
    *  <p>Specify a number to limit the number of configurations returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maxItems = 0;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::ListProvisionedConcurrencyConfigsRequest toAWS() const {
        Aws::Lambda::Model::ListProvisionedConcurrencyConfigsRequest awsListProvisionedConcurrencyConfigsRequest;

		if (!(this->functionName.IsEmpty())) {
            awsListProvisionedConcurrencyConfigsRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

		if (!(this->marker.IsEmpty())) {
            awsListProvisionedConcurrencyConfigsRequest.SetMarker(TCHAR_TO_UTF8(*this->marker));
        }

        if (!(this->maxItems == 0)) {
            awsListProvisionedConcurrencyConfigsRequest.SetMaxItems(this->maxItems);
        }

        return awsListProvisionedConcurrencyConfigsRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && this->marker.IsEmpty() && this->maxItems == 0;
    }
#endif
};
