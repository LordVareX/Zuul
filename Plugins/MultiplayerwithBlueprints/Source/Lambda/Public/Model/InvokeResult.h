/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/InvokeResult.h"

#endif

#include "InvokeResult.generated.h"

USTRUCT(BlueprintType)
struct FInvokeResult {
GENERATED_BODY()

    /**
     * <p>The HTTP status code is in the 200 range for a successful request. For the
     * <code>RequestResponse</code> invocation type, this status code is 200. For the
     * <code>Event</code> invocation type, this status code is 202. For the
     * <code>DryRun</code> invocation type, the status code is 204.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int statusCode = 0;

    /**
     * <p>If present, indicates that an error occurred during function execution.
     * Details about the error are included in the response payload.</p> <ul> <li> <p>
     * <code>Handled</code> - The runtime caught an error thrown by the function and
     * formatted it into a JSON document.</p> </li> <li> <p> <code>Unhandled</code> -
     * The runtime didn't handle the error. For example, the function ran out of memory
     * or timed out.</p> </li> </ul>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionError;

    /**
     * <p>The last 4 KB of the execution log, which is base64 encoded.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString logResult;

    /**
     * <p>The response from the function, or an error object.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString payload;

    /**
     * <p>The version of the function that executed. When you invoke a function with an
     * alias, this indicates which version the alias resolved to.</p>
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString executedVersion;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FInvokeResult &fromAWS(const Aws::Lambda::Model::InvokeResult &awsInvokeResult) {
        this->statusCode = awsInvokeResult.GetStatusCode();

        this->functionError = awsInvokeResult.GetFunctionError().c_str();

        this->logResult = awsInvokeResult.GetLogResult().c_str();

        Aws::StringStream memoryStream;
        std::copy(std::istreambuf_iterator<char>(awsInvokeResult.GetPayload()), std::istreambuf_iterator<char>(), std::ostreambuf_iterator<char>(memoryStream));
        const auto input = memoryStream.str();
        this->payload = UTF8_TO_TCHAR(input.c_str());

        this->executedVersion = awsInvokeResult.GetExecutedVersion().c_str();

        return *this;
    }
#endif
};
