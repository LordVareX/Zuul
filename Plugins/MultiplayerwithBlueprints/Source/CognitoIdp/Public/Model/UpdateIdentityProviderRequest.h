/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UpdateIdentityProviderRequest.h"

#endif

#include "UpdateIdentityProviderRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateIdentityProviderRequest {
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
    *  <p>The identity provider details to be updated, such as <code>MetadataURL</code> and <code>MetadataFile</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> providerDetails;

    /**
    *  <p>The identity provider attribute mapping to be changed.</p>
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
    Aws::CognitoIdentityProvider::Model::UpdateIdentityProviderRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::UpdateIdentityProviderRequest awsUpdateIdentityProviderRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsUpdateIdentityProviderRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->providerName.IsEmpty())) {
            awsUpdateIdentityProviderRequest.SetProviderName(TCHAR_TO_UTF8(*this->providerName));
        }

        for (const TPair<FString, FString>& elem : this->providerDetails) {
            awsUpdateIdentityProviderRequest.AddProviderDetails(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        for (const TPair<FString, FString>& elem : this->attributeMapping) {
            awsUpdateIdentityProviderRequest.AddAttributeMapping(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        for (const FString& elem : this->idpIdentifiers) {
            awsUpdateIdentityProviderRequest.AddIdpIdentifiers(TCHAR_TO_UTF8(*elem));
        }

        return awsUpdateIdentityProviderRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->providerName.IsEmpty() && this->providerDetails.Num() == 0 && this->attributeMapping.Num() == 0 && this->idpIdentifiers.Num() == 0;
    }
#endif
};
