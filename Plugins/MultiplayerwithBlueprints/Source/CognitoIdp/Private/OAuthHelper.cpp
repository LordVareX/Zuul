/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, July 2021
 */

#include "OAuthHelper.h"

#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Misc/Base64.h"
#include "Misc/CString.h"
#include "HttpModule.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Containers/UnrealString.h"
#include "GenericPlatform/GenericPlatformMisc.h"
#include "GenericPlatform/GenericPlatformHttp.h"

#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "LatentActions.h"

#include "CognitoIdpGlobals.h"

class FGetTokenAction : public FPendingLatentAction {
private:
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request;

	bool &success;
	FString &accessToken;
	FString &idToken;
	FString &refreshToken;
	int32 &responseCode;
	FString &errors;

    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetTokenAction(
            bool &success,
            FString cognitoDomain,
            FString scope,
            FString redirectUri,
            FString ClientId,
            FString ClientSecret,
            FString code,
            FString &accessToken,
            FString &idToken,
            FString &refreshToken,
            int32 &responseCode,
            FString &errors,
            const FLatentActionInfo &LatentInfo
    ) :
		    Request(FHttpModule::Get().CreateRequest()),
		    success(success),
		    accessToken(accessToken),
		    idToken(idToken),
		    refreshToken(refreshToken),
		    responseCode(responseCode),
		    errors(errors),
            ExecutionFunction(LatentInfo.ExecutionFunction),
            OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {
        Request->SetVerb("POST");
        Request->SetURL(cognitoDomain + "/oauth2/token");

        FString contentString;
        contentString = contentString
                .Append("grant_type").Append("=").Append(FGenericPlatformHttp::UrlEncode(FString("authorization_code"))).Append("&")
                .Append("scope").Append("=").Append(FGenericPlatformHttp::UrlEncode(scope)).Append("&")
                .Append("redirect_uri").Append("=").Append(FGenericPlatformHttp::UrlEncode(redirectUri)).Append("&")
                .Append("client_id").Append("=").Append(FGenericPlatformHttp::UrlEncode(ClientId)).Append("&")
                .Append("code").Append("=").Append(code);
        Request->SetContentAsString(contentString);

        Request->SetContentAsString(contentString);

        Request->SetHeader(FString("content-type"), FString("application/x-www-form-urlencoded"));
        if (ClientSecret.Len() > 0) {
            Request->SetHeader(FString("Authorization"), FString("Basic ") + FBase64::Encode(ClientId + FString(":") + ClientSecret));
        }

        Request->ProcessRequest();
    }

    void UpdateOperation(FLatentResponse &Response) override {
	    EHttpRequestStatus::Type status = Request->GetStatus();

	    if (status == EHttpRequestStatus::Type::NotStarted) {
		    LOG_COGNITOIDP_WARNING("Get Token is not started...");
		    Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
		    return;
	    }

	    if (status == EHttpRequestStatus::Type::Processing) {
		    Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
		    return;
	    }

	    if (status == EHttpRequestStatus::Type::Failed) {
		    success = false;
		    LOG_COGNITOIDP_WARNING("Get Token failed...");
		    Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		    return;
	    }

	    if (status == EHttpRequestStatus::Type::Failed_ConnectionError) {
		    success = false;
		    LOG_COGNITOIDP_WARNING("connection failed...Please retry later.");
		    Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		    return;
	    }

	    if (status == EHttpRequestStatus::Type::Succeeded) {
		    FHttpResponsePtr httpResponse = Request->GetResponse();
		    success = true;

		    TSharedPtr<FJsonObject> JsonObject;
		    TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<>::Create(httpResponse->GetContentAsString());
		    if (FJsonSerializer::Deserialize(Reader, JsonObject)) {
			    if (JsonObject->HasTypedField<EJson::String>("error")) {
				    errors = JsonObject->GetStringField("error");

				    success = false;
			    }

			    if (JsonObject->HasTypedField<EJson::String>("id_token")) {
				    idToken = JsonObject->GetStringField("id_token");
			    } else {
				    LOG_COGNITOIDP_WARNING("no id_token field in response.");
			    }

			    if (JsonObject->HasTypedField<EJson::String>("access_token")) {
				    accessToken = JsonObject->GetStringField("access_token");
			    } else {
				    LOG_COGNITOIDP_WARNING("no access_token field in response.");
			    }

			    if (JsonObject->HasTypedField<EJson::String>("refresh_token")) {
				    refreshToken = JsonObject->GetStringField("refresh_token");
			    } else {
				    LOG_COGNITOIDP_WARNING("no refresh_token field in response.");
			    }
		    } else {
			    LOG_COGNITOIDP_WARNING("response cannot be deserialized: " + httpResponse->GetContentAsString());

			    success = false;
		    }

		    responseCode = httpResponse->GetResponseCode();

		    Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		    return;
	    }

	    LOG_COGNITOIDP_WARNING("Get Token unknown status...");
	    Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("get token");
    }

#endif
};

void UOAuthHelper::GetToken(
        UObject *WorldContextObject,
        bool &success,
        FString cognitoDomain,
        FString scope,
        FString redirectUri,
        FString ClientId,
        FString ClientSecret,
        FString code,
        FString &accessToken,
        FString &idToken,
        FString &refreshToken,
        int32 &responseCode,
        FString &errors,
        struct FLatentActionInfo LatentInfo
                ) {
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetTokenAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                                             new FGetTokenAction(
                                                     success,
                                                     cognitoDomain,
                                                     scope,
                                                     redirectUri,
                                                     ClientId,
                                                     ClientSecret,
                                                     code,
                                                     accessToken,
                                                     idToken,
                                                     refreshToken,
                                                     responseCode,
                                                     errors,
                                                     LatentInfo
                                             )
            );
        }
    }
    return;
}
