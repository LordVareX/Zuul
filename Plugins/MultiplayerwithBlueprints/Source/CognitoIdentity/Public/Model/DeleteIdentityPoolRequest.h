/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/DeleteIdentityPoolRequest.h"

#endif

#include "DeleteIdentityPoolRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteIdentityPoolRequest {
GENERATED_BODY()

    /**
    *  <p>An identity pool ID in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolId;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::DeleteIdentityPoolRequest toAWS() const {
        Aws::CognitoIdentity::Model::DeleteIdentityPoolRequest awsDeleteIdentityPoolRequest;

        if (!(this->identityPoolId.IsEmpty())) {
            awsDeleteIdentityPoolRequest.SetIdentityPoolId(TCHAR_TO_UTF8(*this->identityPoolId));
        }

        return awsDeleteIdentityPoolRequest;
    }

    bool IsEmpty() const {
        return this->identityPoolId.IsEmpty();
    }
#endif
};
