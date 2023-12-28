/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/TableClassSummary.h"

#endif

#include "Model/AWSDynamoDBTableClass.h"

#include "AWSDynamoDBTableClassSummary.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBTableClassSummary {
GENERATED_BODY()

    /**
    *  <p>The table class of the specified table. Valid values are <code>STANDARD</code> and <code>STANDARD_INFREQUENT_ACCESS</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBTableClass tableClass = EAWSDynamoDBTableClass::NOT_SET;

    /**
    *  <p>The date and time at which the table class was last updated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime lastUpdateDateTime;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBTableClassSummary &fromAWS(const Aws::DynamoDB::Model::TableClassSummary &awsTableClassSummary) {
        switch(awsTableClassSummary.GetTableClass()) {
            case Aws::DynamoDB::Model::TableClass::NOT_SET:
                this->tableClass = EAWSDynamoDBTableClass::NOT_SET;
                break;
            case Aws::DynamoDB::Model::TableClass::STANDARD:
                this->tableClass = EAWSDynamoDBTableClass::STANDARD;
                break;
            case Aws::DynamoDB::Model::TableClass::STANDARD_INFREQUENT_ACCESS:
                this->tableClass = EAWSDynamoDBTableClass::STANDARD_INFREQUENT_ACCESS;
                break;
            default:
                this->tableClass = EAWSDynamoDBTableClass::NOT_SET;
                break;
        }

        this->lastUpdateDateTime = FDateTime(1970, 1, 1) + FTimespan(awsTableClassSummary.GetLastUpdateDateTime().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
