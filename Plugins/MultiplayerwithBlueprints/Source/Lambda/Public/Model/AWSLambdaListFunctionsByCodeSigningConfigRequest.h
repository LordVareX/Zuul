/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListFunctionsByCodeSigningConfigRequest.h"

#endif

#include "AWSLambdaListFunctionsByCodeSigningConfigRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaListFunctionsByCodeSigningConfigRequest {
GENERATED_BODY()

    /**
    *  <p>The The Amazon Resource Name (ARN) of the code signing configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString codeSigningConfigArn;

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
    Aws::Lambda::Model::ListFunctionsByCodeSigningConfigRequest toAWS() const {
        Aws::Lambda::Model::ListFunctionsByCodeSigningConfigRequest awsListFunctionsByCodeSigningConfigRequest;

        if (!(this->codeSigningConfigArn.IsEmpty())) {
            awsListFunctionsByCodeSigningConfigRequest.SetCodeSigningConfigArn(TCHAR_TO_UTF8(*this->codeSigningConfigArn));
        }

        if (!(this->marker.IsEmpty())) {
            awsListFunctionsByCodeSigningConfigRequest.SetMarker(TCHAR_TO_UTF8(*this->marker));
        }

        if (!(this->maxItems == 0)) {
            awsListFunctionsByCodeSigningConfigRequest.SetMaxItems(this->maxItems);
        }

        return awsListFunctionsByCodeSigningConfigRequest;
    }

    bool IsEmpty() const {
        return this->codeSigningConfigArn.IsEmpty() && this->marker.IsEmpty() && this->maxItems == 0;
    }
#endif
};
