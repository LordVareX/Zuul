/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/UpdateContinuousBackupsResult.h"

#endif

#include "Model/ContinuousBackupsDescription.h"

#include "UpdateContinuousBackupsResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateContinuousBackupsResult {
GENERATED_BODY()

    /**
    *  <p>Represents the continuous backups and point in time recovery settings on the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FContinuousBackupsDescription continuousBackupsDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FUpdateContinuousBackupsResult &fromAWS(const Aws::DynamoDB::Model::UpdateContinuousBackupsResult &awsUpdateContinuousBackupsResult) {
        this->continuousBackupsDescription.fromAWS(awsUpdateContinuousBackupsResult.GetContinuousBackupsDescription());

        return *this;
    }
#endif
};
