/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ImageConfigError.h"

#endif

#include "AWSLambdaImageConfigError.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaImageConfigError {
GENERATED_BODY()

    /**
    *  <p>Error code.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString errorCode;

    /**
    *  <p>Error message.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString message;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FAWSLambdaImageConfigError &fromAWS(const Aws::Lambda::Model::ImageConfigError &awsImageConfigError) {
        this->errorCode = UTF8_TO_TCHAR(awsImageConfigError.GetErrorCode().c_str());

        this->message = UTF8_TO_TCHAR(awsImageConfigError.GetMessage().c_str());

        return *this;
    }
#endif
};
