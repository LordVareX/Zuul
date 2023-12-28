/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/GetOpenIdTokenResult.h"

#endif


#include "GetOpenIdTokenResult.generated.h"

USTRUCT(BlueprintType)
struct FGetOpenIdTokenResult {
GENERATED_BODY()

    /**
    *  <p>A unique identifier in the format REGION:GUID. Note that the IdentityId returned may not match the one passed on input.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityId;

    /**
    *  <p>An OpenID token, valid for 10 minutes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString token;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FGetOpenIdTokenResult &fromAWS(const Aws::CognitoIdentity::Model::GetOpenIdTokenResult &awsGetOpenIdTokenResult) {
        this->identityId = UTF8_TO_TCHAR(awsGetOpenIdTokenResult.GetIdentityId().c_str());

        this->token = UTF8_TO_TCHAR(awsGetOpenIdTokenResult.GetToken().c_str());

        return *this;
    }
#endif
};
