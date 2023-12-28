/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListFunctionsRequest.h"

#endif

#include "Model/FunctionVersion.h"

#include "ListFunctionsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListFunctionsRequest {
GENERATED_BODY()

    /**
    *  <p>For Lambda@Edge functions, the AWS Region of the master function. For example, <code>us-east-2</code> or <code>ALL</code>. If specified, you must set <code>FunctionVersion</code> to <code>ALL</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString masterRegion;

    /**
    *  <p>Set to <code>ALL</code> to include entries for all published versions of each function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSFunctionVersion functionVersion = EAWSFunctionVersion::NOT_SET;

    /**
    *  <p>Specify the pagination token that's returned by a previous request to retrieve the next page of results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString marker;

    /**
    *  <p>Specify a value between 1 and 50 to limit the number of functions in the response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maxItems = 0;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::ListFunctionsRequest toAWS() const {
        Aws::Lambda::Model::ListFunctionsRequest awsListFunctionsRequest;

		if (!(this->masterRegion.IsEmpty())) {
            awsListFunctionsRequest.SetMasterRegion(TCHAR_TO_UTF8(*this->masterRegion));
        }

        switch(this->functionVersion) {
            case EAWSFunctionVersion::ALL:
                awsListFunctionsRequest.SetFunctionVersion(Aws::Lambda::Model::FunctionVersion::ALL);
                break;
            default:
                break;
            }

		if (!(this->marker.IsEmpty())) {
            awsListFunctionsRequest.SetMarker(TCHAR_TO_UTF8(*this->marker));
        }

        if (this->maxItems != 0) {
            awsListFunctionsRequest.SetMaxItems(this->maxItems);
        }

        return awsListFunctionsRequest;
    }

    bool IsEmpty() const {
        return this->masterRegion.IsEmpty() && this->functionVersion == EAWSFunctionVersion::NOT_SET && this->marker.IsEmpty() && this->maxItems == 0;
    }
#endif
};
