/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/Replica.h"

#endif

#include "Replica.generated.h"

USTRUCT(BlueprintType)
struct FReplica {
GENERATED_BODY()

    /**
    *  <p>The region where the replica needs to be created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString regionName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::Replica toAWS() const {
        Aws::DynamoDB::Model::Replica awsReplica;

		if (!(this->regionName.IsEmpty())) {
            awsReplica.SetRegionName(TCHAR_TO_UTF8(*this->regionName));
        }

        return awsReplica;
    }

    bool IsEmpty() const {
        return this->regionName.IsEmpty();
    }

    FReplica &fromAWS(const Aws::DynamoDB::Model::Replica &awsReplica) {
        this->regionName = UTF8_TO_TCHAR(awsReplica.GetRegionName().c_str());

        return *this;
    }
#endif
};
