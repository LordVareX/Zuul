/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SetRiskConfigurationRequest.h"

#endif

#include "Model/CompromisedCredentialsRiskConfigurationType.h"
#include "Model/AccountTakeoverRiskConfigurationType.h"
#include "Model/RiskExceptionConfigurationType.h"

#include "SetRiskConfigurationRequest.generated.h"

USTRUCT(BlueprintType)
struct FSetRiskConfigurationRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The app client ID. If <code>ClientId</code> is null, then the risk configuration is mapped to <code>userPoolId</code>. When the client ID is null, the same risk configuration is applied to all the clients in the userPool.</p> <p>Otherwise, <code>ClientId</code> is mapped to the client. When the client ID is not null, the user pool configuration is overridden and the risk configuration for the client is used instead.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientId;

    /**
    *  <p>The compromised credentials risk configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FCompromisedCredentialsRiskConfigurationType compromisedCredentialsRiskConfiguration;

    /**
    *  <p>The account takeover risk configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAccountTakeoverRiskConfigurationType accountTakeoverRiskConfiguration;

    /**
    *  <p>The configuration to override the risk decision.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FRiskExceptionConfigurationType riskExceptionConfiguration;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::SetRiskConfigurationRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::SetRiskConfigurationRequest awsSetRiskConfigurationRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsSetRiskConfigurationRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->clientId.IsEmpty())) {
            awsSetRiskConfigurationRequest.SetClientId(TCHAR_TO_UTF8(*this->clientId));
        }

        if (!(this->compromisedCredentialsRiskConfiguration.IsEmpty())) {
            awsSetRiskConfigurationRequest.SetCompromisedCredentialsRiskConfiguration(this->compromisedCredentialsRiskConfiguration.toAWS());
        }

        if (!(this->accountTakeoverRiskConfiguration.IsEmpty())) {
            awsSetRiskConfigurationRequest.SetAccountTakeoverRiskConfiguration(this->accountTakeoverRiskConfiguration.toAWS());
        }

        if (!(this->riskExceptionConfiguration.IsEmpty())) {
            awsSetRiskConfigurationRequest.SetRiskExceptionConfiguration(this->riskExceptionConfiguration.toAWS());
        }

        return awsSetRiskConfigurationRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->clientId.IsEmpty() && this->compromisedCredentialsRiskConfiguration.IsEmpty() && this->accountTakeoverRiskConfiguration.IsEmpty() && this->riskExceptionConfiguration.IsEmpty();
    }
#endif
};
