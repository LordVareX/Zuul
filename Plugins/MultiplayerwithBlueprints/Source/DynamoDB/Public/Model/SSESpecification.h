/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/SSESpecification.h"

#endif

#include "Model/SSEType.h"

#include "SSESpecification.generated.h"

USTRUCT(BlueprintType)
struct FSSESpecification {
GENERATED_BODY()

    /**
    *  <p>Indicates whether server-side encryption is done using an AWS managed CMK or an AWS owned CMK. If enabled (true), server-side encryption type is set to <code>KMS</code> and an AWS managed CMK is used (AWS KMS charges apply). If disabled (false) or not specified, server-side encryption is set to AWS owned CMK.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    bool enabled = false;

    /**
    *  <p>Server-side encryption type. The only supported value is:</p> <ul> <li> <p> <code>KMS</code> - Server-side encryption which uses AWS Key Management Service. Key is stored in your account and is managed by AWS KMS (KMS charges apply).</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSSSEType SSEType = EAWSSSEType::NOT_SET;

    /**
    *  <p>The KMS Customer Master Key (CMK) which should be used for the KMS encryption. To specify a CMK, use its key ID, Amazon Resource Name (ARN), alias name, or alias ARN. Note that you should only provide this parameter if the key is different from the default DynamoDB Customer Master Key alias/aws/dynamodb.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString KMSMasterKeyId;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::SSESpecification toAWS() const {
        Aws::DynamoDB::Model::SSESpecification awsSSESpecification;

        awsSSESpecification.SetEnabled(this->enabled);

        switch(this->SSEType) {
            case EAWSSSEType::AES256:
                awsSSESpecification.SetSSEType(Aws::DynamoDB::Model::SSEType::AES256);
                break;
            case EAWSSSEType::KMS:
                awsSSESpecification.SetSSEType(Aws::DynamoDB::Model::SSEType::KMS);
                break;
            default:
                break;
            }

		if (!(this->KMSMasterKeyId.IsEmpty())) {
            awsSSESpecification.SetKMSMasterKeyId(TCHAR_TO_UTF8(*this->KMSMasterKeyId));
        }

        return awsSSESpecification;
    }

    bool IsEmpty() const {
        return false && this->SSEType == EAWSSSEType::NOT_SET && this->KMSMasterKeyId.IsEmpty();
    }

    FSSESpecification &fromAWS(const Aws::DynamoDB::Model::SSESpecification &awsSSESpecification) {
        this->enabled = awsSSESpecification.GetEnabled();

        switch(awsSSESpecification.GetSSEType()) {
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

        this->KMSMasterKeyId = UTF8_TO_TCHAR(awsSSESpecification.GetKMSMasterKeyId().c_str());

        return *this;
    }
#endif
};
