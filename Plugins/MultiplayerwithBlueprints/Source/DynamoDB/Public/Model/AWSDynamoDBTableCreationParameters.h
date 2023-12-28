/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/TableCreationParameters.h"

#endif

#include "Model/AttributeDefinition.h"
#include "Model/DynamoDBKeySchemaElement.h"
#include "Model/BillingMode.h"
#include "Model/ProvisionedThroughput.h"
#include "Model/SSESpecification.h"
#include "Model/GlobalSecondaryIndex.h"

#include "AWSDynamoDBTableCreationParameters.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBTableCreationParameters {
GENERATED_BODY()

    /**
    *  <p> The name of the table created as part of the import operation. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p> The attributes of the table created as part of the import operation. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FAttributeDefinition> attributeDefinitions;

    /**
    *  <p> The primary key and option sort key of the table created as part of the import operation. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FDynamoDBKeySchemaElement> keySchema;

    /**
    *  <p> The billing mode for provisioning the table created as part of the import operation. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSBillingMode billingMode = EAWSBillingMode::NOT_SET;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FProvisionedThroughput provisionedThroughput;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FSSESpecification sSESpecification;

    /**
    *  <p> The Global Secondary Indexes (GSI) of the table to be created as part of the import operation. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FGlobalSecondaryIndex> globalSecondaryIndexes;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::TableCreationParameters toAWS() const {
        Aws::DynamoDB::Model::TableCreationParameters awsTableCreationParameters;

        if (!(this->tableName.IsEmpty())) {
            awsTableCreationParameters.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

        for (const FAttributeDefinition& elem : this->attributeDefinitions) {
            awsTableCreationParameters.AddAttributeDefinitions(elem.toAWS());
        }

        for (const FDynamoDBKeySchemaElement& elem : this->keySchema) {
            awsTableCreationParameters.AddKeySchema(elem.toAWS());
        }

        switch(this->billingMode) {
            case EAWSBillingMode::PROVISIONED:
                awsTableCreationParameters.SetBillingMode(Aws::DynamoDB::Model::BillingMode::PROVISIONED);
                break;
            case EAWSBillingMode::PAY_PER_REQUEST:
                awsTableCreationParameters.SetBillingMode(Aws::DynamoDB::Model::BillingMode::PAY_PER_REQUEST);
                break;
            default:
                break;
        }

        if (!(this->provisionedThroughput.IsEmpty())) {
            awsTableCreationParameters.SetProvisionedThroughput(this->provisionedThroughput.toAWS());
        }

        if (!(this->sSESpecification.IsEmpty())) {
            awsTableCreationParameters.SetSSESpecification(this->sSESpecification.toAWS());
        }

        for (const FGlobalSecondaryIndex& elem : this->globalSecondaryIndexes) {
            awsTableCreationParameters.AddGlobalSecondaryIndexes(elem.toAWS());
        }

        return awsTableCreationParameters;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty() && this->attributeDefinitions.Num() == 0 && this->keySchema.Num() == 0 && billingMode == EAWSBillingMode::NOT_SET && this->provisionedThroughput.IsEmpty() && this->sSESpecification.IsEmpty() && this->globalSecondaryIndexes.Num() == 0;
    }

    FAWSDynamoDBTableCreationParameters &fromAWS(const Aws::DynamoDB::Model::TableCreationParameters &awsTableCreationParameters) {
        this->tableName = UTF8_TO_TCHAR(awsTableCreationParameters.GetTableName().c_str());

        this->attributeDefinitions.Empty();
        for (const Aws::DynamoDB::Model::AttributeDefinition& elem : awsTableCreationParameters.GetAttributeDefinitions()) {
            this->attributeDefinitions.Add(FAttributeDefinition().fromAWS(elem));
        }

        this->keySchema.Empty();
        for (const Aws::DynamoDB::Model::KeySchemaElement& elem : awsTableCreationParameters.GetKeySchema()) {
            this->keySchema.Add(FDynamoDBKeySchemaElement().fromAWS(elem));
        }

        switch(awsTableCreationParameters.GetBillingMode()) {
            case Aws::DynamoDB::Model::BillingMode::NOT_SET:
                this->billingMode = EAWSBillingMode::NOT_SET;
                break;
            case Aws::DynamoDB::Model::BillingMode::PROVISIONED:
                this->billingMode = EAWSBillingMode::PROVISIONED;
                break;
            case Aws::DynamoDB::Model::BillingMode::PAY_PER_REQUEST:
                this->billingMode = EAWSBillingMode::PAY_PER_REQUEST;
                break;
            default:
                this->billingMode = EAWSBillingMode::NOT_SET;
                break;
        }

        this->provisionedThroughput.fromAWS(awsTableCreationParameters.GetProvisionedThroughput());

        this->sSESpecification.fromAWS(awsTableCreationParameters.GetSSESpecification());
        

        this->globalSecondaryIndexes.Empty();
        for (const Aws::DynamoDB::Model::GlobalSecondaryIndex& elem : awsTableCreationParameters.GetGlobalSecondaryIndexes()) {
            this->globalSecondaryIndexes.Add(FGlobalSecondaryIndex().fromAWS(elem));
        }

        return *this;
    }
#endif
};
