/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/UpdateAliasRequest.h"

#endif

#include "Model/AliasRoutingConfiguration.h"

#include "LambdaUpdateAliasRequest.generated.h"

USTRUCT(BlueprintType)
struct FLambdaUpdateAliasRequest {
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

    /**
    *  <p>Only update the alias if the revision ID matches the ID that's specified. Use this option to avoid modifying an alias that has changed since you last read it.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString revisionId;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::UpdateAliasRequest toAWS() const {
        Aws::Lambda::Model::UpdateAliasRequest awsUpdateAliasRequest;

		if (!(this->functionName.IsEmpty())) {
            awsUpdateAliasRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

		if (!(this->name.IsEmpty())) {
            awsUpdateAliasRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

		if (!(this->functionVersion.IsEmpty())) {
            awsUpdateAliasRequest.SetFunctionVersion(TCHAR_TO_UTF8(*this->functionVersion));
        }

		if (!(this->description.IsEmpty())) {
            awsUpdateAliasRequest.SetDescription(TCHAR_TO_UTF8(*this->description));
        }

        if (!(this->routingConfig.IsEmpty())) {
            awsUpdateAliasRequest.SetRoutingConfig(this->routingConfig.toAWS());
        }

		if (!(this->revisionId.IsEmpty())) {
            awsUpdateAliasRequest.SetRevisionId(TCHAR_TO_UTF8(*this->revisionId));
        }

        return awsUpdateAliasRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && this->name.IsEmpty() && this->functionVersion.IsEmpty() && this->description.IsEmpty() && this->routingConfig.IsEmpty() && this->revisionId.IsEmpty();
    }
#endif
};
