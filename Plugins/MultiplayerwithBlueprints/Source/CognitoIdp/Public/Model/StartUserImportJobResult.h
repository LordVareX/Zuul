/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/StartUserImportJobResult.h"

#endif

#include "Model/UserImportJobType.h"

#include "StartUserImportJobResult.generated.h"

USTRUCT(BlueprintType)
struct FStartUserImportJobResult {
GENERATED_BODY()

    /**
    *  <p>The job object that represents the user import job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserImportJobType userImportJob;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FStartUserImportJobResult &fromAWS(const Aws::CognitoIdentityProvider::Model::StartUserImportJobResult &awsStartUserImportJobResult) {
        this->userImportJob.fromAWS(awsStartUserImportJobResult.GetUserImportJob());

        return *this;
    }
#endif
};
