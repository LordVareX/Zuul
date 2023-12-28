/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListResourceServersResult.h"

#endif

#include "Model/ResourceServerType.h"

#include "ListResourceServersResult.generated.h"

USTRUCT(BlueprintType)
struct FListResourceServersResult {
GENERATED_BODY()

    /**
    *  <p>The resource servers.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FResourceServerType> resourceServers;

    /**
    *  <p>A pagination token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString nextToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FListResourceServersResult &fromAWS(const Aws::CognitoIdentityProvider::Model::ListResourceServersResult &awsListResourceServersResult) {
        this->resourceServers.Empty();
        for (const Aws::CognitoIdentityProvider::Model::ResourceServerType& elem : awsListResourceServersResult.GetResourceServers()) {
            this->resourceServers.Add(FResourceServerType().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListResourceServersResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
