/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/GetEventSourceMappingResult.h"

#endif

#include "Model/EventSourcePosition.h"
#include "Model/AWSLambdaFilterCriteria.h"
#include "Model/DestinationConfig.h"
#include "Model/AWSLambdaSourceAccessConfiguration.h"
#include "Model/AWSLambdaSelfManagedEventSource.h"
#include "Model/AWSLambdaFunctionResponseType.h"
#include "Model/AWSLambdaAmazonManagedKafkaEventSourceConfig.h"
#include "Model/AWSLambdaSelfManagedKafkaEventSourceConfig.h"

#include "GetEventSourceMappingResult.generated.h"

USTRUCT(BlueprintType)
struct FGetEventSourceMappingResult {
GENERATED_BODY()

    /**
    *  <p>The identifier of the event source mapping.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString UUID;

    /**
    *  <p>The position in a stream from which to start reading. Required for Amazon Kinesis, Amazon DynamoDB, and Amazon MSK stream sources. <code>AT_TIMESTAMP</code> is supported only for Amazon Kinesis streams.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    ES3EventSourcePosition startingPosition = ES3EventSourcePosition::NOT_SET;

    /**
    *  <p>With <code>StartingPosition</code> set to <code>AT_TIMESTAMP</code>, the time from which to start reading.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FDateTime startingPositionTimestamp;

    /**
    *  <p>The maximum number of items to retrieve in a single batch.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int batchSize = 0;

    /**
    *  <p>The maximum amount of time, in seconds, that Lambda spends gathering records before invoking the function. You can configure <code>MaximumBatchingWindowInSeconds</code> to any value from 0 seconds to 300 seconds in increments of seconds.</p> <p>For streams and Amazon SQS event sources, the default batching window is 0 seconds. For Amazon MSK, Self-managed Apache Kafka, and Amazon MQ event sources, the default batching window is 500 ms. Note that because you can only change <code>MaximumBatchingWindowInSeconds</code> in increments of seconds, you cannot revert back to the 500 ms default batching window after you have changed it. To restore the default batching window, you must create a new event source mapping.</p> <p>Related setting: For streams and Amazon SQS event sources, when you set <code>BatchSize</code> to a value greater than 10, you must set <code>MaximumBatchingWindowInSeconds</code> to at least 1.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maximumBatchingWindowInSeconds = 0;

    /**
    *  <p>(Streams only) The number of batches to process concurrently from each shard. The default value is 1.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int parallelizationFactor = 0;

    /**
    *  <p>The Amazon Resource Name (ARN) of the event source.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString eventSourceArn;

    /**
    *  <p>An object that defines the filter criteria that determine whether Lambda should process an event. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/invocation-eventfiltering.html">Lambda event filtering</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaFilterCriteria filterCriteria;

    /**
    *  <p>The ARN of the Lambda function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionArn;

    /**
    *  <p>The date that the event source mapping was last updated or that its state changed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FDateTime lastModified;

    /**
    *  <p>The result of the last Lambda invocation of your function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString lastProcessingResult;

    /**
    *  <p>The state of the event source mapping. It can be one of the following: <code>Creating</code>, <code>Enabling</code>, <code>Enabled</code>, <code>Disabling</code>, <code>Disabled</code>, <code>Updating</code>, or <code>Deleting</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString state;

    /**
    *  <p>Indicates whether a user or Lambda made the last change to the event source mapping.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString stateTransitionReason;

    /**
    *  <p>(Streams only) An Amazon SQS queue or Amazon SNS topic destination for discarded records.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FDestinationConfig destinationConfig;

    /**
    *  <p>The name of the Kafka topic.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FString> topics;

    /**
    *  <p> (Amazon MQ) The name of the Amazon MQ broker destination queue to consume.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FString> queues;

    /**
    *  <p>An array of the authentication protocol, VPC components, or virtual host to secure and define your event source.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FAWSLambdaSourceAccessConfiguration> sourceAccessConfigurations;

    /**
    *  <p>The self-managed Apache Kafka cluster for your event source.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaSelfManagedEventSource selfManagedEventSource;

    /**
    *  <p>(Streams only) Discard records older than the specified age. The default value is -1, which sets the maximum age to infinite. When the value is set to infinite, Lambda never discards old records. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maximumRecordAgeInSeconds = 0;

    /**
    *  <p>(Streams only) If the function returns an error, split the batch in two and retry. The default value is false.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    bool bisectBatchOnFunctionError = false;

    /**
    *  <p>(Streams only) Discard records after the specified number of retries. The default value is -1, which sets the maximum number of retries to infinite. When MaximumRetryAttempts is infinite, Lambda retries failed records until the record expires in the event source.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maximumRetryAttempts = 0;

    /**
    *  <p>(Streams only) The duration in seconds of a processing window. The range is 1–900 seconds.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int tumblingWindowInSeconds = 0;

    /**
    *  <p>(Streams and Amazon SQS) A list of current response type enums applied to the event source mapping.</p>
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
    FGetEventSourceMappingResult &fromAWS(const Aws::Lambda::Model::GetEventSourceMappingResult &awsGetEventSourceMappingResult) {
        this->UUID = UTF8_TO_TCHAR(awsGetEventSourceMappingResult.GetUUID().c_str());

        switch(awsGetEventSourceMappingResult.GetStartingPosition()) {
            case Aws::Lambda::Model::EventSourcePosition::NOT_SET:
                this->startingPosition = ES3EventSourcePosition::NOT_SET;
                break;
            case Aws::Lambda::Model::EventSourcePosition::TRIM_HORIZON:
                this->startingPosition = ES3EventSourcePosition::TRIM_HORIZON;
                break;
            case Aws::Lambda::Model::EventSourcePosition::LATEST:
                this->startingPosition = ES3EventSourcePosition::LATEST;
                break;
            case Aws::Lambda::Model::EventSourcePosition::AT_TIMESTAMP:
                this->startingPosition = ES3EventSourcePosition::AT_TIMESTAMP;
                break;
            default:
                this->startingPosition = ES3EventSourcePosition::NOT_SET;
                break;
            }

        this->startingPositionTimestamp = FDateTime(1970, 1, 1) + FTimespan(awsGetEventSourceMappingResult.GetStartingPositionTimestamp().Millis() * ETimespan::TicksPerMillisecond);

		this->batchSize = awsGetEventSourceMappingResult.GetBatchSize();

		this->maximumBatchingWindowInSeconds = awsGetEventSourceMappingResult.GetMaximumBatchingWindowInSeconds();

		this->parallelizationFactor = awsGetEventSourceMappingResult.GetParallelizationFactor();

        this->eventSourceArn = UTF8_TO_TCHAR(awsGetEventSourceMappingResult.GetEventSourceArn().c_str());

        this->filterCriteria.fromAWS(awsGetEventSourceMappingResult.GetFilterCriteria());

        this->functionArn = UTF8_TO_TCHAR(awsGetEventSourceMappingResult.GetFunctionArn().c_str());

        this->lastModified = FDateTime(1970, 1, 1) + FTimespan(awsGetEventSourceMappingResult.GetLastModified().Millis() * ETimespan::TicksPerMillisecond);

        this->lastProcessingResult = UTF8_TO_TCHAR(awsGetEventSourceMappingResult.GetLastProcessingResult().c_str());

        this->state = UTF8_TO_TCHAR(awsGetEventSourceMappingResult.GetState().c_str());

        this->stateTransitionReason = UTF8_TO_TCHAR(awsGetEventSourceMappingResult.GetStateTransitionReason().c_str());

        this->destinationConfig.fromAWS(awsGetEventSourceMappingResult.GetDestinationConfig());

        this->topics.Empty();
        for (const Aws::String& elem : awsGetEventSourceMappingResult.GetTopics()) {
            this->topics.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->queues.Empty();
        for (const Aws::String& elem : awsGetEventSourceMappingResult.GetQueues()) {
            this->queues.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->sourceAccessConfigurations.Empty();
        for (const Aws::Lambda::Model::SourceAccessConfiguration& elem : awsGetEventSourceMappingResult.GetSourceAccessConfigurations()) {
            this->sourceAccessConfigurations.Add(FAWSLambdaSourceAccessConfiguration().fromAWS(elem));
        }

        this->selfManagedEventSource.fromAWS(awsGetEventSourceMappingResult.GetSelfManagedEventSource());

		this->maximumRecordAgeInSeconds = awsGetEventSourceMappingResult.GetMaximumRecordAgeInSeconds();

        this->bisectBatchOnFunctionError = awsGetEventSourceMappingResult.GetBisectBatchOnFunctionError();

		this->maximumRetryAttempts = awsGetEventSourceMappingResult.GetMaximumRetryAttempts();

		this->tumblingWindowInSeconds = awsGetEventSourceMappingResult.GetTumblingWindowInSeconds();

        this->functionResponseTypes.Empty();
        for (const Aws::Lambda::Model::FunctionResponseType& elem : awsGetEventSourceMappingResult.GetFunctionResponseTypes()) {
            switch(elem) {
                case Aws::Lambda::Model::FunctionResponseType::NOT_SET:
                    this->functionResponseTypes.Add(EAWSLambdaFunctionResponseType::NOT_SET);
                    break;
                case Aws::Lambda::Model::FunctionResponseType::ReportBatchItemFailures:
                    this->functionResponseTypes.Add(EAWSLambdaFunctionResponseType::ReportBatchItemFailures);
                    break;
                default:
                    break;
		    };
        }

        this->amazonManagedKafkaEventSourceConfig.fromAWS(awsGetEventSourceMappingResult.GetAmazonManagedKafkaEventSourceConfig());

        this->selfManagedKafkaEventSourceConfig.fromAWS(awsGetEventSourceMappingResult.GetSelfManagedKafkaEventSourceConfig());

        return *this;
    }
#endif
};
