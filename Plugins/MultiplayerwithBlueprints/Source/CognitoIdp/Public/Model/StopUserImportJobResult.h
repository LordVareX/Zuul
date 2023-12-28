/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/StopUserImportJobResult.h"

#endif

#include "Model/UserImportJobType.h"

#include "StopUserImportJobResult.generated.h"

USTRUCT(BlueprintType)
struct FStopUserImportJobResult {
GENERATED_BODY()

    /**
    *  <p>The job object that represents the user import job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserImportJobType userImportJob;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FStopUserImportJobResult &fromAWS(const Aws::CognitoIdentityProvider::Model::StopUserImportJobResult &awsStopUserImportJobResult) {
        this->userImportJob.fromAWS(awsStopUserImportJobResult.GetUserImportJob());

        return *this;
    }
#endif
};
