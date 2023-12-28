/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/SelfManagedKafkaEventSourceConfig.h"

#endif

#include "AWSLambdaSelfManagedKafkaEventSourceConfig.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaSelfManagedKafkaEventSourceConfig {
GENERATED_BODY()

    /**
    *  <p>The identifier for the Kafka consumer group to join. The consumer group ID must be unique among all your Kafka event sources. After creating a Kafka event source mapping with the consumer group ID specified, you cannot update this value. For more information, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/with-msk.html#services-msk-consumer-group-id">Customizable consumer group ID</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString consumerGroupId;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::SelfManagedKafkaEventSourceConfig toAWS() const {
        Aws::Lambda::Model::SelfManagedKafkaEventSourceConfig awsSelfManagedKafkaEventSourceConfig;

        if (!(this->consumerGroupId.IsEmpty())) {
            awsSelfManagedKafkaEventSourceConfig.SetConsumerGroupId(TCHAR_TO_UTF8(*this->consumerGroupId));
        }

        return awsSelfManagedKafkaEventSourceConfig;
    }

    bool IsEmpty() const {
        return this->consumerGroupId.IsEmpty();
    }

    FAWSLambdaSelfManagedKafkaEventSourceConfig &fromAWS(const Aws::Lambda::Model::SelfManagedKafkaEventSourceConfig &awsSelfManagedKafkaEventSourceConfig) {
        this->consumerGroupId = UTF8_TO_TCHAR(awsSelfManagedKafkaEventSourceConfig.GetConsumerGroupId().c_str());

        return *this;
    }
#endif
};
