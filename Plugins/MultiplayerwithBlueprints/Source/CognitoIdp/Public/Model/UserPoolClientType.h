/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UserPoolClientType.h"

#endif

#include "Model/TokenValidityUnitsType.h"
#include "Model/ExplicitAuthFlowsType.h"
#include "Model/OAuthFlowType.h"
#include "Model/AnalyticsConfigurationType.h"
#include "Model/PreventUserExistenceErrorTypes.h"

#include "UserPoolClientType.generated.h"

USTRUCT(BlueprintType)
struct FUserPoolClientType {
    GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool client.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The client name from the user pool request of the client type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientName;

    /**
    *  <p>The ID of the client associated with the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientId;

    /**
    *  <p>The client secret from the user pool request of the client type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientSecret;

    /**
    *  <p>The date the user pool client was last modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime lastModifiedDate;

    /**
    *  <p>The date the user pool client was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime creationDate;

    /**
    *  <p>The time limit, in days, after which the refresh token is no longer valid and cannot be used.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int refreshTokenValidity = 0;

    /**
    *  <p>The time limit, specified by tokenValidityUnits, defaulting to hours, after which the access token is no longer valid and cannot be used.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int accessTokenValidity = 0;

    /**
    *  <p>The time limit, specified by tokenValidityUnits, defaulting to hours, after which the refresh token is no longer valid and cannot be used.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int idTokenValidity = 0;

    /**
    *  <p>The time units used to specify the token validity times of their respective token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FTokenValidityUnitsType tokenValidityUnits;

    /**
    *  <p>The Read-only attributes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> readAttributes;

    /**
    *  <p>The writeable attributes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> writeAttributes;

    /**
    *  <p>The authentication flows that are supported by the user pool clients. Flow names without the <code>ALLOW_</code> prefix are deprecated in favor of new names with the <code>ALLOW_</code> prefix. Note that values with <code>ALLOW_</code> prefix cannot be used along with values without <code>ALLOW_</code> prefix.</p> <p>Valid values include:</p> <ul> <li> <p> <code>ALLOW_ADMIN_USER_PASSWORD_AUTH</code>: Enable admin based user password authentication flow <code>ADMIN_USER_PASSWORD_AUTH</code>. This setting replaces the <code>ADMIN_NO_SRP_AUTH</code> setting. With this authentication flow, Cognito receives the password in the request instead of using the SRP (Secure Remote Password protocol) protocol to verify passwords.</p> </li> <li> <p> <code>ALLOW_CUSTOM_AUTH</code>: Enable Lambda trigger based authentication.</p> </li> <li> <p> <code>ALLOW_USER_PASSWORD_AUTH</code>: Enable user password-based authentication. In this flow, Cognito receives the password in the request instead of using the SRP protocol to verify passwords.</p> </li> <li> <p> <code>ALLOW_USER_SRP_AUTH</code>: Enable SRP based authentication.</p> </li> <li> <p> <code>ALLOW_REFRESH_TOKEN_AUTH</code>: Enable authflow to refresh tokens.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<EExplicitAuthFlowsType> explicitAuthFlows;

    /**
    *  <p>A list of provider names for the identity providers that are supported on this client.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> supportedIdentityProviders;

    /**
    *  <p>A list of allowed redirect (callback) URLs for the identity providers.</p> <p>A redirect URI must:</p> <ul> <li> <p>Be an absolute URI.</p> </li> <li> <p>Be registered with the authorization server.</p> </li> <li> <p>Not include a fragment component.</p> </li> </ul> <p>See <a href="https://tools.ietf.org/html/rfc6749#section-3.1.2">OAuth 2.0 - Redirection Endpoint</a>.</p> <p>Amazon Cognito requires HTTPS over HTTP except for http://localhost for testing purposes only.</p> <p>App callback URLs such as myapp://example are also supported.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> callbackURLs;

    /**
    *  <p>A list of allowed logout URLs for the identity providers.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> logoutURLs;

    /**
    *  <p>The default redirect URI. Must be in the <code>CallbackURLs</code> list.</p> <p>A redirect URI must:</p> <ul> <li> <p>Be an absolute URI.</p> </li> <li> <p>Be registered with the authorization server.</p> </li> <li> <p>Not include a fragment component.</p> </li> </ul> <p>See <a href="https://tools.ietf.org/html/rfc6749#section-3.1.2">OAuth 2.0 - Redirection Endpoint</a>.</p> <p>Amazon Cognito requires HTTPS over HTTP except for http://localhost for testing purposes only.</p> <p>App callback URLs such as myapp://example are also supported.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString defaultRedirectURI;

    /**
    *  <p>The allowed OAuth flows.</p> <p>Set to <code>code</code> to initiate a code grant flow, which provides an authorization code as the response. This code can be exchanged for access tokens with the token endpoint.</p> <p>Set to <code>implicit</code> to specify that the client should get the access token (and, optionally, ID token, based on scopes) directly.</p> <p>Set to <code>client_credentials</code> to specify that the client should get the access token (and, optionally, ID token, based on scopes) from the token endpoint using a combination of client and client_secret.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<EOAuthFlowType> allowedOAuthFlows;

    /**
    *  <p>The allowed OAuth scopes. Possible values provided by OAuth are: <code>phone</code>, <code>email</code>, <code>openid</code>, and <code>profile</code>. Possible values provided by AWS are: <code>aws.cognito.signin.user.admin</code>. Custom scopes created in Resource Servers are also supported.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> allowedOAuthScopes;

    /**
    *  <p>Set to true if the client is allowed to follow the OAuth protocol when interacting with Cognito user pools.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool allowedOAuthFlowsUserPoolClient = false;

    /**
    *  <p>The Amazon Pinpoint analytics configuration for the user pool client.</p>  <p>Cognito User Pools only supports sending events to Amazon Pinpoint projects in the US East (N. Virginia) us-east-1 Region, regardless of the region in which the user pool resides.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAnalyticsConfigurationType analyticsConfiguration;

    /**
    *  <p>Use this setting to choose which errors and responses are returned by Cognito APIs during authentication, account confirmation, and password recovery when the user does not exist in the user pool. When set to <code>ENABLED</code> and the user does not exist, authentication returns an error indicating either the username or password was incorrect, and account confirmation and password recovery return a response indicating a code was sent to a simulated destination. When set to <code>LEGACY</code>, those APIs will return a <code>UserNotFoundException</code> exception if the user does not exist in the user pool.</p> <p>Valid values include:</p> <ul> <li> <p> <code>ENABLED</code> - This prevents user existence-related errors.</p> </li> <li> <p> <code>LEGACY</code> - This represents the old behavior of Cognito where user existence related errors are not prevented.</p> </li> </ul>  <p>After February 15th 2020, the value of <code>PreventUserExistenceErrors</code> will default to <code>ENABLED</code> for newly created user pool clients if no value is provided.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EAWSPreventUserExistenceErrorTypes preventUserExistenceErrors = EAWSPreventUserExistenceErrorTypes::NOT_SET;

    /**
    *  <p>Indicates whether token revocation is activated for the user pool client. When you create a new user pool client, token revocation is activated by default. For more information about revoking tokens, see <a href="https://docs.aws.amazon.com/cognito-user-identity-pools/latest/APIReference/API_RevokeToken.html">RevokeToken</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool enableTokenRevocation = false;

    /**
    *  <p>When <code>EnablePropagateAdditionalUserContextData</code> is true, Amazon Cognito accepts an <code>IpAddress</code> value that you send in the <code>UserContextData</code> parameter. The <code>UserContextData</code> parameter sends information to Amazon Cognito advanced security for risk analysis. You can send <code>UserContextData</code> when you sign in Amazon Cognito native users with the <code>InitiateAuth</code> and <code>RespondToAuthChallenge</code> API operations.</p> <p>When <code>EnablePropagateAdditionalUserContextData</code> is false, you can't send your user's source IP address to Amazon Cognito advanced security with unauthenticated API operations. <code>EnablePropagateAdditionalUserContextData</code> doesn't affect whether you can send a source IP address in a <code>ContextData</code> parameter with the authenticated API operations <code>AdminInitiateAuth</code> and <code>AdminRespondToAuthChallenge</code>.</p> <p>You can only activate <code>EnablePropagateAdditionalUserContextData</code> in an app client that has a client secret. For more information about propagation of user context data, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/cognito-user-pool-settings-adaptive-authentication.html#user-pool-settings-adaptive-authentication-device-fingerprint">Adding user device and session data to API requests</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool enablePropagateAdditionalUserContextData = false;

    /**
    *  <p>Amazon Cognito creates a session token for each API request in an authentication flow. <code>AuthSessionValidity</code> is the duration, in minutes, of that session token. Your user pool native user must respond to each authentication challenge before the session expires.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int authSessionValidity = 0;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    public:
    FUserPoolClientType &fromAWS(const Aws::CognitoIdentityProvider::Model::UserPoolClientType &awsUserPoolClientType) {
        this->userPoolId = UTF8_TO_TCHAR(awsUserPoolClientType.GetUserPoolId().c_str());

        this->clientName = UTF8_TO_TCHAR(awsUserPoolClientType.GetClientName().c_str());

        this->clientId = UTF8_TO_TCHAR(awsUserPoolClientType.GetClientId().c_str());

        this->clientSecret = UTF8_TO_TCHAR(awsUserPoolClientType.GetClientSecret().c_str());

        this->lastModifiedDate = FDateTime(1970, 1, 1) + FTimespan(awsUserPoolClientType.GetLastModifiedDate().Millis() * ETimespan::TicksPerMillisecond);

        this->creationDate = FDateTime(1970, 1, 1) + FTimespan(awsUserPoolClientType.GetCreationDate().Millis() * ETimespan::TicksPerMillisecond);

		this->refreshTokenValidity = awsUserPoolClientType.GetRefreshTokenValidity();

		this->accessTokenValidity = awsUserPoolClientType.GetAccessTokenValidity();

		this->idTokenValidity = awsUserPoolClientType.GetIdTokenValidity();

        this->tokenValidityUnits.fromAWS(awsUserPoolClientType.GetTokenValidityUnits());

        this->readAttributes.Empty();
        for (const Aws::String& elem : awsUserPoolClientType.GetReadAttributes()) {
            this->readAttributes.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->writeAttributes.Empty();
        for (const Aws::String& elem : awsUserPoolClientType.GetWriteAttributes()) {
            this->writeAttributes.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->explicitAuthFlows.Empty();
        for (const Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType& elem : awsUserPoolClientType.GetExplicitAuthFlows()) {
            switch(elem) {
                case Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::NOT_SET:
                    this->explicitAuthFlows.Add(EExplicitAuthFlowsType::NOT_SET);
                    break;
                case Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::ADMIN_NO_SRP_AUTH:
                    this->explicitAuthFlows.Add(EExplicitAuthFlowsType::ADMIN_NO_SRP_AUTH);
                    break;
                case Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::CUSTOM_AUTH_FLOW_ONLY:
                    this->explicitAuthFlows.Add(EExplicitAuthFlowsType::CUSTOM_AUTH_FLOW_ONLY);
                    break;
                case Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::USER_PASSWORD_AUTH:
                    this->explicitAuthFlows.Add(EExplicitAuthFlowsType::USER_PASSWORD_AUTH);
                    break;
                case Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::ALLOW_ADMIN_USER_PASSWORD_AUTH:
                    this->explicitAuthFlows.Add(EExplicitAuthFlowsType::ALLOW_ADMIN_USER_PASSWORD_AUTH);
                    break;
                case Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::ALLOW_CUSTOM_AUTH:
                    this->explicitAuthFlows.Add(EExplicitAuthFlowsType::ALLOW_CUSTOM_AUTH);
                    break;
                case Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::ALLOW_USER_PASSWORD_AUTH:
                    this->explicitAuthFlows.Add(EExplicitAuthFlowsType::ALLOW_USER_PASSWORD_AUTH);
                    break;
                case Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::ALLOW_USER_SRP_AUTH:
                    this->explicitAuthFlows.Add(EExplicitAuthFlowsType::ALLOW_USER_SRP_AUTH);
                    break;
                case Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::ALLOW_REFRESH_TOKEN_AUTH:
                    this->explicitAuthFlows.Add(EExplicitAuthFlowsType::ALLOW_REFRESH_TOKEN_AUTH);
                    break;
                default:
                    this->explicitAuthFlows.Add(EExplicitAuthFlowsType::NOT_SET);
                    break;
		    };
        }

        this->supportedIdentityProviders.Empty();
        for (const Aws::String& elem : awsUserPoolClientType.GetSupportedIdentityProviders()) {
            this->supportedIdentityProviders.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->callbackURLs.Empty();
        for (const Aws::String& elem : awsUserPoolClientType.GetCallbackURLs()) {
            this->callbackURLs.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->logoutURLs.Empty();
        for (const Aws::String& elem : awsUserPoolClientType.GetLogoutURLs()) {
            this->logoutURLs.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->defaultRedirectURI = UTF8_TO_TCHAR(awsUserPoolClientType.GetDefaultRedirectURI().c_str());

        this->allowedOAuthFlows.Empty();
        for (const Aws::CognitoIdentityProvider::Model::OAuthFlowType& elem : awsUserPoolClientType.GetAllowedOAuthFlows()) {
            switch(elem) {
                case Aws::CognitoIdentityProvider::Model::OAuthFlowType::NOT_SET:
                    this->allowedOAuthFlows.Add(EOAuthFlowType::NOT_SET);
                    break;
                case Aws::CognitoIdentityProvider::Model::OAuthFlowType::code:
                    this->allowedOAuthFlows.Add(EOAuthFlowType::code);
                    break;
                case Aws::CognitoIdentityProvider::Model::OAuthFlowType::implicit:
                    this->allowedOAuthFlows.Add(EOAuthFlowType::implicit);
                    break;
                case Aws::CognitoIdentityProvider::Model::OAuthFlowType::client_credentials:
                    this->allowedOAuthFlows.Add(EOAuthFlowType::client_credentials);
                    break;
                default:
                    this->allowedOAuthFlows.Add(EOAuthFlowType::NOT_SET);
                    break;
		    };
        }

        this->allowedOAuthScopes.Empty();
        for (const Aws::String& elem : awsUserPoolClientType.GetAllowedOAuthScopes()) {
            this->allowedOAuthScopes.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->allowedOAuthFlowsUserPoolClient = awsUserPoolClientType.GetAllowedOAuthFlowsUserPoolClient();

        this->analyticsConfiguration.fromAWS(awsUserPoolClientType.GetAnalyticsConfiguration());

        switch(awsUserPoolClientType.GetPreventUserExistenceErrors()) {
            case Aws::CognitoIdentityProvider::Model::PreventUserExistenceErrorTypes::NOT_SET:
                this->preventUserExistenceErrors = EAWSPreventUserExistenceErrorTypes::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::PreventUserExistenceErrorTypes::LEGACY:
                this->preventUserExistenceErrors = EAWSPreventUserExistenceErrorTypes::LEGACY;
                break;
            case Aws::CognitoIdentityProvider::Model::PreventUserExistenceErrorTypes::ENABLED:
                this->preventUserExistenceErrors = EAWSPreventUserExistenceErrorTypes::ENABLED;
                break;
            default:
                this->preventUserExistenceErrors = EAWSPreventUserExistenceErrorTypes::NOT_SET;
                break;
        }

        this->enableTokenRevocation = awsUserPoolClientType.GetEnableTokenRevocation();

        this->enablePropagateAdditionalUserContextData = awsUserPoolClientType.GetEnablePropagateAdditionalUserContextData();

		this->authSessionValidity = awsUserPoolClientType.GetAuthSessionValidity();

        return *this;
    }
#endif
};
