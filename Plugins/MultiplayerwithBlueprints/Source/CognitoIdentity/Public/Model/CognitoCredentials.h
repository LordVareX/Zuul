/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/Credentials.h"

#endif


#include "CognitoCredentials.generated.h"

USTRUCT(BlueprintType)
struct FCognitoCredentials {
GENERATED_BODY()

    /**
    *  <p>The Access Key portion of the credentials.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString accessKeyId;

    /**
    *  <p>The Secret Access Key portion of the credentials</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString secretKey;

    /**
    *  <p>The Session Token portion of the credentials</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString sessionToken;

    /**
    *  <p>The date at which these credentials will expire.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FDateTime expiration;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FCognitoCredentials &fromAWS(const Aws::CognitoIdentity::Model::Credentials &awsCredentials) {
        this->accessKeyId = UTF8_TO_TCHAR(awsCredentials.GetAccessKeyId().c_str());

        this->secretKey = UTF8_TO_TCHAR(awsCredentials.GetSecretKey().c_str());

        this->sessionToken = UTF8_TO_TCHAR(awsCredentials.GetSessionToken().c_str());

        this->expiration = FDateTime(1970, 1, 1) + FTimespan(awsCredentials.GetExpiration().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
