/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/UpdateIdentityPoolResult.h"

#endif

#include "Model/CognitoIdentityProvider.h"

#include "UpdateIdentityPoolResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateIdentityPoolResult {
GENERATED_BODY()

    /**
    *  <p>An identity pool ID in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolId;

    /**
    *  <p>A string that you provide.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolName;

    /**
    *  <p>TRUE if the identity pool supports unauthenticated logins.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    bool allowUnauthenticatedIdentities = false;

    /**
    *  <p>Enables or disables the Basic (Classic) authentication flow. For more information, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/authentication-flow.html">Identity Pools (Federated Identities) Authentication Flow</a> in the <i>Amazon Cognito Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    bool allowClassicFlow = false;

    /**
    *  <p>Optional key:value pairs mapping provider names to provider app IDs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TMap<FString, FString> supportedLoginProviders;

    /**
    *  <p>The "domain" by which Cognito will refer to your users.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString developerProviderName;

    /**
    *  <p>A list of OpendID Connect provider ARNs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TArray<FString> openIdConnectProviderARNs;

    /**
    *  <p>A list representing an Amazon Cognito user pool and its client ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TArray<FCognitoIdentityProvider> cognitoIdentityProviders;

    /**
    *  <p>An array of Amazon Resource Names (ARNs) of the SAML provider for your identity pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TArray<FString> samlProviderARNs;

    /**
    *  <p>The tags that are assigned to the identity pool. A tag is a label that you can apply to identity pools to categorize and manage them in different ways, such as by purpose, owner, environment, or other criteria.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TMap<FString, FString> identityPoolTags;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FUpdateIdentityPoolResult &fromAWS(const Aws::CognitoIdentity::Model::UpdateIdentityPoolResult &awsUpdateIdentityPoolResult) {
        this->identityPoolId = UTF8_TO_TCHAR(awsUpdateIdentityPoolResult.GetIdentityPoolId().c_str());

        this->identityPoolName = UTF8_TO_TCHAR(awsUpdateIdentityPoolResult.GetIdentityPoolName().c_str());

        this->allowUnauthenticatedIdentities = awsUpdateIdentityPoolResult.GetAllowUnauthenticatedIdentities();

        this->allowClassicFlow = awsUpdateIdentityPoolResult.GetAllowClassicFlow();

        this->supportedLoginProviders.Empty();
        for (const auto& elem : awsUpdateIdentityPoolResult.GetSupportedLoginProviders()) {
            this->supportedLoginProviders.Add(elem.first.c_str(), elem.second.c_str());
        }

        this->developerProviderName = UTF8_TO_TCHAR(awsUpdateIdentityPoolResult.GetDeveloperProviderName().c_str());

        this->openIdConnectProviderARNs.Empty();
        for (const Aws::String& elem : awsUpdateIdentityPoolResult.GetOpenIdConnectProviderARNs()) {
            this->openIdConnectProviderARNs.Add(elem.c_str());
        }

        this->cognitoIdentityProviders.Empty();
        for (const Aws::CognitoIdentity::Model::CognitoIdentityProvider& elem : awsUpdateIdentityPoolResult.GetCognitoIdentityProviders()) {
            this->cognitoIdentityProviders.Add(FCognitoIdentityProvider().fromAWS(elem));
        }

        this->samlProviderARNs.Empty();
        for (const Aws::String& elem : awsUpdateIdentityPoolResult.GetSamlProviderARNs()) {
            this->samlProviderARNs.Add(elem.c_str());
        }

        this->identityPoolTags.Empty();
        for (const auto& elem : awsUpdateIdentityPoolResult.GetIdentityPoolTags()) {
            this->identityPoolTags.Add(elem.first.c_str(), elem.second.c_str());
        }

        return *this;
    }
#endif
};
