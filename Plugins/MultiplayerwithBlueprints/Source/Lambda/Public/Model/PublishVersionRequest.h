/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/PublishVersionRequest.h"

#endif

#include "PublishVersionRequest.generated.h"

USTRUCT(BlueprintType)
struct FPublishVersionRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Lambda function.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> - <code>MyFunction</code>.</p> </li> <li> <p> <b>Function ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:MyFunction</code>.</p> </li> <li> <p> <b>Partial ARN</b> - <code>123456789012:function:MyFunction</code>.</p> </li> </ul> <p>The length constraint applies only to the full ARN. If you specify only the function name, it is limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
    *  <p>Only publish a version if the hash value matches the value that's specified. Use this option to avoid publishing a version if the function code has changed since you last updated it. You can get the hash for the version that you uploaded from the output of <a>UpdateFunctionCode</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString codeSha256;

    /**
    *  <p>A description for the version to override the description in the function configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString description;

    /**
    *  <p>Only update the function if the revision ID matches the ID that's specified. Use this option to avoid publishing a version if the function configuration has changed since you last updated it.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString revisionId;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::PublishVersionRequest toAWS() const {
        Aws::Lambda::Model::PublishVersionRequest awsPublishVersionRequest;

		if (!(this->functionName.IsEmpty())) {
            awsPublishVersionRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

		if (!(this->codeSha256.IsEmpty())) {
            awsPublishVersionRequest.SetCodeSha256(TCHAR_TO_UTF8(*this->codeSha256));
        }

		if (!(this->description.IsEmpty())) {
            awsPublishVersionRequest.SetDescription(TCHAR_TO_UTF8(*this->description));
        }

		if (!(this->revisionId.IsEmpty())) {
            awsPublishVersionRequest.SetRevisionId(TCHAR_TO_UTF8(*this->revisionId));
        }

        return awsPublishVersionRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && this->codeSha256.IsEmpty() && this->description.IsEmpty() && this->revisionId.IsEmpty();
    }
#endif
};
