/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/CreateEventSourceMappingRequest.h"

#endif

#include "Model/AWSLambdaFilterCriteria.h"
#include "Model/EventSourcePosition.h"
#include "Model/DestinationConfig.h"
#include "Model/AWSLambdaSourceAccessConfiguration.h"
#include "Model/AWSLambdaSelfManagedEventSource.h"
#include "Model/AWSLambdaFunctionResponseType.h"
#include "Model/AWSLambdaAmazonManagedKafkaEventSourceConfig.h"
#include "Model/AWSLambdaSelfManagedKafkaEventSourceConfig.h"

#include "CreateEventSourceMappingRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateEventSourceMappingRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the event source.</p> <ul> <li> <p> <b>Amazon Kinesis</b> - The ARN of the data stream or a stream consumer.</p> </li> <li> <p> <b>Amazon DynamoDB Streams</b> - The ARN of the stream.</p> </li> <li> <p> <b>Amazon Simple Queue Service</b> - The ARN of the queue.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString eventSourceArn;

    /**
    *  <p>The name of the Lambda function.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> - <code>MyFunction</code>.</p> </li> <li> <p> <b>Function ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:MyFunction</code>.</p> </li> <li> <p> <b>Version or Alias ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:MyFunction:PROD</code>.</p> </li> <li> <p> <b>Partial ARN</b> - <code>123456789012:function:MyFunction</code>.</p> </li> </ul> <p>The length constraint applies only to the full ARN. If you specify only the function name, it's limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
    *  <p>Disables the event source mapping to pause polling and invocation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    bool enabled = false;

    /**
    *  <p>The maximum number of items to retrieve in a single batch.</p> <ul> <li> <p> <b>Amazon Kinesis</b> - Default 100. Max 10,000.</p> </li> <li> <p> <b>Amazon DynamoDB Streams</b> - Default 100. Max 1,000.</p> </li> <li> <p> <b>Amazon Simple Queue Service</b> - Default 10. Max 10.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int batchSize = 0;

    /**
    *  <p>An object that defines the filter criteria that determine whether Lambda should process an event. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/invocation-eventfiltering.html">Lambda event filtering</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaFilterCriteria filterCriteria;

    /**
    *  <p>(Streams) The maximum amount of time to gather records before invoking the function, in seconds.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maximumBatchingWindowInSeconds = 0;

    /**
    *  <p>(Streams) The number of batches to process from each shard concurrently.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int parallelizationFactor = 0;

    /**
    *  <p>The position in a stream from which to start reading. Required for Amazon Kinesis and Amazon DynamoDB Streams sources. <code>AT_TIMESTAMP</code> is only supported for Amazon Kinesis streams.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    ES3EventSourcePosition startingPosition = ES3EventSourcePosition::NOT_SET;

    /**
    *  <p>With <code>StartingPosition</code> set to <code>AT_TIMESTAMP</code>, the time from which to start reading.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FDateTime startingPositionTimestamp;

    /**
    *  <p>(Streams) An Amazon SQS queue or Amazon SNS topic destination for discarded records.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FDestinationConfig destinationConfig;

    /**
    *  <p>(Streams) The maximum age of a record that Lambda sends to a function for processing.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maximumRecordAgeInSeconds = 0;

    /**
    *  <p>(Streams) If the function returns an error, split the batch in two and retry.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    bool bisectBatchOnFunctionError = false;

    /**
    *  <p>(Streams) Discard records after the specified number of retries. The default value is infinite (-1). When set to infinite (-1), failed records will be retried until the record expires.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maximumRetryAttempts = 0;

    /**
    *  <p>(Streams) The duration in seconds of a processing window. The range is between 1 second up to 900 seconds.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int tumblingWindowInSeconds = 0;
    /**
    *  <p>The name of the Kafka topic.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FString> topics;

    /**
    *  <p> (MQ) The name of the Amazon MQ broker destination queue to consume. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FString> queues;

    /**
    *  <p>An array of the authentication protocol, or the VPC components to secure your event source.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FAWSLambdaSourceAccessConfiguration> sourceAccessConfigurations;

    /**
    *  <p>The Self-Managed Apache Kafka cluster to send records.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaSelfManagedEventSource selfManagedEventSource;

    /**
    *  <p>(Streams) A list of current response type enums applied to the event source mapping.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<EAWSLambdaFunctionResponseType> functionResponseTypes;

    /**
    *  <p>Specific configuration settings for an Amazon Managed Streaming for Apache Kafka (Amazon MSK) event source.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaAmazonManagedKafkaEventSourceConfig amazonManagedKafkaEventSourceConfig;

    /**
    *  <p>Specific configuration settings for a self-managed Apache Kafka event source.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaSelfManagedKafkaEventSourceConfig selfManagedKafkaEventSourceConfig;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::CreateEventSourceMappingRequest toAWS() const {
        Aws::Lambda::Model::CreateEventSourceMappingRequest awsCreateEventSourceMappingRequest;

		if (!(this->eventSourceArn.IsEmpty())) {
            awsCreateEventSourceMappingRequest.SetEventSourceArn(TCHAR_TO_UTF8(*this->eventSourceArn));
        }

		if (!(this->functionName.IsEmpty())) {
            awsCreateEventSourceMappingRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

        awsCreateEventSourceMappingRequest.SetEnabled(this->enabled);

        if (this->batchSize != 0) {
            awsCreateEventSourceMappingRequest.SetBatchSize(this->batchSize);
        }

        if (!(this->filterCriteria.IsEmpty())) {
            awsCreateEventSourceMappingRequest.SetFilterCriteria(this->filterCriteria.toAWS());
        }

        if (!(this->maximumBatchingWindowInSeconds == 0)) {
            awsCreateEventSourceMappingRequest.SetMaximumBatchingWindowInSeconds(this->maximumBatchingWindowInSeconds);
        }

        if (!(this->parallelizationFactor == 0)) {
            awsCreateEventSourceMappingRequest.SetParallelizationFactor(this->parallelizationFactor);
        }

        switch(this->startingPosition) {
            case ES3EventSourcePosition::TRIM_HORIZON:
                awsCreateEventSourceMappingRequest.SetStartingPosition(Aws::Lambda::Model::EventSourcePosition::TRIM_HORIZON);
                break;
            case ES3EventSourcePosition::LATEST:
                awsCreateEventSourceMappingRequest.SetStartingPosition(Aws::Lambda::Model::EventSourcePosition::LATEST);
                break;
            case ES3EventSourcePosition::AT_TIMESTAMP:
                awsCreateEventSourceMappingRequest.SetStartingPosition(Aws::Lambda::Model::EventSourcePosition::AT_TIMESTAMP);
                break;
            default:
                break;
            }

        if (!(this->startingPositionTimestamp.ToUnixTimestamp() <= 0)) {
            awsCreateEventSourceMappingRequest.SetStartingPositionTimestamp(Aws::Utils::DateTime((int64_t)((this->startingPositionTimestamp - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));
        }

        if (!(this->destinationConfig.IsEmpty())) {
            awsCreateEventSourceMappingRequest.SetDestinationConfig(this->destinationConfig.toAWS());
        }

        if (!(this->maximumRecordAgeInSeconds == 0)) {
            awsCreateEventSourceMappingRequest.SetMaximumRecordAgeInSeconds(this->maximumRecordAgeInSeconds);
        }

        if (!(false)) {
            awsCreateEventSourceMappingRequest.SetBisectBatchOnFunctionError(this->bisectBatchOnFunctionError);
        }

        if (!(this->maximumRetryAttempts == 0)) {
            awsCreateEventSourceMappingRequest.SetMaximumRetryAttempts(this->maximumRetryAttempts);
        }

        if (!(this->tumblingWindowInSeconds == 0)) {
            awsCreateEventSourceMappingRequest.SetTumblingWindowInSeconds(this->tumblingWindowInSeconds);
        }

        for (const FString& elem : this->topics) {
            awsCreateEventSourceMappingRequest.AddTopics(TCHAR_TO_UTF8(*elem));
        }

        for (const FString& elem : this->queues) {
            awsCreateEventSourceMappingRequest.AddQueues(TCHAR_TO_UTF8(*elem));
        }

        for (const FAWSLambdaSourceAccessConfiguration& elem : this->sourceAccessConfigurations) {
            awsCreateEventSourceMappingRequest.AddSourceAccessConfigurations(elem.toAWS());
        }

        if (!(this->selfManagedEventSource.IsEmpty())) {
            awsCreateEventSourceMappingRequest.SetSelfManagedEventSource(this->selfManagedEventSource.toAWS());
        }

        for (const EAWSLambdaFunctionResponseType& elem : this->functionResponseTypes) {
		    switch(elem) {
                case EAWSLambdaFunctionResponseType::ReportBatchItemFailures:
                    awsCreateEventSourceMappingRequest.AddFunctionResponseTypes(Aws::Lambda::Model::FunctionResponseType::ReportBatchItemFailures);
                    break;
                default:
                    break;
            };
        }

        if (!(this->amazonManagedKafkaEventSourceConfig.IsEmpty())) {
            awsCreateEventSourceMappingRequest.SetAmazonManagedKafkaEventSourceConfig(this->amazonManagedKafkaEventSourceConfig.toAWS());
        }

        if (!(this->selfManagedKafkaEventSourceConfig.IsEmpty())) {
            awsCreateEventSourceMappingRequest.SetSelfManagedKafkaEventSourceConfig(this->selfManagedKafkaEventSourceConfig.toAWS());
        }

        return awsCreateEventSourceMappingRequest;
    }

    bool IsEmpty() const {
        return this->eventSourceArn.IsEmpty() && this->functionName.IsEmpty() && false && this->batchSize == 0 && this->filterCriteria.IsEmpty() && this->maximumBatchingWindowInSeconds == 0 && this->parallelizationFactor == 0 && startingPosition == ES3EventSourcePosition::NOT_SET && startingPositionTimestamp.ToUnixTimestamp() <= 0 && this->destinationConfig.IsEmpty() && this->maximumRecordAgeInSeconds == 0 && false && this->maximumRetryAttempts == 0 && this->tumblingWindowInSeconds == 0 && this->topics.Num() == 0 && this->queues.Num() == 0 && this->sourceAccessConfigurations.Num() == 0 && this->selfManagedEventSource.IsEmpty() && this->functionResponseTypes.Num() == 0 && this->amazonManagedKafkaEventSourceConfig.IsEmpty() && this->selfManagedKafkaEventSourceConfig.IsEmpty();
    }
#endif
};
