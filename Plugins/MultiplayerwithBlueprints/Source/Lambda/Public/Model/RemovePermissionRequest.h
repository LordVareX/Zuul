/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/RemovePermissionRequest.h"

#endif

#include "RemovePermissionRequest.generated.h"

USTRUCT(BlueprintType)
struct FRemovePermissionRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Lambda function, version, or alias.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> - <code>my-function</code> (name-only), <code>my-function:v1</code> (with alias).</p> </li> <li> <p> <b>Function ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:my-function</code>.</p> </li> <li> <p> <b>Partial ARN</b> - <code>123456789012:function:my-function</code>.</p> </li> </ul> <p>You can append a version number or alias to any of the formats. The length constraint applies only to the full ARN. If you specify only the function name, it is limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
    *  <p>Statement ID of the permission to remove.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString statementId;

    /**
    *  <p>Specify a version or alias to remove permissions from a published version of the function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString qualifier;

    /**
    *  <p>Only update the policy if the revision ID matches the ID that's specified. Use this option to avoid modifying a policy that has changed since you last read it.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString revisionId;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::RemovePermissionRequest toAWS() const {
        Aws::Lambda::Model::RemovePermissionRequest awsRemovePermissionRequest;

		if (!(this->functionName.IsEmpty())) {
            awsRemovePermissionRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

		if (!(this->statementId.IsEmpty())) {
            awsRemovePermissionRequest.SetStatementId(TCHAR_TO_UTF8(*this->statementId));
        }

		if (!(this->qualifier.IsEmpty())) {
            awsRemovePermissionRequest.SetQualifier(TCHAR_TO_UTF8(*this->qualifier));
        }

		if (!(this->revisionId.IsEmpty())) {
            awsRemovePermissionRequest.SetRevisionId(TCHAR_TO_UTF8(*this->revisionId));
        }

        return awsRemovePermissionRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && this->statementId.IsEmpty() && this->qualifier.IsEmpty() && this->revisionId.IsEmpty();
    }
#endif
};
