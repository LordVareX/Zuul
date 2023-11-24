// Fill out your copyright notice in the Description page of Project Settings.


#include "FirebaseFunctionLibrary.h"

//UFirebaseFunctionLibrary::UFirebaseFunctionLibrary()
//{
//    // Initialize Firebase credentials and URLs
//    FirebaseURL = "https://zuul-405809-default-rtdb.asia-southeast1.firebasedatabase.app/";
//    FirebaseAPIKey = "AIzaSyAxh665Jbns5KGURI_Hk-h2uX-1f4NrHTA";
//}

void UFirebaseFunctionLibrary::GetFirebaseData(const FString& FirebaseURL, const FString& APIKey)
{
    TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
    Request->SetVerb("GET");
    Request->SetURL(FirebaseURL);
    Request->SetHeader("Authorization", "Bearer " + APIKey);
    Request->OnProcessRequestComplete().BindStatic(&UFirebaseFunctionLibrary::OnGetResponseReceived);
    Request->ProcessRequest();;
}

void UFirebaseFunctionLibrary::OnGetResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    if (bWasSuccessful && Response.IsValid())
    {
        FString ResponseStr = Response->GetContentAsString();
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseStr);
        if (FJsonSerializer::Deserialize(Reader, JsonObject))
        {
            // Handle JsonObject - extract and use the data in Blueprint or raise events/callbacks.
            if (JsonObject.IsValid())
            {
                // Extract values from JsonObject and process them
                FString ExampleValue;
                if (JsonObject->TryGetStringField("Name", ExampleValue))
                {
                    // Use ExampleValue in Blueprint or perform actions
                    UE_LOG(LogTemp, Error, TEXT("%s"), *ExampleValue);
                }
                else
                {
                    // Handle missing or incorrect field
                }
            }
            else
            {
                // Handle empty JsonObject
            }
        }
        else
        {
            // Handle JSON deserialization error.
            UE_LOG(LogTemp, Error, TEXT("Failed to deserialize JSON response."));
            // Raise an event or handle the error in Blueprint.
        }
    }
    else
    {
        // Handle request failure.
        UE_LOG(LogTemp, Error, TEXT("Request failed or response invalid."));
        // Raise an event or handle the error in Blueprint.
    }
}

