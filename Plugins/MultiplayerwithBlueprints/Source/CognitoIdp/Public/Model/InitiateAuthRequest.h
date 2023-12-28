/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/InitiateAuthRequest.h"

#endif

#include "Model/AuthFlowType.h"
#include "Model/AnalyticsMetadataType.h"
#include "Model/UserContextDataType.h"

#include "InitiateAuthRequest.generated.h"

USTRUCT(BlueprintType)
struct FInitiateAuthRequest {
GENERATED_BODY()

    /**
    *  <p>The authentication flow for this call to execute. The API action will depend on this value. For example: </p> <ul> <li> <p> <code>REFRESH_TOKEN_AUTH</code> will take in a valid refresh token and return new tokens.</p> </li> <li> <p> <code>USER_SRP_AUTH</code> will take in <code>USERNAME</code> and <code>SRP_A</code> and return the SRP variables to be used for next challenge execution.</p> </li> <li> <p> <code>USER_PASSWORD_AUTH</code> will take in <code>USERNAME</code> and <code>PASSWORD</code> and return the next challenge or tokens.</p> </li> </ul> <p>Valid values include:</p> <ul> <li> <p> <code>USER_SRP_AUTH</code>: Authentication flow for the Secure Remote Password (SRP) protocol.</p> </li> <li> <p> <code>REFRESH_TOKEN_AUTH</code>/<code>REFRESH_TOKEN</code>: Authentication flow for refreshing the access token and ID token by supplying a valid refresh token.</p> </li> <li> <p> <code>CUSTOM_AUTH</code>: Custom authentication flow.</p> </li> <li> <p> <code>USER_PASSWORD_AUTH</code>: Non-SRP authentication flow; USERNAME and PASSWORD are passed directly. If a user migration Lambda trigger is set, this flow will invoke the user migration Lambda if the USERNAME is not found in the user pool. </p> </li> </ul> <p> <code>ADMIN_NO_SRP_AUTH</code> is not a valid value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EAuthFlowType authFlow = EAuthFlowType::NOT_SET;

    /**
    *  <p>The authentication parameters. These are inputs corresponding to the <code>AuthFlow</code> that you are invoking. The required values depend on the value of <code>AuthFlow</code>:</p> <ul> <li> <p>For <code>USER_SRP_AUTH</code>: <code>USERNAME</code> (required), <code>SRP_A</code> (required), <code>SECRET_HASH</code> (required if the app client is configured with a client secret), <code>DEVICE_KEY</code> </p> </li> <li> <p>For <code>REFRESH_TOKEN_AUTH/REFRESH_TOKEN</code>: <code>REFRESH_TOKEN</code> (required), <code>SECRET_HASH</code> (required if the app client is configured with a client secret), <code>DEVICE_KEY</code> </p> </li> <li> <p>For <code>CUSTOM_AUTH</code>: <code>USERNAME</code> (required), <code>SECRET_HASH</code> (if app client is configured with client secret), <code>DEVICE_KEY</code> </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> authParameters;

    /**
    *  <p>This is a random key-value pair map which can contain any key and will be passed to your PreAuthentication Lambda trigger as-is. It can be used to implement additional validations around authentication.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> clientMetadata;

    /**
    *  <p>The app client ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientId;

    /**
    *  <p>The Amazon Pinpoint analytics metadata for collecting metrics for <code>InitiateAuth</code> calls.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAnalyticsMetadataType analyticsMetadata;

    /**
    *  <p>Contextual data such as the user's device fingerprint, IP address, or location used for evaluating the risk of an unexpected event by Amazon Cognito advanced security.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserContextDataType userContextData;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::InitiateAuthRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::InitiateAuthRequest awsInitiateAuthRequest;

        switch(this->authFlow) {
            case EAuthFlowType::USER_SRP_AUTH:
                awsInitiateAuthRequest.SetAuthFlow(Aws::CognitoIdentityProvider::Model::AuthFlowType::USER_SRP_AUTH);
                break;
            case EAuthFlowType::REFRESH_TOKEN_AUTH:
                awsInitiateAuthRequest.SetAuthFlow(Aws::CognitoIdentityProvider::Model::AuthFlowType::REFRESH_TOKEN_AUTH);
                break;
            case EAuthFlowType::REFRESH_TOKEN:
                awsInitiateAuthRequest.SetAuthFlow(Aws::CognitoIdentityProvider::Model::AuthFlowType::REFRESH_TOKEN);
                break;
            case EAuthFlowType::CUSTOM_AUTH:
                awsInitiateAuthRequest.SetAuthFlow(Aws::CognitoIdentityProvider::Model::AuthFlowType::CUSTOM_AUTH);
                break;
            case EAuthFlowType::ADMIN_NO_SRP_AUTH:
                awsInitiateAuthRequest.SetAuthFlow(Aws::CognitoIdentityProvider::Model::AuthFlowType::ADMIN_NO_SRP_AUTH);
                break;
            case EAuthFlowType::USER_PASSWORD_AUTH:
                awsInitiateAuthRequest.SetAuthFlow(Aws::CognitoIdentityProvider::Model::AuthFlowType::USER_PASSWORD_AUTH);
                break;
            case EAuthFlowType::ADMIN_USER_PASSWORD_AUTH:
                awsInitiateAuthRequest.SetAuthFlow(Aws::CognitoIdentityProvider::Model::AuthFlowType::ADMIN_USER_PASSWORD_AUTH);
                break;
            default:
                break;
        }

        for (const TPair<FString, FString>& elem : this->authParameters) {
            awsInitiateAuthRequest.AddAuthParameters(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        for (const TPair<FString, FString>& elem : this->clientMetadata) {
            awsInitiateAuthRequest.AddClientMetadata(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        if (!(this->clientId.IsEmpty())) {
            awsInitiateAuthRequest.SetClientId(TCHAR_TO_UTF8(*this->clientId));
        }

        if (!(this->analyticsMetadata.IsEmpty())) {
            awsInitiateAuthRequest.SetAnalyticsMetadata(this->analyticsMetadata.toAWS());
        }

        if (!(this->userContextData.IsEmpty())) {
            awsInitiateAuthRequest.SetUserContextData(this->userContextData.toAWS());
        }

        return awsInitiateAuthRequest;
    }

    bool IsEmpty() const {
        return this->authFlow == EAuthFlowType::NOT_SET && this->authParameters.Num() == 0 && this->clientMetadata.Num() == 0 && this->clientId.IsEmpty() && this->analyticsMetadata.IsEmpty() && this->userContextData.IsEmpty();
    }
#endif
};
