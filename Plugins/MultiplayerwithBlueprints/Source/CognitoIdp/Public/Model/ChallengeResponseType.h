/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ChallengeResponseType.h"

#endif

#include "Model/ChallengeName.h"
#include "Model/ChallengeResponse.h"

#include "ChallengeResponseType.generated.h"

USTRUCT(BlueprintType)
struct FChallengeResponseType {
GENERATED_BODY()

    /**
    *  <p>The challenge name</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EChallengeName challengeName = EChallengeName::NOT_SET;

    /**
    *  <p>The challenge response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EChallengeResponse challengeResponse = EChallengeResponse::NOT_SET;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FChallengeResponseType &fromAWS(const Aws::CognitoIdentityProvider::Model::ChallengeResponseType &awsChallengeResponseType) {
        switch(awsChallengeResponseType.GetChallengeName()) {
            case Aws::CognitoIdentityProvider::Model::ChallengeName::NOT_SET:
                this->challengeName = EChallengeName::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::ChallengeName::Password:
                this->challengeName = EChallengeName::Password;
                break;
            case Aws::CognitoIdentityProvider::Model::ChallengeName::Mfa:
                this->challengeName = EChallengeName::Mfa;
                break;
            default:
                this->challengeName = EChallengeName::NOT_SET;
                break;
        }

        switch(awsChallengeResponseType.GetChallengeResponse()) {
            case Aws::CognitoIdentityProvider::Model::ChallengeResponse::NOT_SET:
                this->challengeResponse = EChallengeResponse::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::ChallengeResponse::Success:
                this->challengeResponse = EChallengeResponse::Success;
                break;
            case Aws::CognitoIdentityProvider::Model::ChallengeResponse::Failure:
                this->challengeResponse = EChallengeResponse::Failure;
                break;
            default:
                this->challengeResponse = EChallengeResponse::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
