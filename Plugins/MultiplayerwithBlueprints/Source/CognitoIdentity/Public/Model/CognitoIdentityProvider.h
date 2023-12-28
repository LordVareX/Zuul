/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/CognitoIdentityProvider.h"

#endif


#include "CognitoIdentityProvider.generated.h"

USTRUCT(BlueprintType)
struct FCognitoIdentityProvider {
GENERATED_BODY()

    /**
    *  <p>The provider name for an Amazon Cognito user pool. For example, <code>cognito-idp.us-east-1.amazonaws.com/us-east-1_123456789</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString providerName;

    /**
    *  <p>The client ID for the Amazon Cognito user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString clientId;

    /**
    *  <p>TRUE if server-side token validation is enabled for the identity provider’s token.</p> <p>Once you set <code>ServerSideTokenCheck</code> to TRUE for an identity pool, that identity pool will check with the integrated user pools to make sure that the user has not been globally signed out or deleted before the identity pool provides an OIDC token or AWS credentials for the user.</p> <p>If the user is signed out or deleted, the identity pool will return a 400 Not Authorized error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    bool serverSideTokenCheck = false;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::CognitoIdentityProvider toAWS() const {
        Aws::CognitoIdentity::Model::CognitoIdentityProvider awsCognitoIdentityProvider;

        if (!(this->providerName.IsEmpty())) {
            awsCognitoIdentityProvider.SetProviderName(TCHAR_TO_UTF8(*this->providerName));
        }

        if (!(this->clientId.IsEmpty())) {
            awsCognitoIdentityProvider.SetClientId(TCHAR_TO_UTF8(*this->clientId));
        }

        if (!(false)) {
            awsCognitoIdentityProvider.SetServerSideTokenCheck(this->serverSideTokenCheck);
        }

        return awsCognitoIdentityProvider;
    }

    bool IsEmpty() const {
        return this->providerName.IsEmpty() && this->clientId.IsEmpty() && false;
    }

    FCognitoIdentityProvider &fromAWS(const Aws::CognitoIdentity::Model::CognitoIdentityProvider &awsCognitoIdentityProvider) {
        this->providerName = UTF8_TO_TCHAR(awsCognitoIdentityProvider.GetProviderName().c_str());

        this->clientId = UTF8_TO_TCHAR(awsCognitoIdentityProvider.GetClientId().c_str());

        this->serverSideTokenCheck = awsCognitoIdentityProvider.GetServerSideTokenCheck();

        return *this;
    }
#endif
};
