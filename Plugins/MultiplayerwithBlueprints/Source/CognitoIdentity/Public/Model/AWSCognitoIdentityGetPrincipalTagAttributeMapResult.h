/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/GetPrincipalTagAttributeMapResult.h"

#endif

#include "AWSCognitoIdentityGetPrincipalTagAttributeMapResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSCognitoIdentityGetPrincipalTagAttributeMapResult {
GENERATED_BODY()

    /**
    *  <p>You can use this operation to get the ID of the Identity Pool you setup attribute mappings for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolId;

    /**
    *  <p>You can use this operation to get the provider name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityProviderName;

    /**
    *  <p>You can use this operation to list </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    bool useDefaults = false;

    /**
    *  <p>You can use this operation to add principal tags. The <code>PrincipalTags</code>operation enables you to reference user attributes in your IAM permissions policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TMap<FString, FString> principalTags;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FAWSCognitoIdentityGetPrincipalTagAttributeMapResult &fromAWS(const Aws::CognitoIdentity::Model::GetPrincipalTagAttributeMapResult &awsGetPrincipalTagAttributeMapResult) {
        this->identityPoolId = UTF8_TO_TCHAR(awsGetPrincipalTagAttributeMapResult.GetIdentityPoolId().c_str());

        this->identityProviderName = UTF8_TO_TCHAR(awsGetPrincipalTagAttributeMapResult.GetIdentityProviderName().c_str());

        this->useDefaults = awsGetPrincipalTagAttributeMapResult.GetUseDefaults();

        this->principalTags.Empty();
        for (const auto& elem : awsGetPrincipalTagAttributeMapResult.GetPrincipalTags()) {
            this->principalTags.Add(UTF8_TO_TCHAR(elem.first.c_str()), UTF8_TO_TCHAR(elem.second.c_str()));
        }

        return *this;
    }
#endif
};
