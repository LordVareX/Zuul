/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DeleteReplicaAction.h"

#endif

#include "DeleteReplicaAction.generated.h"

USTRUCT(BlueprintType)
struct FDeleteReplicaAction {
GENERATED_BODY()

    /**
    *  <p>The region of the replica to be removed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString regionName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DeleteReplicaAction toAWS() const {
        Aws::DynamoDB::Model::DeleteReplicaAction awsDeleteReplicaAction;

		if (!(this->regionName.IsEmpty())) {
            awsDeleteReplicaAction.SetRegionName(TCHAR_TO_UTF8(*this->regionName));
        }

        return awsDeleteReplicaAction;
    }

    bool IsEmpty() const {
        return this->regionName.IsEmpty();
    }
#endif
};
