/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeContinuousBackupsResult.h"

#endif

#include "Model/ContinuousBackupsDescription.h"

#include "DescribeContinuousBackupsResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeContinuousBackupsResult {
GENERATED_BODY()

    /**
    *  <p>Represents the continuous backups and point in time recovery settings on the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FContinuousBackupsDescription continuousBackupsDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FDescribeContinuousBackupsResult &fromAWS(const Aws::DynamoDB::Model::DescribeContinuousBackupsResult &awsDescribeContinuousBackupsResult) {
        this->continuousBackupsDescription.fromAWS(awsDescribeContinuousBackupsResult.GetContinuousBackupsDescription());

        return *this;
    }
#endif
};
