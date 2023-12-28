/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/LayerVersionContentOutput.h"

#endif

#include "LayerVersionContentOutput.generated.h"

USTRUCT(BlueprintType)
struct FLayerVersionContentOutput {
GENERATED_BODY()

    /**
    *  <p>A link to the layer archive in Amazon S3 that is valid for 10 minutes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString location;

    /**
    *  <p>The SHA-256 hash of the layer archive.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString codeSha256;

    /**
    *  <p>The size of the layer archive in bytes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int64 codeSize = 0;

    /**
    *  <p>The Amazon Resource Name (ARN) for a signing profile version.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString signingProfileVersionArn;

    /**
    *  <p>The Amazon Resource Name (ARN) of a signing job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString signingJobArn;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FLayerVersionContentOutput &fromAWS(const Aws::Lambda::Model::LayerVersionContentOutput &awsLayerVersionContentOutput) {
        this->location = UTF8_TO_TCHAR(awsLayerVersionContentOutput.GetLocation().c_str());

        this->codeSha256 = UTF8_TO_TCHAR(awsLayerVersionContentOutput.GetCodeSha256().c_str());

        this->codeSize = (int64)awsLayerVersionContentOutput.GetCodeSize();

        this->signingProfileVersionArn = UTF8_TO_TCHAR(awsLayerVersionContentOutput.GetSigningProfileVersionArn().c_str());

        this->signingJobArn = UTF8_TO_TCHAR(awsLayerVersionContentOutput.GetSigningJobArn().c_str());

        return *this;
    }
#endif
};
