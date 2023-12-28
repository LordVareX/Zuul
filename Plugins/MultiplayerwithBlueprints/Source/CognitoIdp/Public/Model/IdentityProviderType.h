/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/IdentityProviderType.h"

#endif

#include "Model/IdentityProviderTypeType.h"

#include "IdentityProviderType.generated.h"

USTRUCT(BlueprintType)
struct FIdentityProviderType {
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

    /**
    *  <p>The date the identity provider was last modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime lastModifiedDate;

    /**
    *  <p>The date the identity provider was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime creationDate;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FIdentityProviderType &fromAWS(const Aws::CognitoIdentityProvider::Model::IdentityProviderType &awsIdentityProviderType) {
        this->userPoolId = UTF8_TO_TCHAR(awsIdentityProviderType.GetUserPoolId().c_str());

        this->providerName = UTF8_TO_TCHAR(awsIdentityProviderType.GetProviderName().c_str());

        switch(awsIdentityProviderType.GetProviderType()) {
            case Aws::CognitoIdentityProvider::Model::IdentityProviderTypeType::NOT_SET:
                this->providerType = EIdentityProviderTypeType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::IdentityProviderTypeType::SAML:
                this->providerType = EIdentityProviderTypeType::SAML;
                break;
            case Aws::CognitoIdentityProvider::Model::IdentityProviderTypeType::Facebook:
                this->providerType = EIdentityProviderTypeType::Facebook;
                break;
            case Aws::CognitoIdentityProvider::Model::IdentityProviderTypeType::Google:
                this->providerType = EIdentityProviderTypeType::Google;
                break;
            case Aws::CognitoIdentityProvider::Model::IdentityProviderTypeType::LoginWithAmazon:
                this->providerType = EIdentityProviderTypeType::LoginWithAmazon;
                break;
            case Aws::CognitoIdentityProvider::Model::IdentityProviderTypeType::SignInWithApple:
                this->providerType = EIdentityProviderTypeType::SignInWithApple;
                break;
            case Aws::CognitoIdentityProvider::Model::IdentityProviderTypeType::OIDC:
                this->providerType = EIdentityProviderTypeType::OIDC;
                break;
            default:
                this->providerType = EIdentityProviderTypeType::NOT_SET;
                break;
        }

        this->providerDetails.Empty();
        for (const auto& elem : awsIdentityProviderType.GetProviderDetails()) {
            this->providerDetails.Add(elem.first.c_str(), elem.second.c_str());
        }

        this->attributeMapping.Empty();
        for (const auto& elem : awsIdentityProviderType.GetAttributeMapping()) {
            this->attributeMapping.Add(elem.first.c_str(), elem.second.c_str());
        }

        this->idpIdentifiers.Empty();
        for (const Aws::String& elem : awsIdentityProviderType.GetIdpIdentifiers()) {
            this->idpIdentifiers.Add(elem.c_str());
        }

        this->lastModifiedDate = FDateTime(1970, 1, 1) + FTimespan(awsIdentityProviderType.GetLastModifiedDate().Millis() * ETimespan::TicksPerMillisecond);

        this->creationDate = FDateTime(1970, 1, 1) + FTimespan(awsIdentityProviderType.GetCreationDate().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
