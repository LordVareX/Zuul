/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/InitiateAuthResult.h"

#endif

#include "Model/ChallengeNameType.h"
#include "Model/AuthenticationResultType.h"

#include "InitiateAuthResult.generated.h"

USTRUCT(BlueprintType)
struct FInitiateAuthResult {
GENERATED_BODY()

    /**
    *  <p>The name of the challenge which you are responding to with this call. This is returned to you in the <code>AdminInitiateAuth</code> response if you need to pass another challenge.</p> <p>Valid values include the following. Note that all of these challenges require <code>USERNAME</code> and <code>SECRET_HASH</code> (if applicable) in the parameters.</p> <ul> <li> <p> <code>SMS_MFA</code>: Next challenge is to supply an <code>SMS_MFA_CODE</code>, delivered via SMS.</p> </li> <li> <p> <code>PASSWORD_VERIFIER</code>: Next challenge is to supply <code>PASSWORD_CLAIM_SIGNATURE</code>, <code>PASSWORD_CLAIM_SECRET_BLOCK</code>, and <code>TIMESTAMP</code> after the client-side SRP calculations.</p> </li> <li> <p> <code>CUSTOM_CHALLENGE</code>: This is returned if your custom authentication flow determines that the user should pass another challenge before tokens are issued.</p> </li> <li> <p> <code>DEVICE_SRP_AUTH</code>: If device tracking was enabled on your user pool and the previous challenges were passed, this challenge is returned so that Amazon Cognito can start tracking this device.</p> </li> <li> <p> <code>DEVICE_PASSWORD_VERIFIER</code>: Similar to <code>PASSWORD_VERIFIER</code>, but for devices only.</p> </li> <li> <p> <code>NEW_PASSWORD_REQUIRED</code>: For users which are required to change their passwords after successful first login. This challenge should be passed with <code>NEW_PASSWORD</code> and any other required attributes.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EChallengeNameType challengeName = EChallengeNameType::NOT_SET;

    /**
    *  <p>The session which should be passed both ways in challenge-response calls to the service. If the or API call determines that the caller needs to go through another challenge, they return a session with other challenge parameters. This session should be passed as it is to the next <code>RespondToAuthChallenge</code> API call.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString session;

    /**
    *  <p>The challenge parameters. These are returned to you in the <code>InitiateAuth</code> response if you need to pass another challenge. The responses in this parameter should be used to compute inputs to the next call (<code>RespondToAuthChallenge</code>). </p> <p>All challenges require <code>USERNAME</code> and <code>SECRET_HASH</code> (if applicable).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> challengeParameters;

    /**
    *  <p>The result of the authentication response. This is only returned if the caller does not need to pass another challenge. If the caller does need to pass another challenge before it gets tokens, <code>ChallengeName</code>, <code>ChallengeParameters</code>, and <code>Session</code> are returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAuthenticationResultType authenticationResult;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FInitiateAuthResult &fromAWS(const Aws::CognitoIdentityProvider::Model::InitiateAuthResult &awsInitiateAuthResult) {
        switch(awsInitiateAuthResult.GetChallengeName()) {
            case Aws::CognitoIdentityProvider::Model::ChallengeNameType::NOT_SET:
                this->challengeName = EChallengeNameType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::ChallengeNameType::SMS_MFA:
                this->challengeName = EChallengeNameType::SMS_MFA;
                break;
            case Aws::CognitoIdentityProvider::Model::ChallengeNameType::SOFTWARE_TOKEN_MFA:
                this->challengeName = EChallengeNameType::SOFTWARE_TOKEN_MFA;
                break;
            case Aws::CognitoIdentityProvider::Model::ChallengeNameType::SELECT_MFA_TYPE:
                this->challengeName = EChallengeNameType::SELECT_MFA_TYPE;
                break;
            case Aws::CognitoIdentityProvider::Model::ChallengeNameType::MFA_SETUP:
                this->challengeName = EChallengeNameType::MFA_SETUP;
                break;
            case Aws::CognitoIdentityProvider::Model::ChallengeNameType::PASSWORD_VERIFIER:
                this->challengeName = EChallengeNameType::PASSWORD_VERIFIER;
                break;
            case Aws::CognitoIdentityProvider::Model::ChallengeNameType::CUSTOM_CHALLENGE:
                this->challengeName = EChallengeNameType::CUSTOM_CHALLENGE;
                break;
            case Aws::CognitoIdentityProvider::Model::ChallengeNameType::DEVICE_SRP_AUTH:
                this->challengeName = EChallengeNameType::DEVICE_SRP_AUTH;
                break;
            case Aws::CognitoIdentityProvider::Model::ChallengeNameType::DEVICE_PASSWORD_VERIFIER:
                this->challengeName = EChallengeNameType::DEVICE_PASSWORD_VERIFIER;
                break;
            case Aws::CognitoIdentityProvider::Model::ChallengeNameType::ADMIN_NO_SRP_AUTH:
                this->challengeName = EChallengeNameType::ADMIN_NO_SRP_AUTH;
                break;
            case Aws::CognitoIdentityProvider::Model::ChallengeNameType::NEW_PASSWORD_REQUIRED:
                this->challengeName = EChallengeNameType::NEW_PASSWORD_REQUIRED;
                break;
            default:
                this->challengeName = EChallengeNameType::NOT_SET;
                break;
        }

        this->session = UTF8_TO_TCHAR(awsInitiateAuthResult.GetSession().c_str());

        this->challengeParameters.Empty();
        for (const auto& elem : awsInitiateAuthResult.GetChallengeParameters()) {
            this->challengeParameters.Add(elem.first.c_str(), elem.second.c_str());
        }

        this->authenticationResult.fromAWS(awsInitiateAuthResult.GetAuthenticationResult());

        return *this;
    }
#endif
};
