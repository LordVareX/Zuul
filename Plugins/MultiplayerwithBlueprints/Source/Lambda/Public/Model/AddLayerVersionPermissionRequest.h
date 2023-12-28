/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/AddLayerVersionPermissionRequest.h"

#endif

#include "AddLayerVersionPermissionRequest.generated.h"

USTRUCT(BlueprintType)
struct FAddLayerVersionPermissionRequest {
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
    *  <p>An identifier that distinguishes the policy from others on the same layer version.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString statementId;

    /**
    *  <p>The API action that grants access to the layer. For example, <code>lambda:GetLayerVersion</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString action;

    /**
    *  <p>An account ID, or <code>*</code> to grant permission to all AWS accounts.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString principal;

    /**
    *  <p>With the principal set to <code>*</code>, grant permission to all accounts in the specified organization.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString organizationId;

    /**
    *  <p>Only update the policy if the revision ID matches the ID specified. Use this option to avoid modifying a policy that has changed since you last read it.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString revisionId;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::AddLayerVersionPermissionRequest toAWS() const {
        Aws::Lambda::Model::AddLayerVersionPermissionRequest awsAddLayerVersionPermissionRequest;

		if (!(this->layerName.IsEmpty())) {
            awsAddLayerVersionPermissionRequest.SetLayerName(TCHAR_TO_UTF8(*this->layerName));
        }

        if (this->versionNumber >= 0) {
            awsAddLayerVersionPermissionRequest.SetVersionNumber(this->versionNumber);
        }

		if (!(this->statementId.IsEmpty())) {
            awsAddLayerVersionPermissionRequest.SetStatementId(TCHAR_TO_UTF8(*this->statementId));
        }

		if (!(this->action.IsEmpty())) {
            awsAddLayerVersionPermissionRequest.SetAction(TCHAR_TO_UTF8(*this->action));
        }

		if (!(this->principal.IsEmpty())) {
            awsAddLayerVersionPermissionRequest.SetPrincipal(TCHAR_TO_UTF8(*this->principal));
        }

		if (!(this->organizationId.IsEmpty())) {
            awsAddLayerVersionPermissionRequest.SetOrganizationId(TCHAR_TO_UTF8(*this->organizationId));
        }

		if (!(this->revisionId.IsEmpty())) {
            awsAddLayerVersionPermissionRequest.SetRevisionId(TCHAR_TO_UTF8(*this->revisionId));
        }

        return awsAddLayerVersionPermissionRequest;
    }

    bool IsEmpty() const {
        return this->layerName.IsEmpty() && this->versionNumber < 0 && this->statementId.IsEmpty() && this->action.IsEmpty() && this->principal.IsEmpty() && this->organizationId.IsEmpty() && this->revisionId.IsEmpty();
    }
#endif
};
