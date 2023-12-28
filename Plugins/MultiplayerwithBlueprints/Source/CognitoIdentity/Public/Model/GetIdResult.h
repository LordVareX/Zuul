/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/GetIdResult.h"

#endif

#include "GetIdResult.generated.h"

USTRUCT(BlueprintType)
struct FGetIdResult {
GENERATED_BODY()

    /**
    *  <p>A unique identifier in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityId;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FGetIdResult &fromAWS(const Aws::CognitoIdentity::Model::GetIdResult &awsGetIdResult) {
        this->identityId = UTF8_TO_TCHAR(awsGetIdResult.GetIdentityId().c_str());

        return *this;
    }
#endif
};
