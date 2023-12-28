/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CreateIdentityProviderRequest.h"

#endif

#include "Model/IdentityProviderTypeType.h"

#include "CreateIdentityProviderRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateIdentityProviderRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The identity provider name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString providerName;

    /**
    *  <p>The identity provider type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EIdentityProviderTypeType providerType = EIdentityProviderTypeType::NOT_SET;

    /**
    *  <p>The identity provider details, such as <code>MetadataURL</code> and <code>MetadataFile</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> providerDetails;

    /**
    *  <p>A mapping of identity provider attributes to standard and custom user pool attributes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> attributeMapping;

    /**
    *  <p>A list of identity provider identifiers.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> idpIdentifiers;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::CreateIdentityProviderRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::CreateIdentityProviderRequest awsCreateIdentityProviderRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsCreateIdentityProviderRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->providerName.IsEmpty())) {
            awsCreateIdentityProviderRequest.SetProviderName(TCHAR_TO_UTF8(*this->providerName));
        }

        switch(this->providerType) {
            case EIdentityProviderTypeType::SAML:
                awsCreateIdentityProviderRequest.SetProviderType(Aws::CognitoIdentityProvider::Model::IdentityProviderTypeType::SAML);
                break;
            case EIdentityProviderTypeType::Facebook:
                awsCreateIdentityProviderRequest.SetProviderType(Aws::CognitoIdentityProvider::Model::IdentityProviderTypeType::Facebook);
                break;
            case EIdentityProviderTypeType::Google:
                awsCreateIdentityProviderRequest.SetProviderType(Aws::CognitoIdentityProvider::Model::IdentityProviderTypeType::Google);
                break;
            case EIdentityProviderTypeType::LoginWithAmazon:
                awsCreateIdentityProviderRequest.SetProviderType(Aws::CognitoIdentityProvider::Model::IdentityProviderTypeType::LoginWithAmazon);
                break;
            case EIdentityProviderTypeType::SignInWithApple:
                awsCreateIdentityProviderRequest.SetProviderType(Aws::CognitoIdentityProvider::Model::IdentityProviderTypeType::SignInWithApple);
                break;
            case EIdentityProviderTypeType::OIDC:
                awsCreateIdentityProviderRequest.SetProviderType(Aws::CognitoIdentityProvider::Model::IdentityProviderTypeType::OIDC);
                break;
            default:
                break;
        }

        for (const TPair<FString, FString>& elem : this->providerDetails) {
            awsCreateIdentityProviderRequest.AddProviderDetails(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        for (const TPair<FString, FString>& elem : this->attributeMapping) {
            awsCreateIdentityProviderRequest.AddAttributeMapping(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        for (const FString& elem : this->idpIdentifiers) {
            awsCreateIdentityProviderRequest.AddIdpIdentifiers(TCHAR_TO_UTF8(*elem));
        }

        return awsCreateIdentityProviderRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->providerName.IsEmpty() && this->providerType == EIdentityProviderTypeType::NOT_SET && this->providerDetails.Num() == 0 && this->attributeMapping.Num() == 0 && this->idpIdentifiers.Num() == 0;
    }
#endif
};
