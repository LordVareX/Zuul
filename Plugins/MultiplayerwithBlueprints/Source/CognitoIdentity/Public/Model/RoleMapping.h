/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/RoleMapping.h"

#endif

#include "Model/RoleMappingType.h"
#include "Model/AmbiguousRoleResolutionType.h"
#include "Model/RulesConfigurationType.h"

#include "RoleMapping.generated.h"

USTRUCT(BlueprintType)
struct FRoleMapping {
GENERATED_BODY()

    /**
    *  <p>The role mapping type. Token will use <code>cognito:roles</code> and <code>cognito:preferred_role</code> claims from the Cognito identity provider token to map groups to roles. Rules will attempt to match claims from the token to map to a role.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    ERoleMappingType type = ERoleMappingType::NOT_SET;

    /**
    *  <p>If you specify Token or Rules as the <code>Type</code>, <code>AmbiguousRoleResolution</code> is required.</p> <p>Specifies the action to be taken if either no rules match the claim value for the <code>Rules</code> type, or there is no <code>cognito:preferred_role</code> claim and there are multiple <code>cognito:roles</code> matches for the <code>Token</code> type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    EAmbiguousRoleResolutionType ambiguousRoleResolution = EAmbiguousRoleResolutionType::NOT_SET;

    /**
    *  <p>The rules to be used for mapping users to roles.</p> <p>If you specify Rules as the role mapping type, <code>RulesConfiguration</code> is required.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FRulesConfigurationType rulesConfiguration;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::RoleMapping toAWS() const {
        Aws::CognitoIdentity::Model::RoleMapping awsRoleMapping;

        switch(this->type) {
            case ERoleMappingType::Token:
                awsRoleMapping.SetType(Aws::CognitoIdentity::Model::RoleMappingType::Token);
                break;
            case ERoleMappingType::Rules:
                awsRoleMapping.SetType(Aws::CognitoIdentity::Model::RoleMappingType::Rules);
                break;
            default:
               break;
        }

        switch(this->ambiguousRoleResolution) {
            case EAmbiguousRoleResolutionType::AuthenticatedRole:
                awsRoleMapping.SetAmbiguousRoleResolution(Aws::CognitoIdentity::Model::AmbiguousRoleResolutionType::AuthenticatedRole);
                break;
            case EAmbiguousRoleResolutionType::Deny:
                awsRoleMapping.SetAmbiguousRoleResolution(Aws::CognitoIdentity::Model::AmbiguousRoleResolutionType::Deny);
                break;
            default:
                break;
        }

        if (!(this->rulesConfiguration.IsEmpty())) {
            awsRoleMapping.SetRulesConfiguration(this->rulesConfiguration.toAWS());
        }


        return awsRoleMapping;
    }

    bool IsEmpty() const {
        return this->type == ERoleMappingType::NOT_SET && this->ambiguousRoleResolution == EAmbiguousRoleResolutionType::NOT_SET && this->rulesConfiguration.IsEmpty();
    }

    FRoleMapping &fromAWS(const Aws::CognitoIdentity::Model::RoleMapping &awsRoleMapping) {
        switch(awsRoleMapping.GetType()) {
            case Aws::CognitoIdentity::Model::RoleMappingType::NOT_SET:
                this->type = ERoleMappingType::NOT_SET;
                break;
            case Aws::CognitoIdentity::Model::RoleMappingType::Token:
                this->type = ERoleMappingType::Token;
                break;
            case Aws::CognitoIdentity::Model::RoleMappingType::Rules:
                this->type = ERoleMappingType::Rules;
                break;
            default:
                this->type = ERoleMappingType::NOT_SET;
                break;
        }

        switch(awsRoleMapping.GetAmbiguousRoleResolution()) {
            case Aws::CognitoIdentity::Model::AmbiguousRoleResolutionType::NOT_SET:
                this->ambiguousRoleResolution = EAmbiguousRoleResolutionType::NOT_SET;
                break;
            case Aws::CognitoIdentity::Model::AmbiguousRoleResolutionType::AuthenticatedRole:
                this->ambiguousRoleResolution = EAmbiguousRoleResolutionType::AuthenticatedRole;
                break;
            case Aws::CognitoIdentity::Model::AmbiguousRoleResolutionType::Deny:
                this->ambiguousRoleResolution = EAmbiguousRoleResolutionType::Deny;
                break;
            default:
                this->ambiguousRoleResolution = EAmbiguousRoleResolutionType::NOT_SET;
                break;
        }

        this->rulesConfiguration.fromAWS(awsRoleMapping.GetRulesConfiguration());

        return *this;
    }
#endif
};
