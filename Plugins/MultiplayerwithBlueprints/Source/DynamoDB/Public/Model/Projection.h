/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/Projection.h"

#endif

#include "Model/ProjectionType.h"

#include "Projection.generated.h"

USTRUCT(BlueprintType)
struct FProjection {
GENERATED_BODY()

    /**
    *  <p>The set of attributes that are projected into the index:</p> <ul> <li> <p> <code>KEYS_ONLY</code> - Only the index and primary keys are projected into the index.</p> </li> <li> <p> <code>INCLUDE</code> - Only the specified table attributes are projected into the index. The list of projected attributes are in <code>NonKeyAttributes</code>.</p> </li> <li> <p> <code>ALL</code> - All of the table attributes are projected into the index.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSProjectionType projectionType = EAWSProjectionType::NOT_SET;

    /**
    *  <p>Represents the non-key attribute names which will be projected into the index.</p> <p>For local secondary indexes, the total count of <code>NonKeyAttributes</code> summed across all of the local secondary indexes, must not exceed 20. If you project the same attribute into two different indexes, this counts as two distinct attributes when determining the total.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FString> nonKeyAttributes;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::Projection toAWS() const {
        Aws::DynamoDB::Model::Projection awsProjection;

        switch(this->projectionType) {
            case EAWSProjectionType::ALL:
                awsProjection.SetProjectionType(Aws::DynamoDB::Model::ProjectionType::ALL);
                break;
            case EAWSProjectionType::KEYS_ONLY:
                awsProjection.SetProjectionType(Aws::DynamoDB::Model::ProjectionType::KEYS_ONLY);
                break;
            case EAWSProjectionType::INCLUDE:
                awsProjection.SetProjectionType(Aws::DynamoDB::Model::ProjectionType::INCLUDE);
                break;
            default:
                break;
            }

        for (const FString& elem : this->nonKeyAttributes) {
            awsProjection.AddNonKeyAttributes(TCHAR_TO_UTF8(*elem));
        }

        return awsProjection;
    }

    bool IsEmpty() const {
        return this->projectionType == EAWSProjectionType::NOT_SET && this->nonKeyAttributes.Num() == 0;
    }

    FProjection &fromAWS(const Aws::DynamoDB::Model::Projection &awsProjection) {
        switch(awsProjection.GetProjectionType()) {
            case Aws::DynamoDB::Model::ProjectionType::NOT_SET:
                this->projectionType = EAWSProjectionType::NOT_SET;
                break;
            case Aws::DynamoDB::Model::ProjectionType::ALL:
                this->projectionType = EAWSProjectionType::ALL;
                break;
            case Aws::DynamoDB::Model::ProjectionType::KEYS_ONLY:
                this->projectionType = EAWSProjectionType::KEYS_ONLY;
                break;
            case Aws::DynamoDB::Model::ProjectionType::INCLUDE:
                this->projectionType = EAWSProjectionType::INCLUDE;
                break;
            default:
                this->projectionType = EAWSProjectionType::NOT_SET;
                break;
        }

        this->nonKeyAttributes.Empty();
        for (const Aws::String& elem : awsProjection.GetNonKeyAttributes()) {
            this->nonKeyAttributes.Add(elem.c_str());
        }

        return *this;
    }
#endif
};
