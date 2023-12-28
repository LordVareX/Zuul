/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/Filter.h"

#endif

#include "AWSLambdaFilter.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaFilter {
GENERATED_BODY()

    /**
    *  <p> A filter pattern. For more information on the syntax of a filter pattern, see <a href="https://docs.aws.amazon.com/lambda/latest/dg/invocation-eventfiltering.html#filtering-syntax"> Filter rule syntax</a>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString pattern;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::Filter toAWS() const {
        Aws::Lambda::Model::Filter awsFilter;

        if (!(this->pattern.IsEmpty())) {
            awsFilter.SetPattern(TCHAR_TO_UTF8(*this->pattern));
        }

        return awsFilter;
    }

    bool IsEmpty() const {
        return this->pattern.IsEmpty();
    }

    FAWSLambdaFilter &fromAWS(const Aws::Lambda::Model::Filter &awsFilter) {
        this->pattern = UTF8_TO_TCHAR(awsFilter.GetPattern().c_str());

        return *this;
    }
#endif
};
