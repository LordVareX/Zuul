/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/Environment.h"

#endif

#include "Environment.generated.h"

USTRUCT(BlueprintType)
struct FEnvironment {
GENERATED_BODY()

    /**
    *  <p>Environment variable key-value pairs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TMap<FString, FString> variables;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::Environment toAWS() const {
        Aws::Lambda::Model::Environment awsEnvironment;

        for (const TPair<FString, FString>& elem : this->variables) {
            awsEnvironment.AddVariables(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsEnvironment;
    }

    bool IsEmpty() const {
        return this->variables.Num() == 0;
    }
#endif
};
