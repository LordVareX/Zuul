/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/SourceAccessConfiguration.h"

#endif

#include "Model/AWSLambdaSourceAccessType.h"

#include "AWSLambdaSourceAccessConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaSourceAccessConfiguration {
GENERATED_BODY()

    /**
    *  <p>The type of authentication protocol or the VPC components for your event source. For example: <code>"Type":"SASL_SCRAM_512_AUTH"</code>.</p> <ul> <li> <p> <code>BASIC_AUTH</code> - (MQ) The Secrets Manager secret that stores your broker credentials.</p> </li> <li> <p> <code>VPC_SUBNET</code> - The subnets associated with your VPC. Lambda connects to these subnets to fetch data from your Self-Managed Apache Kafka cluster.</p> </li> <li> <p> <code>VPC_SECURITY_GROUP</code> - The VPC security group used to manage access to your Self-Managed Apache Kafka brokers.</p> </li> <li> <p> <code>SASL_SCRAM_256_AUTH</code> - The Secrets Manager ARN of your secret key used for SASL SCRAM-256 authentication of your Self-Managed Apache Kafka brokers.</p> </li> <li> <p> <code>SASL_SCRAM_512_AUTH</code> - The Secrets Manager ARN of your secret key used for SASL SCRAM-512 authentication of your Self-Managed Apache Kafka brokers.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSLambdaSourceAccessType type = EAWSLambdaSourceAccessType::NOT_SET;

    /**
    *  <p>The value for your chosen configuration in <code>Type</code>. For example: <code>"URI": "arn:aws:secretsmanager:us-east-1:01234567890:secret:MyBrokerSecretName"</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString URI;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::SourceAccessConfiguration toAWS() const {
        Aws::Lambda::Model::SourceAccessConfiguration awsSourceAccessConfiguration;

        switch(this->type) {
            case EAWSLambdaSourceAccessType::BASIC_AUTH:
                awsSourceAccessConfiguration.SetType(Aws::Lambda::Model::SourceAccessType::BASIC_AUTH);
                break;
            case EAWSLambdaSourceAccessType::VPC_SUBNET:
                awsSourceAccessConfiguration.SetType(Aws::Lambda::Model::SourceAccessType::VPC_SUBNET);
                break;
            case EAWSLambdaSourceAccessType::VPC_SECURITY_GROUP:
                awsSourceAccessConfiguration.SetType(Aws::Lambda::Model::SourceAccessType::VPC_SECURITY_GROUP);
                break;
            case EAWSLambdaSourceAccessType::SASL_SCRAM_512_AUTH:
                awsSourceAccessConfiguration.SetType(Aws::Lambda::Model::SourceAccessType::SASL_SCRAM_512_AUTH);
                break;
            case EAWSLambdaSourceAccessType::SASL_SCRAM_256_AUTH:
                awsSourceAccessConfiguration.SetType(Aws::Lambda::Model::SourceAccessType::SASL_SCRAM_256_AUTH);
                break;
            case EAWSLambdaSourceAccessType::VIRTUAL_HOST:
                awsSourceAccessConfiguration.SetType(Aws::Lambda::Model::SourceAccessType::VIRTUAL_HOST);
                break;
            case EAWSLambdaSourceAccessType::CLIENT_CERTIFICATE_TLS_AUTH:
                awsSourceAccessConfiguration.SetType(Aws::Lambda::Model::SourceAccessType::CLIENT_CERTIFICATE_TLS_AUTH);
                break;
            case EAWSLambdaSourceAccessType::SERVER_ROOT_CA_CERTIFICATE:
                awsSourceAccessConfiguration.SetType(Aws::Lambda::Model::SourceAccessType::SERVER_ROOT_CA_CERTIFICATE);
                break;
            default:
                break;
        }

        if (!(this->URI.IsEmpty())) {
            awsSourceAccessConfiguration.SetURI(TCHAR_TO_UTF8(*this->URI));
        }

        return awsSourceAccessConfiguration;
    }

    bool IsEmpty() const {
        return type == EAWSLambdaSourceAccessType::NOT_SET && this->URI.IsEmpty();
    }

    FAWSLambdaSourceAccessConfiguration &fromAWS(const Aws::Lambda::Model::SourceAccessConfiguration &awsSourceAccessConfiguration) {
        switch(awsSourceAccessConfiguration.GetType()) {
            case Aws::Lambda::Model::SourceAccessType::NOT_SET:
                this->type = EAWSLambdaSourceAccessType::NOT_SET;
                break;
            case Aws::Lambda::Model::SourceAccessType::BASIC_AUTH:
                this->type = EAWSLambdaSourceAccessType::BASIC_AUTH;
                break;
            case Aws::Lambda::Model::SourceAccessType::VPC_SUBNET:
                this->type = EAWSLambdaSourceAccessType::VPC_SUBNET;
                break;
            case Aws::Lambda::Model::SourceAccessType::VPC_SECURITY_GROUP:
                this->type = EAWSLambdaSourceAccessType::VPC_SECURITY_GROUP;
                break;
            case Aws::Lambda::Model::SourceAccessType::SASL_SCRAM_512_AUTH:
                this->type = EAWSLambdaSourceAccessType::SASL_SCRAM_512_AUTH;
                break;
            case Aws::Lambda::Model::SourceAccessType::SASL_SCRAM_256_AUTH:
                this->type = EAWSLambdaSourceAccessType::SASL_SCRAM_256_AUTH;
                break;
            case Aws::Lambda::Model::SourceAccessType::VIRTUAL_HOST:
                this->type = EAWSLambdaSourceAccessType::VIRTUAL_HOST;
                break;
            case Aws::Lambda::Model::SourceAccessType::CLIENT_CERTIFICATE_TLS_AUTH:
                this->type = EAWSLambdaSourceAccessType::CLIENT_CERTIFICATE_TLS_AUTH;
                break;
            case Aws::Lambda::Model::SourceAccessType::SERVER_ROOT_CA_CERTIFICATE:
                this->type = EAWSLambdaSourceAccessType::SERVER_ROOT_CA_CERTIFICATE;
                break;
            default:
                this->type = EAWSLambdaSourceAccessType::NOT_SET;
                break;
            }

        this->URI = UTF8_TO_TCHAR(awsSourceAccessConfiguration.GetURI().c_str());

        return *this;
    }
#endif
};
