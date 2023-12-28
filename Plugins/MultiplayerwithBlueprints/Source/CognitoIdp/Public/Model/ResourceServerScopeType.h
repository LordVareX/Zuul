/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ResourceServerScopeType.h"

#endif

#include "ResourceServerScopeType.generated.h"

USTRUCT(BlueprintType)
struct FResourceServerScopeType {
GENERATED_BODY()

    /**
    *  <p>The name of the scope.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString scopeName;

    /**
    *  <p>A description of the scope.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString scopeDescription;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::ResourceServerScopeType toAWS() const {
        Aws::CognitoIdentityProvider::Model::ResourceServerScopeType awsResourceServerScopeType;

        if (!(this->scopeName.IsEmpty())) {
            awsResourceServerScopeType.SetScopeName(TCHAR_TO_UTF8(*this->scopeName));
        }

        if (!(this->scopeDescription.IsEmpty())) {
            awsResourceServerScopeType.SetScopeDescription(TCHAR_TO_UTF8(*this->scopeDescription));
        }

        return awsResourceServerScopeType;
    }

    bool IsEmpty() const {
        return this->scopeName.IsEmpty() && this->scopeDescription.IsEmpty();
    }

    FResourceServerScopeType &fromAWS(const Aws::CognitoIdentityProvider::Model::ResourceServerScopeType &awsResourceServerScopeType) {
        this->scopeName = UTF8_TO_TCHAR(awsResourceServerScopeType.GetScopeName().c_str());

        this->scopeDescription = UTF8_TO_TCHAR(awsResourceServerScopeType.GetScopeDescription().c_str());

        return *this;
    }
#endif
};
