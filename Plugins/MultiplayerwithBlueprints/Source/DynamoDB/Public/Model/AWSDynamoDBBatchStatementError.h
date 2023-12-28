/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/BatchStatementError.h"

#endif

#include "Model/AWSDynamoDBBatchStatementErrorCodeEnum.h"

#include "AWSDynamoDBBatchStatementError.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBBatchStatementError {
GENERATED_BODY()
    /**
    *  <p> The error code associated with the failed PartiQL batch statement. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBBatchStatementErrorCodeEnum code = EAWSDynamoDBBatchStatementErrorCodeEnum::NOT_SET;
    /**
    *  <p> The error message associated with the PartiQL batch resposne. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString message;
    
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBBatchStatementError &fromAWS(const Aws::DynamoDB::Model::BatchStatementError &awsBatchStatementError) {
        switch(awsBatchStatementError.GetCode()) {
            case Aws::DynamoDB::Model::BatchStatementErrorCodeEnum::NOT_SET:
                this->code = EAWSDynamoDBBatchStatementErrorCodeEnum::NOT_SET;
                break;
            case Aws::DynamoDB::Model::BatchStatementErrorCodeEnum::ConditionalCheckFailed:
                this->code = EAWSDynamoDBBatchStatementErrorCodeEnum::ConditionalCheckFailed;
                break;
            case Aws::DynamoDB::Model::BatchStatementErrorCodeEnum::ItemCollectionSizeLimitExceeded:
                this->code = EAWSDynamoDBBatchStatementErrorCodeEnum::ItemCollectionSizeLimitExceeded;
                break;
            case Aws::DynamoDB::Model::BatchStatementErrorCodeEnum::RequestLimitExceeded:
                this->code = EAWSDynamoDBBatchStatementErrorCodeEnum::RequestLimitExceeded;
                break;
            case Aws::DynamoDB::Model::BatchStatementErrorCodeEnum::ValidationError:
                this->code = EAWSDynamoDBBatchStatementErrorCodeEnum::ValidationError;
                break;
            case Aws::DynamoDB::Model::BatchStatementErrorCodeEnum::ProvisionedThroughputExceeded:
                this->code = EAWSDynamoDBBatchStatementErrorCodeEnum::ProvisionedThroughputExceeded;
                break;
            case Aws::DynamoDB::Model::BatchStatementErrorCodeEnum::TransactionConflict:
                this->code = EAWSDynamoDBBatchStatementErrorCodeEnum::TransactionConflict;
                break;
            case Aws::DynamoDB::Model::BatchStatementErrorCodeEnum::ThrottlingError:
                this->code = EAWSDynamoDBBatchStatementErrorCodeEnum::ThrottlingError;
                break;
            case Aws::DynamoDB::Model::BatchStatementErrorCodeEnum::InternalServerError:
                this->code = EAWSDynamoDBBatchStatementErrorCodeEnum::InternalServerError;
                break;
            case Aws::DynamoDB::Model::BatchStatementErrorCodeEnum::ResourceNotFound:
                this->code = EAWSDynamoDBBatchStatementErrorCodeEnum::ResourceNotFound;
                break;
            case Aws::DynamoDB::Model::BatchStatementErrorCodeEnum::AccessDenied:
                this->code = EAWSDynamoDBBatchStatementErrorCodeEnum::AccessDenied;
                break;
            case Aws::DynamoDB::Model::BatchStatementErrorCodeEnum::DuplicateItem:
                this->code = EAWSDynamoDBBatchStatementErrorCodeEnum::DuplicateItem;
                break;
            default:
                this->code = EAWSDynamoDBBatchStatementErrorCodeEnum::NOT_SET;
                break;
            }

        this->message = UTF8_TO_TCHAR(awsBatchStatementError.GetMessage().c_str());

        return *this;
    }
#endif
};
