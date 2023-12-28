/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/LatentActionManager.h"

#include "Auth/AWSCoreCredentials.h"
#include "Client/AWSClientConfiguration.h"

#include "LambdaError.h"

#include "Model/AddLayerVersionPermissionRequest.h"
#include "Model/AddPermissionRequest.h"
#include "Model/LambdaCreateAliasRequest.h"
#include "Model/AWSLambdaCreateCodeSigningConfigRequest.h"
#include "Model/CreateEventSourceMappingRequest.h"
#include "Model/CreateFunctionRequest.h"
#include "Model/AWSLambdaCreateFunctionUrlConfigRequest.h"
#include "Model/LambdaDeleteAliasRequest.h"
#include "Model/AWSLambdaDeleteCodeSigningConfigRequest.h"
#include "Model/DeleteEventSourceMappingRequest.h"
#include "Model/DeleteFunctionRequest.h"
#include "Model/AWSLambdaDeleteFunctionCodeSigningConfigRequest.h"
#include "Model/DeleteFunctionConcurrencyRequest.h"
#include "Model/DeleteFunctionEventInvokeConfigRequest.h"
#include "Model/AWSLambdaDeleteFunctionUrlConfigRequest.h"
#include "Model/DeleteLayerVersionRequest.h"
#include "Model/DeleteProvisionedConcurrencyConfigRequest.h"
#include "Model/GetAccountSettingsRequest.h"
#include "Model/GetAliasRequest.h"
#include "Model/AWSLambdaGetCodeSigningConfigRequest.h"
#include "Model/GetEventSourceMappingRequest.h"
#include "Model/GetFunctionRequest.h"
#include "Model/AWSLambdaGetFunctionCodeSigningConfigRequest.h"
#include "Model/GetFunctionConcurrencyRequest.h"
#include "Model/GetFunctionConfigurationRequest.h"
#include "Model/GetFunctionEventInvokeConfigRequest.h"
#include "Model/AWSLambdaGetFunctionUrlConfigRequest.h"
#include "Model/GetLayerVersionRequest.h"
#include "Model/GetLayerVersionByArnRequest.h"
#include "Model/GetLayerVersionPolicyRequest.h"
#include "Model/GetPolicyRequest.h"
#include "Model/GetProvisionedConcurrencyConfigRequest.h"
#include "Model/InvokeRequest.h"
#include "Model/LambdaListAliasesRequest.h"
#include "Model/AWSLambdaListCodeSigningConfigsRequest.h"
#include "Model/ListEventSourceMappingsRequest.h"
#include "Model/ListFunctionEventInvokeConfigsRequest.h"
#include "Model/AWSLambdaListFunctionUrlConfigsRequest.h"
#include "Model/ListFunctionsRequest.h"
#include "Model/AWSLambdaListFunctionsByCodeSigningConfigRequest.h"
#include "Model/ListLayerVersionsRequest.h"
#include "Model/ListLayersRequest.h"
#include "Model/ListProvisionedConcurrencyConfigsRequest.h"
#include "Model/ListTagsRequest.h"
#include "Model/ListVersionsByFunctionRequest.h"
#include "Model/PublishLayerVersionRequest.h"
#include "Model/PublishVersionRequest.h"
#include "Model/AWSLambdaPutFunctionCodeSigningConfigRequest.h"
#include "Model/PutFunctionConcurrencyRequest.h"
#include "Model/PutFunctionEventInvokeConfigRequest.h"
#include "Model/PutProvisionedConcurrencyConfigRequest.h"
#include "Model/RemoveLayerVersionPermissionRequest.h"
#include "Model/RemovePermissionRequest.h"
#include "Model/LambdaTagResourceRequest.h"
#include "Model/LambdaUntagResourceRequest.h"
#include "Model/LambdaUpdateAliasRequest.h"
#include "Model/AWSLambdaUpdateCodeSigningConfigRequest.h"
#include "Model/UpdateEventSourceMappingRequest.h"
#include "Model/UpdateFunctionCodeRequest.h"
#include "Model/UpdateFunctionConfigurationRequest.h"
#include "Model/UpdateFunctionEventInvokeConfigRequest.h"
#include "Model/AWSLambdaUpdateFunctionUrlConfigRequest.h"

#include "Model/AddLayerVersionPermissionResult.h"
#include "Model/AddPermissionResult.h"
#include "Model/LambdaCreateAliasResult.h"
#include "Model/AWSLambdaCreateCodeSigningConfigResult.h"
#include "Model/CreateEventSourceMappingResult.h"
#include "Model/CreateFunctionResult.h"
#include "Model/AWSLambdaCreateFunctionUrlConfigResult.h"
#include "Model/AWSLambdaDeleteCodeSigningConfigResult.h"
#include "Model/DeleteEventSourceMappingResult.h"
#include "Model/GetAccountSettingsResult.h"
#include "Model/GetAliasResult.h"
#include "Model/AWSLambdaGetCodeSigningConfigResult.h"
#include "Model/GetEventSourceMappingResult.h"
#include "Model/GetFunctionResult.h"
#include "Model/AWSLambdaGetFunctionCodeSigningConfigResult.h"
#include "Model/GetFunctionConcurrencyResult.h"
#include "Model/GetFunctionConfigurationResult.h"
#include "Model/GetFunctionEventInvokeConfigResult.h"
#include "Model/AWSLambdaGetFunctionUrlConfigResult.h"
#include "Model/GetLayerVersionResult.h"
#include "Model/GetLayerVersionByArnResult.h"
#include "Model/GetLayerVersionPolicyResult.h"
#include "Model/GetPolicyResult.h"
#include "Model/GetProvisionedConcurrencyConfigResult.h"
#include "Model/InvokeResult.h"
#include "Model/LambdaListAliasesResult.h"
#include "Model/AWSLambdaListCodeSigningConfigsResult.h"
#include "Model/ListEventSourceMappingsResult.h"
#include "Model/ListFunctionEventInvokeConfigsResult.h"
#include "Model/AWSLambdaListFunctionUrlConfigsResult.h"
#include "Model/ListFunctionsResult.h"
#include "Model/AWSLambdaListFunctionsByCodeSigningConfigResult.h"
#include "Model/ListLayerVersionsResult.h"
#include "Model/ListLayersResult.h"
#include "Model/ListProvisionedConcurrencyConfigsResult.h"
#include "Model/ListTagsResult.h"
#include "Model/ListVersionsByFunctionResult.h"
#include "Model/PublishLayerVersionResult.h"
#include "Model/PublishVersionResult.h"
#include "Model/AWSLambdaPutFunctionCodeSigningConfigResult.h"
#include "Model/PutFunctionConcurrencyResult.h"
#include "Model/PutFunctionEventInvokeConfigResult.h"
#include "Model/PutProvisionedConcurrencyConfigResult.h"
#include "Model/LambdaUpdateAliasResult.h"
#include "Model/AWSLambdaUpdateCodeSigningConfigResult.h"
#include "Model/UpdateEventSourceMappingResult.h"
#include "Model/UpdateFunctionCodeResult.h"
#include "Model/UpdateFunctionConfigurationResult.h"
#include "Model/UpdateFunctionEventInvokeConfigResult.h"
#include "Model/AWSLambdaUpdateFunctionUrlConfigResult.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/LambdaClient.h"

