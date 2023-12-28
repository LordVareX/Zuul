/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/StringAttributeConstraintsType.h"

#endif

#include "StringAttributeConstraintsType.generated.h"

USTRUCT(BlueprintType)
struct FStringAttributeConstraintsType {
GENERATED_BODY()

    /**
    *  <p>The minimum length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString minLength;

    /**
    *  <p>The maximum length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString maxLength;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::StringAttributeConstraintsType toAWS() const {
        Aws::CognitoIdentityProvider::Model::StringAttributeConstraintsType awsStringAttributeConstraintsType;

        if (!(this->minLength.IsEmpty())) {
            awsStringAttributeConstraintsType.SetMinLength(TCHAR_TO_UTF8(*this->minLength));
        }

        if (!(this->maxLength.IsEmpty())) {
            awsStringAttributeConstraintsType.SetMaxLength(TCHAR_TO_UTF8(*this->maxLength));
        }

        return awsStringAttributeConstraintsType;
    }

    bool IsEmpty() const {
        return this->minLength.IsEmpty() && this->maxLength.IsEmpty();
    }

    FStringAttributeConstraintsType &fromAWS(const Aws::CognitoIdentityProvider::Model::StringAttributeConstraintsType &awsStringAttributeConstraintsType) {
        this->minLength = UTF8_TO_TCHAR(awsStringAttributeConstraintsType.GetMinLength().c_str());

        this->maxLength = UTF8_TO_TCHAR(awsStringAttributeConstraintsType.GetMaxLength().c_str());

        return *this;
    }
#endif
};
