/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/RegisterComputeRequest.h"

#endif

#include "AWSGameLiftRegisterComputeRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftRegisterComputeRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet to register the compute to. You can use either the fleet ID or ARN value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>A descriptive label that is associated with the compute resource registered to your fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString computeName;

    /**
    *  <p>The path to the TLS certificate on your compute resource. The path and certificate are not validated by GameLift.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString certificatePath;

    /**
    *  <p>The DNS name of the compute resource. GameLift requires the DNS name or IP address to manage your compute resource.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString dnsName;

    /**
    *  <p>The IP address of the compute resource. GameLift requires the DNS name or IP address to manage your compute resource.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ipAddress;

    /**
    *  <p>The name of the custom location you added to the fleet you are registering this compute resource to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::RegisterComputeRequest toAWS() const {
        Aws::GameLift::Model::RegisterComputeRequest awsRegisterComputeRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsRegisterComputeRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        if (!(this->computeName.IsEmpty())) {
            awsRegisterComputeRequest.SetComputeName(TCHAR_TO_UTF8(*this->computeName));
        }

        if (!(this->certificatePath.IsEmpty())) {
            awsRegisterComputeRequest.SetCertificatePath(TCHAR_TO_UTF8(*this->certificatePath));
        }

        if (!(this->dnsName.IsEmpty())) {
            awsRegisterComputeRequest.SetDnsName(TCHAR_TO_UTF8(*this->dnsName));
        }

        if (!(this->ipAddress.IsEmpty())) {
            awsRegisterComputeRequest.SetIpAddress(TCHAR_TO_UTF8(*this->ipAddress));
        }

        if (!(this->location.IsEmpty())) {
            awsRegisterComputeRequest.SetLocation(TCHAR_TO_UTF8(*this->location));
        }

        return awsRegisterComputeRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->computeName.IsEmpty() && this->certificatePath.IsEmpty() && this->dnsName.IsEmpty() && this->ipAddress.IsEmpty() && this->location.IsEmpty();
    }
#endif
};
