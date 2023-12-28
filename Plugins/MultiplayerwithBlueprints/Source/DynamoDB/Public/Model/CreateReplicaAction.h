/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/CreateReplicaAction.h"

#endif

#include "CreateReplicaAction.generated.h"

USTRUCT(BlueprintType)
struct FCreateReplicaAction {
GENERATED_BODY()

    /**
    *  <p>The region of the replica to be added.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString regionName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::CreateReplicaAction toAWS() const {
        Aws::DynamoDB::Model::CreateReplicaAction awsCreateReplicaAction;

		if (!(this->regionName.IsEmpty())) {
            awsCreateReplicaAction.SetRegionName(TCHAR_TO_UTF8(*this->regionName));
        }

        return awsCreateReplicaAction;
    }

    bool IsEmpty() const {
        return this->regionName.IsEmpty();
    }
#endif
};
