/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/Compute.h"

#endif

#include "Model/AWSGameLiftComputeStatus.h"
#include "Model/OperatingSystem.h"
#include "Model/EC2InstanceType.h"

#include "AWSGameLiftCompute.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftCompute {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet that the compute is registered to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The Amazon Resource Name (ARN) of the fleet that the compute is registered to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetArn;

    /**
    *  <p>A descriptive label that is associated with the compute resource registered to your fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString computeName;

    /**
    *  <p>The ARN that is assigned to the compute resource and uniquely identifies it. ARNs are unique across locations.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString computeArn;

    /**
    *  <p>The IP address of the compute resource. GameLift requires the DNS name or IP address to manage your compute resource.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString ipAddress;

    /**
    *  <p>The DNS name of the compute resource. GameLift requires the DNS name or IP address to manage your compute resource.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString dnsName;

    /**
    *  <p>Current status of the compute. A compute must have an <code>ACTIVE</code> status to host game sessions.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EAWSGameLiftComputeStatus computeStatus = EAWSGameLiftComputeStatus::NOT_SET;

    /**
    *  <p>The name of the custom location you added to the fleet that this compute resource resides in.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

    /**
    *  <p>A time stamp indicating when this data object was created. Format is a number expressed in Unix time as milliseconds (for example <code>"1469498468.057"</code>).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime creationTime;

    /**
    *  <p>The type of operating system on your compute resource.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EOperatingSystem operatingSystem = EOperatingSystem::NOT_SET;

    /**
    *  <p>Which compute type that the fleet uses. A fleet can use Anywhere compute resources owned by you or managed Amazon EC2 instances.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EEC2InstanceType type = EEC2InstanceType::NOT_SET;

    /**
    *  <p>The endpoint connection details of the GameLift SDK endpoint that your game server connects to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString gameLiftServiceSdkEndpoint;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAWSGameLiftCompute &fromAWS(const Aws::GameLift::Model::Compute &awsCompute) {
        this->fleetId = UTF8_TO_TCHAR(awsCompute.GetFleetId().c_str());

        this->fleetArn = UTF8_TO_TCHAR(awsCompute.GetFleetArn().c_str());

        this->computeName = UTF8_TO_TCHAR(awsCompute.GetComputeName().c_str());

        this->computeArn = UTF8_TO_TCHAR(awsCompute.GetComputeArn().c_str());

        this->ipAddress = UTF8_TO_TCHAR(awsCompute.GetIpAddress().c_str());

        this->dnsName = UTF8_TO_TCHAR(awsCompute.GetDnsName().c_str());

        switch(awsCompute.GetComputeStatus()) {
            case Aws::GameLift::Model::ComputeStatus::NOT_SET:
                this->computeStatus = EAWSGameLiftComputeStatus::NOT_SET;
                break;
            case Aws::GameLift::Model::ComputeStatus::PENDING:
                this->computeStatus = EAWSGameLiftComputeStatus::PENDING;
                break;
            case Aws::GameLift::Model::ComputeStatus::ACTIVE:
                this->computeStatus = EAWSGameLiftComputeStatus::ACTIVE;
                break;
            case Aws::GameLift::Model::ComputeStatus::TERMINATING:
                this->computeStatus = EAWSGameLiftComputeStatus::TERMINATING;
                break;
            default:
                this->computeStatus = EAWSGameLiftComputeStatus::NOT_SET;
                break;
        }

        this->location = UTF8_TO_TCHAR(awsCompute.GetLocation().c_str());

        this->creationTime = FDateTime(1970, 1, 1) + FTimespan(awsCompute.GetCreationTime().Millis() * ETimespan::TicksPerMillisecond);

        switch(awsCompute.GetOperatingSystem()) {
            case Aws::GameLift::Model::OperatingSystem::NOT_SET:
                this->operatingSystem = EOperatingSystem::NOT_SET;
                break;
            case Aws::GameLift::Model::OperatingSystem::WINDOWS_2012:
                this->operatingSystem = EOperatingSystem::WINDOWS_2012;
                break;
            case Aws::GameLift::Model::OperatingSystem::AMAZON_LINUX:
                this->operatingSystem = EOperatingSystem::AMAZON_LINUX;
                break;
            case Aws::GameLift::Model::OperatingSystem::AMAZON_LINUX_2:
                this->operatingSystem = EOperatingSystem::AMAZON_LINUX_2;
                break;
            default:
                this->operatingSystem = EOperatingSystem::NOT_SET;
                break;
        }

        switch(awsCompute.GetType()) {
            case Aws::GameLift::Model::EC2InstanceType::NOT_SET:
                this->type = EEC2InstanceType::NOT_SET;
                break;
            case Aws::GameLift::Model::EC2InstanceType::t2_micro:
                this->type = EEC2InstanceType::t2_micro;
                break;
            case Aws::GameLift::Model::EC2InstanceType::t2_small:
                this->type = EEC2InstanceType::t2_small;
                break;
            case Aws::GameLift::Model::EC2InstanceType::t2_medium:
                this->type = EEC2InstanceType::t2_medium;
                break;
            case Aws::GameLift::Model::EC2InstanceType::t2_large:
                this->type = EEC2InstanceType::t2_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c3_large:
                this->type = EEC2InstanceType::c3_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c3_xlarge:
                this->type = EEC2InstanceType::c3_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c3_2xlarge:
                this->type = EEC2InstanceType::c3_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c3_4xlarge:
                this->type = EEC2InstanceType::c3_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c3_8xlarge:
                this->type = EEC2InstanceType::c3_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c4_large:
                this->type = EEC2InstanceType::c4_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c4_xlarge:
                this->type = EEC2InstanceType::c4_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c4_2xlarge:
                this->type = EEC2InstanceType::c4_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c4_4xlarge:
                this->type = EEC2InstanceType::c4_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c4_8xlarge:
                this->type = EEC2InstanceType::c4_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_large:
                this->type = EEC2InstanceType::c5_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_xlarge:
                this->type = EEC2InstanceType::c5_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_2xlarge:
                this->type = EEC2InstanceType::c5_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_4xlarge:
                this->type = EEC2InstanceType::c5_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_9xlarge:
                this->type = EEC2InstanceType::c5_9xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_12xlarge:
                this->type = EEC2InstanceType::c5_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_18xlarge:
                this->type = EEC2InstanceType::c5_18xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5_24xlarge:
                this->type = EEC2InstanceType::c5_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_large:
                this->type = EEC2InstanceType::c5a_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_xlarge:
                this->type = EEC2InstanceType::c5a_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_2xlarge:
                this->type = EEC2InstanceType::c5a_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_4xlarge:
                this->type = EEC2InstanceType::c5a_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_8xlarge:
                this->type = EEC2InstanceType::c5a_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_12xlarge:
                this->type = EEC2InstanceType::c5a_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_16xlarge:
                this->type = EEC2InstanceType::c5a_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5a_24xlarge:
                this->type = EEC2InstanceType::c5a_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r3_large:
                this->type = EEC2InstanceType::r3_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r3_xlarge:
                this->type = EEC2InstanceType::r3_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r3_2xlarge:
                this->type = EEC2InstanceType::r3_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r3_4xlarge:
                this->type = EEC2InstanceType::r3_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r3_8xlarge:
                this->type = EEC2InstanceType::r3_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r4_large:
                this->type = EEC2InstanceType::r4_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r4_xlarge:
                this->type = EEC2InstanceType::r4_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r4_2xlarge:
                this->type = EEC2InstanceType::r4_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r4_4xlarge:
                this->type = EEC2InstanceType::r4_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r4_8xlarge:
                this->type = EEC2InstanceType::r4_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r4_16xlarge:
                this->type = EEC2InstanceType::r4_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_large:
                this->type = EEC2InstanceType::r5_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_xlarge:
                this->type = EEC2InstanceType::r5_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_2xlarge:
                this->type = EEC2InstanceType::r5_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_4xlarge:
                this->type = EEC2InstanceType::r5_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_8xlarge:
                this->type = EEC2InstanceType::r5_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_12xlarge:
                this->type = EEC2InstanceType::r5_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_16xlarge:
                this->type = EEC2InstanceType::r5_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5_24xlarge:
                this->type = EEC2InstanceType::r5_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_large:
                this->type = EEC2InstanceType::r5a_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_xlarge:
                this->type = EEC2InstanceType::r5a_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_2xlarge:
                this->type = EEC2InstanceType::r5a_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_4xlarge:
                this->type = EEC2InstanceType::r5a_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_8xlarge:
                this->type = EEC2InstanceType::r5a_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_12xlarge:
                this->type = EEC2InstanceType::r5a_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_16xlarge:
                this->type = EEC2InstanceType::r5a_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5a_24xlarge:
                this->type = EEC2InstanceType::r5a_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m3_medium:
                this->type = EEC2InstanceType::m3_medium;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m3_large:
                this->type = EEC2InstanceType::m3_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m3_xlarge:
                this->type = EEC2InstanceType::m3_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m3_2xlarge:
                this->type = EEC2InstanceType::m3_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m4_large:
                this->type = EEC2InstanceType::m4_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m4_xlarge:
                this->type = EEC2InstanceType::m4_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m4_2xlarge:
                this->type = EEC2InstanceType::m4_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m4_4xlarge:
                this->type = EEC2InstanceType::m4_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m4_10xlarge:
                this->type = EEC2InstanceType::m4_10xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_large:
                this->type = EEC2InstanceType::m5_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_xlarge:
                this->type = EEC2InstanceType::m5_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_2xlarge:
                this->type = EEC2InstanceType::m5_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_4xlarge:
                this->type = EEC2InstanceType::m5_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_8xlarge:
                this->type = EEC2InstanceType::m5_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_12xlarge:
                this->type = EEC2InstanceType::m5_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_16xlarge:
                this->type = EEC2InstanceType::m5_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5_24xlarge:
                this->type = EEC2InstanceType::m5_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_large:
                this->type = EEC2InstanceType::m5a_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_xlarge:
                this->type = EEC2InstanceType::m5a_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_2xlarge:
                this->type = EEC2InstanceType::m5a_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_4xlarge:
                this->type = EEC2InstanceType::m5a_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_8xlarge:
                this->type = EEC2InstanceType::m5a_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_12xlarge:
                this->type = EEC2InstanceType::m5a_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_16xlarge:
                this->type = EEC2InstanceType::m5a_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::m5a_24xlarge:
                this->type = EEC2InstanceType::m5a_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5d_large:
                this->type = EEC2InstanceType::c5d_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5d_xlarge:
                this->type = EEC2InstanceType::c5d_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5d_2xlarge:
                this->type = EEC2InstanceType::c5d_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5d_4xlarge:
                this->type = EEC2InstanceType::c5d_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5d_9xlarge:
                this->type = EEC2InstanceType::c5d_9xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5d_12xlarge:
                this->type = EEC2InstanceType::c5d_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5d_18xlarge:
                this->type = EEC2InstanceType::c5d_18xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c5d_24xlarge:
                this->type = EEC2InstanceType::c5d_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c6a_large:
                this->type = EEC2InstanceType::c6a_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c6a_xlarge:
                this->type = EEC2InstanceType::c6a_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c6a_2xlarge:
                this->type = EEC2InstanceType::c6a_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c6a_4xlarge:
                this->type = EEC2InstanceType::c6a_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c6a_8xlarge:
                this->type = EEC2InstanceType::c6a_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c6a_12xlarge:
                this->type = EEC2InstanceType::c6a_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c6a_16xlarge:
                this->type = EEC2InstanceType::c6a_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c6a_24xlarge:
                this->type = EEC2InstanceType::c6a_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c6i_large:
                this->type = EEC2InstanceType::c6i_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c6i_xlarge:
                this->type = EEC2InstanceType::c6i_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c6i_2xlarge:
                this->type = EEC2InstanceType::c6i_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c6i_4xlarge:
                this->type = EEC2InstanceType::c6i_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c6i_8xlarge:
                this->type = EEC2InstanceType::c6i_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c6i_12xlarge:
                this->type = EEC2InstanceType::c6i_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c6i_16xlarge:
                this->type = EEC2InstanceType::c6i_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::c6i_24xlarge:
                this->type = EEC2InstanceType::c6i_24xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5d_large:
                this->type = EEC2InstanceType::r5d_large;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5d_xlarge:
                this->type = EEC2InstanceType::r5d_xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5d_2xlarge:
                this->type = EEC2InstanceType::r5d_2xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5d_4xlarge:
                this->type = EEC2InstanceType::r5d_4xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5d_8xlarge:
                this->type = EEC2InstanceType::r5d_8xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5d_12xlarge:
                this->type = EEC2InstanceType::r5d_12xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5d_16xlarge:
                this->type = EEC2InstanceType::r5d_16xlarge;
                break;
            case Aws::GameLift::Model::EC2InstanceType::r5d_24xlarge:
                this->type = EEC2InstanceType::r5d_24xlarge;
                break;
            default:
                this->type = EEC2InstanceType::NOT_SET;
                break;
        }

        this->gameLiftServiceSdkEndpoint = UTF8_TO_TCHAR(awsCompute.GetGameLiftServiceSdkEndpoint().c_str());

        return *this;
    }
#endif
};
