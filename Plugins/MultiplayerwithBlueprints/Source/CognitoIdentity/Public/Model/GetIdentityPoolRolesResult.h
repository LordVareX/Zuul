/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/GetIdentityPoolRolesResult.h"

#endif

#include "Model/RoleMapping.h"

#include "GetIdentityPoolRolesResult.generated.h"

USTRUCT(BlueprintType)
struct FGetIdentityPoolRolesResult {
GENERATED_BODY()

    /**
    *  <p>An identity pool ID in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolId;

    /**
    *  <p>The map of roles associated with this pool. Currently only authenticated and unauthenticated roles are supported.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TMap<FString, FString> roles;

    /**
    *  <p>How users for a specific identity provider are to mapped to roles. This is a String-to-<a>RoleMapping</a> object map. The string identifies the identity provider, for example, "graph.facebook.com" or "cognito-idp.us-east-1.amazonaws.com/us-east-1_abcdefghi:app_client_id".</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TMap<FString, FRoleMapping> roleMappings;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FGetIdentityPoolRolesResult &fromAWS(const Aws::CognitoIdentity::Model::GetIdentityPoolRolesResult &awsGetIdentityPoolRolesResult) {
        this->identityPoolId = UTF8_TO_TCHAR(awsGetIdentityPoolRolesResult.GetIdentityPoolId().c_str());

        this->roles.Empty();
        for (const auto& elem : awsGetIdentityPoolRolesResult.GetRoles()) {
            this->roles.Add(elem.first.c_str(), elem.second.c_str());
        }

        this->roleMappings.Empty();
        for (const auto& elem : awsGetIdentityPoolRolesResult.GetRoleMappings()) {
            this->roleMappings.Add(elem.first.c_str(), FRoleMapping().fromAWS(elem.second));
        }

        return *this;
    }
#endif
};
