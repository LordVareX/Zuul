/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/AmazonManagedKafkaEventSourceConfig.h"

#endif

#include "AWSLambdaAmazonManagedKafkaEventSourceConfig.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaAmazonManagedKafkaEventSourceConfig {
GENERATED_BODY()

    /**
    *  <p>The identifier for the Kafka consumer group to join. The consumer group ID must be unique among all your Kafka event sources. After creating a Kafka event source mapping with the consumer group ID specified, you cannot update this value. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-msk.html#services-msk-consumer-group-id">Customizable consumer group ID</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString consumerGroupId;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::AmazonManagedKafkaEventSourceConfig toAWS() const {
        Aws::Lambda::Model::AmazonManagedKafkaEventSourceConfig awsAmazonManagedKafkaEventSourceConfig;

        if (!(this->consumerGroupId.IsEmpty())) {
            awsAmazonManagedKafkaEventSourceConfig.SetConsumerGroupId(TCHAR_TO_UTF8(*this->consumerGroupId));
        }

        return awsAmazonManagedKafkaEventSourceConfig;
    }

    bool IsEmpty() const {
        return this->consumerGroupId.IsEmpty();
    }

    FAWSLambdaAmazonManagedKafkaEventSourceConfig &fromAWS(const Aws::Lambda::Model::AmazonManagedKafkaEventSourceConfig &awsAmazonManagedKafkaEventSourceConfig) {
        this->consumerGroupId = UTF8_TO_TCHAR(awsAmazonManagedKafkaEventSourceConfig.GetConsumerGroupId().c_str());

        return *this;
    }
#endif
};
