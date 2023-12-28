/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ResourceServerType.h"

#endif

#include "Model/ResourceServerScopeType.h"

#include "ResourceServerType.generated.h"

USTRUCT(BlueprintType)
struct FResourceServerType {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool that hosts the resource server.</p>
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
    *  <p>A list of scopes that are defined for the resource server.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FResourceServerScopeType> scopes;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FResourceServerType &fromAWS(const Aws::CognitoIdentityProvider::Model::ResourceServerType &awsResourceServerType) {
        this->userPoolId = UTF8_TO_TCHAR(awsResourceServerType.GetUserPoolId().c_str());

        this->identifier = UTF8_TO_TCHAR(awsResourceServerType.GetIdentifier().c_str());

        this->name = UTF8_TO_TCHAR(awsResourceServerType.GetName().c_str());

        this->scopes.Empty();
        for (const Aws::CognitoIdentityProvider::Model::ResourceServerScopeType& elem : awsResourceServerType.GetScopes()) {
            this->scopes.Add(FResourceServerScopeType().fromAWS(elem));
        }

        return *this;
    }
#endif
};
