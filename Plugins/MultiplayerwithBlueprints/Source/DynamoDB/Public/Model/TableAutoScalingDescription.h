/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/TableAutoScalingDescription.h"

#endif

#include "Model/TableStatus.h"
#include "Model/ReplicaAutoScalingDescription.h"

#include "TableAutoScalingDescription.generated.h"

USTRUCT(BlueprintType)
struct FTableAutoScalingDescription {
GENERATED_BODY()

    /**
    *  <p>The name of the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>The current state of the table:</p> <ul> <li> <p> <code>CREATING</code> - The table is being created.</p> </li> <li> <p> <code>UPDATING</code> - The table is being updated.</p> </li> <li> <p> <code>DELETING</code> - The table is being deleted.</p> </li> <li> <p> <code>ACTIVE</code> - The table is ready for use.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSTableStatus tableStatus = EAWSTableStatus::NOT_SET;

    /**
    *  <p>Represents replicas of the global table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FReplicaAutoScalingDescription> replicas;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FTableAutoScalingDescription &fromAWS(const Aws::DynamoDB::Model::TableAutoScalingDescription &awsTableAutoScalingDescription) {
        this->tableName = UTF8_TO_TCHAR(awsTableAutoScalingDescription.GetTableName().c_str());

        switch(awsTableAutoScalingDescription.GetTableStatus()) {
            case Aws::DynamoDB::Model::TableStatus::NOT_SET:
                this->tableStatus = EAWSTableStatus::NOT_SET;
                break;
            case Aws::DynamoDB::Model::TableStatus::CREATING:
                this->tableStatus = EAWSTableStatus::CREATING;
                break;
            case Aws::DynamoDB::Model::TableStatus::UPDATING:
                this->tableStatus = EAWSTableStatus::UPDATING;
                break;
            case Aws::DynamoDB::Model::TableStatus::DELETING:
                this->tableStatus = EAWSTableStatus::DELETING;
                break;
            case Aws::DynamoDB::Model::TableStatus::ACTIVE:
                this->tableStatus = EAWSTableStatus::ACTIVE;
                break;
            case Aws::DynamoDB::Model::TableStatus::INACCESSIBLE_ENCRYPTION_CREDENTIALS:
                this->tableStatus = EAWSTableStatus::INACCESSIBLE_ENCRYPTION_CREDENTIALS;
                break;
            case Aws::DynamoDB::Model::TableStatus::ARCHIVING:
                this->tableStatus = EAWSTableStatus::ARCHIVING;
                break;
            case Aws::DynamoDB::Model::TableStatus::ARCHIVED:
                this->tableStatus = EAWSTableStatus::ARCHIVED;
                break;
            default:
                this->tableStatus = EAWSTableStatus::NOT_SET;
                break;
        }

        this->replicas.Empty();
        for (const Aws::DynamoDB::Model::ReplicaAutoScalingDescription& elem : awsTableAutoScalingDescription.GetReplicas()) {
            this->replicas.Add(FReplicaAutoScalingDescription().fromAWS(elem));
        }

        return *this;
    }
#endif
};
