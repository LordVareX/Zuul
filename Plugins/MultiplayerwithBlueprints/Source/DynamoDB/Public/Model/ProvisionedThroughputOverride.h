/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ProvisionedThroughputOverride.h"

#endif

#include "ProvisionedThroughputOverride.generated.h"

USTRUCT(BlueprintType)
struct FProvisionedThroughputOverride {
GENERATED_BODY()

    /**
    *  <p>Replica-specific read capacity units. If not specified, uses the source table's read capacity settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 readCapacityUnits = 0;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ProvisionedThroughputOverride toAWS() const {
        Aws::DynamoDB::Model::ProvisionedThroughputOverride awsProvisionedThroughputOverride;

        if (!(this->readCapacityUnits == 0)) {
            awsProvisionedThroughputOverride.SetReadCapacityUnits(this->readCapacityUnits);
        }

        return awsProvisionedThroughputOverride;
    }

    bool IsEmpty() const {
        return this->readCapacityUnits == 0;
    }

    FProvisionedThroughputOverride &fromAWS(const Aws::DynamoDB::Model::ProvisionedThroughputOverride &awsProvisionedThroughputOverride) {
        this->readCapacityUnits = (int64)awsProvisionedThroughputOverride.GetReadCapacityUnits();

        return *this;
    }
#endif
};
