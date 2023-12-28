/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/GetIdentityPoolRolesRequest.h"

#endif


#include "GetIdentityPoolRolesRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetIdentityPoolRolesRequest {
GENERATED_BODY()

    /**
    *  <p>An identity pool ID in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolId;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::GetIdentityPoolRolesRequest toAWS() const {
        Aws::CognitoIdentity::Model::GetIdentityPoolRolesRequest awsGetIdentityPoolRolesRequest;

        if (!(this->identityPoolId.IsEmpty())) {
            awsGetIdentityPoolRolesRequest.SetIdentityPoolId(TCHAR_TO_UTF8(*this->identityPoolId));
        }

        return awsGetIdentityPoolRolesRequest;
    }

    bool IsEmpty() const {
        return this->identityPoolId.IsEmpty();
    }
#endif
};
