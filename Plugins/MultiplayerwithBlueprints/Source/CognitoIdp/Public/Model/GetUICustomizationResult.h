/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GetUICustomizationResult.h"

#endif

#include "Model/UICustomizationType.h"

#include "GetUICustomizationResult.generated.h"

USTRUCT(BlueprintType)
struct FGetUICustomizationResult {
GENERATED_BODY()

    /**
    *  <p>The UI customization information.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUICustomizationType uICustomization;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FGetUICustomizationResult &fromAWS(const Aws::CognitoIdentityProvider::Model::GetUICustomizationResult &awsGetUICustomizationResult) {
        this->uICustomization.fromAWS(awsGetUICustomizationResult.GetUICustomization());

        return *this;
    }
#endif
};
