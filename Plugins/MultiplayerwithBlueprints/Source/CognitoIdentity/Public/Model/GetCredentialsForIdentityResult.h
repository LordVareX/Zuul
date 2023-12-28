/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/GetCredentialsForIdentityResult.h"

#endif

#include "Model/CognitoCredentials.h"

#include "GetCredentialsForIdentityResult.generated.h"

USTRUCT(BlueprintType)
struct FGetCredentialsForIdentityResult {
GENERATED_BODY()

    /**
    *  <p>A unique identifier in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityId;

    /**
    *  <p>Credentials for the provided identity ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FCognitoCredentials credentials;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FGetCredentialsForIdentityResult &fromAWS(const Aws::CognitoIdentity::Model::GetCredentialsForIdentityResult &awsGetCredentialsForIdentityResult) {
        this->identityId = UTF8_TO_TCHAR(awsGetCredentialsForIdentityResult.GetIdentityId().c_str());

        this->credentials.fromAWS(awsGetCredentialsForIdentityResult.GetCredentials());

        return *this;
    }
#endif
};
