/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/GlobalTableDescription.h"

#endif

#include "Model/ReplicaDescription.h"
#include "Model/GlobalTableStatus.h"

#include "GlobalTableDescription.generated.h"

USTRUCT(BlueprintType)
struct FGlobalTableDescription {
GENERATED_BODY()

    /**
    *  <p>The regions where the global table has replicas.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FReplicaDescription> replicationGroup;

    /**
    *  <p>The unique identifier of the global table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString globalTableArn;

    /**
    *  <p>The creation time of the global table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime creationDateTime;

    /**
    *  <p>The current state of the global table:</p> <ul> <li> <p> <code>CREATING</code> - The global table is being created.</p> </li> <li> <p> <code>UPDATING</code> - The global table is being updated.</p> </li> <li> <p> <code>DELETING</code> - The global table is being deleted.</p> </li> <li> <p> <code>ACTIVE</code> - The global table is ready for use.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSGlobalTableStatus globalTableStatus = EAWSGlobalTableStatus::NOT_SET;

    /**
    *  <p>The global table name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString globalTableName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FGlobalTableDescription &fromAWS(const Aws::DynamoDB::Model::GlobalTableDescription &awsGlobalTableDescription) {
        this->replicationGroup.Empty();
        for (const Aws::DynamoDB::Model::ReplicaDescription& elem : awsGlobalTableDescription.GetReplicationGroup()) {
            this->replicationGroup.Add(FReplicaDescription().fromAWS(elem));
        }

        this->globalTableArn = UTF8_TO_TCHAR(awsGlobalTableDescription.GetGlobalTableArn().c_str());

        this->creationDateTime = FDateTime(1970, 1, 1) + FTimespan(awsGlobalTableDescription.GetCreationDateTime().Millis() * ETimespan::TicksPerMillisecond);

        switch(awsGlobalTableDescription.GetGlobalTableStatus()) {
            case Aws::DynamoDB::Model::GlobalTableStatus::NOT_SET:
                this->globalTableStatus = EAWSGlobalTableStatus::NOT_SET;
                break;
            case Aws::DynamoDB::Model::GlobalTableStatus::CREATING:
                this->globalTableStatus = EAWSGlobalTableStatus::CREATING;
                break;
            case Aws::DynamoDB::Model::GlobalTableStatus::ACTIVE:
                this->globalTableStatus = EAWSGlobalTableStatus::ACTIVE;
                break;
            case Aws::DynamoDB::Model::GlobalTableStatus::DELETING:
                this->globalTableStatus = EAWSGlobalTableStatus::DELETING;
                break;
            case Aws::DynamoDB::Model::GlobalTableStatus::UPDATING:
                this->globalTableStatus = EAWSGlobalTableStatus::UPDATING;
                break;
            default:
                this->globalTableStatus = EAWSGlobalTableStatus::NOT_SET;
                break;
            }

        this->globalTableName = UTF8_TO_TCHAR(awsGlobalTableDescription.GetGlobalTableName().c_str());

        return *this;
    }
#endif
};
