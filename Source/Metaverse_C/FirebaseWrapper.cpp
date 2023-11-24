// Fill out your copyright notice in the Description page of Project Settings.


#include "FirebaseWrapper.h"

UFirebaseWrapper::UFirebaseWrapper()
{
    // Initialize Firebase credentials and URLs
    FirebaseURL = "https://zuul-405809-default-rtdb.asia-southeast1.firebasedatabase.app/";
    FirebaseAPIKey = "AIzaSyAxh665Jbns5KGURI_Hk-h2uX-1f4NrHTA";
}

void UFirebaseWrapper::GetFirebaseData()
{
    TSharedRef<IHttpRequest> Request = CreateRequest(FirebaseURL, TEXT("GET"));
    Request->OnProcessRequestComplete().BindUObject(this, &UFirebaseWrapper::OnGetResponseReceived);
    Request->ProcessRequest();
}

void UFirebaseWrapper::OnGetResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    if (bWasSuccessful && Response.IsValid())
    {
        // Handle successful response - parse JSON data
        FString ResponseStr = Response->GetContentAsString();
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseStr);
        if (FJsonSerializer::Deserialize(Reader, JsonObject))
        {
            // Process JsonObject - extract and use the data
        }
        else
        {
            // Handle JSON deserialization error
        }
    }
    else
    {
        // Handle request failure
    }
}

TSharedRef<IHttpRequest> UFirebaseWrapper::CreateRequest(const FString& Url, const FString& Verb)
{
    TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
    Request->SetURL(Url);
    Request->SetVerb(Verb);

    // Set headers for authentication if needed (using API key)
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    Request->SetHeader(TEXT("Authorization"), FString::Printf(TEXT("Bearer %s"), *FirebaseAPIKey));

    return Request;
}