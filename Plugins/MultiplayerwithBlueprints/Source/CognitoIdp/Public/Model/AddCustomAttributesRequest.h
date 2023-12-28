/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AddCustomAttributesRequest.h"

#endif

#include "Model/SchemaAttributeType.h"

#include "AddCustomAttributesRequest.generated.h"

USTRUCT(BlueprintType)
struct FAddCustomAttributesRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool where you want to add custom attributes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>An array of custom attributes, such as Mutable and Name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FSchemaAttributeType> customAttributes;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AddCustomAttributesRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AddCustomAttributesRequest awsAddCustomAttributesRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAddCustomAttributesRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        for (const FSchemaAttributeType& elem : this->customAttributes) {
            awsAddCustomAttributesRequest.AddCustomAttributes(elem.toAWS());
        }

        return awsAddCustomAttributesRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->customAttributes.Num() == 0;
    }
#endif
};
