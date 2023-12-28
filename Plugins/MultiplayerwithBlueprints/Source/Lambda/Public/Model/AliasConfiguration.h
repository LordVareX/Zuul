/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/AliasConfiguration.h"

#endif

#include "Model/AliasRoutingConfiguration.h"

#include "AliasConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAliasConfiguration {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the alias.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString aliasArn;

    /**
    *  <p>The name of the alias.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString name;

    /**
    *  <p>The function version that the alias invokes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionVersion;

    /**
    *  <p>A description of the alias.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString description;

    /**
    *  <p>The <a href="https://docs.aws.amazon.com/lambda/latest/dg/lambda-traffic-shifting-using-aliases.html">routing configuration</a> of the alias.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAliasRoutingConfiguration routingConfig;

    /**
    *  <p>A unique identifier that changes when you update the alias.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString revisionId;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FAliasConfiguration &fromAWS(const Aws::Lambda::Model::AliasConfiguration &awsAliasConfiguration) {
        this->aliasArn = UTF8_TO_TCHAR(awsAliasConfiguration.GetAliasArn().c_str());

        this->name = UTF8_TO_TCHAR(awsAliasConfiguration.GetName().c_str());

        this->functionVersion = UTF8_TO_TCHAR(awsAliasConfiguration.GetFunctionVersion().c_str());

        this->description = UTF8_TO_TCHAR(awsAliasConfiguration.GetDescription().c_str());

        this->routingConfig.fromAWS(awsAliasConfiguration.GetRoutingConfig());

        this->revisionId = UTF8_TO_TCHAR(awsAliasConfiguration.GetRevisionId().c_str());

        return *this;
    }
#endif
};
