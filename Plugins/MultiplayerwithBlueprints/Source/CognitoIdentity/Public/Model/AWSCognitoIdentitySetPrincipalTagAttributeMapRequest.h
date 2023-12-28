/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/SetPrincipalTagAttributeMapRequest.h"

#endif

#include "AWSCognitoIdentitySetPrincipalTagAttributeMapRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSCognitoIdentitySetPrincipalTagAttributeMapRequest {
GENERATED_BODY()

    /**
    *  <p>The ID of the Identity Pool you want to set attribute mappings for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolId;

    /**
    *  <p>The provider name you want to use for attribute mappings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityProviderName;

    /**
    *  <p>You can use this operation to use default (username and clientID) attribute mappings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    bool useDefaults = false;

    /**
    *  <p>You can use this operation to add principal tags.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TMap<FString, FString> principalTags;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::SetPrincipalTagAttributeMapRequest toAWS() const {
        Aws::CognitoIdentity::Model::SetPrincipalTagAttributeMapRequest awsSetPrincipalTagAttributeMapRequest;

        if (!(this->identityPoolId.IsEmpty())) {
            awsSetPrincipalTagAttributeMapRequest.SetIdentityPoolId(TCHAR_TO_UTF8(*this->identityPoolId));
        }

        if (!(this->identityProviderName.IsEmpty())) {
            awsSetPrincipalTagAttributeMapRequest.SetIdentityProviderName(TCHAR_TO_UTF8(*this->identityProviderName));
        }

        if (!(false)) {
            awsSetPrincipalTagAttributeMapRequest.SetUseDefaults(this->useDefaults);
        }

        for (const TPair<FString, FString>& elem : this->principalTags) {
            awsSetPrincipalTagAttributeMapRequest.AddPrincipalTags(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }
        return awsSetPrincipalTagAttributeMapRequest;
    }

    bool IsEmpty() const {
        return this->identityPoolId.IsEmpty() && this->identityProviderName.IsEmpty() && false && this->principalTags.Num() == 0;
    }
#endif
};
