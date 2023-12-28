/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ProvisionedConcurrencyConfigListItem.h"

#endif

#include "Model/ProvisionedConcurrencyStatusEnum.h"

#include "ProvisionedConcurrencyConfigListItem.generated.h"

USTRUCT(BlueprintType)
struct FProvisionedConcurrencyConfigListItem {
    GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the alias or version.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionArn;

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
    FProvisionedConcurrencyConfigListItem &fromAWS(const Aws::Lambda::Model::ProvisionedConcurrencyConfigListItem &awsProvisionedConcurrencyConfigListItem) {
        this->functionArn = UTF8_TO_TCHAR(awsProvisionedConcurrencyConfigListItem.GetFunctionArn().c_str());

		this->requestedProvisionedConcurrentExecutions = awsProvisionedConcurrencyConfigListItem.GetRequestedProvisionedConcurrentExecutions();

		this->availableProvisionedConcurrentExecutions = awsProvisionedConcurrencyConfigListItem.GetAvailableProvisionedConcurrentExecutions();

		this->allocatedProvisionedConcurrentExecutions = awsProvisionedConcurrencyConfigListItem.GetAllocatedProvisionedConcurrentExecutions();

        switch(awsProvisionedConcurrencyConfigListItem.GetStatus()) {
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

        this->statusReason = UTF8_TO_TCHAR(awsProvisionedConcurrencyConfigListItem.GetStatusReason().c_str());

        this->lastModified = UTF8_TO_TCHAR(awsProvisionedConcurrencyConfigListItem.GetLastModified().c_str());

        return *this;
    }
#endif
};
