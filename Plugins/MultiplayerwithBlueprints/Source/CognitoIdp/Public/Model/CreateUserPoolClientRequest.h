/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CreateUserPoolClientRequest.h"

#endif

#include "Model/TokenValidityUnitsType.h"
#include "Model/ExplicitAuthFlowsType.h"
#include "Model/OAuthFlowType.h"
#include "Model/AnalyticsConfigurationType.h"
#include "Model/PreventUserExistenceErrorTypes.h"

#include "CreateUserPoolClientRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateUserPoolClientRequest {
    GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool where you want to create a user pool client.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The client name for the user pool client you would like to create.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientName;

    /**
    *  <p>Boolean to specify whether you want to generate a secret for the user pool client being created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool generateSecret = false;

    /**
    *  <p>The time limit, in days, after which the refresh token is no longer valid and cannot be used.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int refreshTokenValidity = 0;

    /**
    *  <p>The time limit, between 5 minutes and 1 day, after which the access token is no longer valid and cannot be used. This value will be overridden if you have entered a value in TokenValidityUnits.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int accessTokenValidity = 0;

    /**
    *  <p>The time limit, between 5 minutes and 1 day, after which the ID token is no longer valid and cannot be used. This value will be overridden if you have entered a value in TokenValidityUnits.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int idTokenValidity = 0;

    /**
    *  <p>The units in which the validity times are represented in. Default for RefreshToken is days, and default for ID and access tokens are hours.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FTokenValidityUnitsType tokenValidityUnits;

    /**
    *  <p>The read attributes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> readAttributes;

    /**
    *  <p>The user pool attributes that the app client can write to.</p> <p>If your app client allows users to sign in through an identity provider, this array must include all attributes that are mapped to identity provider attributes. Amazon Cognito updates mapped attributes when users sign in to your application through an identity provider. If your app client lacks write access to a mapped attribute, Amazon Cognito throws an error when it attempts to update the attribute. For more information, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/cognito-user-pools-specifying-attribute-mapping.html">Specifying Identity Provider Attribute Mappings for Your User Pool</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> writeAttributes;

    /**
    *  <p>The authentication flows that are supported by the user pool clients. Flow names without the <code>ALLOW_</code> prefix are deprecated in favor of new names with the <code>ALLOW_</code> prefix. Note that values with <code>ALLOW_</code> prefix cannot be used along with values without <code>ALLOW_</code> prefix.</p> <p>Valid values include:</p> <ul> <li> <p> <code>ALLOW_ADMIN_USER_PASSWORD_AUTH</code>: Enable admin based user password authentication flow <code>ADMIN_USER_PASSWORD_AUTH</code>. This setting replaces the <code>ADMIN_NO_SRP_AUTH</code> setting. With this authentication flow, Cognito receives the password in the request instead of using the SRP (Secure Remote Password protocol) protocol to verify passwords.</p> </li> <li> <p> <code>ALLOW_CUSTOM_AUTH</code>: Enable Lambda trigger based authentication.</p> </li> <li> <p> <code>ALLOW_USER_PASSWORD_AUTH</code>: Enable user password-based authentication. In this flow, Cognito receives the password in the request instead of using the SRP protocol to verify passwords.</p> </li> <li> <p> <code>ALLOW_USER_SRP_AUTH</code>: Enable SRP based authentication.</p> </li> <li> <p> <code>ALLOW_REFRESH_TOKEN_AUTH</code>: Enable authflow to refresh tokens.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<EExplicitAuthFlowsType> explicitAuthFlows;

    /**
    *  <p>A list of provider names for the identity providers that are supported on this client. The following are supported: <code>COGNITO</code>, <code>Facebook</code>, <code>Google</code> and <code>LoginWithAmazon</code>.</p>
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
    *  <p>The Amazon Pinpoint analytics configuration for collecting metrics for this user pool.</p>  <p>In regions where Pinpoint is not available, Cognito User Pools only supports sending events to Amazon Pinpoint projects in us-east-1. In regions where Pinpoint is available, Cognito User Pools will support sending events to Amazon Pinpoint projects within that same region. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAnalyticsConfigurationType analyticsConfiguration;

    /**
    *  <p>Use this setting to choose which errors and responses are returned by Cognito APIs during authentication, account confirmation, and password recovery when the user does not exist in the user pool. When set to <code>ENABLED</code> and the user does not exist, authentication returns an error indicating either the username or password was incorrect, and account confirmation and password recovery return a response indicating a code was sent to a simulated destination. When set to <code>LEGACY</code>, those APIs will return a <code>UserNotFoundException</code> exception if the user does not exist in the user pool.</p> <p>Valid values include:</p> <ul> <li> <p> <code>ENABLED</code> - This prevents user existence-related errors.</p> </li> <li> <p> <code>LEGACY</code> - This represents the old behavior of Cognito where user existence related errors are not prevented.</p> </li> </ul>  <p>After February 15th 2020, the value of <code>PreventUserExistenceErrors</code> will default to <code>ENABLED</code> for newly created user pool clients if no value is provided.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EAWSPreventUserExistenceErrorTypes preventUserExistenceErrors = EAWSPreventUserExistenceErrorTypes::NOT_SET;

    /**
    *  <p>Activates or deactivates token revocation. For more information about revoking tokens, see <a href="https://docs.aws.amazon.com/cognito-user-identity-pools/latest/APIReference/API_RevokeToken.html">RevokeToken</a>.</p> <p>If you don't include this parameter, token revocation is automatically activated for the new user pool client.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool enableTokenRevocation = false;

    /**
    *  <p>Activates the propagation of additional user context data. For more information about propagation of user context data, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/cognito-user-pool-settings-advanced-security.html"> Adding advanced security to a user pool</a>. If you don’t include this parameter, you can't send device fingerprint information, including source IP address, to Amazon Cognito advanced security. You can only activate <code>EnablePropagateAdditionalUserContextData</code> in an app client that has a client secret.</p>
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
    Aws::CognitoIdentityProvider::Model::CreateUserPoolClientRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::CreateUserPoolClientRequest awsCreateUserPoolClientRequest;

		if (!(this->userPoolId.IsEmpty())) {
            awsCreateUserPoolClientRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

		if (!(this->clientName.IsEmpty())) {
            awsCreateUserPoolClientRequest.SetClientName(TCHAR_TO_UTF8(*this->clientName));
        }

        if (!(false)) {
            awsCreateUserPoolClientRequest.SetGenerateSecret(this->generateSecret);
        }

        if (!(this->refreshTokenValidity == 0)) {
            awsCreateUserPoolClientRequest.SetRefreshTokenValidity(this->refreshTokenValidity);
        }

        if (!(this->accessTokenValidity == 0)) {
            awsCreateUserPoolClientRequest.SetAccessTokenValidity(this->accessTokenValidity);
        }

        if (!(this->idTokenValidity == 0)) {
            awsCreateUserPoolClientRequest.SetIdTokenValidity(this->idTokenValidity);
        }

        if (!(this->tokenValidityUnits.IsEmpty())) {
            awsCreateUserPoolClientRequest.SetTokenValidityUnits(this->tokenValidityUnits.toAWS());
        }

        for (const FString& elem : this->readAttributes) {
            awsCreateUserPoolClientRequest.AddReadAttributes(TCHAR_TO_UTF8(*elem));
        }

        for (const FString& elem : this->writeAttributes) {
            awsCreateUserPoolClientRequest.AddWriteAttributes(TCHAR_TO_UTF8(*elem));
        }

        for (const EExplicitAuthFlowsType& elem : this->explicitAuthFlows) {
		    switch(elem) {
                case EExplicitAuthFlowsType::ADMIN_NO_SRP_AUTH:
                        awsCreateUserPoolClientRequest.AddExplicitAuthFlows(Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::ADMIN_NO_SRP_AUTH);
                        break;
                case EExplicitAuthFlowsType::CUSTOM_AUTH_FLOW_ONLY:
                        awsCreateUserPoolClientRequest.AddExplicitAuthFlows(Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::CUSTOM_AUTH_FLOW_ONLY);
                        break;
                case EExplicitAuthFlowsType::USER_PASSWORD_AUTH:
                        awsCreateUserPoolClientRequest.AddExplicitAuthFlows(Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::USER_PASSWORD_AUTH);
                        break;
                case EExplicitAuthFlowsType::ALLOW_ADMIN_USER_PASSWORD_AUTH:
                        awsCreateUserPoolClientRequest.AddExplicitAuthFlows(Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::ALLOW_ADMIN_USER_PASSWORD_AUTH);
                        break;
                case EExplicitAuthFlowsType::ALLOW_CUSTOM_AUTH:
                        awsCreateUserPoolClientRequest.AddExplicitAuthFlows(Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::ALLOW_CUSTOM_AUTH);
                        break;
                case EExplicitAuthFlowsType::ALLOW_USER_PASSWORD_AUTH:
                        awsCreateUserPoolClientRequest.AddExplicitAuthFlows(Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::ALLOW_USER_PASSWORD_AUTH);
                        break;
                case EExplicitAuthFlowsType::ALLOW_USER_SRP_AUTH:
                        awsCreateUserPoolClientRequest.AddExplicitAuthFlows(Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::ALLOW_USER_SRP_AUTH);
                        break;
                case EExplicitAuthFlowsType::ALLOW_REFRESH_TOKEN_AUTH:
                        awsCreateUserPoolClientRequest.AddExplicitAuthFlows(Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::ALLOW_REFRESH_TOKEN_AUTH);
                        break;
                default:
                    break;
            };
        }

        for (const FString& elem : this->supportedIdentityProviders) {
            awsCreateUserPoolClientRequest.AddSupportedIdentityProviders(TCHAR_TO_UTF8(*elem));
        }

        for (const FString& elem : this->callbackURLs) {
            awsCreateUserPoolClientRequest.AddCallbackURLs(TCHAR_TO_UTF8(*elem));
        }

        for (const FString& elem : this->logoutURLs) {
            awsCreateUserPoolClientRequest.AddLogoutURLs(TCHAR_TO_UTF8(*elem));
        }

		if (!(this->defaultRedirectURI.IsEmpty())) {
            awsCreateUserPoolClientRequest.SetDefaultRedirectURI(TCHAR_TO_UTF8(*this->defaultRedirectURI));
        }

        for (const EOAuthFlowType& elem : this->allowedOAuthFlows) {
		    switch(elem) {
                case EOAuthFlowType::code:
                        awsCreateUserPoolClientRequest.AddAllowedOAuthFlows(Aws::CognitoIdentityProvider::Model::OAuthFlowType::code);
                        break;
                case EOAuthFlowType::implicit:
                        awsCreateUserPoolClientRequest.AddAllowedOAuthFlows(Aws::CognitoIdentityProvider::Model::OAuthFlowType::implicit);
                        break;
                case EOAuthFlowType::client_credentials:
                        awsCreateUserPoolClientRequest.AddAllowedOAuthFlows(Aws::CognitoIdentityProvider::Model::OAuthFlowType::client_credentials);
                        break;
                default:
                    break;
            };
        }

        for (const FString& elem : this->allowedOAuthScopes) {
            awsCreateUserPoolClientRequest.AddAllowedOAuthScopes(TCHAR_TO_UTF8(*elem));
        }

        if (!(false)) {
            awsCreateUserPoolClientRequest.SetAllowedOAuthFlowsUserPoolClient(this->allowedOAuthFlowsUserPoolClient);
        }

        if (!(this->analyticsConfiguration.IsEmpty())) {
            awsCreateUserPoolClientRequest.SetAnalyticsConfiguration(this->analyticsConfiguration.toAWS());
        }

        switch(this->preventUserExistenceErrors) {
            case EAWSPreventUserExistenceErrorTypes::LEGACY:
                awsCreateUserPoolClientRequest.SetPreventUserExistenceErrors(Aws::CognitoIdentityProvider::Model::PreventUserExistenceErrorTypes::LEGACY);
                break;
            case EAWSPreventUserExistenceErrorTypes::ENABLED:
                awsCreateUserPoolClientRequest.SetPreventUserExistenceErrors(Aws::CognitoIdentityProvider::Model::PreventUserExistenceErrorTypes::ENABLED);
                break;
            default:
                break;
        }

        awsCreateUserPoolClientRequest.SetEnableTokenRevocation(this->enableTokenRevocation);

        awsCreateUserPoolClientRequest.SetEnablePropagateAdditionalUserContextData(this->enablePropagateAdditionalUserContextData);

        if (!(this->authSessionValidity == 0)) {
            awsCreateUserPoolClientRequest.SetAuthSessionValidity(this->authSessionValidity);
        }

        return awsCreateUserPoolClientRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->clientName.IsEmpty() && false && this->refreshTokenValidity == 0 && this->accessTokenValidity == 0 && this->idTokenValidity == 0 && this->tokenValidityUnits.IsEmpty() && this->readAttributes.Num() == 0 && this->writeAttributes.Num() == 0 && this->explicitAuthFlows.Num() == 0 && this->supportedIdentityProviders.Num() == 0 && this->callbackURLs.Num() == 0 && this->logoutURLs.Num() == 0 && this->defaultRedirectURI.IsEmpty() && this->allowedOAuthFlows.Num() == 0 && this->allowedOAuthScopes.Num() == 0 && false && this->analyticsConfiguration.IsEmpty() && preventUserExistenceErrors == EAWSPreventUserExistenceErrorTypes::NOT_SET && false && false && this->authSessionValidity == 0;
    }
#endif
};
