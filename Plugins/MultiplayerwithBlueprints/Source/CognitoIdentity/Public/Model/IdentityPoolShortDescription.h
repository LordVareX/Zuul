/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/IdentityPoolShortDescription.h"

#endif

#include "IdentityPoolShortDescription.generated.h"

USTRUCT(BlueprintType)
struct FIdentityPoolShortDescription {
GENERATED_BODY()

    /**
    *  <p>An identity pool ID in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolId;

    /**
    *  <p>A string that you provide.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolName;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FIdentityPoolShortDescription &fromAWS(const Aws::CognitoIdentity::Model::IdentityPoolShortDescription &awsIdentityPoolShortDescription) {
        this->identityPoolId = UTF8_TO_TCHAR(awsIdentityPoolShortDescription.GetIdentityPoolId().c_str());

        this->identityPoolName = UTF8_TO_TCHAR(awsIdentityPoolShortDescription.GetIdentityPoolName().c_str());

        return *this;
    }
#endif
};
