/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ParameterizedStatement.h"

#endif

#include "Model/DynamoDBAttributeValue.h"

#include "AWSDynamoDBParameterizedStatement.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBParameterizedStatement {
GENERATED_BODY()

    /**
    *  <p> A PartiQL statment that uses parameters. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString statement;

    /**
    *  <p> The parameter values. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FDynamoDBAttributeValue> parameters;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ParameterizedStatement toAWS() const {
        Aws::DynamoDB::Model::ParameterizedStatement awsParameterizedStatement;

        if (!(this->statement.IsEmpty())) {
            awsParameterizedStatement.SetStatement(TCHAR_TO_UTF8(*this->statement));
        }

		for (const FDynamoDBAttributeValue& elem : this->parameters) {
            awsParameterizedStatement.AddParameters(elem.toAWS());
        }
        return awsParameterizedStatement;
    }

    bool IsEmpty() const {
        return this->statement.IsEmpty() && this->parameters.Num() == 0;
    }
#endif
};
