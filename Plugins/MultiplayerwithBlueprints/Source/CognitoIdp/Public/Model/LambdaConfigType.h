/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/LambdaConfigType.h"

#endif

#include "Model/AWSCognitoIdpCustomSMSLambdaVersionConfigType.h"
#include "Model/AWSCognitoIdpCustomEmailLambdaVersionConfigType.h"

#include "LambdaConfigType.generated.h"

USTRUCT(BlueprintType)
struct FLambdaConfigType {
GENERATED_BODY()

    /**
    *  <p>A pre-registration AWS Lambda trigger.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString preSignUp;

    /**
    *  <p>A custom Message AWS Lambda trigger.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString customMessage;

    /**
    *  <p>A post-confirmation AWS Lambda trigger.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString postConfirmation;

    /**
    *  <p>A pre-authentication AWS Lambda trigger.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString preAuthentication;

    /**
    *  <p>A post-authentication AWS Lambda trigger.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString postAuthentication;

    /**
    *  <p>Defines the authentication challenge.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString defineAuthChallenge;

    /**
    *  <p>Creates an authentication challenge.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString createAuthChallenge;

    /**
    *  <p>Verifies the authentication challenge response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString verifyAuthChallengeResponse;

    /**
    *  <p>A Lambda trigger that is invoked before token generation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString preTokenGeneration;

    /**
    *  <p>The user migration Lambda config type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userMigration;

    /**
    *  <p>A custom SMS sender AWS Lambda trigger.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAWSCognitoIdpCustomSMSLambdaVersionConfigType customSMSSender;

    /**
    *  <p>A custom email sender AWS Lambda trigger.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAWSCognitoIdpCustomEmailLambdaVersionConfigType customEmailSender;

    /**
    *  <p>The Amazon Resource Name of Key Management Service <a href="/kms/latest/developerguide/concepts.html#master_keys">Customer master keys</a> . Amazon Cognito uses the key to encrypt codes and temporary passwords sent to <code>CustomEmailSender</code> and <code>CustomSMSSender</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString kMSKeyID;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::LambdaConfigType toAWS() const {
        Aws::CognitoIdentityProvider::Model::LambdaConfigType awsLambdaConfigType;

        if (!(this->preSignUp.IsEmpty())) {
            awsLambdaConfigType.SetPreSignUp(TCHAR_TO_UTF8(*this->preSignUp));
        }

        if (!(this->customMessage.IsEmpty())) {
            awsLambdaConfigType.SetCustomMessage(TCHAR_TO_UTF8(*this->customMessage));
        }

        if (!(this->postConfirmation.IsEmpty())) {
            awsLambdaConfigType.SetPostConfirmation(TCHAR_TO_UTF8(*this->postConfirmation));
        }

        if (!(this->preAuthentication.IsEmpty())) {
            awsLambdaConfigType.SetPreAuthentication(TCHAR_TO_UTF8(*this->preAuthentication));
        }

        if (!(this->postAuthentication.IsEmpty())) {
            awsLambdaConfigType.SetPostAuthentication(TCHAR_TO_UTF8(*this->postAuthentication));
        }

        if (!(this->defineAuthChallenge.IsEmpty())) {
            awsLambdaConfigType.SetDefineAuthChallenge(TCHAR_TO_UTF8(*this->defineAuthChallenge));
        }

        if (!(this->createAuthChallenge.IsEmpty())) {
            awsLambdaConfigType.SetCreateAuthChallenge(TCHAR_TO_UTF8(*this->createAuthChallenge));
        }

        if (!(this->verifyAuthChallengeResponse.IsEmpty())) {
            awsLambdaConfigType.SetVerifyAuthChallengeResponse(TCHAR_TO_UTF8(*this->verifyAuthChallengeResponse));
        }

        if (!(this->preTokenGeneration.IsEmpty())) {
            awsLambdaConfigType.SetPreTokenGeneration(TCHAR_TO_UTF8(*this->preTokenGeneration));
        }

        if (!(this->userMigration.IsEmpty())) {
            awsLambdaConfigType.SetUserMigration(TCHAR_TO_UTF8(*this->userMigration));
        }

        if (!(this->customSMSSender.IsEmpty())) {
            awsLambdaConfigType.SetCustomSMSSender(this->customSMSSender.toAWS());
        }

        if (!(this->customEmailSender.IsEmpty())) {
            awsLambdaConfigType.SetCustomEmailSender(this->customEmailSender.toAWS());
        }

        if (!(this->kMSKeyID.IsEmpty())) {
            awsLambdaConfigType.SetKMSKeyID(TCHAR_TO_UTF8(*this->kMSKeyID));
        }

        return awsLambdaConfigType;
    }

    bool IsEmpty() const {
        return this->preSignUp.IsEmpty() && this->customMessage.IsEmpty() && this->postConfirmation.IsEmpty() && this->preAuthentication.IsEmpty() && this->postAuthentication.IsEmpty() && this->defineAuthChallenge.IsEmpty() && this->createAuthChallenge.IsEmpty() && this->verifyAuthChallengeResponse.IsEmpty() && this->preTokenGeneration.IsEmpty() && this->userMigration.IsEmpty();
    }

    FLambdaConfigType &fromAWS(const Aws::CognitoIdentityProvider::Model::LambdaConfigType &awsLambdaConfigType) {
        this->preSignUp = UTF8_TO_TCHAR(awsLambdaConfigType.GetPreSignUp().c_str());

        this->customMessage = UTF8_TO_TCHAR(awsLambdaConfigType.GetCustomMessage().c_str());

        this->postConfirmation = UTF8_TO_TCHAR(awsLambdaConfigType.GetPostConfirmation().c_str());

        this->preAuthentication = UTF8_TO_TCHAR(awsLambdaConfigType.GetPreAuthentication().c_str());

        this->postAuthentication = UTF8_TO_TCHAR(awsLambdaConfigType.GetPostAuthentication().c_str());

        this->defineAuthChallenge = UTF8_TO_TCHAR(awsLambdaConfigType.GetDefineAuthChallenge().c_str());

        this->createAuthChallenge = UTF8_TO_TCHAR(awsLambdaConfigType.GetCreateAuthChallenge().c_str());

        this->verifyAuthChallengeResponse = UTF8_TO_TCHAR(awsLambdaConfigType.GetVerifyAuthChallengeResponse().c_str());

        this->preTokenGeneration = UTF8_TO_TCHAR(awsLambdaConfigType.GetPreTokenGeneration().c_str());

        this->userMigration = UTF8_TO_TCHAR(awsLambdaConfigType.GetUserMigration().c_str());

        this->customSMSSender.fromAWS(awsLambdaConfigType.GetCustomSMSSender());

        this->customEmailSender.fromAWS(awsLambdaConfigType.GetCustomEmailSender());

        this->kMSKeyID = UTF8_TO_TCHAR(awsLambdaConfigType.GetKMSKeyID().c_str());

        return *this;
    }
#endif
};
