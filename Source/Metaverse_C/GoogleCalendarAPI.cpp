// Fill out your copyright notice in the Description page of Project Settings.


#include "GoogleCalendarAPI.h"
#include "HttpModule.h"

FString UGoogleCalendarAPI::ClientID = "374383116907-hqnt573rrrrh0k5g6odf2otmje1pfmv1.apps.googleusercontent.com";
FString UGoogleCalendarAPI::ClientSecret = "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";
FString UGoogleCalendarAPI::RedirectURI = "http://localhost/";
FString UGoogleCalendarAPI::AuthorizationCode = "";
FString UGoogleCalendarAPI::AccessToken = "";

void UGoogleCalendarAPI::AuthenticateAndFetchCalendar() {
    OpenGoogleAuthorizationPage();
}

void UGoogleCalendarAPI::OpenGoogleAuthorizationPage() {
    FString AuthURL = FString::Printf(TEXT("https://accounts.google.com/o/oauth2/auth?client_id=%s&redirect_uri=%s&response_type=code&scope=https://www.googleapis.com/auth/calendar.readonly"), *ClientID, *RedirectURI);

    //FWebBrowserModule& WebBrowserModule = FWebBrowserModule::Get();
    //IWebBrowserWidget::Create(WebBrowserModule.Get(), nullptr, AuthURL, false, FLinearColor::White);
}

void UGoogleCalendarAPI::ExchangeAuthorizationCodeForAccessToken() {
    // Construct URL for token exchange
    FString TokenExchangeURL = "https://oauth2.googleapis.com/token";
    TSharedRef<IHttpRequest> TokenExchangeRequest = FHttpModule::Get().CreateRequest();
    TokenExchangeRequest->SetVerb("POST");
    TokenExchangeRequest->SetURL(TokenExchangeURL);

    // Construct request body
    FString RequestBody = FString::Printf(TEXT("code=%s&client_id=%s&client_secret=%s&redirect_uri=%s&grant_type=authorization_code"), *AuthorizationCode, *ClientID, *ClientSecret, *RedirectURI);
    TokenExchangeRequest->SetContentAsString(RequestBody);
    TokenExchangeRequest->SetHeader(TEXT("Content-Type"), TEXT("application/x-www-form-urlencoded"));

    // Bind the response callback
    TokenExchangeRequest->OnProcessRequestComplete().BindStatic(&UGoogleCalendarAPI::OnAccessTokenResponse);

    // Send the request
    TokenExchangeRequest->ProcessRequest();
}

void UGoogleCalendarAPI::OnAccessTokenResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
    if (bWasSuccessful && Response.IsValid()) {
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
        if (FJsonSerializer::Deserialize(Reader, JsonObject)) {
            AccessToken = JsonObject->GetStringField("access_token");

            FetchCalendarData();
        }
    }
    else {
        UE_LOG(LogTemp, Error, TEXT("Failed to exchange authorization code for access token!"));
    }
}

void UGoogleCalendarAPI::FetchCalendarData() {
    FString CalendarAPIURL = "https://www.googleapis.com/calendar/v3/calendars/primary/events";
    FString AuthHeader = "Authorization: Bearer " + AccessToken;

    TSharedRef<IHttpRequest> CalendarDataRequest = FHttpModule::Get().CreateRequest();
    CalendarDataRequest->SetVerb("GET");
    CalendarDataRequest->SetURL(CalendarAPIURL);
    CalendarDataRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    CalendarDataRequest->SetHeader(TEXT("Authorization"), *AuthHeader);

    CalendarDataRequest->OnProcessRequestComplete().BindStatic(&UGoogleCalendarAPI::OnCalendarDataResponse);
    CalendarDataRequest->ProcessRequest();
}

void UGoogleCalendarAPI::OnCalendarDataResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
    if (bWasSuccessful && Response.IsValid()) {
        FString CalendarData = Response->GetContentAsString();

        // Process calendar data here
        // For example, parse the CalendarData JSON
    }
    else {
        UE_LOG(LogTemp, Error, TEXT("Failed to fetch calendar data!"));
    }
}