/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/SetPrincipalTagAttributeMapResult.h"

#endif

#include "AWSCognitoIdentitySetPrincipalTagAttributeMapResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSCognitoIdentitySetPrincipalTagAttributeMapResult {
GENERATED_BODY()

    /**
    *  <p>The ID of the Identity Pool you want to set attribute mappings for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolId;

    /**
    *  <p>The provider name you want to use for attribute mappings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityProviderName;

    /**
    *  <p>You can use this operation to select default (username and clientID) attribute mappings.</p>
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
    FAWSCognitoIdentitySetPrincipalTagAttributeMapResult &fromAWS(const Aws::CognitoIdentity::Model::SetPrincipalTagAttributeMapResult &awsSetPrincipalTagAttributeMapResult) {
        this->identityPoolId = UTF8_TO_TCHAR(awsSetPrincipalTagAttributeMapResult.GetIdentityPoolId().c_str());

        this->identityProviderName = UTF8_TO_TCHAR(awsSetPrincipalTagAttributeMapResult.GetIdentityProviderName().c_str());

        this->useDefaults = awsSetPrincipalTagAttributeMapResult.GetUseDefaults();

        this->principalTags.Empty();
        for (const auto& elem : awsSetPrincipalTagAttributeMapResult.GetPrincipalTags()) {
            this->principalTags.Add(UTF8_TO_TCHAR(elem.first.c_str()), UTF8_TO_TCHAR(elem.second.c_str()));
        }

        return *this;
    }
#endif
};
