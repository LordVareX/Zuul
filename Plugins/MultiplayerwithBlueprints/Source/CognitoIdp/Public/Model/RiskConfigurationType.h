/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/RiskConfigurationType.h"

#endif

#include "Model/CompromisedCredentialsRiskConfigurationType.h"
#include "Model/AccountTakeoverRiskConfigurationType.h"
#include "Model/RiskExceptionConfigurationType.h"

#include "RiskConfigurationType.generated.h"

USTRUCT(BlueprintType)
struct FRiskConfigurationType {
GENERATED_BODY()

    /**
    *  <p>The user pool ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The app client ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientId;

    /**
    *  <p>The compromised credentials risk configuration object including the <code>EventFilter</code> and the <code>EventAction</code> </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FCompromisedCredentialsRiskConfigurationType compromisedCredentialsRiskConfiguration;

    /**
    *  <p>The account takeover risk configuration object including the <code>NotifyConfiguration</code> object and <code>Actions</code> to take in the case of an account takeover.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAccountTakeoverRiskConfigurationType accountTakeoverRiskConfiguration;

    /**
    *  <p>The configuration to override the risk decision.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FRiskExceptionConfigurationType riskExceptionConfiguration;

    /**
    *  <p>The last modified date.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime lastModifiedDate;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FRiskConfigurationType &fromAWS(const Aws::CognitoIdentityProvider::Model::RiskConfigurationType &awsRiskConfigurationType) {
        this->userPoolId = UTF8_TO_TCHAR(awsRiskConfigurationType.GetUserPoolId().c_str());

        this->clientId = UTF8_TO_TCHAR(awsRiskConfigurationType.GetClientId().c_str());

        this->compromisedCredentialsRiskConfiguration.fromAWS(awsRiskConfigurationType.GetCompromisedCredentialsRiskConfiguration());

        this->accountTakeoverRiskConfiguration.fromAWS(awsRiskConfigurationType.GetAccountTakeoverRiskConfiguration());

        this->riskExceptionConfiguration.fromAWS(awsRiskConfigurationType.GetRiskExceptionConfiguration());

        this->lastModifiedDate = FDateTime(1970, 1, 1) + FTimespan(awsRiskConfigurationType.GetLastModifiedDate().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
