/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/DeleteCodeSigningConfigRequest.h"

#endif

#include "AWSLambdaDeleteCodeSigningConfigRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaDeleteCodeSigningConfigRequest {
GENERATED_BODY()

    /**
    *  <p>The The Amazon Resource Name (ARN) of the code signing configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString codeSigningConfigArn;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::DeleteCodeSigningConfigRequest toAWS() const {
        Aws::Lambda::Model::DeleteCodeSigningConfigRequest awsDeleteCodeSigningConfigRequest;

        if (!(this->codeSigningConfigArn.IsEmpty())) {
            awsDeleteCodeSigningConfigRequest.SetCodeSigningConfigArn(TCHAR_TO_UTF8(*this->codeSigningConfigArn));
        }

        return awsDeleteCodeSigningConfigRequest;
    }

    bool IsEmpty() const {
        return this->codeSigningConfigArn.IsEmpty();
    }
#endif
};
