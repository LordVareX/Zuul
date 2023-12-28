/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/MergeDeveloperIdentitiesResult.h"

#endif

#include "MergeDeveloperIdentitiesResult.generated.h"

USTRUCT(BlueprintType)
struct FMergeDeveloperIdentitiesResult {
GENERATED_BODY()

    /**
    *  <p>A unique identifier in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityId;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FMergeDeveloperIdentitiesResult &fromAWS(const Aws::CognitoIdentity::Model::MergeDeveloperIdentitiesResult &awsMergeDeveloperIdentitiesResult) {
        this->identityId = UTF8_TO_TCHAR(awsMergeDeveloperIdentitiesResult.GetIdentityId().c_str());

        return *this;
    }
#endif
};
