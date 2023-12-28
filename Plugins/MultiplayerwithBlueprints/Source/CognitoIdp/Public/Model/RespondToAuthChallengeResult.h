/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/RespondToAuthChallengeResult.h"

#endif

#include "Model/ChallengeNameType.h"
#include "Model/AuthenticationResultType.h"

#include "RespondToAuthChallengeResult.generated.h"

USTRUCT(BlueprintType)
struct FRespondToAuthChallengeResult {
GENERATED_BODY()

    /**
    *  <p>The challenge name. For more information, see .</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EChallengeNameType challengeName = EChallengeNameType::NOT_SET;

    /**
    *  <p>The session which should be passed both ways in challenge-response calls to the service. If the or API call determines that the caller needs to go through another challenge, they return a session with other challenge parameters. This session should be passed as it is to the next <code>RespondToAuthChallenge</code> API call.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString session;

    /**
    *  <p>The challenge parameters. For more information, see .</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> challengeParameters;

    /**
    *  <p>The result returned by the server in response to the request to respond to the authentication challenge.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAuthenticationResultType authenticationResult;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FRespondToAuthChallengeResult &fromAWS(const Aws::CognitoIdentityProvider::Model::RespondToAuthChallengeResult &awsRespondToAuthChallengeResult) {
        switch(awsRespondToAuthChallengeResult.GetChallengeName()) {
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

        this->session = UTF8_TO_TCHAR(awsRespondToAuthChallengeResult.GetSession().c_str());

        this->challengeParameters.Empty();
        for (const auto& elem : awsRespondToAuthChallengeResult.GetChallengeParameters()) {
            this->challengeParameters.Add(elem.first.c_str(), elem.second.c_str());
        }

        this->authenticationResult.fromAWS(awsRespondToAuthChallengeResult.GetAuthenticationResult());

        return *this;
    }
#endif
};
