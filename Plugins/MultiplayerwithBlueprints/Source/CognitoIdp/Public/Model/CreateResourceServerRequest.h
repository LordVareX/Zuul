/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CreateResourceServerRequest.h"

#endif

#include "Model/ResourceServerScopeType.h"

#include "CreateResourceServerRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateResourceServerRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>A unique resource server identifier for the resource server. This could be an HTTPS endpoint where the resource server is located. For example, <code>https://my-weather-api.example.com</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString identifier;

    /**
    *  <p>A friendly name for the resource server.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString name;

    /**
    *  <p>A list of scopes. Each scope is map, where the keys are <code>name</code> and <code>description</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FResourceServerScopeType> scopes;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::CreateResourceServerRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::CreateResourceServerRequest awsCreateResourceServerRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsCreateResourceServerRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->identifier.IsEmpty())) {
            awsCreateResourceServerRequest.SetIdentifier(TCHAR_TO_UTF8(*this->identifier));
        }

        if (!(this->name.IsEmpty())) {
            awsCreateResourceServerRequest.SetName(TCHAR_TO_UTF8(*this->name));
        }

        for (const FResourceServerScopeType& elem : this->scopes) {
            awsCreateResourceServerRequest.AddScopes(elem.toAWS());
        }

        return awsCreateResourceServerRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->identifier.IsEmpty() && this->name.IsEmpty() && this->scopes.Num() == 0;
    }
#endif
};
