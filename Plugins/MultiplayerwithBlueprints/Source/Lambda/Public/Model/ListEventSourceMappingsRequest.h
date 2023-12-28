/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListEventSourceMappingsRequest.h"

#endif

#include "ListEventSourceMappingsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListEventSourceMappingsRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the event source.</p> <ul> <li> <p> <b>Amazon Kinesis</b> - The ARN of the data stream or a stream consumer.</p> </li> <li> <p> <b>Amazon DynamoDB Streams</b> - The ARN of the stream.</p> </li> <li> <p> <b>Amazon Simple Queue Service</b> - The ARN of the queue.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString eventSourceArn;

    /**
    *  <p>The name of the Lambda function.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> - <code>MyFunction</code>.</p> </li> <li> <p> <b>Function ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:MyFunction</code>.</p> </li> <li> <p> <b>Version or Alias ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:MyFunction:PROD</code>.</p> </li> <li> <p> <b>Partial ARN</b> - <code>123456789012:function:MyFunction</code>.</p> </li> </ul> <p>The length constraint applies only to the full ARN. If you specify only the function name, it's limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
    *  <p>A pagination token returned by a previous call.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString marker;

    /**
    *  <p>The maximum number of event source mappings to return.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maxItems = 0;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::ListEventSourceMappingsRequest toAWS() const {
        Aws::Lambda::Model::ListEventSourceMappingsRequest awsListEventSourceMappingsRequest;

		if (!(this->eventSourceArn.IsEmpty())) {
            awsListEventSourceMappingsRequest.SetEventSourceArn(TCHAR_TO_UTF8(*this->eventSourceArn));
        }

		if (!(this->functionName.IsEmpty())) {
            awsListEventSourceMappingsRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

		if (!(this->marker.IsEmpty())) {
            awsListEventSourceMappingsRequest.SetMarker(TCHAR_TO_UTF8(*this->marker));
        }

        if (this->maxItems != 0) {
            awsListEventSourceMappingsRequest.SetMaxItems(this->maxItems);
        }

        return awsListEventSourceMappingsRequest;
    }

    bool IsEmpty() const {
        return this->eventSourceArn.IsEmpty() && this->functionName.IsEmpty() && this->marker.IsEmpty() && this->maxItems == 0;
    }
#endif
};
