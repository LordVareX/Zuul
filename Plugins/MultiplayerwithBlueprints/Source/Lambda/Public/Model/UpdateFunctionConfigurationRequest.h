/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/UpdateFunctionConfigurationRequest.h"

#endif

#include "Model/VpcConfig.h"
#include "Model/Environment.h"
#include "Model/Runtime.h"
#include "Model/DeadLetterConfig.h"
#include "Model/TracingConfig.h"
#include "Model/FileSystemConfig.h"
#include "Model/AWSLambdaImageConfig.h"
#include "Model/AWSLambdaEphemeralStorage.h"
#include "Model/AWSLambdaSnapStart.h"

#include "UpdateFunctionConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateFunctionConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Lambda function.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> – <code>my-function</code>.</p> </li> <li> <p> <b>Function ARN</b> – <code>arn:aws:lambda:us-west-2:123456789012:function:my-function</code>.</p> </li> <li> <p> <b>Partial ARN</b> – <code>123456789012:function:my-function</code>.</p> </li> </ul> <p>The length constraint applies only to the full ARN. If you specify only the function name, it is limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
    *  <p>The Amazon Resource Name (ARN) of the function's execution role.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString role;

    /**
    *  <p>The name of the method within your code that Lambda calls to run your function. Handler is required if the deployment package is a .zip file archive. The format includes the file name. It can also include namespaces and other qualifiers, depending on the runtime. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/foundation-progmodel.html">Lambda programming model</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString handler;

    /**
    *  <p>A description of the function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString description;

    /**
    *  <p>The amount of time (in seconds) that Lambda allows a function to run before stopping it. The default is 3 seconds. The maximum allowed value is 900 seconds. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/runtimes-context.html">Lambda execution environment</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int timeout = 0;

    /**
    *  <p>The amount of <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-function-common.html#configuration-memory-console">memory available to the function</a> at runtime. Increasing the function memory also increases its CPU allocation. The default value is 128 MB. The value can be any multiple of 1 MB.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int memorySize = 0;

    /**
    *  <p>For network connectivity to Amazon Web Services resources in a VPC, specify a list of security groups and subnets in the VPC. When you connect a function to a VPC, it can access resources and the internet only through that VPC. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-vpc.html">Configuring a Lambda function to access resources in a VPC</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FVpcConfig vpcConfig;

    /**
    *  <p>Environment variables that are accessible from function code during execution.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FEnvironment environment;

    /**
    *  <p>The identifier of the function's <a href="https://docs.aws.amazon.com/lambda/latest/dg/lambda-runtimes.html">runtime</a>. Runtime is required if the deployment package is a .zip file archive. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSRuntime runtime = EAWSRuntime::NOT_SET;

    /**
    *  <p>A dead-letter queue configuration that specifies the queue or topic where Lambda sends asynchronous events when they fail processing. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/invocation-async.html#invocation-dlq">Dead-letter queues</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FDeadLetterConfig deadLetterConfig;

    /**
    *  <p>The ARN of the Key Management Service (KMS) key that's used to encrypt your function's environment variables. If it's not provided, Lambda uses a default service key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString kMSKeyArn;

    /**
    *  <p>Set <code>Mode</code> to <code>Active</code> to sample and trace a subset of incoming requests with <a href="https://docs.aws.amazon.com/lambda/latest/dg/services-xray.html">X-Ray</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FTracingConfig tracingConfig;

    /**
    *  <p>Update the function only if the revision ID matches the ID that's specified. Use this option to avoid modifying a function that has changed since you last read it.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString revisionId;

    /**
    *  <p>A list of <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-layers.html">function layers</a> to add to the function's execution environment. Specify each layer by its ARN, including the version.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FString> layers;

    /**
    *  <p>Connection settings for an Amazon EFS file system.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FFileSystemConfig> fileSystemConfigs;

    /**
    *  <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/images-parms.html">Container image configuration values</a> that override the values in the container image Docker file.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaImageConfig imageConfig;

    /**
    *  <p>The size of the function's <code>/tmp</code> directory in MB. The default value is 512, but can be any whole number between 512 and 10,240 MB.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaEphemeralStorage ephemeralStorage;

    /**
    *  <p>The function's <a href="https://docs.aws.amazon.com/lambda/latest/dg/snapstart.html">SnapStart</a> setting.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaSnapStart snapStart;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::UpdateFunctionConfigurationRequest toAWS() const {
        Aws::Lambda::Model::UpdateFunctionConfigurationRequest awsUpdateFunctionConfigurationRequest;

		if (!(this->functionName.IsEmpty())) {
            awsUpdateFunctionConfigurationRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

		if (!(this->role.IsEmpty())) {
            awsUpdateFunctionConfigurationRequest.SetRole(TCHAR_TO_UTF8(*this->role));
        }

		if (!(this->handler.IsEmpty())) {
            awsUpdateFunctionConfigurationRequest.SetHandler(TCHAR_TO_UTF8(*this->handler));
        }

		if (!(this->description.IsEmpty())) {
            awsUpdateFunctionConfigurationRequest.SetDescription(TCHAR_TO_UTF8(*this->description));
        }

        if (this->timeout != 0) {
            awsUpdateFunctionConfigurationRequest.SetTimeout(this->timeout);
        }

        if (this->memorySize != 0) {
            awsUpdateFunctionConfigurationRequest.SetMemorySize(this->memorySize);
        }

        if (!(this->vpcConfig.IsEmpty())) {
            awsUpdateFunctionConfigurationRequest.SetVpcConfig(this->vpcConfig.toAWS());
        }

        if (!(this->environment.IsEmpty())) {
            awsUpdateFunctionConfigurationRequest.SetEnvironment(this->environment.toAWS());
        }

        switch(this->runtime) {
            case EAWSRuntime::nodejs:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::nodejs);
                break;
            case EAWSRuntime::nodejs4_3:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::nodejs4_3);
                break;
            case EAWSRuntime::nodejs6_10:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::nodejs6_10);
                break;
            case EAWSRuntime::nodejs8_10:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::nodejs8_10);
                break;
            case EAWSRuntime::nodejs10_x:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::nodejs10_x);
                break;
            case EAWSRuntime::nodejs12_x:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::nodejs12_x);
                break;
            case EAWSRuntime::nodejs14_x:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::nodejs14_x);
                break;
            case EAWSRuntime::nodejs16_x:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::nodejs16_x);
                break;
            case EAWSRuntime::java8:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::java8);
                break;
            case EAWSRuntime::java8_al2:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::java8_al2);
                break;
            case EAWSRuntime::java11:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::java11);
                break;
            case EAWSRuntime::python2_7:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::python2_7);
                break;
            case EAWSRuntime::python3_6:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::python3_6);
                break;
            case EAWSRuntime::python3_7:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::python3_7);
                break;
            case EAWSRuntime::python3_8:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::python3_8);
                break;
            case EAWSRuntime::python3_9:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::python3_9);
                break;
            case EAWSRuntime::dotnetcore1_0:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::dotnetcore1_0);
                break;
            case EAWSRuntime::dotnetcore2_0:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::dotnetcore2_0);
                break;
            case EAWSRuntime::dotnetcore2_1:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::dotnetcore2_1);
                break;
            case EAWSRuntime::dotnetcore3_1:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::dotnetcore3_1);
                break;
            case EAWSRuntime::dotnet6:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::dotnet6);
                break;
            case EAWSRuntime::nodejs4_3_edge:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::nodejs4_3_edge);
                break;
            case EAWSRuntime::go1_x:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::go1_x);
                break;
            case EAWSRuntime::ruby2_5:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::ruby2_5);
                break;
            case EAWSRuntime::ruby2_7:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::ruby2_7);
                break;
            case EAWSRuntime::provided:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::provided);
                break;
            case EAWSRuntime::provided_al2:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::provided_al2);
                break;
            case EAWSRuntime::nodejs18_x:
                awsUpdateFunctionConfigurationRequest.SetRuntime(Aws::Lambda::Model::Runtime::nodejs18_x);
                break;
            default:
                break;
        }

        if (!(this->deadLetterConfig.IsEmpty())) {
            awsUpdateFunctionConfigurationRequest.SetDeadLetterConfig(this->deadLetterConfig.toAWS());
        }

		if (!(this->kMSKeyArn.IsEmpty())) {
            awsUpdateFunctionConfigurationRequest.SetKMSKeyArn(TCHAR_TO_UTF8(*this->kMSKeyArn));
        }

        if (!(this->tracingConfig.IsEmpty())) {
            awsUpdateFunctionConfigurationRequest.SetTracingConfig(this->tracingConfig.toAWS());
        }

		if (!(this->revisionId.IsEmpty())) {
            awsUpdateFunctionConfigurationRequest.SetRevisionId(TCHAR_TO_UTF8(*this->revisionId));
        }

        for (const FString& elem : this->layers) {
            awsUpdateFunctionConfigurationRequest.AddLayers(TCHAR_TO_UTF8(*elem));
        }

        for (const FFileSystemConfig& elem : this->fileSystemConfigs) {
            awsUpdateFunctionConfigurationRequest.AddFileSystemConfigs(elem.toAWS());
        }

        if (!(this->imageConfig.IsEmpty())) {
            awsUpdateFunctionConfigurationRequest.SetImageConfig(this->imageConfig.toAWS());
        }

        if (!(this->ephemeralStorage.IsEmpty())) {
            awsUpdateFunctionConfigurationRequest.SetEphemeralStorage(this->ephemeralStorage.toAWS());
        }

        if (!(this->snapStart.IsEmpty())) {
            awsUpdateFunctionConfigurationRequest.SetSnapStart(this->snapStart.toAWS());
        }

        return awsUpdateFunctionConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && this->role.IsEmpty() && this->handler.IsEmpty() && this->description.IsEmpty() && this->timeout == 0 && this->memorySize == 0 && this->vpcConfig.IsEmpty() && this->environment.IsEmpty() && this->runtime == EAWSRuntime::NOT_SET && this->deadLetterConfig.IsEmpty() && this->kMSKeyArn.IsEmpty() && this->tracingConfig.IsEmpty() && this->revisionId.IsEmpty() && this->layers.Num() == 0 && this->fileSystemConfigs.Num() == 0 && this->imageConfig.IsEmpty() && this->ephemeralStorage.IsEmpty() && this->snapStart.IsEmpty();
    }
#endif
};
