/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/RemoveLayerVersionPermissionRequest.h"

#endif

#include "RemoveLayerVersionPermissionRequest.generated.h"

USTRUCT(BlueprintType)
struct FRemoveLayerVersionPermissionRequest {
GENERATED_BODY()

    /**
    *  <p>The name or Amazon Resource Name (ARN) of the layer.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString layerName;

    /**
    *  <p>The version number.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int64 versionNumber = 0;

    /**
    *  <p>The identifier that was specified when the statement was added.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString statementId;

    /**
    *  <p>Only update the policy if the revision ID matches the ID specified. Use this option to avoid modifying a policy that has changed since you last read it.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString revisionId;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::RemoveLayerVersionPermissionRequest toAWS() const {
        Aws::Lambda::Model::RemoveLayerVersionPermissionRequest awsRemoveLayerVersionPermissionRequest;

		if (!(this->layerName.IsEmpty())) {
            awsRemoveLayerVersionPermissionRequest.SetLayerName(TCHAR_TO_UTF8(*this->layerName));
        }

        if (this->versionNumber >= 0) {
            awsRemoveLayerVersionPermissionRequest.SetVersionNumber(this->versionNumber);
        }

		if (!(this->statementId.IsEmpty())) {
            awsRemoveLayerVersionPermissionRequest.SetStatementId(TCHAR_TO_UTF8(*this->statementId));
        }

		if (!(this->revisionId.IsEmpty())) {
            awsRemoveLayerVersionPermissionRequest.SetRevisionId(TCHAR_TO_UTF8(*this->revisionId));
        }

        return awsRemoveLayerVersionPermissionRequest;
    }

    bool IsEmpty() const {
        return this->layerName.IsEmpty() && this->versionNumber < 0 && this->statementId.IsEmpty() && this->revisionId.IsEmpty();
    }
#endif
};
