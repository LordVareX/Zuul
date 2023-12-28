/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/DescribeIdentityPoolRequest.h"

#endif

#include "DescribeIdentityPoolRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeIdentityPoolRequest {
GENERATED_BODY()

    /**
    *  <p>An identity pool ID in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolId;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::DescribeIdentityPoolRequest toAWS() const {
        Aws::CognitoIdentity::Model::DescribeIdentityPoolRequest awsDescribeIdentityPoolRequest;

        if (!(this->identityPoolId.IsEmpty())) {
            awsDescribeIdentityPoolRequest.SetIdentityPoolId(TCHAR_TO_UTF8(*this->identityPoolId));
        }

        return awsDescribeIdentityPoolRequest;
    }

    bool IsEmpty() const {
        return this->identityPoolId.IsEmpty();
    }
#endif
};
