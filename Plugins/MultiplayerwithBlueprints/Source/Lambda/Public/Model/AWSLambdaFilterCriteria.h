/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/FilterCriteria.h"

#endif

#include "Model/AWSLambdaFilter.h"

#include "AWSLambdaFilterCriteria.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaFilterCriteria {
GENERATED_BODY()

    /**
    *  <p> A list of filters. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FAWSLambdaFilter> filters;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::FilterCriteria toAWS() const {
        Aws::Lambda::Model::FilterCriteria awsFilterCriteria;

        for (const FAWSLambdaFilter& elem : this->filters) {
            awsFilterCriteria.AddFilters(elem.toAWS());
        }

        return awsFilterCriteria;
    }

    bool IsEmpty() const {
        return this->filters.Num() == 0;
    }

    FAWSLambdaFilterCriteria &fromAWS(const Aws::Lambda::Model::FilterCriteria &awsFilterCriteria) {
        this->filters.Empty();
        for (const Aws::Lambda::Model::Filter& elem : awsFilterCriteria.GetFilters()) {
            this->filters.Add(FAWSLambdaFilter().fromAWS(elem));
        }

        return *this;
    }
#endif
};
