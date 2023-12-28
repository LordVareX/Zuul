/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ProviderUserIdentifierType.h"

#endif

#include "ProviderUserIdentifierType.generated.h"

USTRUCT(BlueprintType)
struct FProviderUserIdentifierType {
GENERATED_BODY()

    /**
    *  <p>The name of the provider, for example, Facebook, Google, or Login with Amazon.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString providerName;

    /**
    *  <p>The name of the provider attribute to link to, for example, <code>NameID</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString providerAttributeName;

    /**
    *  <p>The value of the provider attribute to link to, for example, <code>xxxxx_account</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString providerAttributeValue;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::ProviderUserIdentifierType toAWS() const {
        Aws::CognitoIdentityProvider::Model::ProviderUserIdentifierType awsProviderUserIdentifierType;

        if (!(this->providerName.IsEmpty())) {
            awsProviderUserIdentifierType.SetProviderName(TCHAR_TO_UTF8(*this->providerName));
        }

        if (!(this->providerAttributeName.IsEmpty())) {
            awsProviderUserIdentifierType.SetProviderAttributeName(TCHAR_TO_UTF8(*this->providerAttributeName));
        }

        if (!(this->providerAttributeValue.IsEmpty())) {
            awsProviderUserIdentifierType.SetProviderAttributeValue(TCHAR_TO_UTF8(*this->providerAttributeValue));
        }

        return awsProviderUserIdentifierType;
    }

    bool IsEmpty() const {
        return this->providerName.IsEmpty() && this->providerAttributeName.IsEmpty() && this->providerAttributeValue.IsEmpty();
    }
#endif
};
