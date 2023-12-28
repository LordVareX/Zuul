/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/TokenValidityUnitsType.h"

#endif

#include "Model/TimeUnitsType.h"

#include "TokenValidityUnitsType.generated.h"

USTRUCT(BlueprintType)
struct FTokenValidityUnitsType {
GENERATED_BODY()

    /**
    *  <p> A time unit in “seconds”, “minutes”, “hours” or “days” for the value in AccessTokenValidity, defaults to hours.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EAWSTimeUnitsType accessToken = EAWSTimeUnitsType::NOT_SET;

    /**
    *  <p>A time unit in “seconds”, “minutes”, “hours” or “days” for the value in IdTokenValidity, defaults to hours.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EAWSTimeUnitsType idToken = EAWSTimeUnitsType::NOT_SET;

    /**
    *  <p>A time unit in “seconds”, “minutes”, “hours” or “days” for the value in RefreshTokenValidity, defaults to days.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EAWSTimeUnitsType refreshToken = EAWSTimeUnitsType::NOT_SET;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::TokenValidityUnitsType toAWS() const {
        Aws::CognitoIdentityProvider::Model::TokenValidityUnitsType awsTokenValidityUnitsType;
        
        switch(this->accessToken) {
            case EAWSTimeUnitsType::seconds:
                awsTokenValidityUnitsType.SetAccessToken(Aws::CognitoIdentityProvider::Model::TimeUnitsType::seconds);
                break;
            case EAWSTimeUnitsType::minutes:
                awsTokenValidityUnitsType.SetAccessToken(Aws::CognitoIdentityProvider::Model::TimeUnitsType::minutes);
                break;
            case EAWSTimeUnitsType::hours:
                awsTokenValidityUnitsType.SetAccessToken(Aws::CognitoIdentityProvider::Model::TimeUnitsType::hours);
                break;
            case EAWSTimeUnitsType::days:
                awsTokenValidityUnitsType.SetAccessToken(Aws::CognitoIdentityProvider::Model::TimeUnitsType::days);
                break;
            default:
                break;
        }
            
        switch(this->idToken) {
            case EAWSTimeUnitsType::seconds:
                awsTokenValidityUnitsType.SetIdToken(Aws::CognitoIdentityProvider::Model::TimeUnitsType::seconds);
                break;
            case EAWSTimeUnitsType::minutes:
                awsTokenValidityUnitsType.SetIdToken(Aws::CognitoIdentityProvider::Model::TimeUnitsType::minutes);
                break;
            case EAWSTimeUnitsType::hours:
                awsTokenValidityUnitsType.SetIdToken(Aws::CognitoIdentityProvider::Model::TimeUnitsType::hours);
                break;
            case EAWSTimeUnitsType::days:
                awsTokenValidityUnitsType.SetIdToken(Aws::CognitoIdentityProvider::Model::TimeUnitsType::days);
                break;
            default:
                break;
        }

        switch(this->refreshToken) {
            case EAWSTimeUnitsType::seconds:
                awsTokenValidityUnitsType.SetRefreshToken(Aws::CognitoIdentityProvider::Model::TimeUnitsType::seconds);
                break;
            case EAWSTimeUnitsType::minutes:
                awsTokenValidityUnitsType.SetRefreshToken(Aws::CognitoIdentityProvider::Model::TimeUnitsType::minutes);
                break;
            case EAWSTimeUnitsType::hours:
                awsTokenValidityUnitsType.SetRefreshToken(Aws::CognitoIdentityProvider::Model::TimeUnitsType::hours);
                break;
            case EAWSTimeUnitsType::days:
                awsTokenValidityUnitsType.SetRefreshToken(Aws::CognitoIdentityProvider::Model::TimeUnitsType::days);
                break;
            default:
                break;
        }

        return awsTokenValidityUnitsType;
    }

    bool IsEmpty() const {
        return accessToken == EAWSTimeUnitsType::NOT_SET && idToken == EAWSTimeUnitsType::NOT_SET && refreshToken == EAWSTimeUnitsType::NOT_SET;
    }

    FTokenValidityUnitsType &fromAWS(const Aws::CognitoIdentityProvider::Model::TokenValidityUnitsType &awsTokenValidityUnitsType) {
        switch(awsTokenValidityUnitsType.GetAccessToken()) {
            case Aws::CognitoIdentityProvider::Model::TimeUnitsType::NOT_SET:
                this->accessToken = EAWSTimeUnitsType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::TimeUnitsType::seconds:
                this->accessToken = EAWSTimeUnitsType::seconds;
                break;
            case Aws::CognitoIdentityProvider::Model::TimeUnitsType::minutes:
                this->accessToken = EAWSTimeUnitsType::minutes;
                break;
            case Aws::CognitoIdentityProvider::Model::TimeUnitsType::hours:
                this->accessToken = EAWSTimeUnitsType::hours;
                break;
            case Aws::CognitoIdentityProvider::Model::TimeUnitsType::days:
                this->accessToken = EAWSTimeUnitsType::days;
                break;
            default:
                this->accessToken = EAWSTimeUnitsType::NOT_SET;
                break;
        }


        switch(awsTokenValidityUnitsType.GetIdToken()) {
            case Aws::CognitoIdentityProvider::Model::TimeUnitsType::NOT_SET:
                this->idToken = EAWSTimeUnitsType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::TimeUnitsType::seconds:
                this->idToken = EAWSTimeUnitsType::seconds;
                break;
            case Aws::CognitoIdentityProvider::Model::TimeUnitsType::minutes:
                this->idToken = EAWSTimeUnitsType::minutes;
                break;
            case Aws::CognitoIdentityProvider::Model::TimeUnitsType::hours:
                this->idToken = EAWSTimeUnitsType::hours;
                break;
            case Aws::CognitoIdentityProvider::Model::TimeUnitsType::days:
                this->idToken = EAWSTimeUnitsType::days;
                break;
            default:
                this->idToken = EAWSTimeUnitsType::NOT_SET;
                break;
        }

        switch(awsTokenValidityUnitsType.GetRefreshToken()) {
            case Aws::CognitoIdentityProvider::Model::TimeUnitsType::NOT_SET:
                this->refreshToken = EAWSTimeUnitsType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::TimeUnitsType::seconds:
                this->refreshToken = EAWSTimeUnitsType::seconds;
                break;
            case Aws::CognitoIdentityProvider::Model::TimeUnitsType::minutes:
                this->refreshToken = EAWSTimeUnitsType::minutes;
                break;
            case Aws::CognitoIdentityProvider::Model::TimeUnitsType::hours:
                this->refreshToken = EAWSTimeUnitsType::hours;
                break;
            case Aws::CognitoIdentityProvider::Model::TimeUnitsType::days:
                this->refreshToken = EAWSTimeUnitsType::days;
                break;
            default:
                this->refreshToken = EAWSTimeUnitsType::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
