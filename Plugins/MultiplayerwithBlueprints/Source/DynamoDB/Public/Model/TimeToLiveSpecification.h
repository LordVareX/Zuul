/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/TimeToLiveSpecification.h"

#endif

#include "TimeToLiveSpecification.generated.h"

USTRUCT(BlueprintType)
struct FTimeToLiveSpecification {
GENERATED_BODY()

    /**
    *  <p>Indicates whether TTL is to be enabled (true) or disabled (false) on the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    bool enabled = false;

    /**
    *  <p>The name of the TTL attribute used to store the expiration time for items in the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString attributeName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::TimeToLiveSpecification toAWS() const {
        Aws::DynamoDB::Model::TimeToLiveSpecification awsTimeToLiveSpecification;

        awsTimeToLiveSpecification.SetEnabled(this->enabled);

		if (!(this->attributeName.IsEmpty())) {
            awsTimeToLiveSpecification.SetAttributeName(TCHAR_TO_UTF8(*this->attributeName));
        }

        return awsTimeToLiveSpecification;
    }

    bool IsEmpty() const {
        return false && this->attributeName.IsEmpty();
    }

    FTimeToLiveSpecification &fromAWS(const Aws::DynamoDB::Model::TimeToLiveSpecification &awsTimeToLiveSpecification) {
        this->enabled = awsTimeToLiveSpecification.GetEnabled();

        this->attributeName = UTF8_TO_TCHAR(awsTimeToLiveSpecification.GetAttributeName().c_str());

        return *this;
    }
#endif
};
