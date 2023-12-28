/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/SourceTableFeatureDetails.h"

#endif

#include "Model/LocalSecondaryIndexInfo.h"
#include "Model/GlobalSecondaryIndexInfo.h"
#include "Model/StreamSpecification.h"
#include "Model/TimeToLiveDescription.h"
#include "Model/SSEDescription.h"

#include "SourceTableFeatureDetails.generated.h"

USTRUCT(BlueprintType)
struct FSourceTableFeatureDetails {
GENERATED_BODY()

    /**
    *  <p>Represents the LSI properties for the table when the backup was created. It includes the IndexName, KeySchema and Projection for the LSIs on the table at the time of backup. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FLocalSecondaryIndexInfo> localSecondaryIndexes;

    /**
    *  <p>Represents the GSI properties for the table when the backup was created. It includes the IndexName, KeySchema, Projection and ProvisionedThroughput for the GSIs on the table at the time of backup. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FGlobalSecondaryIndexInfo> globalSecondaryIndexes;

    /**
    *  <p>Stream settings on the table when the backup was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FStreamSpecification streamDescription;

    /**
    *  <p>Time to Live settings on the table when the backup was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FTimeToLiveDescription timeToLiveDescription;

    /**
    *  <p>The description of the server-side encryption status on the table when the backup was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FSSEDescription sSEDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FSourceTableFeatureDetails &fromAWS(const Aws::DynamoDB::Model::SourceTableFeatureDetails &awsSourceTableFeatureDetails) {
        this->localSecondaryIndexes.Empty();
        for (const Aws::DynamoDB::Model::LocalSecondaryIndexInfo& elem : awsSourceTableFeatureDetails.GetLocalSecondaryIndexes()) {
            this->localSecondaryIndexes.Add(FLocalSecondaryIndexInfo().fromAWS(elem));
        }

        this->globalSecondaryIndexes.Empty();
        for (const Aws::DynamoDB::Model::GlobalSecondaryIndexInfo& elem : awsSourceTableFeatureDetails.GetGlobalSecondaryIndexes()) {
            this->globalSecondaryIndexes.Add(FGlobalSecondaryIndexInfo().fromAWS(elem));
        }

        this->streamDescription.fromAWS(awsSourceTableFeatureDetails.GetStreamDescription());

        this->timeToLiveDescription.fromAWS(awsSourceTableFeatureDetails.GetTimeToLiveDescription());

        this->sSEDescription.fromAWS(awsSourceTableFeatureDetails.GetSSEDescription());

        return *this;
    }
#endif
};
