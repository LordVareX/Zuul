/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/UnprocessedIdentityId.h"

#endif

#include "Model/ErrorCode.h"

#include "UnprocessedIdentityId.generated.h"

USTRUCT(BlueprintType)
struct FUnprocessedIdentityId {
GENERATED_BODY()

    /**
    *  <p>A unique identifier in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityId;

    /**
    *  <p>The error code indicating the type of error that occurred.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    EErrorCode errorCode = EErrorCode::NOT_SET;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FUnprocessedIdentityId &fromAWS(const Aws::CognitoIdentity::Model::UnprocessedIdentityId &awsUnprocessedIdentityId) {
        this->identityId = UTF8_TO_TCHAR(awsUnprocessedIdentityId.GetIdentityId().c_str());

        switch(awsUnprocessedIdentityId.GetErrorCode()) {
            case Aws::CognitoIdentity::Model::ErrorCode::NOT_SET:
                this->errorCode = EErrorCode::NOT_SET;
                break;
            case Aws::CognitoIdentity::Model::ErrorCode::AccessDenied:
                this->errorCode = EErrorCode::AccessDenied;
                break;
            case Aws::CognitoIdentity::Model::ErrorCode::InternalServerError:
                this->errorCode = EErrorCode::InternalServerError;
                break;
            default:
                this->errorCode = EErrorCode::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
