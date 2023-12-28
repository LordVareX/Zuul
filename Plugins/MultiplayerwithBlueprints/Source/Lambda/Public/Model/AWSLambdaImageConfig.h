/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ImageConfig.h"

#endif

#include "AWSLambdaImageConfig.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaImageConfig {
GENERATED_BODY()

    /**
    *  <p>Specifies the entry point to their application, which is typically the location of the runtime executable.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FString> entryPoint;

    /**
    *  <p>Specifies parameters that you want to pass in with ENTRYPOINT. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FString> command;

    /**
    *  <p>Specifies the working directory.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString workingDirectory;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::ImageConfig toAWS() const {
        Aws::Lambda::Model::ImageConfig awsImageConfig;

        for (const FString& elem : this->entryPoint) {
            awsImageConfig.AddEntryPoint(TCHAR_TO_UTF8(*elem));
        }

        for (const FString& elem : this->command) {
            awsImageConfig.AddCommand(TCHAR_TO_UTF8(*elem));
        }

        if (!(this->workingDirectory.IsEmpty())) {
            awsImageConfig.SetWorkingDirectory(TCHAR_TO_UTF8(*this->workingDirectory));
        }

        return awsImageConfig;
    }

    bool IsEmpty() const {
        return this->entryPoint.Num() == 0 && this->command.Num() == 0 && this->workingDirectory.IsEmpty();
    }

    FAWSLambdaImageConfig &fromAWS(const Aws::Lambda::Model::ImageConfig &awsImageConfig) {
        this->entryPoint.Empty();
        for (const Aws::String& elem : awsImageConfig.GetEntryPoint()) {
            this->entryPoint.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->command.Empty();
        for (const Aws::String& elem : awsImageConfig.GetCommand()) {
            this->command.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->workingDirectory = UTF8_TO_TCHAR(awsImageConfig.GetWorkingDirectory().c_str());

        return *this;
    }
#endif
};
