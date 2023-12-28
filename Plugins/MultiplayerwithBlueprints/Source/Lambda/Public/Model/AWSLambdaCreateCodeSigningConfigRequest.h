/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/CreateCodeSigningConfigRequest.h"

#endif

#include "Model/AWSLambdaAllowedPublishers.h"
#include "Model/AWSLambdaCodeSigningPolicies.h"

#include "AWSLambdaCreateCodeSigningConfigRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaCreateCodeSigningConfigRequest {
GENERATED_BODY()

    /**
    *  <p>Descriptive name for this code signing configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString description;

    /**
    *  <p>Signing profiles for this code signing configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaAllowedPublishers allowedPublishers;

    /**
    *  <p>The code signing policies define the actions to take if the validation checks fail. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaCodeSigningPolicies codeSigningPolicies;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::CreateCodeSigningConfigRequest toAWS() const {
        Aws::Lambda::Model::CreateCodeSigningConfigRequest awsCreateCodeSigningConfigRequest;

        if (!(this->description.IsEmpty())) {
            awsCreateCodeSigningConfigRequest.SetDescription(TCHAR_TO_UTF8(*this->description));
        }

        if (!(this->allowedPublishers.IsEmpty())) {
            awsCreateCodeSigningConfigRequest.SetAllowedPublishers(this->allowedPublishers.toAWS());
        }

        if (!(this->codeSigningPolicies.IsEmpty())) {
            awsCreateCodeSigningConfigRequest.SetCodeSigningPolicies(this->codeSigningPolicies.toAWS());
        }

        return awsCreateCodeSigningConfigRequest;
    }

    bool IsEmpty() const {
        return this->description.IsEmpty() && this->allowedPublishers.IsEmpty() && this->codeSigningPolicies.IsEmpty();
    }
#endif
};
