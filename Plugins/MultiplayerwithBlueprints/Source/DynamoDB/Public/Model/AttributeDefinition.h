/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/AttributeDefinition.h"

#endif

#include "Model/ScalarAttributeType.h"

#include "AttributeDefinition.generated.h"

USTRUCT(BlueprintType)
struct FAttributeDefinition {
GENERATED_BODY()

    /**
    *  <p>A name for the attribute.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString attributeName;

    /**
    *  <p>The data type for the attribute, where:</p> <ul> <li> <p> <code>S</code> - the attribute is of type String</p> </li> <li> <p> <code>N</code> - the attribute is of type Number</p> </li> <li> <p> <code>B</code> - the attribute is of type Binary</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSScalarAttributeType attributeType = EAWSScalarAttributeType::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::AttributeDefinition toAWS() const {
        Aws::DynamoDB::Model::AttributeDefinition awsAttributeDefinition;

		if (!(this->attributeName.IsEmpty())) {
            awsAttributeDefinition.SetAttributeName(TCHAR_TO_UTF8(*this->attributeName));
        }

        switch(this->attributeType) {
            case EAWSScalarAttributeType::S:
                awsAttributeDefinition.SetAttributeType(Aws::DynamoDB::Model::ScalarAttributeType::S);
                break;
            case EAWSScalarAttributeType::N:
                awsAttributeDefinition.SetAttributeType(Aws::DynamoDB::Model::ScalarAttributeType::N);
                break;
            case EAWSScalarAttributeType::B:
                awsAttributeDefinition.SetAttributeType(Aws::DynamoDB::Model::ScalarAttributeType::B);
                break;
            default:
                break;
            }

        return awsAttributeDefinition;
    }

    bool IsEmpty() const {
        return this->attributeName.IsEmpty() && this->attributeType == EAWSScalarAttributeType::NOT_SET;
    }

    FAttributeDefinition &fromAWS(const Aws::DynamoDB::Model::AttributeDefinition &awsAttributeDefinition) {
        this->attributeName = UTF8_TO_TCHAR(awsAttributeDefinition.GetAttributeName().c_str());

        switch(awsAttributeDefinition.GetAttributeType()) {
            case Aws::DynamoDB::Model::ScalarAttributeType::NOT_SET:
                this->attributeType = EAWSScalarAttributeType::NOT_SET;
                break;
            case Aws::DynamoDB::Model::ScalarAttributeType::S:
                this->attributeType = EAWSScalarAttributeType::S;
                break;
            case Aws::DynamoDB::Model::ScalarAttributeType::N:
                this->attributeType = EAWSScalarAttributeType::N;
                break;
            case Aws::DynamoDB::Model::ScalarAttributeType::B:
                this->attributeType = EAWSScalarAttributeType::B;
                break;
            default:
                this->attributeType = EAWSScalarAttributeType::NOT_SET;
                break;
            }

        return *this;
    }
#endif
};
