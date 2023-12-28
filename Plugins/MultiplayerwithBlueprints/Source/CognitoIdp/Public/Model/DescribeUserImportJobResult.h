/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DescribeUserImportJobResult.h"

#endif

#include "Model/UserImportJobType.h"

#include "DescribeUserImportJobResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeUserImportJobResult {
GENERATED_BODY()

    /**
    *  <p>The job object that represents the user import job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserImportJobType userImportJob;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FDescribeUserImportJobResult &fromAWS(const Aws::CognitoIdentityProvider::Model::DescribeUserImportJobResult &awsDescribeUserImportJobResult) {
        this->userImportJob.fromAWS(awsDescribeUserImportJobResult.GetUserImportJob());

        return *this;
    }
#endif
};
