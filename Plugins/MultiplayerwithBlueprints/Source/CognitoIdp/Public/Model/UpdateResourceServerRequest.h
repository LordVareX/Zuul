/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UpdateResourceServerRequest.h"

#endif

#include "Model/ResourceServerScopeType.h"

#include "UpdateResourceServerRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateResourceServerRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The identifier for the resource server.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString identifier;

    /**
    *  <p>The name of the resource server.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString name;

    /**
    *  <p>The scope values to be set for the resource server.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FResourceServerScopeType> scopes;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::UpdateResourceServerRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::UpdateResourceServerRequest awsUpdateResourceServerRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsUpdateResourceServerRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->identifier.IsEmpty())) {
            awsUpdateResourceServerRequest.SetIdentifier(TCHAR_TO_UTF8(*this->identifier));
        }

        if (!(this->name.IsEmpty())) {
            awsUpdateResourceServerRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        for (const FResourceServerScopeType& elem : this->scopes) {
            awsUpdateResourceServerRequest.AddScopes(elem.toAWS());
        }

        return awsUpdateResourceServerRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->identifier.IsEmpty() && this->name.IsEmpty() && this->scopes.Num() == 0;
    }
#endif
};
