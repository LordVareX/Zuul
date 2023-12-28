/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/EnvironmentResponse.h"

#endif

#include "Model/EnvironmentError.h"

#include "EnvironmentResponse.generated.h"

USTRUCT(BlueprintType)
struct FEnvironmentResponse {
GENERATED_BODY()

    /**
    *  <p>Environment variable key-value pairs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TMap<FString, FString> variables;

    /**
    *  <p>Error messages for environment variables that couldn't be applied.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FEnvironmentError error;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FEnvironmentResponse &fromAWS(const Aws::Lambda::Model::EnvironmentResponse &awsEnvironmentResponse) {
        this->variables.Empty();
        for (const auto& elem : awsEnvironmentResponse.GetVariables()) {
            this->variables.Add(elem.first.c_str(), elem.second.c_str());
        }

        this->error.fromAWS(awsEnvironmentResponse.GetError());

        return *this;
    }
#endif
};
