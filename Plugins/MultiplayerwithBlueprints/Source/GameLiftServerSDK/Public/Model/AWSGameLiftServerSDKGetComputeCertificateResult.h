/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT && WITH_GAMELIFT_5

#include "aws/gamelift/server/model/GetComputeCertificateResult.h"

#endif

#include "AWSGameLiftServerSDKGetComputeCertificateResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftServerSDKGetComputeCertificateResult {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString CertificatePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString ComputeName;

#if WITH_GAMELIFT && WITH_GAMELIFT_5
    public:
    FAWSGameLiftServerSDKGetComputeCertificateResult& fromAWS(const Aws::GameLift::Server::Model::GetComputeCertificateResult& awsGetComputeCertificateResult) {
        this->CertificatePath = awsGetComputeCertificateResult.GetCertificatePath();

        this->ComputeName = awsGetComputeCertificateResult.GetComputeName();

        return *this;
    };

#endif
};