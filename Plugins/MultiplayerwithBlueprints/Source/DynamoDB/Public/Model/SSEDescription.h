/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/SSEDescription.h"

#endif

#include "Model/SSEStatus.h"
#include "Model/SSEType.h"

#include "SSEDescription.generated.h"

USTRUCT(BlueprintType)
struct FSSEDescription {
GENERATED_BODY()

    /**
    *  <p>Represents the current state of server-side encryption. The only supported values are:</p> <ul> <li> <p> <code>ENABLED</code> - Server-side encryption is enabled.</p> </li> <li> <p> <code>UPDATING</code> - Server-side encryption is being updated.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSSSEStatus status = EAWSSSEStatus::NOT_SET;

    /**
    *  <p>Server-side encryption type. The only supported value is:</p> <ul> <li> <p> <code>KMS</code> - Server-side encryption which uses AWS Key Management Service. Key is stored in your account and is managed by AWS KMS (KMS charges apply).</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSSSEType SSEType = EAWSSSEType::NOT_SET;

    /**
    *  <p>The KMS customer master key (CMK) ARN used for the KMS encryption.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString KMSMasterKeyArn;

    /**
    *  <p>Indicates the time, in UNIX epoch date format, when DynamoDB detected that the table's AWS KMS key was inaccessible. This attribute will automatically be cleared when DynamoDB detects that the table's AWS KMS key is accessible again. DynamoDB will initiate the table archival process when table's AWS KMS key remains inaccessible for more than seven days from this date.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime inaccessibleEncryptionDateTime;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FSSEDescription &fromAWS(const Aws::DynamoDB::Model::SSEDescription &awsSSEDescription) {
        switch(awsSSEDescription.GetStatus()) {
            case Aws::DynamoDB::Model::SSEStatus::NOT_SET:
                this->status = EAWSSSEStatus::NOT_SET;
                break;
            case Aws::DynamoDB::Model::SSEStatus::ENABLING:
                this->status = EAWSSSEStatus::ENABLING;
                break;
            case Aws::DynamoDB::Model::SSEStatus::ENABLED:
                this->status = EAWSSSEStatus::ENABLED;
                break;
            case Aws::DynamoDB::Model::SSEStatus::DISABLING:
                this->status = EAWSSSEStatus::DISABLING;
                break;
            case Aws::DynamoDB::Model::SSEStatus::DISABLED:
                this->status = EAWSSSEStatus::DISABLED;
                break;
            case Aws::DynamoDB::Model::SSEStatus::UPDATING:
                this->status = EAWSSSEStatus::UPDATING;
                break;
            default:
                this->status = EAWSSSEStatus::NOT_SET;
                break;
            }

        switch(awsSSEDescription.GetSSEType()) {
            case Aws::DynamoDB::Model::SSEType::NOT_SET:
                this->SSEType = EAWSSSEType::NOT_SET;
                break;
            case Aws::DynamoDB::Model::SSEType::AES256:
                this->SSEType = EAWSSSEType::AES256;
                break;
            case Aws::DynamoDB::Model::SSEType::KMS:
                this->SSEType = EAWSSSEType::KMS;
                break;
            default:
                this->SSEType = EAWSSSEType::NOT_SET;
                break;
            }

        this->KMSMasterKeyArn = UTF8_TO_TCHAR(awsSSEDescription.GetKMSMasterKeyArn().c_str());

        this->inaccessibleEncryptionDateTime = FDateTime(1970, 1, 1) + FTimespan(awsSSEDescription.GetInaccessibleEncryptionDateTime().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
