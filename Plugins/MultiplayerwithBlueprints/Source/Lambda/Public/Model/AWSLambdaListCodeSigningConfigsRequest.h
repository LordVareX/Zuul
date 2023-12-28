/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListCodeSigningConfigsRequest.h"

#endif

#include "AWSLambdaListCodeSigningConfigsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaListCodeSigningConfigsRequest {
GENERATED_BODY()

    /**
    *  <p>Specify the pagination token that's returned by a previous request to retrieve the next page of results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString marker;

    /**
    *  <p>Maximum number of items to return.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maxItems = 0;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::ListCodeSigningConfigsRequest toAWS() const {
        Aws::Lambda::Model::ListCodeSigningConfigsRequest awsListCodeSigningConfigsRequest;

        if (!(this->marker.IsEmpty())) {
            awsListCodeSigningConfigsRequest.SetMarker(TCHAR_TO_UTF8(*this->marker));
        }

        if (!(this->maxItems == 0)) {
            awsListCodeSigningConfigsRequest.SetMaxItems(this->maxItems);
        }

        return awsListCodeSigningConfigsRequest;
    }

    bool IsEmpty() const {
        return this->marker.IsEmpty() && this->maxItems == 0;
    }
#endif
};
