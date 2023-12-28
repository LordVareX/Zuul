/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SetUICustomizationResult.h"

#endif

#include "Model/UICustomizationType.h"

#include "SetUICustomizationResult.generated.h"

USTRUCT(BlueprintType)
struct FSetUICustomizationResult {
GENERATED_BODY()

    /**
    *  <p>The UI customization information.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUICustomizationType uICustomization;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FSetUICustomizationResult &fromAWS(const Aws::CognitoIdentityProvider::Model::SetUICustomizationResult &awsSetUICustomizationResult) {
        this->uICustomization.fromAWS(awsSetUICustomizationResult.GetUICustomization());

        return *this;
    }
#endif
};
