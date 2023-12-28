/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/GetOpenIdTokenForDeveloperIdentityResult.h"

#endif

#include "GetOpenIdTokenForDeveloperIdentityResult.generated.h"

USTRUCT(BlueprintType)
struct FGetOpenIdTokenForDeveloperIdentityResult {
GENERATED_BODY()

    /**
    *  <p>A unique identifier in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityId;

    /**
    *  <p>An OpenID token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString token;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FGetOpenIdTokenForDeveloperIdentityResult &fromAWS(const Aws::CognitoIdentity::Model::GetOpenIdTokenForDeveloperIdentityResult &awsGetOpenIdTokenForDeveloperIdentityResult) {
        this->identityId = UTF8_TO_TCHAR(awsGetOpenIdTokenForDeveloperIdentityResult.GetIdentityId().c_str());

        this->token = UTF8_TO_TCHAR(awsGetOpenIdTokenForDeveloperIdentityResult.GetToken().c_str());

        return *this;
    }
#endif
};
