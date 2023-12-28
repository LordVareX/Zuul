/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UpdateResourceServerResult.h"

#endif

#include "Model/ResourceServerType.h"

#include "UpdateResourceServerResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateResourceServerResult {
GENERATED_BODY()

    /**
    *  <p>The resource server.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FResourceServerType resourceServer;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FUpdateResourceServerResult &fromAWS(const Aws::CognitoIdentityProvider::Model::UpdateResourceServerResult &awsUpdateResourceServerResult) {
        this->resourceServer.fromAWS(awsUpdateResourceServerResult.GetResourceServer());

        return *this;
    }
#endif
};
