/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GetIdentityProviderByIdentifierRequest.h"

#endif

#include "GetIdentityProviderByIdentifierRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetIdentityProviderByIdentifierRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The identity provider ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString idpIdentifier;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::GetIdentityProviderByIdentifierRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::GetIdentityProviderByIdentifierRequest awsGetIdentityProviderByIdentifierRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsGetIdentityProviderByIdentifierRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->idpIdentifier.IsEmpty())) {
            awsGetIdentityProviderByIdentifierRequest.SetIdpIdentifier(TCHAR_TO_UTF8(*this->idpIdentifier));
        }

        return awsGetIdentityProviderByIdentifierRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->idpIdentifier.IsEmpty();
    }
#endif
};
