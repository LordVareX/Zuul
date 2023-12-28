/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/UpdateIdentityPoolRequest.h"

#endif

#include "Model/CognitoIdentityProvider.h"

#include "UpdateIdentityPoolRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateIdentityPoolRequest {
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
    Aws::CognitoIdentity::Model::UpdateIdentityPoolRequest toAWS() const {
        Aws::CognitoIdentity::Model::UpdateIdentityPoolRequest awsUpdateIdentityPoolRequest;

        if (!(this->identityPoolId.IsEmpty())) {
            awsUpdateIdentityPoolRequest.SetIdentityPoolId(TCHAR_TO_UTF8(*this->identityPoolId));
        }

        if (!(this->identityPoolName.IsEmpty())) {
            awsUpdateIdentityPoolRequest.SetIdentityPoolName(TCHAR_TO_UTF8(*this->identityPoolName));
        }

        if (!(false)) {
            awsUpdateIdentityPoolRequest.SetAllowUnauthenticatedIdentities(this->allowUnauthenticatedIdentities);
        }

        if (!(false)) {
            awsUpdateIdentityPoolRequest.SetAllowClassicFlow(this->allowClassicFlow);
        }

        for (const TPair<FString, FString>& elem : this->supportedLoginProviders) {
            awsUpdateIdentityPoolRequest.AddSupportedLoginProviders(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        if (!(this->developerProviderName.IsEmpty())) {
            awsUpdateIdentityPoolRequest.SetDeveloperProviderName(TCHAR_TO_UTF8(*this->developerProviderName));
        }

        for (const FString& elem : this->openIdConnectProviderARNs) {
            awsUpdateIdentityPoolRequest.AddOpenIdConnectProviderARNs(TCHAR_TO_UTF8(*elem));
        }

        for (const FCognitoIdentityProvider& elem : this->cognitoIdentityProviders) {
            awsUpdateIdentityPoolRequest.AddCognitoIdentityProviders(elem.toAWS());
        }

        for (const FString& elem : this->samlProviderARNs) {
            awsUpdateIdentityPoolRequest.AddSamlProviderARNs(TCHAR_TO_UTF8(*elem));
        }

        for (const TPair<FString, FString>& elem : this->identityPoolTags) {
            awsUpdateIdentityPoolRequest.AddIdentityPoolTags(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsUpdateIdentityPoolRequest;
    }

    bool IsEmpty() const {
        return this->identityPoolId.IsEmpty() && this->identityPoolName.IsEmpty() && false && false && this->supportedLoginProviders.Num() == 0 && this->developerProviderName.IsEmpty() && this->openIdConnectProviderARNs.Num() == 0 && this->cognitoIdentityProviders.Num() == 0 && this->samlProviderARNs.Num() == 0 && this->identityPoolTags.Num() == 0;
    }
#endif
};
