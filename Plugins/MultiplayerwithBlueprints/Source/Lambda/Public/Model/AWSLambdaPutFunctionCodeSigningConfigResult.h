/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/PutFunctionCodeSigningConfigResult.h"

#endif

#include "AWSLambdaPutFunctionCodeSigningConfigResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaPutFunctionCodeSigningConfigResult {
GENERATED_BODY()

    /**
    *  <p>The The Amazon Resource Name (ARN) of the code signing configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString codeSigningConfigArn;

    /**
    *  <p>The name of the Lambda function.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> - <code>MyFunction</code>.</p> </li> <li> <p> <b>Function ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:MyFunction</code>.</p> </li> <li> <p> <b>Partial ARN</b> - <code>123456789012:function:MyFunction</code>.</p> </li> </ul> <p>The length constraint applies only to the full ARN. If you specify only the function name, it is limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FAWSLambdaPutFunctionCodeSigningConfigResult &fromAWS(const Aws::Lambda::Model::PutFunctionCodeSigningConfigResult &awsPutFunctionCodeSigningConfigResult) {
        this->codeSigningConfigArn = UTF8_TO_TCHAR(awsPutFunctionCodeSigningConfigResult.GetCodeSigningConfigArn().c_str());

        this->functionName = UTF8_TO_TCHAR(awsPutFunctionCodeSigningConfigResult.GetFunctionName().c_str());

        return *this;
    }
#endif
};
