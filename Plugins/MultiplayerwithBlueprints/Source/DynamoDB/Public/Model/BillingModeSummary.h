/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/BillingModeSummary.h"

#endif

#include "Model/BillingMode.h"

#include "BillingModeSummary.generated.h"

USTRUCT(BlueprintType)
struct FBillingModeSummary {
GENERATED_BODY()

    /**
    *  <p>Controls how you are charged for read and write throughput and how you manage capacity. This setting can be changed later.</p> <ul> <li> <p> <code>PROVISIONED</code> - Sets the read/write capacity mode to <code>PROVISIONED</code>. We recommend using <code>PROVISIONED</code> for predictable workloads.</p> </li> <li> <p> <code>PAY_PER_REQUEST</code> - Sets the read/write capacity mode to <code>PAY_PER_REQUEST</code>. We recommend using <code>PAY_PER_REQUEST</code> for unpredictable workloads. </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSBillingMode billingMode = EAWSBillingMode::NOT_SET;

    /**
    *  <p>Represents the time when <code>PAY_PER_REQUEST</code> was last set as the read/write capacity mode.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime lastUpdateToPayPerRequestDateTime;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FBillingModeSummary &fromAWS(const Aws::DynamoDB::Model::BillingModeSummary &awsBillingModeSummary) {
        switch(awsBillingModeSummary.GetBillingMode()) {
            case Aws::DynamoDB::Model::BillingMode::NOT_SET:
                this->billingMode = EAWSBillingMode::NOT_SET;
                break;
            case Aws::DynamoDB::Model::BillingMode::PROVISIONED:
                this->billingMode = EAWSBillingMode::PROVISIONED;
                break;
            case Aws::DynamoDB::Model::BillingMode::PAY_PER_REQUEST:
                this->billingMode = EAWSBillingMode::PAY_PER_REQUEST;
                break;
            default:
                this->billingMode = EAWSBillingMode::NOT_SET;
                break;
            }

        this->lastUpdateToPayPerRequestDateTime = FDateTime(1970, 1, 1) + FTimespan(awsBillingModeSummary.GetLastUpdateToPayPerRequestDateTime().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
