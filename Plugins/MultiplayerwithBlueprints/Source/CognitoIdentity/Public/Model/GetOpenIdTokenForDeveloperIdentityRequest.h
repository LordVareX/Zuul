/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/GetOpenIdTokenForDeveloperIdentityRequest.h"

#endif

#include "GetOpenIdTokenForDeveloperIdentityRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetOpenIdTokenForDeveloperIdentityRequest {
GENERATED_BODY()

    /**
    *  <p>An identity pool ID in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolId;

    /**
    *  <p>A unique identifier in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityId;

    /**
    *  <p>A set of optional name-value pairs that map provider names to provider tokens. Each name-value pair represents a user from a public provider or developer provider. If the user is from a developer provider, the name-value pair will follow the syntax <code>"developer_provider_name": "developer_user_identifier"</code>. The developer provider is the "domain" by which Cognito will refer to your users; you provided this domain while creating/updating the identity pool. The developer user identifier is an identifier from your backend that uniquely identifies a user. When you create an identity pool, you can specify the supported logins.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TMap<FString, FString> logins;

    /**
    *  <p>Use this operation to configure attribute mappings for custom providers. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TMap<FString, FString> principalTags;

    /**
    *  <p>The expiration time of the token, in seconds. You can specify a custom expiration time for the token so that you can cache it. If you don't provide an expiration time, the token is valid for 15 minutes. You can exchange the token with Amazon STS for temporary AWS credentials, which are valid for a maximum of one hour. The maximum token duration you can set is 24 hours. You should take care in setting the expiration time for a token, as there are significant security implications: an attacker could use a leaked token to access your AWS resources for the token's duration.</p>  <p>Please provide for a small grace period, usually no more than 5 minutes, to account for clock skew.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    int64 tokenDuration = 0;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::GetOpenIdTokenForDeveloperIdentityRequest toAWS() const {
        Aws::CognitoIdentity::Model::GetOpenIdTokenForDeveloperIdentityRequest awsGetOpenIdTokenForDeveloperIdentityRequest;

        if (!(this->identityPoolId.IsEmpty())) {
            awsGetOpenIdTokenForDeveloperIdentityRequest.SetIdentityPoolId(TCHAR_TO_UTF8(*this->identityPoolId));
        }

        if (!(this->identityId.IsEmpty())) {
            awsGetOpenIdTokenForDeveloperIdentityRequest.SetIdentityId(TCHAR_TO_UTF8(*this->identityId));
        }

        for (const TPair<FString, FString>& elem : this->logins) {
            awsGetOpenIdTokenForDeveloperIdentityRequest.AddLogins(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        for (const TPair<FString, FString>& elem : this->principalTags) {
            awsGetOpenIdTokenForDeveloperIdentityRequest.AddPrincipalTags(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        if (this->tokenDuration != 0) {
            awsGetOpenIdTokenForDeveloperIdentityRequest.SetTokenDuration(this->tokenDuration);
        }

        return awsGetOpenIdTokenForDeveloperIdentityRequest;
    }

    bool IsEmpty() const {
        return this->identityPoolId.IsEmpty() && this->identityId.IsEmpty() && this->logins.Num() == 0 && this->principalTags.Num() == 0 && this->tokenDuration == 0;
    }
#endif
};
