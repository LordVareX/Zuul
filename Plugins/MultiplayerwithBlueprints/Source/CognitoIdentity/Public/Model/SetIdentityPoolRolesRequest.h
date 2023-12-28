/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/SetIdentityPoolRolesRequest.h"

#endif

#include "Model/RoleMapping.h"

#include "SetIdentityPoolRolesRequest.generated.h"

USTRUCT(BlueprintType)
struct FSetIdentityPoolRolesRequest {
GENERATED_BODY()

    /**
    *  <p>An identity pool ID in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolId;

    /**
    *  <p>The map of roles associated with this pool. For a given role, the key will be either "authenticated" or "unauthenticated" and the value will be the Role ARN.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TMap<FString, FString> roles;

    /**
    *  <p>How users for a specific identity provider are to mapped to roles. This is a string to <a>RoleMapping</a> object map. The string identifies the identity provider, for example, "graph.facebook.com" or "cognito-idp-east-1.amazonaws.com/us-east-1_abcdefghi:app_client_id".</p> <p>Up to 25 rules can be specified per identity provider.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TMap<FString, FRoleMapping> roleMappings;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::SetIdentityPoolRolesRequest toAWS() const {
        Aws::CognitoIdentity::Model::SetIdentityPoolRolesRequest awsSetIdentityPoolRolesRequest;

        if (!(this->identityPoolId.IsEmpty())) {
            awsSetIdentityPoolRolesRequest.SetIdentityPoolId(TCHAR_TO_UTF8(*this->identityPoolId));
        }

        for (const TPair<FString, FString>& elem : this->roles) {
            awsSetIdentityPoolRolesRequest.AddRoles(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        for (const TPair<FString, FRoleMapping>& elem : this->roleMappings) {
            awsSetIdentityPoolRolesRequest.AddRoleMappings(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

        return awsSetIdentityPoolRolesRequest;
    }

    bool IsEmpty() const {
        return this->identityPoolId.IsEmpty() && this->roles.Num() == 0 && this->roleMappings.Num() == 0;
    }
#endif
};
