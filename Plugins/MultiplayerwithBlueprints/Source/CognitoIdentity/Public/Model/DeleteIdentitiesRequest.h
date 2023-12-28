/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/DeleteIdentitiesRequest.h"

#endif

#include "DeleteIdentitiesRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteIdentitiesRequest {
GENERATED_BODY()

    /**
    *  <p>A list of 1-60 identities that you want to delete.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TArray<FString> identityIdsToDelete;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::DeleteIdentitiesRequest toAWS() const {
        Aws::CognitoIdentity::Model::DeleteIdentitiesRequest awsDeleteIdentitiesRequest;

        for (const FString& elem : this->identityIdsToDelete) {
            awsDeleteIdentitiesRequest.AddIdentityIdsToDelete(TCHAR_TO_UTF8(*elem));
        }

        return awsDeleteIdentitiesRequest;
    }

    bool IsEmpty() const {
        return this->identityIdsToDelete.Num() == 0;
    }
#endif
};
