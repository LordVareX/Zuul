/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CreateResourceServerResult.h"

#endif

#include "Model/ResourceServerType.h"

#include "CreateResourceServerResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateResourceServerResult {
GENERATED_BODY()

    /**
    *  <p>The newly created resource server.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FResourceServerType resourceServer;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FCreateResourceServerResult &fromAWS(const Aws::CognitoIdentityProvider::Model::CreateResourceServerResult &awsCreateResourceServerResult) {
        this->resourceServer.fromAWS(awsCreateResourceServerResult.GetResourceServer());

        return *this;
    }
#endif
};
