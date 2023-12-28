/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ItemResponse.h"

#endif

#include "Model/DynamoDBAttributeValue.h"

#include "ItemResponse.generated.h"

USTRUCT(BlueprintType)
struct FItemResponse {
GENERATED_BODY()

    /**
    *  <p>Map of attribute data consisting of the data type and attribute value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> item;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FItemResponse &fromAWS(const Aws::DynamoDB::Model::ItemResponse &awsItemResponse) {
        this->item.Empty();
        for (const auto& elem : awsItemResponse.GetItem()) {
            this->item.Add(elem.first.c_str(), FDynamoDBAttributeValue().fromAWS(elem.second));
        }

        return *this;
    }
#endif
};
