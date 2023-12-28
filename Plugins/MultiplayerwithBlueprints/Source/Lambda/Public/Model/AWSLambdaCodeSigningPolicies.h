/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/CodeSigningPolicies.h"

#endif

#include "Model/AWSLambdaCodeSigningPolicy.h"

#include "AWSLambdaCodeSigningPolicies.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaCodeSigningPolicies {
GENERATED_BODY()

    /**
    *  <p>Code signing configuration policy for deployment validation failure. If you set the policy to <code>Enforce</code>, Lambda blocks the deployment request if signature validation checks fail. If you set the policy to <code>Warn</code>, Lambda allows the deployment and creates a CloudWatch log. </p> <p>Default value: <code>Warn</code> </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSLambdaCodeSigningPolicy untrustedArtifactOnDeployment = EAWSLambdaCodeSigningPolicy::NOT_SET;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::CodeSigningPolicies toAWS() const {
        Aws::Lambda::Model::CodeSigningPolicies awsCodeSigningPolicies;

        switch(this->untrustedArtifactOnDeployment) {
            case EAWSLambdaCodeSigningPolicy::Warn:
                awsCodeSigningPolicies.SetUntrustedArtifactOnDeployment(Aws::Lambda::Model::CodeSigningPolicy::Warn);
                break;
            case EAWSLambdaCodeSigningPolicy::Enforce:
                awsCodeSigningPolicies.SetUntrustedArtifactOnDeployment(Aws::Lambda::Model::CodeSigningPolicy::Enforce);
                break;
            default:
                break;
        }

        return awsCodeSigningPolicies;
    }

    bool IsEmpty() const {
        return untrustedArtifactOnDeployment == EAWSLambdaCodeSigningPolicy::NOT_SET;
    }

    FAWSLambdaCodeSigningPolicies &fromAWS(const Aws::Lambda::Model::CodeSigningPolicies &awsCodeSigningPolicies) {
        switch(awsCodeSigningPolicies.GetUntrustedArtifactOnDeployment()) {
            case Aws::Lambda::Model::CodeSigningPolicy::NOT_SET:
                this->untrustedArtifactOnDeployment = EAWSLambdaCodeSigningPolicy::NOT_SET;
                break;
            case Aws::Lambda::Model::CodeSigningPolicy::Warn:
                this->untrustedArtifactOnDeployment = EAWSLambdaCodeSigningPolicy::Warn;
                break;
            case Aws::Lambda::Model::CodeSigningPolicy::Enforce:
                this->untrustedArtifactOnDeployment = EAWSLambdaCodeSigningPolicy::Enforce;
                break;
            default:
                this->untrustedArtifactOnDeployment = EAWSLambdaCodeSigningPolicy::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
