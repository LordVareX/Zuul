/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DeleteReplicationGroupMemberAction.h"

#endif

#include "DeleteReplicationGroupMemberAction.generated.h"

USTRUCT(BlueprintType)
struct FDeleteReplicationGroupMemberAction {
GENERATED_BODY()

    /**
    *  <p>The Region where the replica exists.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString regionName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DeleteReplicationGroupMemberAction toAWS() const {
        Aws::DynamoDB::Model::DeleteReplicationGroupMemberAction awsDeleteReplicationGroupMemberAction;

		if (!(this->regionName.IsEmpty())) {
            awsDeleteReplicationGroupMemberAction.SetRegionName(TCHAR_TO_UTF8(*this->regionName));
        }

        return awsDeleteReplicationGroupMemberAction;
    }

    bool IsEmpty() const {
        return this->regionName.IsEmpty();
    }
#endif
};
