/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/DeleteIdentitiesResult.h"

#endif

#include "Model/UnprocessedIdentityId.h"

#include "DeleteIdentitiesResult.generated.h"

USTRUCT(BlueprintType)
struct FDeleteIdentitiesResult {
GENERATED_BODY()

    /**
    *  <p>An array of UnprocessedIdentityId objects, each of which contains an ErrorCode and IdentityId.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TArray<FUnprocessedIdentityId> unprocessedIdentityIds;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FDeleteIdentitiesResult &fromAWS(const Aws::CognitoIdentity::Model::DeleteIdentitiesResult &awsDeleteIdentitiesResult) {
        this->unprocessedIdentityIds.Empty();
        for (const Aws::CognitoIdentity::Model::UnprocessedIdentityId& elem : awsDeleteIdentitiesResult.GetUnprocessedIdentityIds()) {
            this->unprocessedIdentityIds.Add(FUnprocessedIdentityId().fromAWS(elem));
        }

        return *this;
    }
#endif
};
