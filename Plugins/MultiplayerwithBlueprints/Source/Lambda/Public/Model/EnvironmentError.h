/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/EnvironmentError.h"

#endif

#include "EnvironmentError.generated.h"

USTRUCT(BlueprintType)
struct FEnvironmentError {
GENERATED_BODY()

    /**
    *  <p>The error code.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString errorCode;

    /**
    *  <p>The error message.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString message;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FEnvironmentError &fromAWS(const Aws::Lambda::Model::EnvironmentError &awsEnvironmentError) {
        this->errorCode = UTF8_TO_TCHAR(awsEnvironmentError.GetErrorCode().c_str());

        this->message = UTF8_TO_TCHAR(awsEnvironmentError.GetMessage().c_str());

        return *this;
    }
#endif
};
