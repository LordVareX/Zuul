/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/Cors.h"

#endif


#include "AWSLambdaCors.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaCors {
GENERATED_BODY()

    /**
    *  <p>Whether to allow cookies or other credentials in requests to your function URL. The default is <code>false</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    bool allowCredentials = false;

    /**
    *  <p>The HTTP headers that origins can include in requests to your function URL. For example: <code>Date</code>, <code>Keep-Alive</code>, <code>X-Custom-Header</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FString> allowHeaders;

    /**
    *  <p>The HTTP methods that are allowed when calling your function URL. For example: <code>GET</code>, <code>POST</code>, <code>DELETE</code>, or the wildcard character (<code>*</code>).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FString> allowMethods;

    /**
    *  <p>The origins that can access your function URL. You can list any number of specific origins, separated by a comma. For example: <code>https://www.example.com</code>, <code>http://localhost:60905</code>.</p> <p>Alternatively, you can grant access to all origins using the wildcard character (<code>*</code>).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FString> allowOrigins;

    /**
    *  <p>The HTTP headers in your function response that you want to expose to origins that call your function URL. For example: <code>Date</code>, <code>Keep-Alive</code>, <code>X-Custom-Header</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FString> exposeHeaders;

    /**
    *  <p>The maximum amount of time, in seconds, that web browsers can cache results of a preflight request. By default, this is set to <code>0</code>, which means that the browser doesn't cache results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maxAge = 0;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::Cors toAWS() const {
        Aws::Lambda::Model::Cors awsCors;

        awsCors.SetAllowCredentials(this->allowCredentials);

        for (const FString& elem : this->allowHeaders) {
            awsCors.AddAllowHeaders(TCHAR_TO_UTF8(*elem));
        }

        for (const FString& elem : this->allowMethods) {
            awsCors.AddAllowMethods(TCHAR_TO_UTF8(*elem));
        }

        for (const FString& elem : this->allowOrigins) {
            awsCors.AddAllowOrigins(TCHAR_TO_UTF8(*elem));
        }

        for (const FString& elem : this->exposeHeaders) {
            awsCors.AddExposeHeaders(TCHAR_TO_UTF8(*elem));
        }

        if (!(this->maxAge == 0)) {
            awsCors.SetMaxAge(this->maxAge);
        }

        return awsCors;
    }

    bool IsEmpty() const {
        return false && this->allowHeaders.Num() == 0 && this->allowMethods.Num() == 0 && this->allowOrigins.Num() == 0 && this->exposeHeaders.Num() == 0 && this->maxAge == 0;
    }

    FAWSLambdaCors &fromAWS(const Aws::Lambda::Model::Cors &awsCors) {
        this->allowCredentials = awsCors.GetAllowCredentials();

        this->allowHeaders.Empty();
        for (const Aws::String& elem : awsCors.GetAllowHeaders()) {
            this->allowHeaders.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->allowMethods.Empty();
        for (const Aws::String& elem : awsCors.GetAllowMethods()) {
            this->allowMethods.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->allowOrigins.Empty();
        for (const Aws::String& elem : awsCors.GetAllowOrigins()) {
            this->allowOrigins.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->exposeHeaders.Empty();
        for (const Aws::String& elem : awsCors.GetExposeHeaders()) {
            this->exposeHeaders.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

		this->maxAge = awsCors.GetMaxAge();

        return *this;
    }
#endif
};
