/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/PublishLayerVersionRequest.h"

#endif

#include "Model/LayerVersionContentInput.h"
#include "Model/Runtime.h"
#include "Model/AWSLambdaArchitecture.h"

#include "PublishLayerVersionRequest.generated.h"

USTRUCT(BlueprintType)
struct FPublishLayerVersionRequest {
GENERATED_BODY()

    /**
    *  <p>The name or Amazon Resource Name (ARN) of the layer.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString layerName;

    /**
    *  <p>The description of the version.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString description;

    /**
    *  <p>The function layer archive.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FLayerVersionContentInput content;

    /**
    *  <p>A list of compatible <a href="https://docs.aws.amazon.com/lambda/latest/dg/lambda-runtimes.html">function runtimes</a>. Used for filtering with <a>ListLayers</a> and <a>ListLayerVersions</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<EAWSRuntime> compatibleRuntimes;

    /**
    *  <p>The layer's software license. It can be any of the following:</p> <ul> <li> <p>An <a href="https://spdx.org/licenses/">SPDX license identifier</a>. For example, <code>MIT</code>.</p> </li> <li> <p>The URL of a license hosted on the internet. For example, <code>https://opensource.org/licenses/MIT</code>.</p> </li> <li> <p>The full text of the license.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString licenseInfo;
    
    /**
    *  <p>A list of compatible <a href="https://docs.aws.amazon.com/lambda/latest/dg/foundation-arch.html">instruction set architectures</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<EAWSLambdaArchitecture> compatibleArchitectures;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::PublishLayerVersionRequest toAWS() const {
        Aws::Lambda::Model::PublishLayerVersionRequest awsPublishLayerVersionRequest;

		if (!(this->layerName.IsEmpty())) {
            awsPublishLayerVersionRequest.SetLayerName(TCHAR_TO_UTF8(*this->layerName));
        }

		if (!(this->description.IsEmpty())) {
            awsPublishLayerVersionRequest.SetDescription(TCHAR_TO_UTF8(*this->description));
        }

        if (!(this->content.IsEmpty())) {
            awsPublishLayerVersionRequest.SetContent(this->content.toAWS());
        }

        for (const EAWSRuntime& elem : this->compatibleRuntimes) {
		    switch(elem) {
                case EAWSRuntime::nodejs:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::nodejs);
                        break;
                case EAWSRuntime::nodejs4_3:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::nodejs4_3);
                        break;
                case EAWSRuntime::nodejs6_10:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::nodejs6_10);
                        break;
                case EAWSRuntime::nodejs8_10:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::nodejs8_10);
                        break;
                case EAWSRuntime::nodejs10_x:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::nodejs10_x);
                        break;
                case EAWSRuntime::nodejs12_x:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::nodejs12_x);
                        break;
                case EAWSRuntime::nodejs14_x:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::nodejs14_x);
                        break;
                case EAWSRuntime::nodejs16_x:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::nodejs16_x);
                        break;
                case EAWSRuntime::java8:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::java8);
                        break;
                case EAWSRuntime::java8_al2:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::java8_al2);
                        break;
                case EAWSRuntime::java11:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::java11);
                        break;
                case EAWSRuntime::python2_7:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::python2_7);
                        break;
                case EAWSRuntime::python3_6:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::python3_6);
                        break;
                case EAWSRuntime::python3_7:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::python3_7);
                        break;
                case EAWSRuntime::python3_8:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::python3_8);
                        break;
                case EAWSRuntime::python3_9:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::python3_9);
                        break;
                case EAWSRuntime::dotnetcore1_0:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::dotnetcore1_0);
                        break;
                case EAWSRuntime::dotnetcore2_0:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::dotnetcore2_0);
                        break;
                case EAWSRuntime::dotnetcore2_1:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::dotnetcore2_1);
                        break;
                case EAWSRuntime::dotnetcore3_1:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::dotnetcore3_1);
                        break;
                case EAWSRuntime::dotnet6:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::dotnet6);
                        break;
                case EAWSRuntime::nodejs4_3_edge:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::nodejs4_3_edge);
                        break;
                case EAWSRuntime::go1_x:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::go1_x);
                        break;
                case EAWSRuntime::ruby2_5:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::ruby2_5);
                        break;
                case EAWSRuntime::ruby2_7:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::ruby2_7);
                        break;
                case EAWSRuntime::provided:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::provided);
                        break;
                case EAWSRuntime::provided_al2:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::provided_al2);
                        break;
                case EAWSRuntime::nodejs18_x:
                        awsPublishLayerVersionRequest.AddCompatibleRuntimes(Aws::Lambda::Model::Runtime::nodejs18_x);
                        break;
                default:
                    break;
            };
        }

		if (!(this->licenseInfo.IsEmpty())) {
            awsPublishLayerVersionRequest.SetLicenseInfo(TCHAR_TO_UTF8(*this->licenseInfo));
        }

        for (const EAWSLambdaArchitecture& elem : this->compatibleArchitectures) {
		    switch(elem) {
                case EAWSLambdaArchitecture::x86_64:
                    awsPublishLayerVersionRequest.AddCompatibleArchitectures(Aws::Lambda::Model::Architecture::x86_64);
                    break;
                case EAWSLambdaArchitecture::arm64:
                    awsPublishLayerVersionRequest.AddCompatibleArchitectures(Aws::Lambda::Model::Architecture::arm64);
                    break;
                default:
                    break;
            };
        }
        return awsPublishLayerVersionRequest;
    }

    bool IsEmpty() const {
        return this->layerName.IsEmpty() && this->description.IsEmpty() && this->content.IsEmpty() && this->compatibleRuntimes.Num() == 0 && this->licenseInfo.IsEmpty() && this->compatibleArchitectures.Num() == 0;
    }
#endif
};
