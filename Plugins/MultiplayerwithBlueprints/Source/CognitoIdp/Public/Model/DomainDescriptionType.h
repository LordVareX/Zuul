/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DomainDescriptionType.h"

#endif

#include "Model/DomainStatusType.h"
#include "Model/CustomDomainConfigType.h"

#include "DomainDescriptionType.generated.h"

USTRUCT(BlueprintType)
struct FDomainDescriptionType {
GENERATED_BODY()

    /**
    *  <p>The user pool ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The AWS account ID for the user pool owner.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString AWSAccountId;

    /**
    *  <p>The domain string.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString domain;

    /**
    *  <p>The S3 bucket where the static files for this domain are stored.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString s3Bucket;

    /**
    *  <p>The ARN of the CloudFront distribution.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString cloudFrontDistribution;

    /**
    *  <p>The app version.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString version;

    /**
    *  <p>The domain status.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EDomainStatusType status = EDomainStatusType::NOT_SET;

    /**
    *  <p>The configuration for a custom domain that hosts the sign-up and sign-in webpages for your application.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FCustomDomainConfigType customDomainConfig;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FDomainDescriptionType &fromAWS(const Aws::CognitoIdentityProvider::Model::DomainDescriptionType &awsDomainDescriptionType) {
        this->userPoolId = UTF8_TO_TCHAR(awsDomainDescriptionType.GetUserPoolId().c_str());

        this->AWSAccountId = UTF8_TO_TCHAR(awsDomainDescriptionType.GetAWSAccountId().c_str());

        this->domain = UTF8_TO_TCHAR(awsDomainDescriptionType.GetDomain().c_str());

        this->s3Bucket = UTF8_TO_TCHAR(awsDomainDescriptionType.GetS3Bucket().c_str());

        this->cloudFrontDistribution = UTF8_TO_TCHAR(awsDomainDescriptionType.GetCloudFrontDistribution().c_str());

        this->version = UTF8_TO_TCHAR(awsDomainDescriptionType.GetVersion().c_str());

        switch(awsDomainDescriptionType.GetStatus()) {
            case Aws::CognitoIdentityProvider::Model::DomainStatusType::NOT_SET:
                this->status = EDomainStatusType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::DomainStatusType::CREATING:
                this->status = EDomainStatusType::CREATING;
                break;
            case Aws::CognitoIdentityProvider::Model::DomainStatusType::DELETING:
                this->status = EDomainStatusType::DELETING;
                break;
            case Aws::CognitoIdentityProvider::Model::DomainStatusType::UPDATING:
                this->status = EDomainStatusType::UPDATING;
                break;
            case Aws::CognitoIdentityProvider::Model::DomainStatusType::ACTIVE:
                this->status = EDomainStatusType::ACTIVE;
                break;
            case Aws::CognitoIdentityProvider::Model::DomainStatusType::FAILED:
                this->status = EDomainStatusType::FAILED;
                break;
            default:
                this->status = EDomainStatusType::NOT_SET;
                break;
        }

        this->customDomainConfig.fromAWS(awsDomainDescriptionType.GetCustomDomainConfig());

        return *this;
    }
#endif
};
