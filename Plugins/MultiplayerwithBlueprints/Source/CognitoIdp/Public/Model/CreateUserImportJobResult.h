/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CreateUserImportJobResult.h"

#endif

#include "Model/UserImportJobType.h"

#include "CreateUserImportJobResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateUserImportJobResult {
GENERATED_BODY()

    /**
    *  <p>The job object that represents the user import job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserImportJobType userImportJob;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FCreateUserImportJobResult &fromAWS(const Aws::CognitoIdentityProvider::Model::CreateUserImportJobResult &awsCreateUserImportJobResult) {
        this->userImportJob.fromAWS(awsCreateUserImportJobResult.GetUserImportJob());

        return *this;
    }
#endif
};
