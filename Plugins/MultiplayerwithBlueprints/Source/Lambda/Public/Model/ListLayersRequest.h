/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListLayersRequest.h"

#endif

#include "Model/Runtime.h"
#include "Model/AWSLambdaArchitecture.h"

#include "ListLayersRequest.generated.h"

USTRUCT(BlueprintType)
struct FListLayersRequest {
GENERATED_BODY()

    /**
    *  <p>A runtime identifier. For example, <code>go1.x</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSRuntime compatibleRuntime = EAWSRuntime::NOT_SET;

    /**
    *  <p>A pagination token returned by a previous call.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString marker;

    /**
    *  <p>The maximum number of layers to return.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maxItems = 0;

    /**
    *  <p>The compatible <a href="https://docs.aws.amazon.com/lambda/latest/dg/foundation-arch.html">instruction set architecture</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSLambdaArchitecture compatibleArchitecture = EAWSLambdaArchitecture::NOT_SET;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::ListLayersRequest toAWS() const {
        Aws::Lambda::Model::ListLayersRequest awsListLayersRequest;

        switch(this->compatibleRuntime) {
            case EAWSRuntime::nodejs:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs);
                break;
            case EAWSRuntime::nodejs4_3:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs4_3);
                break;
            case EAWSRuntime::nodejs6_10:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs6_10);
                break;
            case EAWSRuntime::nodejs8_10:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs8_10);
                break;
            case EAWSRuntime::nodejs10_x:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs10_x);
                break;
            case EAWSRuntime::nodejs12_x:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs12_x);
                break;
            case EAWSRuntime::nodejs14_x:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs14_x);
                break;
            case EAWSRuntime::nodejs16_x:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs16_x);
                break;
            case EAWSRuntime::java8:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::java8);
                break;
            case EAWSRuntime::java8_al2:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::java8_al2);
                break;
            case EAWSRuntime::java11:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::java11);
                break;
            case EAWSRuntime::python2_7:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::python2_7);
                break;
            case EAWSRuntime::python3_6:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::python3_6);
                break;
            case EAWSRuntime::python3_7:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::python3_7);
                break;
            case EAWSRuntime::python3_8:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::python3_8);
                break;
            case EAWSRuntime::python3_9:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::python3_9);
                break;
            case EAWSRuntime::dotnetcore1_0:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::dotnetcore1_0);
                break;
            case EAWSRuntime::dotnetcore2_0:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::dotnetcore2_0);
                break;
            case EAWSRuntime::dotnetcore2_1:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::dotnetcore2_1);
                break;
            case EAWSRuntime::dotnetcore3_1:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::dotnetcore3_1);
                break;
            case EAWSRuntime::dotnet6:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::dotnet6);
                break;
            case EAWSRuntime::nodejs4_3_edge:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs4_3_edge);
                break;
            case EAWSRuntime::go1_x:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::go1_x);
                break;
            case EAWSRuntime::ruby2_5:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::ruby2_5);
                break;
            case EAWSRuntime::ruby2_7:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::ruby2_7);
                break;
            case EAWSRuntime::provided:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::provided);
                break;
            case EAWSRuntime::provided_al2:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::provided_al2);
                break;
            case EAWSRuntime::nodejs18_x:
                awsListLayersRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs18_x);
                break;
            default:
                break;
            }

		if (!(this->marker.IsEmpty())) {
            awsListLayersRequest.SetMarker(TCHAR_TO_UTF8(*this->marker));
        }

        if (!(this->maxItems == 0)) {
            awsListLayersRequest.SetMaxItems(this->maxItems);
        }

        switch(this->compatibleArchitecture) {
            case EAWSLambdaArchitecture::x86_64:
                awsListLayersRequest.SetCompatibleArchitecture(Aws::Lambda::Model::Architecture::x86_64);
                break;
            case EAWSLambdaArchitecture::arm64:
                awsListLayersRequest.SetCompatibleArchitecture(Aws::Lambda::Model::Architecture::arm64);
                break;
            default:
                break;
        }

        return awsListLayersRequest;
    }

    bool IsEmpty() const {
        return this->compatibleRuntime == EAWSRuntime::NOT_SET && this->marker.IsEmpty() && this->maxItems == 0 && this->compatibleArchitecture == EAWSLambdaArchitecture::NOT_SET;
    }
#endif
};
