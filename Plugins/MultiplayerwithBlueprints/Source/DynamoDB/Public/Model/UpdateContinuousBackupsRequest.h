/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/UpdateContinuousBackupsRequest.h"

#endif

#include "Model/PointInTimeRecoverySpecification.h"

#include "UpdateContinuousBackupsRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateContinuousBackupsRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>Represents the settings used to enable point in time recovery.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FPointInTimeRecoverySpecification pointInTimeRecoverySpecification;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::UpdateContinuousBackupsRequest toAWS() const {
        Aws::DynamoDB::Model::UpdateContinuousBackupsRequest awsUpdateContinuousBackupsRequest;

		if (!(this->tableName.IsEmpty())) {
            awsUpdateContinuousBackupsRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

        if (!(this->pointInTimeRecoverySpecification.IsEmpty())) {
            awsUpdateContinuousBackupsRequest.SetPointInTimeRecoverySpecification(this->pointInTimeRecoverySpecification.toAWS());
        }

        return awsUpdateContinuousBackupsRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty() && this->pointInTimeRecoverySpecification.IsEmpty();
    }
#endif
};
