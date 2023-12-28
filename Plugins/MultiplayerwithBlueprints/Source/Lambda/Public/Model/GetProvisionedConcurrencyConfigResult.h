/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/GetProvisionedConcurrencyConfigResult.h"

#endif

#include "Model/ProvisionedConcurrencyStatusEnum.h"

#include "GetProvisionedConcurrencyConfigResult.generated.h"

USTRUCT(BlueprintType)
struct FGetProvisionedConcurrencyConfigResult {
GENERATED_BODY()

    /**
    *  <p>The amount of provisioned concurrency requested.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int requestedProvisionedConcurrentExecutions = 0;

    /**
    *  <p>The amount of provisioned concurrency available.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int availableProvisionedConcurrentExecutions = 0;

    /**
    *  <p>The amount of provisioned concurrency allocated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int allocatedProvisionedConcurrentExecutions = 0;

    /**
    *  <p>The status of the allocation process.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSProvisionedConcurrencyStatusEnum status = EAWSProvisionedConcurrencyStatusEnum::NOT_SET;

    /**
    *  <p>For failed allocations, the reason that provisioned concurrency could not be allocated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString statusReason;

    /**
    *  <p>The date and time that a user last updated the configuration, in <a href="https://www.iso.org/iso-8601-date-and-time-format.html">ISO 8601 format</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString lastModified;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FGetProvisionedConcurrencyConfigResult &fromAWS(const Aws::Lambda::Model::GetProvisionedConcurrencyConfigResult &awsGetProvisionedConcurrencyConfigResult) {
		this->requestedProvisionedConcurrentExecutions = awsGetProvisionedConcurrencyConfigResult.GetRequestedProvisionedConcurrentExecutions();

		this->availableProvisionedConcurrentExecutions = awsGetProvisionedConcurrencyConfigResult.GetAvailableProvisionedConcurrentExecutions();

		this->allocatedProvisionedConcurrentExecutions = awsGetProvisionedConcurrencyConfigResult.GetAllocatedProvisionedConcurrentExecutions();

        switch(awsGetProvisionedConcurrencyConfigResult.GetStatus()) {
            case Aws::Lambda::Model::ProvisionedConcurrencyStatusEnum::NOT_SET:
                this->status = EAWSProvisionedConcurrencyStatusEnum::NOT_SET;
                break;
            case Aws::Lambda::Model::ProvisionedConcurrencyStatusEnum::IN_PROGRESS:
                this->status = EAWSProvisionedConcurrencyStatusEnum::IN_PROGRESS;
                break;
            case Aws::Lambda::Model::ProvisionedConcurrencyStatusEnum::READY:
                this->status = EAWSProvisionedConcurrencyStatusEnum::READY;
                break;
            case Aws::Lambda::Model::ProvisionedConcurrencyStatusEnum::FAILED:
                this->status = EAWSProvisionedConcurrencyStatusEnum::FAILED;
                break;
            default:
                this->status = EAWSProvisionedConcurrencyStatusEnum::NOT_SET;
                break;
        }

        this->statusReason = UTF8_TO_TCHAR(awsGetProvisionedConcurrencyConfigResult.GetStatusReason().c_str());

        this->lastModified = UTF8_TO_TCHAR(awsGetProvisionedConcurrencyConfigResult.GetLastModified().c_str());

        return *this;
    }
#endif
};
