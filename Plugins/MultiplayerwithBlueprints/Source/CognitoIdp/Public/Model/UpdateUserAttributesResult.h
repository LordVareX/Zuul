/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UpdateUserAttributesResult.h"

#endif

#include "Model/CodeDeliveryDetailsType.h"

#include "UpdateUserAttributesResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateUserAttributesResult {
GENERATED_BODY()

    /**
    *  <p>The code delivery details list from the server for the request to update user attributes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FCodeDeliveryDetailsType> codeDeliveryDetailsList;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FUpdateUserAttributesResult &fromAWS(const Aws::CognitoIdentityProvider::Model::UpdateUserAttributesResult &awsUpdateUserAttributesResult) {
        this->codeDeliveryDetailsList.Empty();
        for (const Aws::CognitoIdentityProvider::Model::CodeDeliveryDetailsType& elem : awsUpdateUserAttributesResult.GetCodeDeliveryDetailsList()) {
            this->codeDeliveryDetailsList.Add(FCodeDeliveryDetailsType().fromAWS(elem));
        }

        return *this;
    }
#endif
};
