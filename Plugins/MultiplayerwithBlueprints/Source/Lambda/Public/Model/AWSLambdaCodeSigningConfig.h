/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/CodeSigningConfig.h"

#endif

#include "Model/AWSLambdaAllowedPublishers.h"
#include "Model/AWSLambdaCodeSigningPolicies.h"

#include "AWSLambdaCodeSigningConfig.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaCodeSigningConfig {
GENERATED_BODY()

    /**
    *  <p>Unique identifer for the Code signing configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString codeSigningConfigId;

    /**
    *  <p>The Amazon Resource Name (ARN) of the Code signing configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString codeSigningConfigArn;

    /**
    *  <p>Code signing configuration description.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString description;

    /**
    *  <p>List of allowed publishers.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaAllowedPublishers allowedPublishers;

    /**
    *  <p>The code signing policy controls the validation failure action for signature mismatch or expiry.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaCodeSigningPolicies codeSigningPolicies;

    /**
    *  <p>The date and time that the Code signing configuration was last modified, in ISO-8601 format (YYYY-MM-DDThh:mm:ss.sTZD). </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString lastModified;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FAWSLambdaCodeSigningConfig &fromAWS(const Aws::Lambda::Model::CodeSigningConfig &awsCodeSigningConfig) {
        this->codeSigningConfigId = UTF8_TO_TCHAR(awsCodeSigningConfig.GetCodeSigningConfigId().c_str());

        this->codeSigningConfigArn = UTF8_TO_TCHAR(awsCodeSigningConfig.GetCodeSigningConfigArn().c_str());

        this->description = UTF8_TO_TCHAR(awsCodeSigningConfig.GetDescription().c_str());

        this->allowedPublishers.fromAWS(awsCodeSigningConfig.GetAllowedPublishers());

        this->codeSigningPolicies.fromAWS(awsCodeSigningConfig.GetCodeSigningPolicies());

        this->lastModified = UTF8_TO_TCHAR(awsCodeSigningConfig.GetLastModified().c_str());

        return *this;
    }
#endif
};
