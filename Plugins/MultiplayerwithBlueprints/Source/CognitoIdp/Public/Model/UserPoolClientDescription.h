/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UserPoolClientDescription.h"

#endif

#include "UserPoolClientDescription.generated.h"

USTRUCT(BlueprintType)
struct FUserPoolClientDescription {
GENERATED_BODY()

    /**
    *  <p>The ID of the client associated with the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientId;

    /**
    *  <p>The user pool ID for the user pool where you want to describe the user pool client.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The client name from the user pool client description.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientName;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FUserPoolClientDescription &fromAWS(const Aws::CognitoIdentityProvider::Model::UserPoolClientDescription &awsUserPoolClientDescription) {
        this->clientId = UTF8_TO_TCHAR(awsUserPoolClientDescription.GetClientId().c_str());

        this->userPoolId = UTF8_TO_TCHAR(awsUserPoolClientDescription.GetUserPoolId().c_str());

        this->clientName = UTF8_TO_TCHAR(awsUserPoolClientDescription.GetClientName().c_str());

        return *this;
    }
#endif
};
