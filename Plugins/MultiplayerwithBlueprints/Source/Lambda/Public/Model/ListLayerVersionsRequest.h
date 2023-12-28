/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListLayerVersionsRequest.h"

#endif

#include "Model/Runtime.h"
#include "Model/AWSLambdaArchitecture.h"

#include "ListLayerVersionsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListLayerVersionsRequest {
GENERATED_BODY()

    /**
    *  <p>A runtime identifier. For example, <code>go1.x</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSRuntime compatibleRuntime = EAWSRuntime::NOT_SET;

    /**
    *  <p>The name or Amazon Resource Name (ARN) of the layer.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString layerName;

    /**
    *  <p>A pagination token returned by a previous call.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString marker;

    /**
    *  <p>The maximum number of versions to return.</p>
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
    Aws::Lambda::Model::ListLayerVersionsRequest toAWS() const {
        Aws::Lambda::Model::ListLayerVersionsRequest awsListLayerVersionsRequest;

        switch(this->compatibleRuntime) {
            case EAWSRuntime::nodejs:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs);
                break;
            case EAWSRuntime::nodejs4_3:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs4_3);
                break;
            case EAWSRuntime::nodejs6_10:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs6_10);
                break;
            case EAWSRuntime::nodejs8_10:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs8_10);
                break;
            case EAWSRuntime::nodejs10_x:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs10_x);
                break;
            case EAWSRuntime::nodejs12_x:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs12_x);
                break;
            case EAWSRuntime::nodejs14_x:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs14_x);
                break;
            case EAWSRuntime::nodejs16_x:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs16_x);
                break;
            case EAWSRuntime::java8:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::java8);
                break;
            case EAWSRuntime::java8_al2:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::java8_al2);
                break;
            case EAWSRuntime::java11:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::java11);
                break;
            case EAWSRuntime::python2_7:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::python2_7);
                break;
            case EAWSRuntime::python3_6:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::python3_6);
                break;
            case EAWSRuntime::python3_7:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::python3_7);
                break;
            case EAWSRuntime::python3_8:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::python3_8);
                break;
            case EAWSRuntime::python3_9:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::python3_9);
                break;
            case EAWSRuntime::dotnetcore1_0:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::dotnetcore1_0);
                break;
            case EAWSRuntime::dotnetcore2_0:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::dotnetcore2_0);
                break;
            case EAWSRuntime::dotnetcore2_1:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::dotnetcore2_1);
                break;
            case EAWSRuntime::dotnetcore3_1:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::dotnetcore3_1);
                break;
            case EAWSRuntime::dotnet6:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::dotnet6);
                break;
            case EAWSRuntime::nodejs4_3_edge:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs4_3_edge);
                break;
            case EAWSRuntime::go1_x:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::go1_x);
                break;
            case EAWSRuntime::ruby2_5:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::ruby2_5);
                break;
            case EAWSRuntime::ruby2_7:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::ruby2_7);
                break;
            case EAWSRuntime::provided:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::provided);
                break;
            case EAWSRuntime::provided_al2:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::provided_al2);
                break;
            case EAWSRuntime::nodejs18_x:
                awsListLayerVersionsRequest.SetCompatibleRuntime(Aws::Lambda::Model::Runtime::nodejs18_x);
                break;
            default:
                break;
        }

		if (!(this->layerName.IsEmpty())) {
            awsListLayerVersionsRequest.SetLayerName(TCHAR_TO_UTF8(*this->layerName));
        }

		if (!(this->marker.IsEmpty())) {
            awsListLayerVersionsRequest.SetMarker(TCHAR_TO_UTF8(*this->marker));
        }

        if (this->maxItems != 0) {
            awsListLayerVersionsRequest.SetMaxItems(this->maxItems);
        }

        switch(this->compatibleArchitecture) {
            case EAWSLambdaArchitecture::x86_64:
                awsListLayerVersionsRequest.SetCompatibleArchitecture(Aws::Lambda::Model::Architecture::x86_64);
                break;
            case EAWSLambdaArchitecture::arm64:
                awsListLayerVersionsRequest.SetCompatibleArchitecture(Aws::Lambda::Model::Architecture::arm64);
                break;
            default:
                break;
        }

        return awsListLayerVersionsRequest;
    }

    bool IsEmpty() const {
        return this->compatibleRuntime == EAWSRuntime::NOT_SET && this->layerName.IsEmpty() && this->marker.IsEmpty() && this->maxItems == 0 && this->compatibleArchitecture == EAWSLambdaArchitecture::NOT_SET;
    }
#endif
};
