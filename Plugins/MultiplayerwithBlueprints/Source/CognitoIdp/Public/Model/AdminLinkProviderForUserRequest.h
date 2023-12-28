/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminLinkProviderForUserRequest.h"

#endif

#include "Model/ProviderUserIdentifierType.h"
#include "Model/ProviderUserIdentifierType.h"

#include "AdminLinkProviderForUserRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminLinkProviderForUserRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The existing user in the user pool to be linked to the external identity provider user account. Can be a native (Username + Password) Cognito User Pools user or a federated user (for example, a SAML or Facebook user). If the user doesn't exist, an exception is thrown. This is the user that is returned when the new user (with the linked identity provider attribute) signs in.</p> <p>For a native username + password user, the <code>ProviderAttributeValue</code> for the <code>DestinationUser</code> should be the username in the user pool. For a federated user, it should be the provider-specific <code>user_id</code>.</p> <p>The <code>ProviderAttributeName</code> of the <code>DestinationUser</code> is ignored.</p> <p>The <code>ProviderName</code> should be set to <code>Cognito</code> for users in Cognito user pools.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FProviderUserIdentifierType destinationUser;

    /**
    *  <p>An external identity provider account for a user who does not currently exist yet in the user pool. This user must be a federated user (for example, a SAML or Facebook user), not another native user.</p> <p>If the <code>SourceUser</code> is a federated social identity provider user (Facebook, Google, or Login with Amazon), you must set the <code>ProviderAttributeName</code> to <code>Cognito_Subject</code>. For social identity providers, the <code>ProviderName</code> will be <code>Facebook</code>, <code>Google</code>, or <code>LoginWithAmazon</code>, and Cognito will automatically parse the Facebook, Google, and Login with Amazon tokens for <code>id</code>, <code>sub</code>, and <code>user_id</code>, respectively. The <code>ProviderAttributeValue</code> for the user must be the same value as the <code>id</code>, <code>sub</code>, or <code>user_id</code> value found in the social identity provider token.</p> <p/> <p>For SAML, the <code>ProviderAttributeName</code> can be any value that matches a claim in the SAML assertion. If you wish to link SAML users based on the subject of the SAML assertion, you should map the subject to a claim through the SAML identity provider and submit that claim name as the <code>ProviderAttributeName</code>. If you set <code>ProviderAttributeName</code> to <code>Cognito_Subject</code>, Cognito will automatically parse the default unique identifier found in the subject from the SAML token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FProviderUserIdentifierType sourceUser;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminLinkProviderForUserRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminLinkProviderForUserRequest awsAdminLinkProviderForUserRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminLinkProviderForUserRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->destinationUser.IsEmpty())) {
            awsAdminLinkProviderForUserRequest.SetDestinationUser(this->destinationUser.toAWS());
        }

        if (!(this->sourceUser.IsEmpty())) {
            awsAdminLinkProviderForUserRequest.SetSourceUser(this->sourceUser.toAWS());
        }

        return awsAdminLinkProviderForUserRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->destinationUser.IsEmpty() && this->sourceUser.IsEmpty();
    }
#endif
};
