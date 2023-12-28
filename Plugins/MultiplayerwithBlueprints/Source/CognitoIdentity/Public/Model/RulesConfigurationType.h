/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/RulesConfigurationType.h"

#endif

#include "Model/MappingRule.h"

#include "RulesConfigurationType.generated.h"

USTRUCT(BlueprintType)
struct FRulesConfigurationType {
GENERATED_BODY()

    /**
    *  <p>An array of rules. You can specify up to 25 rules per identity provider.</p> <p>Rules are evaluated in order. The first one to match specifies the role.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TArray<FMappingRule> rules;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::RulesConfigurationType toAWS() const {
        Aws::CognitoIdentity::Model::RulesConfigurationType awsRulesConfigurationType;

        for (const FMappingRule& elem : this->rules) {
            awsRulesConfigurationType.AddRules(elem.toAWS());
        }

        return awsRulesConfigurationType;
    }

    bool IsEmpty() const {
        return this->rules.Num() == 0;
    }

    FRulesConfigurationType &fromAWS(const Aws::CognitoIdentity::Model::RulesConfigurationType &awsRulesConfigurationType) {
        this->rules.Empty();
        for (const Aws::CognitoIdentity::Model::MappingRule& elem : awsRulesConfigurationType.GetRules()) {
            this->rules.Add(FMappingRule().fromAWS(elem));
        }

        return *this;
    }
#endif
};
