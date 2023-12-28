/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/CreateAliasRequest.h"

#endif

#include "Model/AliasRoutingConfiguration.h"

#include "LambdaCreateAliasRequest.generated.h"

USTRUCT(BlueprintType)
struct FLambdaCreateAliasRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Lambda function.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> - <code>MyFunction</code>.</p> </li> <li> <p> <b>Function ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:MyFunction</code>.</p> </li> <li> <p> <b>Partial ARN</b> - <code>123456789012:function:MyFunction</code>.</p> </li> </ul> <p>The length constraint applies only to the full ARN. If you specify only the function name, it is limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

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

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::CreateAliasRequest toAWS() const {
        Aws::Lambda::Model::CreateAliasRequest awsCreateAliasRequest;

		if (!(this->functionName.IsEmpty())) {
            awsCreateAliasRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

		if (!(this->name.IsEmpty())) {
            awsCreateAliasRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

		if (!(this->functionVersion.IsEmpty())) {
            awsCreateAliasRequest.SetFunctionVersion(TCHAR_TO_UTF8(*this->functionVersion));
        }

		if (!(this->description.IsEmpty())) {
            awsCreateAliasRequest.SetDescription(TCHAR_TO_UTF8(*this->description));
        }

        if (!(this->routingConfig.IsEmpty())) {
            awsCreateAliasRequest.SetRoutingConfig(this->routingConfig.toAWS());
        }

        return awsCreateAliasRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && this->name.IsEmpty() && this->functionVersion.IsEmpty() && this->description.IsEmpty() && this->routingConfig.IsEmpty();
    }
#endif
};
