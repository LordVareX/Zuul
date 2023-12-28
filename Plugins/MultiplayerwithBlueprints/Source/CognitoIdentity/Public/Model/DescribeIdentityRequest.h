/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/DescribeIdentityRequest.h"

#endif


#include "DescribeIdentityRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeIdentityRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityId;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::DescribeIdentityRequest toAWS() const {
        Aws::CognitoIdentity::Model::DescribeIdentityRequest awsDescribeIdentityRequest;

        if (!(this->identityId.IsEmpty())) {
            awsDescribeIdentityRequest.SetIdentityId(TCHAR_TO_UTF8(*this->identityId));
        }

        return awsDescribeIdentityRequest;
    }

    bool IsEmpty() const {
        return this->identityId.IsEmpty();
    }
#endif
};
