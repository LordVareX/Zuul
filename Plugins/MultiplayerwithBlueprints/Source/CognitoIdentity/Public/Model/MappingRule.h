/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/MappingRule.h"

#endif

#include "Model/MappingRuleMatchType.h"

#include "MappingRule.generated.h"

USTRUCT(BlueprintType)
struct FMappingRule {
GENERATED_BODY()

    /**
    *  <p>The claim name that must be present in the token, for example, "isAdmin" or "paid".</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString claim;

    /**
    *  <p>The match condition that specifies how closely the claim value in the IdP token must match <code>Value</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    EMappingRuleMatchType matchType = EMappingRuleMatchType::NOT_SET;

    /**
    *  <p>A brief string that the claim must match, for example, "paid" or "yes".</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString value;

    /**
    *  <p>The role ARN.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString roleARN;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::MappingRule toAWS() const {
        Aws::CognitoIdentity::Model::MappingRule awsMappingRule;

        if (!(this->claim.IsEmpty())) {
            awsMappingRule.SetClaim(TCHAR_TO_UTF8(*this->claim));
        }

        switch(this->matchType) {
            case EMappingRuleMatchType::Equals:
                awsMappingRule.SetMatchType(Aws::CognitoIdentity::Model::MappingRuleMatchType::Equals);
                break;
            case EMappingRuleMatchType::Contains:
                awsMappingRule.SetMatchType(Aws::CognitoIdentity::Model::MappingRuleMatchType::Contains);
                break;
            case EMappingRuleMatchType::StartsWith:
                awsMappingRule.SetMatchType(Aws::CognitoIdentity::Model::MappingRuleMatchType::StartsWith);
                break;
            case EMappingRuleMatchType::NotEqual:
                awsMappingRule.SetMatchType(Aws::CognitoIdentity::Model::MappingRuleMatchType::NotEqual);
                break;
            default:
                break;
        }

        if (!(this->value.IsEmpty())) {
            awsMappingRule.SetValue(TCHAR_TO_UTF8(*this->value));
        }

        if (!(this->roleARN.IsEmpty())) {
            awsMappingRule.SetRoleARN(TCHAR_TO_UTF8(*this->roleARN));
        }

        return awsMappingRule;
    }

    bool IsEmpty() const {
        return this->claim.IsEmpty() && this->matchType == EMappingRuleMatchType::NOT_SET && this->value.IsEmpty() && this->roleARN.IsEmpty();
    }

    FMappingRule &fromAWS(const Aws::CognitoIdentity::Model::MappingRule &awsMappingRule) {
        this->claim = UTF8_TO_TCHAR(awsMappingRule.GetClaim().c_str());

        switch(awsMappingRule.GetMatchType()) {
            case Aws::CognitoIdentity::Model::MappingRuleMatchType::NOT_SET:
                this->matchType = EMappingRuleMatchType::NOT_SET;
                break;
            case Aws::CognitoIdentity::Model::MappingRuleMatchType::Equals:
                this->matchType = EMappingRuleMatchType::Equals;
                break;
            case Aws::CognitoIdentity::Model::MappingRuleMatchType::Contains:
                this->matchType = EMappingRuleMatchType::Contains;
                break;
            case Aws::CognitoIdentity::Model::MappingRuleMatchType::StartsWith:
                this->matchType = EMappingRuleMatchType::StartsWith;
                break;
            case Aws::CognitoIdentity::Model::MappingRuleMatchType::NotEqual:
                this->matchType = EMappingRuleMatchType::NotEqual;
                break;
            default:
                this->matchType = EMappingRuleMatchType::NOT_SET;
                break;
        }

        this->value = UTF8_TO_TCHAR(awsMappingRule.GetValue().c_str());

        this->roleARN = UTF8_TO_TCHAR(awsMappingRule.GetRoleARN().c_str());

        return *this;
    }
#endif
};
