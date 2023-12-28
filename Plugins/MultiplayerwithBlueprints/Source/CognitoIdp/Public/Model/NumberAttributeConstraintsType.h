/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/NumberAttributeConstraintsType.h"

#endif

#include "NumberAttributeConstraintsType.generated.h"

USTRUCT(BlueprintType)
struct FNumberAttributeConstraintsType {
GENERATED_BODY()

    /**
    *  <p>The minimum value of an attribute that is of the number data type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString minValue;

    /**
    *  <p>The maximum value of an attribute that is of the number data type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString maxValue;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::NumberAttributeConstraintsType toAWS() const {
        Aws::CognitoIdentityProvider::Model::NumberAttributeConstraintsType awsNumberAttributeConstraintsType;

        if (!(this->minValue.IsEmpty())) {
            awsNumberAttributeConstraintsType.SetMinValue(TCHAR_TO_UTF8(*this->minValue));
        }

        if (!(this->maxValue.IsEmpty())) {
            awsNumberAttributeConstraintsType.SetMaxValue(TCHAR_TO_UTF8(*this->maxValue));
        }

        return awsNumberAttributeConstraintsType;
    }

    bool IsEmpty() const {
        return this->minValue.IsEmpty() && this->maxValue.IsEmpty();
    }

    FNumberAttributeConstraintsType &fromAWS(const Aws::CognitoIdentityProvider::Model::NumberAttributeConstraintsType &awsNumberAttributeConstraintsType) {
        this->minValue = UTF8_TO_TCHAR(awsNumberAttributeConstraintsType.GetMinValue().c_str());

        this->maxValue = UTF8_TO_TCHAR(awsNumberAttributeConstraintsType.GetMaxValue().c_str());

        return *this;
    }
#endif
};
