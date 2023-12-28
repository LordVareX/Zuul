/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ExecuteStatementRequest.h"

#endif

#include "Model/DynamoDBAttributeValue.h"
#include "Model/ReturnConsumedCapacity.h"

#include "AWSDynamoDBExecuteStatementRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBExecuteStatementRequest {
GENERATED_BODY()
    /**
    *  <p> The PartiQL statement representing the operation to run. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString statement;

    /**
    *  <p> The parameters for the PartiQL statement, if any. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FDynamoDBAttributeValue> parameters;

    /**
    *  <p> The consistency of a read operation. If set to <code>true</code>, then a strongly consistent read is used; otherwise, an eventually consistent read is used. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    bool consistentRead = false;

    /**
    *  <p> Set this value to get remaining results, if <code>NextToken</code> was returned in the statement response. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString nextToken;

    /**
    *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReturnConsumedCapacity returnConsumedCapacity = EAWSReturnConsumedCapacity::NOT_SET;

    /**
    *  <p>The maximum number of items to evaluate (not necessarily the number of matching items). If DynamoDB processes the number of items up to the limit while processing the results, it stops the operation and returns the matching values up to that point, along with a key in <code>LastEvaluatedKey</code> to apply in a subsequent operation so you can pick up where you left off. Also, if the processed dataset size exceeds 1 MB before DynamoDB reaches this limit, it stops the operation and returns the matching values up to the limit, and a key in <code>LastEvaluatedKey</code> to apply in a subsequent operation to continue the operation. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int limit = 0;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ExecuteStatementRequest toAWS() const {
        Aws::DynamoDB::Model::ExecuteStatementRequest awsExecuteStatementRequest;

        if (!(this->statement.IsEmpty())) {
            awsExecuteStatementRequest.SetStatement(TCHAR_TO_UTF8(*this->statement));
        }

        for (const FDynamoDBAttributeValue& elem : this->parameters) {
            awsExecuteStatementRequest.AddParameters(elem.toAWS());
        }

        if (!(false)) {
            awsExecuteStatementRequest.SetConsistentRead(this->consistentRead);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsExecuteStatementRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        switch(this->returnConsumedCapacity) {
            case EAWSReturnConsumedCapacity::INDEXES:
                awsExecuteStatementRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::INDEXES);
                break;
            case EAWSReturnConsumedCapacity::TOTAL:
                awsExecuteStatementRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::TOTAL);
                break;
            case EAWSReturnConsumedCapacity::NONE:
                awsExecuteStatementRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::NONE);
                break;
            default:
                break;
        }

        if (!(this->limit == 0)) {
            awsExecuteStatementRequest.SetLimit(this->limit);
        }

        return awsExecuteStatementRequest;
    }

    bool IsEmpty() const {
        return this->statement.IsEmpty() && this->parameters.Num() == 0 && false && this->nextToken.IsEmpty() && this->returnConsumedCapacity == EAWSReturnConsumedCapacity::NOT_SET && this->limit == 0 ;
    }
#endif
};
