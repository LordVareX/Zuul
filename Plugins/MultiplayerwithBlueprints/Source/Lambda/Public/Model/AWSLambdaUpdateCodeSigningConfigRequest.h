/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/UpdateCodeSigningConfigRequest.h"

#endif

#include "Model/AWSLambdaAllowedPublishers.h"
#include "Model/AWSLambdaCodeSigningPolicies.h"

#include "AWSLambdaUpdateCodeSigningConfigRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaUpdateCodeSigningConfigRequest {
GENERATED_BODY()

    /**
    *  <p>The The Amazon Resource Name (ARN) of the code signing configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString codeSigningConfigArn;

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
    *  <p>The code signing policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaCodeSigningPolicies codeSigningPolicies;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::UpdateCodeSigningConfigRequest toAWS() const {
        Aws::Lambda::Model::UpdateCodeSigningConfigRequest awsUpdateCodeSigningConfigRequest;

        if (!(this->codeSigningConfigArn.IsEmpty())) {
            awsUpdateCodeSigningConfigRequest.SetCodeSigningConfigArn(TCHAR_TO_UTF8(*this->codeSigningConfigArn));
        }

		if (!(this->description.IsEmpty())) {
            awsUpdateCodeSigningConfigRequest.SetDescription(TCHAR_TO_UTF8(*this->description));
        }

		if (!(this->allowedPublishers.IsEmpty())) {
            awsUpdateCodeSigningConfigRequest.SetAllowedPublishers(this->allowedPublishers.toAWS());
        }

        if (!(this->codeSigningPolicies.IsEmpty())) {
            awsUpdateCodeSigningConfigRequest.SetCodeSigningPolicies(this->codeSigningPolicies.toAWS());
        }

        return awsUpdateCodeSigningConfigRequest;
    }

    bool IsEmpty() const {
        return this->codeSigningConfigArn.IsEmpty() && this->description.IsEmpty() && this->allowedPublishers.IsEmpty() && this->codeSigningPolicies.IsEmpty();
    }
#endif
};
