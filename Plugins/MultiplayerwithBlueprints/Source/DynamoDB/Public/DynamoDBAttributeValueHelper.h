/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, Oct 2021
 */

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

#include "DynamoDBAttributeValueHelper.generated.h"

/**
 * 
 */
UCLASS()
class DYNAMODB_API UDynamoDBAttributeValueHelper : public UBlueprintFunctionLibrary {
    GENERATED_BODY()

public:
    /*
     * type Invalid will be translated into null
     * type raw will be translated into string
     * */
    UFUNCTION(BlueprintPure,
              Category = "DynamoDB")
    static FString JsonToDynamoDBAttributeValue(FString json);

    /*
     * type binary will be translated into string
     * */
    UFUNCTION(BlueprintPure,
              Category = "DynamoDB")
    static FString DynamoDBAttributeValueToJson(FString attributeValue);
};

