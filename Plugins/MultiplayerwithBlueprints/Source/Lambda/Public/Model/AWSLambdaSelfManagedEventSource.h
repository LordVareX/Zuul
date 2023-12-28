/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/core/utils/json/JsonSerializer.h"
#include "aws/lambda/model/SelfManagedEventSource.h"

#endif

#include "LambdaGlobals.h"
#include "Model/AWSLambdaEndPointType.h"

#include "AWSLambdaSelfManagedEventSource.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaSelfManagedEventSource {
GENERATED_BODY()

    /**
    *  <p>The list of bootstrap servers for your Kafka brokers in the following format: <code>"KAFKA_BOOTSTRAP_SERVERS": ["abc.xyz.com:xxxx","abc2.xyz.com:xxxx"]</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TMap<EAWSLambdaEndPointType, FString> endpoints;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::SelfManagedEventSource toAWS() const {
        Aws::Lambda::Model::SelfManagedEventSource awsSelfManagedEventSource;

        for (const TPair<EAWSLambdaEndPointType, FString>& elem : this->endpoints) {
            switch(elem.Key) {
                case EAWSLambdaEndPointType::KAFKA_BOOTSTRAP_SERVERS:
                    {
                        Aws::Utils::Json::JsonValue json(Aws::String(TCHAR_TO_UTF8(*elem.Value)));
                        if (json.WasParseSuccessful()) {
                            Aws::Utils::Json::JsonView view = json.View();
                            if (view.IsListType()) {
                                Aws::Utils::Array<Aws::Utils::Json::JsonView> array = view.AsArray();
                                Aws::Vector<Aws::String> value;
                                for (int i = 0; i < array.GetLength(); i++) {
                                    const Aws::Utils::Json::JsonView& item = array[i];
                                    value.push_back(item.WriteCompact(false));
                                }
                                awsSelfManagedEventSource.AddEndpoints(Aws::Lambda::Model::EndPointType::KAFKA_BOOTSTRAP_SERVERS, value);
                            } else {
                                LOG_LAMBDA_NORMAL(FString::Printf(TEXT("json is not array. json: %s"), TCHAR_TO_UTF8(*elem.Value)));
                            }
                        } else {
                            LOG_LAMBDA_NORMAL(FString::Printf(TEXT("json parse error. error message is: %s"), json.GetErrorMessage().c_str()));
                        }
                    }
                    break;
                default:
                    break;
            }
        }

        return awsSelfManagedEventSource;
    }

    bool IsEmpty() const {
        return this->endpoints.Num() == 0;
    }

    FAWSLambdaSelfManagedEventSource &fromAWS(const Aws::Lambda::Model::SelfManagedEventSource &awsSelfManagedEventSource) {
        this->endpoints.Empty();
        for (const auto& elem : awsSelfManagedEventSource.GetEndpoints()) {
            Aws::Utils::Array<Aws::Utils::Json::JsonValue> jsonArray1(elem.second.size());
            int i = 0;
            for (const Aws::String& elem1 : elem.second) {
                jsonArray1[i++].AsString(elem1);
            }
            Aws::Utils::Json::JsonValue value;
            value.AsArray(jsonArray1);
            switch(elem.first) {
                case Aws::Lambda::Model::EndPointType::NOT_SET:
                    this->endpoints.Add(EAWSLambdaEndPointType::NOT_SET, UTF8_TO_TCHAR(value.View().WriteReadable().c_str()));
                    break;
                case Aws::Lambda::Model::EndPointType::KAFKA_BOOTSTRAP_SERVERS:
                    this->endpoints.Add(EAWSLambdaEndPointType::KAFKA_BOOTSTRAP_SERVERS, UTF8_TO_TCHAR(value.View().WriteReadable().c_str()));
                    break;
                default:
                    break;
		    }
        }

        return *this;
    }
#endif
};
