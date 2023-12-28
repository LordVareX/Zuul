/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/GetPrincipalTagAttributeMapRequest.h"

#endif

#include "AWSCognitoIdentityGetPrincipalTagAttributeMapRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSCognitoIdentityGetPrincipalTagAttributeMapRequest {
GENERATED_BODY()

    /**
    *  <p>You can use this operation to get the ID of the Identity Pool you setup attribute mappings for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolId;

    /**
    *  <p>You can use this operation to get the provider name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityProviderName;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::GetPrincipalTagAttributeMapRequest toAWS() const {
        Aws::CognitoIdentity::Model::GetPrincipalTagAttributeMapRequest awsGetPrincipalTagAttributeMapRequest;

        if (!(this->identityPoolId.IsEmpty())) {
            awsGetPrincipalTagAttributeMapRequest.SetIdentityPoolId(TCHAR_TO_UTF8(*this->identityPoolId));
        }

        if (!(this->identityProviderName.IsEmpty())) {
            awsGetPrincipalTagAttributeMapRequest.SetIdentityProviderName(TCHAR_TO_UTF8(*this->identityProviderName));
        }

        return awsGetPrincipalTagAttributeMapRequest;
    }

    bool IsEmpty() const {
        return this->identityPoolId.IsEmpty() && this->identityProviderName.IsEmpty();
    }
#endif
};
