/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/GetCodeSigningConfigRequest.h"

#endif

#include "AWSLambdaGetCodeSigningConfigRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaGetCodeSigningConfigRequest {
GENERATED_BODY()

    /**
    *  <p>The The Amazon Resource Name (ARN) of the code signing configuration. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString codeSigningConfigArn;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::GetCodeSigningConfigRequest toAWS() const {
        Aws::Lambda::Model::GetCodeSigningConfigRequest awsGetCodeSigningConfigRequest;

        if (!(this->codeSigningConfigArn.IsEmpty())) {
            awsGetCodeSigningConfigRequest.SetCodeSigningConfigArn(TCHAR_TO_UTF8(*this->codeSigningConfigArn));
        }

        return awsGetCodeSigningConfigRequest;
    }

    bool IsEmpty() const {
        return this->codeSigningConfigArn.IsEmpty();
    }
#endif
};
