/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/FailureException.h"

#endif

#include "FailureException.generated.h"

USTRUCT(BlueprintType)
struct FFailureException {
GENERATED_BODY()

    /**
    *  <p>Exception name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString exceptionName;

    /**
    *  <p>Description of the failure.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString exceptionDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FFailureException &fromAWS(const Aws::DynamoDB::Model::FailureException &awsFailureException) {
        this->exceptionName = UTF8_TO_TCHAR(awsFailureException.GetExceptionName().c_str());

        this->exceptionDescription = UTF8_TO_TCHAR(awsFailureException.GetExceptionDescription().c_str());

        return *this;
    }
#endif
};