#endif

#include "LambdaClientObject.generated.h"

/**
*  <fullname>AWS Lambda</fullname> <p> <b>Overview</b> </p> <p>This is the <i>AWS Lambda API Reference</i>. The AWS Lambda Developer Guide provides additional information. For the service overview, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/welcome.html">What is AWS Lambda</a>, and for information about how the service works, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/lambda-introduction.html">AWS Lambda: How it Works</a> in the <b>AWS Lambda Developer Guide</b>.</p>
**/
UCLASS(BlueprintType)
class LAMBDA_API ULambdaClientObject : public UObject {
    GENERATED_BODY()

public:
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    Aws::Lambda::LambdaClient *awsLambdaClient;
#endif

    /**
    * public static ULambdaClientObject::CreateLambdaObject
    * Creates a LambdaClientObject. This function must be called first before accessing any Lambda client functions.
    * @param credentials [FAWSCredentials] .
    * @param clientConfiguration [FClientConfiguration] .
    * @return [ULambdaClient*] Returns ULambdaClient*.
    **/
    UFUNCTION(BlueprintCallable, Category = "Lambda Client")
    static ULambdaClientObject *
    CreateLambdaObject(const FAWSCredentials &credentials, const FAWSClientConfiguration &clientConfiguration);

    /**
    * <p>Adds permissions to the resource-based policy of a version of an <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-layers.html">Lambda layer</a>. Use this action to grant layer usage permission to other accounts. You can grant permission to a single account, all accounts in an organization, or all Amazon Web Services accounts. </p> <p>To revoke permission, call <a>RemoveLayerVersionPermission</a> with the statement ID that you specified when you added it.</p>
    * @param
    * @param addLayerVersionPermissionRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void AddLayerVersionPermission (
        UObject *WorldContextObject,
        bool &success,
        FAddLayerVersionPermissionRequest addLayerVersionPermissionRequest,
        FAddLayerVersionPermissionResult &addLayerVersionPermissionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Grants an Amazon Web Service, Amazon Web Services account, or Amazon Web Services organization permission to use a function. You can apply the policy at the function level, or specify a qualifier to restrict access to a single version or alias. If you use a qualifier, the invoker must use the full Amazon Resource Name (ARN) of that version or alias to invoke the function. Note: Lambda does not support adding policies to version $LATEST.</p> <p>To grant permission to another account, specify the account ID as the <code>Principal</code>. To grant permission to an organization defined in Organizations, specify the organization ID as the <code>PrincipalOrgID</code>. For Amazon Web Services, the principal is a domain-style identifier that the service defines, such as <code>s3.amazonaws.com</code> or <code>sns.amazonaws.com</code>. For Amazon Web Services, you can also specify the ARN of the associated resource as the <code>SourceArn</code>. If you grant permission to a service principal without specifying the source, other accounts could potentially configure resources in their account to invoke your Lambda function.</p> <p>This operation adds a statement to a resource-based permissions policy for the function. For more information about function policies, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/access-control-resource-based.html">Using resource-based policies for Lambda</a>.</p>
    * @param
    * @param addPermissionRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void AddPermission (
        UObject *WorldContextObject,
        bool &success,
        FAddPermissionRequest addPermissionRequest,
        FAddPermissionResult &addPermissionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Creates an <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-aliases.html">alias</a> for a Lambda function version. Use aliases to provide clients with a function identifier that you can update to invoke a different version.</p> <p>You can also map an alias to split invocation requests between two versions. Use the <code>RoutingConfig</code> parameter to specify a second version and the percentage of invocation requests that it receives.</p>
    * @param
    * @param createAliasRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void CreateAlias (
        UObject *WorldContextObject,
        bool &success,
        FLambdaCreateAliasRequest createAliasRequest,
        FLambdaCreateAliasResult &createAliasResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Creates a code signing configuration. A <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-codesigning.html">code signing configuration</a> defines a list of allowed signing profiles and defines the code-signing validation policy (action to be taken if deployment validation checks fail). </p>
    * @param
    * @param createCodeSigningConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void CreateCodeSigningConfig (
        UObject *WorldContextObject,
        bool &success,
        FAWSLambdaCreateCodeSigningConfigRequest createCodeSigningConfigRequest,
        FAWSLambdaCreateCodeSigningConfigResult &createCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Creates a mapping between an event source and an Lambda function. Lambda reads items from the event source and invokes the function.</p> <p>For details about how to configure different event sources, see the following topics. </p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-ddb.html#services-dynamodb-eventsourcemapping"> Amazon DynamoDB Streams</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-kinesis.html#services-kinesis-eventsourcemapping"> Amazon Kinesis</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-sqs.html#events-sqs-eventsource"> Amazon SQS</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-mq.html#services-mq-eventsourcemapping"> Amazon MQ and RabbitMQ</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-msk.html"> Amazon MSK</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/kafka-smaa.html"> Apache Kafka</a> </p> </li> </ul> <p>The following error handling options are available only for stream sources (DynamoDB and Kinesis):</p> <ul> <li> <p> <code>BisectBatchOnFunctionError</code> – If the function returns an error, split the batch in two and retry.</p> </li> <li> <p> <code>DestinationConfig</code> – Send discarded records to an Amazon SQS queue or Amazon SNS topic.</p> </li> <li> <p> <code>MaximumRecordAgeInSeconds</code> – Discard records older than the specified age. The default value is infinite (-1). When set to infinite (-1), failed records are retried until the record expires</p> </li> <li> <p> <code>MaximumRetryAttempts</code> – Discard records after the specified number of retries. The default value is infinite (-1). When set to infinite (-1), failed records are retried until the record expires.</p> </li> <li> <p> <code>ParallelizationFactor</code> – Process multiple batches from each shard concurrently.</p> </li> </ul> <p>For information about which configuration parameters apply to each event source, see the following topics.</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-ddb.html#services-ddb-params"> Amazon DynamoDB Streams</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-kinesis.html#services-kinesis-params"> Amazon Kinesis</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-sqs.html#services-sqs-params"> Amazon SQS</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-mq.html#services-mq-params"> Amazon MQ and RabbitMQ</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-msk.html#services-msk-parms"> Amazon MSK</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-kafka.html#services-kafka-parms"> Apache Kafka</a> </p> </li> </ul>
    * @param
    * @param createEventSourceMappingRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void CreateEventSourceMapping (
        UObject *WorldContextObject,
        bool &success,
        FCreateEventSourceMappingRequest createEventSourceMappingRequest,
        FCreateEventSourceMappingResult &createEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Creates a Lambda function. To create a function, you need a <a href="https://docs.aws.amazon.com/lambda/latest/dg/gettingstarted-package.html">deployment package</a> and an <a href="https://docs.aws.amazon.com/lambda/latest/dg/intro-permission-model.html#lambda-intro-execution-role">execution role</a>. The deployment package is a .zip file archive or container image that contains your function code. The execution role grants the function permission to use Amazon Web Services, such as Amazon CloudWatch Logs for log streaming and X-Ray for request tracing.</p> <p>If the deployment package is a <a href="https://docs.aws.amazon.com/lambda/latest/dg/lambda-images.html">container image</a>, then you set the package type to <code>Image</code>. For a container image, the code property must include the URI of a container image in the Amazon ECR registry. You do not need to specify the handler and runtime properties.</p> <p>If the deployment package is a <a href="https://docs.aws.amazon.com/lambda/latest/dg/gettingstarted-package.html#gettingstarted-package-zip">.zip file archive</a>, then you set the package type to <code>Zip</code>. For a .zip file archive, the code property specifies the location of the .zip file. You must also specify the handler and runtime properties. The code in the deployment package must be compatible with the target instruction set architecture of the function (<code>x86-64</code> or <code>arm64</code>). If you do not specify the architecture, then the default value is <code>x86-64</code>.</p> <p>When you create a function, Lambda provisions an instance of the function and its supporting resources. If your function connects to a VPC, this process can take a minute or so. During this time, you can't invoke or modify the function. The <code>State</code>, <code>StateReason</code>, and <code>StateReasonCode</code> fields in the response from <a>GetFunctionConfiguration</a> indicate when the function is ready to invoke. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/functions-states.html">Lambda function states</a>.</p> <p>A function has an unpublished version, and can have published versions and aliases. The unpublished version changes when you update your function's code and configuration. A published version is a snapshot of your function code and configuration that can't be changed. An alias is a named resource that maps to a version, and can be changed to map to a different version. Use the <code>Publish</code> parameter to create version <code>1</code> of your function from its initial configuration.</p> <p>The other parameters let you configure version-specific and function-level settings. You can modify version-specific settings later with <a>UpdateFunctionConfiguration</a>. Function-level settings apply to both the unpublished and published versions of the function, and include tags (<a>TagResource</a>) and per-function concurrency limits (<a>PutFunctionConcurrency</a>).</p> <p>You can use code signing if your deployment package is a .zip file archive. To enable code signing for this function, specify the ARN of a code-signing configuration. When a user attempts to deploy a code package with <a>UpdateFunctionCode</a>, Lambda checks that the code package has a valid signature from a trusted publisher. The code-signing configuration includes set of signing profiles, which define the trusted publishers for this function.</p> <p>If another Amazon Web Services account or an Amazon Web Service invokes your function, use <a>AddPermission</a> to grant permission by creating a resource-based Identity and Access Management (IAM) policy. You can grant permissions at the function level, on a version, or on an alias.</p> <p>To invoke your function directly, use <a>Invoke</a>. To invoke your function in response to events in other Amazon Web Services, create an event source mapping (<a>CreateEventSourceMapping</a>), or configure a function trigger in the other service. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/lambda-invocation.html">Invoking Lambda functions</a>.</p>
    * @param
    * @param createFunctionRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void CreateFunction (
        UObject *WorldContextObject,
        bool &success,
        FCreateFunctionRequest createFunctionRequest,
        FCreateFunctionResult &createFunctionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Creates a Lambda function URL with the specified configuration parameters. A function URL is a dedicated HTTP(S) endpoint that you can use to invoke your function.</p>
    * @param
    * @param createFunctionUrlConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void CreateFunctionUrlConfig (
        UObject *WorldContextObject,
        bool &success,
        FAWSLambdaCreateFunctionUrlConfigRequest createFunctionUrlConfigRequest,
        FAWSLambdaCreateFunctionUrlConfigResult &createFunctionUrlConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Deletes a Lambda function <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-aliases.html">alias</a>.</p>
    * @param
    * @param deleteAliasRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void DeleteAlias (
        UObject *WorldContextObject,
        bool &success,
        FLambdaDeleteAliasRequest deleteAliasRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Deletes the code signing configuration. You can delete the code signing configuration only if no function is using it. </p>
    * @param
    * @param deleteCodeSigningConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void DeleteCodeSigningConfig (
        UObject *WorldContextObject,
        bool &success,
        FAWSLambdaDeleteCodeSigningConfigRequest deleteCodeSigningConfigRequest,
        FAWSLambdaDeleteCodeSigningConfigResult &deleteCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Deletes an <a href="https://docs.aws.amazon.com/lambda/latest/dg/intro-invocation-modes.html">event source mapping</a>. You can get the identifier of a mapping from the output of <a>ListEventSourceMappings</a>.</p> <p>When you delete an event source mapping, it enters a <code>Deleting</code> state and might not be completely deleted for several seconds.</p>
    * @param
    * @param deleteEventSourceMappingRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void DeleteEventSourceMapping (
        UObject *WorldContextObject,
        bool &success,
        FDeleteEventSourceMappingRequest deleteEventSourceMappingRequest,
        FDeleteEventSourceMappingResult &deleteEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Deletes a Lambda function. To delete a specific function version, use the <code>Qualifier</code> parameter. Otherwise, all versions and aliases are deleted.</p> <p>To delete Lambda event source mappings that invoke a function, use <a>DeleteEventSourceMapping</a>. For Amazon Web Services and resources that invoke your function directly, delete the trigger in the service where you originally configured it.</p>
    * @param
    * @param deleteFunctionRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void DeleteFunction (
        UObject *WorldContextObject,
        bool &success,
        FDeleteFunctionRequest deleteFunctionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Removes the code signing configuration from the function.</p>
    * @param
    * @param deleteFunctionCodeSigningConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void DeleteFunctionCodeSigningConfig (
        UObject *WorldContextObject,
        bool &success,
        FAWSLambdaDeleteFunctionCodeSigningConfigRequest deleteFunctionCodeSigningConfigRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Removes a concurrent execution limit from a function.</p>
    * @param
    * @param deleteFunctionConcurrencyRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void DeleteFunctionConcurrency (
        UObject *WorldContextObject,
        bool &success,
        FDeleteFunctionConcurrencyRequest deleteFunctionConcurrencyRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Deletes the configuration for asynchronous invocation for a function, version, or alias.</p> <p>To configure options for asynchronous invocation, use <a>PutFunctionEventInvokeConfig</a>.</p>
    * @param
    * @param deleteFunctionEventInvokeConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void DeleteFunctionEventInvokeConfig (
        UObject *WorldContextObject,
        bool &success,
        FDeleteFunctionEventInvokeConfigRequest deleteFunctionEventInvokeConfigRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Deletes a Lambda function URL. When you delete a function URL, you can't recover it. Creating a new function URL results in a different URL address.</p>
    * @param
    * @param deleteFunctionUrlConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void DeleteFunctionUrlConfig (
        UObject *WorldContextObject,
        bool &success,
        FAWSLambdaDeleteFunctionUrlConfigRequest deleteFunctionUrlConfigRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Deletes a version of an <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-layers.html">Lambda layer</a>. Deleted versions can no longer be viewed or added to functions. To avoid breaking functions, a copy of the version remains in Lambda until no functions refer to it.</p>
    * @param
    * @param deleteLayerVersionRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void DeleteLayerVersion (
        UObject *WorldContextObject,
        bool &success,
        FDeleteLayerVersionRequest deleteLayerVersionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Deletes the provisioned concurrency configuration for a function.</p>
    * @param
    * @param deleteProvisionedConcurrencyConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void DeleteProvisionedConcurrencyConfig (
        UObject *WorldContextObject,
        bool &success,
        FDeleteProvisionedConcurrencyConfigRequest deleteProvisionedConcurrencyConfigRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Retrieves details about your account's <a href="https://docs.aws.amazon.com/lambda/latest/dg/limits.html">limits</a> and usage in an Amazon Web Services Region.</p>
    * @param
    * @param getAccountSettingsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void GetAccountSettings (
        UObject *WorldContextObject,
        bool &success,
        FGetAccountSettingsRequest getAccountSettingsRequest,
        FGetAccountSettingsResult &getAccountSettingsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns details about a Lambda function <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-aliases.html">alias</a>.</p>
    * @param
    * @param getAliasRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void GetAlias (
        UObject *WorldContextObject,
        bool &success,
        FGetAliasRequest getAliasRequest,
        FGetAliasResult &getAliasResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns information about the specified code signing configuration.</p>
    * @param
    * @param getCodeSigningConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void GetCodeSigningConfig (
        UObject *WorldContextObject,
        bool &success,
        FAWSLambdaGetCodeSigningConfigRequest getCodeSigningConfigRequest,
        FAWSLambdaGetCodeSigningConfigResult &getCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns details about an event source mapping. You can get the identifier of a mapping from the output of <a>ListEventSourceMappings</a>.</p>
    * @param
    * @param getEventSourceMappingRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void GetEventSourceMapping (
        UObject *WorldContextObject,
        bool &success,
        FGetEventSourceMappingRequest getEventSourceMappingRequest,
        FGetEventSourceMappingResult &getEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns information about the function or function version, with a link to download the deployment package that's valid for 10 minutes. If you specify a function version, only details that are specific to that version are returned.</p>
    * @param
    * @param getFunctionRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void GetFunction (
        UObject *WorldContextObject,
        bool &success,
        FGetFunctionRequest getFunctionRequest,
        FGetFunctionResult &getFunctionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns the code signing configuration for the specified function.</p>
    * @param
    * @param getFunctionCodeSigningConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void GetFunctionCodeSigningConfig (
        UObject *WorldContextObject,
        bool &success,
        FAWSLambdaGetFunctionCodeSigningConfigRequest getFunctionCodeSigningConfigRequest,
        FAWSLambdaGetFunctionCodeSigningConfigResult &getFunctionCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns details about the reserved concurrency configuration for a function. To set a concurrency limit for a function, use <a>PutFunctionConcurrency</a>.</p>
    * @param
    * @param getFunctionConcurrencyRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void GetFunctionConcurrency (
        UObject *WorldContextObject,
        bool &success,
        FGetFunctionConcurrencyRequest getFunctionConcurrencyRequest,
        FGetFunctionConcurrencyResult &getFunctionConcurrencyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns the version-specific settings of a Lambda function or version. The output includes only options that can vary between versions of a function. To modify these settings, use <a>UpdateFunctionConfiguration</a>.</p> <p>To get all of a function's details, including function-level settings, use <a>GetFunction</a>.</p>
    * @param
    * @param getFunctionConfigurationRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void GetFunctionConfiguration (
        UObject *WorldContextObject,
        bool &success,
        FGetFunctionConfigurationRequest getFunctionConfigurationRequest,
        FGetFunctionConfigurationResult &getFunctionConfigurationResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Retrieves the configuration for asynchronous invocation for a function, version, or alias.</p> <p>To configure options for asynchronous invocation, use <a>PutFunctionEventInvokeConfig</a>.</p>
    * @param
    * @param getFunctionEventInvokeConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void GetFunctionEventInvokeConfig (
        UObject *WorldContextObject,
        bool &success,
        FGetFunctionEventInvokeConfigRequest getFunctionEventInvokeConfigRequest,
        FGetFunctionEventInvokeConfigResult &getFunctionEventInvokeConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns details about a Lambda function URL.</p>
    * @param
    * @param getFunctionUrlConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void GetFunctionUrlConfig (
        UObject *WorldContextObject,
        bool &success,
        FAWSLambdaGetFunctionUrlConfigRequest getFunctionUrlConfigRequest,
        FAWSLambdaGetFunctionUrlConfigResult &getFunctionUrlConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns information about a version of an <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-layers.html">Lambda layer</a>, with a link to download the layer archive that's valid for 10 minutes.</p>
    * @param
    * @param getLayerVersionRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void GetLayerVersion (
        UObject *WorldContextObject,
        bool &success,
        FGetLayerVersionRequest getLayerVersionRequest,
        FGetLayerVersionResult &getLayerVersionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns information about a version of an <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-layers.html">Lambda layer</a>, with a link to download the layer archive that's valid for 10 minutes.</p>
    * @param
    * @param getLayerVersionByArnRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void GetLayerVersionByArn (
        UObject *WorldContextObject,
        bool &success,
        FGetLayerVersionByArnRequest getLayerVersionByArnRequest,
        FGetLayerVersionByArnResult &getLayerVersionByArnResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns the permission policy for a version of an <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-layers.html">Lambda layer</a>. For more information, see <a>AddLayerVersionPermission</a>.</p>
    * @param
    * @param getLayerVersionPolicyRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void GetLayerVersionPolicy (
        UObject *WorldContextObject,
        bool &success,
        FGetLayerVersionPolicyRequest getLayerVersionPolicyRequest,
        FGetLayerVersionPolicyResult &getLayerVersionPolicyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns the <a href="https://docs.aws.amazon.com/lambda/latest/dg/access-control-resource-based.html">resource-based IAM policy</a> for a function, version, or alias.</p>
    * @param
    * @param getPolicyRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void GetPolicy (
        UObject *WorldContextObject,
        bool &success,
        FGetPolicyRequest getPolicyRequest,
        FGetPolicyResult &getPolicyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Retrieves the provisioned concurrency configuration for a function's alias or version.</p>
    * @param
    * @param getProvisionedConcurrencyConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void GetProvisionedConcurrencyConfig (
        UObject *WorldContextObject,
        bool &success,
        FGetProvisionedConcurrencyConfigRequest getProvisionedConcurrencyConfigRequest,
        FGetProvisionedConcurrencyConfigResult &getProvisionedConcurrencyConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Invokes a Lambda function. You can invoke a function synchronously (and wait for the response), or asynchronously. To invoke a function asynchronously, set <code>InvocationType</code> to <code>Event</code>.</p> <p>For <a href="https://docs.aws.amazon.com/lambda/latest/dg/invocation-sync.html">synchronous invocation</a>, details about the function response, including errors, are included in the response body and headers. For either invocation type, you can find more information in the <a href="https://docs.aws.amazon.com/lambda/latest/dg/monitoring-functions.html">execution log</a> and <a href="https://docs.aws.amazon.com/lambda/latest/dg/lambda-x-ray.html">trace</a>.</p> <p>When an error occurs, your function may be invoked multiple times. Retry behavior varies by error type, client, event source, and invocation type. For example, if you invoke a function asynchronously and it returns an error, Lambda executes the function up to two more times. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/invocation-retries.html">Error handling and automatic retries in Lambda</a>.</p> <p>For <a href="https://docs.aws.amazon.com/lambda/latest/dg/invocation-async.html">asynchronous invocation</a>, Lambda adds events to a queue before sending them to your function. If your function does not have enough capacity to keep up with the queue, events may be lost. Occasionally, your function may receive the same event multiple times, even if no error occurs. To retain events that were not processed, configure your function with a <a href="https://docs.aws.amazon.com/lambda/latest/dg/invocation-async.html#invocation-dlq">dead-letter queue</a>.</p> <p>The status code in the API response doesn't reflect function errors. Error codes are reserved for errors that prevent your function from executing, such as permissions errors, <a href="https://docs.aws.amazon.com/lambda/latest/dg/gettingstarted-limits.html">quota</a> errors, or issues with your function's code and configuration. For example, Lambda returns <code>TooManyRequestsException</code> if running the function would cause you to exceed a concurrency limit at either the account level (<code>ConcurrentInvocationLimitExceeded</code>) or function level (<code>ReservedFunctionConcurrentInvocationLimitExceeded</code>).</p> <p>For functions with a long timeout, your client might disconnect during synchronous invocation while it waits for a response. Configure your HTTP client, SDK, firewall, proxy, or operating system to allow for long connections with timeout or keep-alive settings.</p> <p>This operation requires permission for the <a href="https://docs.aws.amazon.com/IAM/latest/UserGuide/list_awslambda.html">lambda:InvokeFunction</a> action. For details on how to set up permissions for cross-account invocations, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/access-control-resource-based.html#permissions-resource-xaccountinvoke">Granting function access to other accounts</a>.</p>
    * @param
    * @param invokeRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void Invoke (
        UObject *WorldContextObject,
        bool &success,
        FInvokeRequest invokeRequest,
        FInvokeResult &invokeResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns a list of <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-aliases.html">aliases</a> for a Lambda function.</p>
    * @param
    * @param listAliasesRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void ListAliases (
        UObject *WorldContextObject,
        bool &success,
        FLambdaListAliasesRequest listAliasesRequest,
        FLambdaListAliasesResult &listAliasesResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns a list of <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuring-codesigning.html">code signing configurations</a>. A request returns up to 10,000 configurations per call. You can use the <code>MaxItems</code> parameter to return fewer configurations per call. </p>
    * @param
    * @param listCodeSigningConfigsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void ListCodeSigningConfigs (
        UObject *WorldContextObject,
        bool &success,
        FAWSLambdaListCodeSigningConfigsRequest listCodeSigningConfigsRequest,
        FAWSLambdaListCodeSigningConfigsResult &listCodeSigningConfigsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Lists event source mappings. Specify an <code>EventSourceArn</code> to show only event source mappings for a single event source.</p>
    * @param
    * @param listEventSourceMappingsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void ListEventSourceMappings (
        UObject *WorldContextObject,
        bool &success,
        FListEventSourceMappingsRequest listEventSourceMappingsRequest,
        FListEventSourceMappingsResult &listEventSourceMappingsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Retrieves a list of configurations for asynchronous invocation for a function.</p> <p>To configure options for asynchronous invocation, use <a>PutFunctionEventInvokeConfig</a>.</p>
    * @param
    * @param listFunctionEventInvokeConfigsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void ListFunctionEventInvokeConfigs (
        UObject *WorldContextObject,
        bool &success,
        FListFunctionEventInvokeConfigsRequest listFunctionEventInvokeConfigsRequest,
        FListFunctionEventInvokeConfigsResult &listFunctionEventInvokeConfigsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns a list of Lambda function URLs for the specified function.</p>
    * @param
    * @param listFunctionUrlConfigsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void ListFunctionUrlConfigs (
        UObject *WorldContextObject,
        bool &success,
        FAWSLambdaListFunctionUrlConfigsRequest listFunctionUrlConfigsRequest,
        FAWSLambdaListFunctionUrlConfigsResult &listFunctionUrlConfigsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns a list of Lambda functions, with the version-specific configuration of each. Lambda returns up to 50 functions per call.</p> <p>Set <code>FunctionVersion</code> to <code>ALL</code> to include all published versions of each function in addition to the unpublished version.</p> <note> <p>The <code>ListFunctions</code> operation returns a subset of the <a>FunctionConfiguration</a> fields. To get the additional fields (State, StateReasonCode, StateReason, LastUpdateStatus, LastUpdateStatusReason, LastUpdateStatusReasonCode, RuntimeVersionConfig) for a function or version, use <a>GetFunction</a>.</p> </note>
    * @param
    * @param listFunctionsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void ListFunctions (
        UObject *WorldContextObject,
        bool &success,
        FListFunctionsRequest listFunctionsRequest,
        FListFunctionsResult &listFunctionsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>List the functions that use the specified code signing configuration. You can use this method prior to deleting a code signing configuration, to verify that no functions are using it.</p>
    * @param
    * @param listFunctionsByCodeSigningConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void ListFunctionsByCodeSigningConfig (
        UObject *WorldContextObject,
        bool &success,
        FAWSLambdaListFunctionsByCodeSigningConfigRequest listFunctionsByCodeSigningConfigRequest,
        FAWSLambdaListFunctionsByCodeSigningConfigResult &listFunctionsByCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Lists the versions of an <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-layers.html">Lambda layer</a>. Versions that have been deleted aren't listed. Specify a <a href="https://docs.aws.amazon.com/lambda/latest/dg/lambda-runtimes.html">runtime identifier</a> to list only versions that indicate that they're compatible with that runtime. Specify a compatible architecture to include only layer versions that are compatible with that architecture.</p>
    * @param
    * @param listLayerVersionsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void ListLayerVersions (
        UObject *WorldContextObject,
        bool &success,
        FListLayerVersionsRequest listLayerVersionsRequest,
        FListLayerVersionsResult &listLayerVersionsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Lists <a href="https://docs.aws.amazon.com/lambda/latest/dg/invocation-layers.html">Lambda layers</a> and shows information about the latest version of each. Specify a <a href="https://docs.aws.amazon.com/lambda/latest/dg/lambda-runtimes.html">runtime identifier</a> to list only layers that indicate that they're compatible with that runtime. Specify a compatible architecture to include only layers that are compatible with that <a href="https://docs.aws.amazon.com/lambda/latest/dg/foundation-arch.html">instruction set architecture</a>.</p>
    * @param
    * @param listLayersRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void ListLayers (
        UObject *WorldContextObject,
        bool &success,
        FListLayersRequest listLayersRequest,
        FListLayersResult &listLayersResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Retrieves a list of provisioned concurrency configurations for a function.</p>
    * @param
    * @param listProvisionedConcurrencyConfigsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void ListProvisionedConcurrencyConfigs (
        UObject *WorldContextObject,
        bool &success,
        FListProvisionedConcurrencyConfigsRequest listProvisionedConcurrencyConfigsRequest,
        FListProvisionedConcurrencyConfigsResult &listProvisionedConcurrencyConfigsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns a function's <a href="https://docs.aws.amazon.com/lambda/latest/dg/tagging.html">tags</a>. You can also view tags with <a>GetFunction</a>.</p>
    * @param
    * @param listTagsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void ListTags (
        UObject *WorldContextObject,
        bool &success,
        FListTagsRequest listTagsRequest,
        FListTagsResult &listTagsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns a list of <a href="https://docs.aws.amazon.com/lambda/latest/dg/versioning-aliases.html">versions</a>, with the version-specific configuration of each. Lambda returns up to 50 versions per call.</p>
    * @param
    * @param listVersionsByFunctionRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void ListVersionsByFunction (
        UObject *WorldContextObject,
        bool &success,
        FListVersionsByFunctionRequest listVersionsByFunctionRequest,
        FListVersionsByFunctionResult &listVersionsByFunctionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Creates an <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-layers.html">Lambda layer</a> from a ZIP archive. Each time you call <code>PublishLayerVersion</code> with the same layer name, a new version is created.</p> <p>Add layers to your function with <a>CreateFunction</a> or <a>UpdateFunctionConfiguration</a>.</p>
    * @param
    * @param publishLayerVersionRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void PublishLayerVersion (
        UObject *WorldContextObject,
        bool &success,
        FPublishLayerVersionRequest publishLayerVersionRequest,
        FPublishLayerVersionResult &publishLayerVersionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Creates a <a href="https://docs.aws.amazon.com/lambda/latest/dg/versioning-aliases.html">version</a> from the current code and configuration of a function. Use versions to create a snapshot of your function code and configuration that doesn't change.</p> <p>Lambda doesn't publish a version if the function's configuration and code haven't changed since the last version. Use <a>UpdateFunctionCode</a> or <a>UpdateFunctionConfiguration</a> to update the function before publishing a version.</p> <p>Clients can invoke versions directly or with an alias. To create an alias, use <a>CreateAlias</a>.</p>
    * @param
    * @param publishVersionRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void PublishVersion (
        UObject *WorldContextObject,
        bool &success,
        FPublishVersionRequest publishVersionRequest,
        FPublishVersionResult &publishVersionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Update the code signing configuration for the function. Changes to the code signing configuration take effect the next time a user tries to deploy a code package to the function. </p>
    * @param
    * @param putFunctionCodeSigningConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void PutFunctionCodeSigningConfig (
        UObject *WorldContextObject,
        bool &success,
        FAWSLambdaPutFunctionCodeSigningConfigRequest putFunctionCodeSigningConfigRequest,
        FAWSLambdaPutFunctionCodeSigningConfigResult &putFunctionCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Sets the maximum number of simultaneous executions for a function, and reserves capacity for that concurrency level.</p> <p>Concurrency settings apply to the function as a whole, including all published versions and the unpublished version. Reserving concurrency both ensures that your function has capacity to process the specified number of events simultaneously, and prevents it from scaling beyond that level. Use <a>GetFunction</a> to see the current setting for a function.</p> <p>Use <a>GetAccountSettings</a> to see your Regional concurrency limit. You can reserve concurrency for as many functions as you like, as long as you leave at least 100 simultaneous executions unreserved for functions that aren't configured with a per-function limit. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/invocation-scaling.html">Lambda function scaling</a>.</p>
    * @param
    * @param putFunctionConcurrencyRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void PutFunctionConcurrency (
        UObject *WorldContextObject,
        bool &success,
        FPutFunctionConcurrencyRequest putFunctionConcurrencyRequest,
        FPutFunctionConcurrencyResult &putFunctionConcurrencyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Configures options for <a href="https://docs.aws.amazon.com/lambda/latest/dg/invocation-async.html">asynchronous invocation</a> on a function, version, or alias. If a configuration already exists for a function, version, or alias, this operation overwrites it. If you exclude any settings, they are removed. To set one option without affecting existing settings for other options, use <a>UpdateFunctionEventInvokeConfig</a>.</p> <p>By default, Lambda retries an asynchronous invocation twice if the function returns an error. It retains events in a queue for up to six hours. When an event fails all processing attempts or stays in the asynchronous invocation queue for too long, Lambda discards it. To retain discarded events, configure a dead-letter queue with <a>UpdateFunctionConfiguration</a>.</p> <p>To send an invocation record to a queue, topic, function, or event bus, specify a <a href="https://docs.aws.amazon.com/lambda/latest/dg/invocation-async.html#invocation-async-destinations">destination</a>. You can configure separate destinations for successful invocations (on-success) and events that fail all processing attempts (on-failure). You can configure destinations in addition to or instead of a dead-letter queue.</p>
    * @param
    * @param putFunctionEventInvokeConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void PutFunctionEventInvokeConfig (
        UObject *WorldContextObject,
        bool &success,
        FPutFunctionEventInvokeConfigRequest putFunctionEventInvokeConfigRequest,
        FPutFunctionEventInvokeConfigResult &putFunctionEventInvokeConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Adds a provisioned concurrency configuration to a function's alias or version.</p>
    * @param
    * @param putProvisionedConcurrencyConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void PutProvisionedConcurrencyConfig (
        UObject *WorldContextObject,
        bool &success,
        FPutProvisionedConcurrencyConfigRequest putProvisionedConcurrencyConfigRequest,
        FPutProvisionedConcurrencyConfigResult &putProvisionedConcurrencyConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Removes a statement from the permissions policy for a version of an <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-layers.html">Lambda layer</a>. For more information, see <a>AddLayerVersionPermission</a>.</p>
    * @param
    * @param removeLayerVersionPermissionRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void RemoveLayerVersionPermission (
        UObject *WorldContextObject,
        bool &success,
        FRemoveLayerVersionPermissionRequest removeLayerVersionPermissionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Revokes function-use permission from an Amazon Web Service or another Amazon Web Services account. You can get the ID of the statement from the output of <a>GetPolicy</a>.</p>
    * @param
    * @param removePermissionRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void RemovePermission (
        UObject *WorldContextObject,
        bool &success,
        FRemovePermissionRequest removePermissionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Adds <a href="https://docs.aws.amazon.com/lambda/latest/dg/tagging.html">tags</a> to a function.</p>
    * @param
    * @param tagResourceRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void TagResource (
        UObject *WorldContextObject,
        bool &success,
        FLambdaTagResourceRequest tagResourceRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Removes <a href="https://docs.aws.amazon.com/lambda/latest/dg/tagging.html">tags</a> from a function.</p>
    * @param
    * @param untagResourceRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void UntagResource (
        UObject *WorldContextObject,
        bool &success,
        FLambdaUntagResourceRequest untagResourceRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Updates the configuration of a Lambda function <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-aliases.html">alias</a>.</p>
    * @param
    * @param updateAliasRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void UpdateAlias (
        UObject *WorldContextObject,
        bool &success,
        FLambdaUpdateAliasRequest updateAliasRequest,
        FLambdaUpdateAliasResult &updateAliasResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Update the code signing configuration. Changes to the code signing configuration take effect the next time a user tries to deploy a code package to the function. </p>
    * @param
    * @param updateCodeSigningConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void UpdateCodeSigningConfig (
        UObject *WorldContextObject,
        bool &success,
        FAWSLambdaUpdateCodeSigningConfigRequest updateCodeSigningConfigRequest,
        FAWSLambdaUpdateCodeSigningConfigResult &updateCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Updates an event source mapping. You can change the function that Lambda invokes, or pause invocation and resume later from the same location.</p> <p>For details about how to configure different event sources, see the following topics. </p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-ddb.html#services-dynamodb-eventsourcemapping"> Amazon DynamoDB Streams</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-kinesis.html#services-kinesis-eventsourcemapping"> Amazon Kinesis</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-sqs.html#events-sqs-eventsource"> Amazon SQS</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-mq.html#services-mq-eventsourcemapping"> Amazon MQ and RabbitMQ</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-msk.html"> Amazon MSK</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/kafka-smaa.html"> Apache Kafka</a> </p> </li> </ul> <p>The following error handling options are available only for stream sources (DynamoDB and Kinesis):</p> <ul> <li> <p> <code>BisectBatchOnFunctionError</code> – If the function returns an error, split the batch in two and retry.</p> </li> <li> <p> <code>DestinationConfig</code> – Send discarded records to an Amazon SQS queue or Amazon SNS topic.</p> </li> <li> <p> <code>MaximumRecordAgeInSeconds</code> – Discard records older than the specified age. The default value is infinite (-1). When set to infinite (-1), failed records are retried until the record expires</p> </li> <li> <p> <code>MaximumRetryAttempts</code> – Discard records after the specified number of retries. The default value is infinite (-1). When set to infinite (-1), failed records are retried until the record expires.</p> </li> <li> <p> <code>ParallelizationFactor</code> – Process multiple batches from each shard concurrently.</p> </li> </ul> <p>For information about which configuration parameters apply to each event source, see the following topics.</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-ddb.html#services-ddb-params"> Amazon DynamoDB Streams</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-kinesis.html#services-kinesis-params"> Amazon Kinesis</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-sqs.html#services-sqs-params"> Amazon SQS</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-mq.html#services-mq-params"> Amazon MQ and RabbitMQ</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-msk.html#services-msk-parms"> Amazon MSK</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-kafka.html#services-kafka-parms"> Apache Kafka</a> </p> </li> </ul>
    * @param
    * @param updateEventSourceMappingRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void UpdateEventSourceMapping (
        UObject *WorldContextObject,
        bool &success,
        FUpdateEventSourceMappingRequest updateEventSourceMappingRequest,
        FUpdateEventSourceMappingResult &updateEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Updates a Lambda function's code. If code signing is enabled for the function, the code package must be signed by a trusted publisher. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-codesigning.html">Configuring code signing for Lambda</a>.</p> <p>If the function's package type is <code>Image</code>, then you must specify the code package in <code>ImageUri</code> as the URI of a <a href="https://docs.aws.amazon.com/lambda/latest/dg/lambda-images.html">container image</a> in the Amazon ECR registry.</p> <p>If the function's package type is <code>Zip</code>, then you must specify the deployment package as a <a href="https://docs.aws.amazon.com/lambda/latest/dg/gettingstarted-package.html#gettingstarted-package-zip">.zip file archive</a>. Enter the Amazon S3 bucket and key of the code .zip file location. You can also provide the function code inline using the <code>ZipFile</code> field.</p> <p>The code in the deployment package must be compatible with the target instruction set architecture of the function (<code>x86-64</code> or <code>arm64</code>).</p> <p>The function's code is locked when you publish a version. You can't modify the code of a published version, only the unpublished version.</p> <note> <p>For a function defined as a container image, Lambda resolves the image tag to an image digest. In Amazon ECR, if you update the image tag to a new image, Lambda does not automatically update the function.</p> </note>
    * @param
    * @param updateFunctionCodeRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void UpdateFunctionCode (
        UObject *WorldContextObject,
        bool &success,
        FUpdateFunctionCodeRequest updateFunctionCodeRequest,
        FUpdateFunctionCodeResult &updateFunctionCodeResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Modify the version-specific settings of a Lambda function.</p> <p>When you update a function, Lambda provisions an instance of the function and its supporting resources. If your function connects to a VPC, this process can take a minute. During this time, you can't modify the function, but you can still invoke it. The <code>LastUpdateStatus</code>, <code>LastUpdateStatusReason</code>, and <code>LastUpdateStatusReasonCode</code> fields in the response from <a>GetFunctionConfiguration</a> indicate when the update is complete and the function is processing events with the new configuration. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/functions-states.html">Lambda function states</a>.</p> <p>These settings can vary between versions of a function and are locked when you publish a version. You can't modify the configuration of a published version, only the unpublished version.</p> <p>To configure function concurrency, use <a>PutFunctionConcurrency</a>. To grant invoke permissions to an Amazon Web Services account or Amazon Web Service, use <a>AddPermission</a>.</p>
    * @param
    * @param updateFunctionConfigurationRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void UpdateFunctionConfiguration (
        UObject *WorldContextObject,
        bool &success,
        FUpdateFunctionConfigurationRequest updateFunctionConfigurationRequest,
        FUpdateFunctionConfigurationResult &updateFunctionConfigurationResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Updates the configuration for asynchronous invocation for a function, version, or alias.</p> <p>To configure options for asynchronous invocation, use <a>PutFunctionEventInvokeConfig</a>.</p>
    * @param
    * @param updateFunctionEventInvokeConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void UpdateFunctionEventInvokeConfig (
        UObject *WorldContextObject,
        bool &success,
        FUpdateFunctionEventInvokeConfigRequest updateFunctionEventInvokeConfigRequest,
        FUpdateFunctionEventInvokeConfigResult &updateFunctionEventInvokeConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Updates the configuration for a Lambda function URL.</p>
    * @param
    * @param updateFunctionUrlConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "Lambda Client")
    void UpdateFunctionUrlConfig (
        UObject *WorldContextObject,
        bool &success,
        FAWSLambdaUpdateFunctionUrlConfigRequest updateFunctionUrlConfigRequest,
        FAWSLambdaUpdateFunctionUrlConfigResult &updateFunctionUrlConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
};
