/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/GetCredentialsForIdentityRequest.h"

#endif

#include "GetCredentialsForIdentityRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetCredentialsForIdentityRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityId;

    /**
    *  <p>A set of optional name-value pairs that map provider names to provider tokens. The name-value pair will follow the syntax "provider_name": "provider_user_identifier".</p> <p>Logins should not be specified when trying to get credentials for an unauthenticated identity.</p> <p>The Logins parameter is required when using identities associated with external identity providers such as FaceBook. For examples of <code>Logins</code> maps, see the code examples in the <a href="http://docs.aws.amazon.com/cognito/latest/developerguide/external-identity-providers.html">External Identity Providers</a> section of the Amazon Cognito Developer Guide.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TMap<FString, FString> logins;

    /**
    *  <p>The Amazon Resource Name (ARN) of the role to be assumed when multiple roles were received in the token from the identity provider. For example, a SAML-based identity provider. This parameter is optional for identity providers that do not support role customization.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString customRoleArn;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::GetCredentialsForIdentityRequest toAWS() const {
        Aws::CognitoIdentity::Model::GetCredentialsForIdentityRequest awsGetCredentialsForIdentityRequest;

        if (!(this->identityId.IsEmpty())) {
            awsGetCredentialsForIdentityRequest.SetIdentityId(TCHAR_TO_UTF8(*this->identityId));
        }

        for (const TPair<FString, FString>& elem : this->logins) {
            awsGetCredentialsForIdentityRequest.AddLogins(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        if (!(this->customRoleArn.IsEmpty())) {
            awsGetCredentialsForIdentityRequest.SetCustomRoleArn(TCHAR_TO_UTF8(*this->customRoleArn));
        }

        return awsGetCredentialsForIdentityRequest;
    }

    bool IsEmpty() const {
        return this->identityId.IsEmpty() && this->logins.Num() == 0 && this->customRoleArn.IsEmpty();
    }
#endif
};
