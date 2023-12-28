/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AttributeType.h"

#endif

#include "AttributeType.generated.h"

USTRUCT(BlueprintType)
struct FAttributeType {
GENERATED_BODY()

    /**
    *  <p>The name of the attribute.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString name;

    /**
    *  <p>The value of the attribute.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString value;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AttributeType toAWS() const {
        Aws::CognitoIdentityProvider::Model::AttributeType awsAttributeType;

        if (!(this->name.IsEmpty())) {
            awsAttributeType.SetName(TCHAR_TO_UTF8(*this->name));
        }

        if (!(this->value.IsEmpty())) {
            awsAttributeType.SetValue(TCHAR_TO_UTF8(*this->value));
        }

        return awsAttributeType;
    }

    bool IsEmpty() const {
        return this->name.IsEmpty() && this->value.IsEmpty();
    }

    FAttributeType &fromAWS(const Aws::CognitoIdentityProvider::Model::AttributeType &awsAttributeType) {
        this->name = UTF8_TO_TCHAR(awsAttributeType.GetName().c_str());

        this->value = UTF8_TO_TCHAR(awsAttributeType.GetValue().c_str());

        return *this;
    }
#endif
};
