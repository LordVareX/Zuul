/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ProvisionedThroughput.h"

#endif

#include "ProvisionedThroughput.generated.h"

USTRUCT(BlueprintType)
struct FProvisionedThroughput {
GENERATED_BODY()

    /**
    *  <p>The maximum number of strongly consistent reads consumed per second before DynamoDB returns a <code>ThrottlingException</code>. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/WorkingWithTables.html#ProvisionedThroughput">Specifying Read and Write Requirements</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p> <p>If read/write capacity mode is <code>PAY_PER_REQUEST</code> the value is set to 0.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 readCapacityUnits = 0;

    /**
    *  <p>The maximum number of writes consumed per second before DynamoDB returns a <code>ThrottlingException</code>. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/WorkingWithTables.html#ProvisionedThroughput">Specifying Read and Write Requirements</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p> <p>If read/write capacity mode is <code>PAY_PER_REQUEST</code> the value is set to 0.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 writeCapacityUnits = 0;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ProvisionedThroughput toAWS() const {
        Aws::DynamoDB::Model::ProvisionedThroughput awsProvisionedThroughput;

        if (this->readCapacityUnits != 0) {
            awsProvisionedThroughput.SetReadCapacityUnits(this->readCapacityUnits);
        }

        if (this->writeCapacityUnits != 0) {
            awsProvisionedThroughput.SetWriteCapacityUnits(this->writeCapacityUnits);
        }

        return awsProvisionedThroughput;
    }

    bool IsEmpty() const {
        return this->readCapacityUnits == 0 && this->writeCapacityUnits == 0;
    }

    FProvisionedThroughput &fromAWS(const Aws::DynamoDB::Model::ProvisionedThroughput &awsProvisionedThroughput) {
        this->readCapacityUnits = (int64)awsProvisionedThroughput.GetReadCapacityUnits();

        this->writeCapacityUnits = (int64)awsProvisionedThroughput.GetWriteCapacityUnits();

        return *this;
    }
#endif
};
