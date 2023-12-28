// Copyright (c) 2022 King Wai Mark

#include "Storage/FBPStorage.h"
#include "Misc/FileHelper.h"

firebase::storage::Storage* UFBPStorage::Storage = nullptr;

firebase::storage::Storage* UFBPStorage::FBPGetStorage()
{
	firebase::App* App = UFBPApp::FBPGet();
	if(UFBPStorage::Storage == nullptr && App != nullptr)
	{
		UFBPStorage::Storage = firebase::storage::Storage::GetInstance(App);
	}
	return UFBPStorage::Storage;
}
firebase::storage::StorageReference UFBPStorage::FBPGetStorageRef(TArray<FString> StoragePath)
{
	FString PathStr = "";
	for(int i = 0; i < StoragePath.Num(); i++)
	{
		if(i == StoragePath.Num() - 1)
		{
			PathStr.Append(StoragePath[i]);
		}
		else
		{
			PathStr.Append(StoragePath[i].Append("/"));
		}
	}
	if(PathStr.StartsWith("gs://"))
	{
		return FBPGetStorage()->GetReferenceFromUrl(TCHAR_TO_UTF8(*PathStr));
	}
	else if(PathStr.StartsWith("https://firebasestorage.googleapis.com"))
	{
		FString* Left = new FString("");
		FString* Right = new FString("");
		PathStr.Split("?", Left, Right);
		const FString Str = *Left;
		return FBPGetStorage()->GetReferenceFromUrl(TCHAR_TO_UTF8(*Str));
	}
	else
	{
		return FBPGetStorage()->GetReference(TCHAR_TO_UTF8(*PathStr));
	}
}


void UFBPStorage::FBPSetStorageBucket(FString StorageBucket)
{
	firebase::App* App = UFBPApp::FBPGet();
	if(App != nullptr)
	{
		UFBPStorage::Storage = firebase::storage::Storage::GetInstance(UFBPApp::FBPGet(), TCHAR_TO_UTF8(*StorageBucket));
	}
}

void UFBPStorage::FBPDeleteFile(TArray<FString> StoragePath, const FOnFileDeleted& OnFileDeleted, const FOnFailToDeleteFile& OnFailToDeleteFile)
{
	#if PLATFORM_ANDROID || PLATFORM_MAC || PLATFORM_IOS
	FBPGetStorage();
	if(UFBPFileUtilities::HasGoogleFile)
	{

		firebase::storage::StorageReference StorageReference = FBPGetStorageRef(StoragePath);
		StorageReference.Delete().OnCompletion(
		[OnFailToDeleteFile, OnFileDeleted](const firebase::Future<void>& Result)
		{
			if(Result.error())
			{
				OnFailToDeleteFile.ExecuteIfBound(FString("Error Deleting File..."));
			}
			else
			{
				OnFileDeleted.ExecuteIfBound();
			}
		}
		);

	}
#elif PLATFORM_WINDOWS
	FBPGetStorage();
	if (UFBPFileUtilities::HasGoogleFile)
	{

		firebase::storage::StorageReference StorageReference = FBPGetStorageRef(StoragePath);
		StorageReference.Delete().Await(60 * 1000);
		firebase::Future<void> Result =
			StorageReference.DeleteLastResult();

		if (Result.status() == firebase::kFutureStatusComplete) {
			if (Result.error() == firebase::storage::kErrorNone) {
				OnFileDeleted.ExecuteIfBound();
			}
			else {
				OnFailToDeleteFile.ExecuteIfBound("Failed to download file.");

			}
		}
	}
#endif

}

void UFBPStorage::FBPDownloadFile(TArray<FString> StoragePath, FString LocalPath, int64 MaxSize, const FOnDownloaded& OnDownloaded,
                                  const FOnFailToDownload& OnFailToDownload)
{		
	#if PLATFORM_ANDROID || PLATFORM_MAC || PLATFORM_IOS
	FBPGetStorage();
	if (UFBPFileUtilities::HasGoogleFile)
	{
		firebase::storage::Controller Controller;
		firebase::storage::StorageReference StorageReference = FBPGetStorageRef(StoragePath);
		uint8* Buffer = new uint8[MaxSize];
		StorageReference.GetBytes(Buffer, MaxSize).OnCompletion(
						[OnDownloaded, OnFailToDownload, LocalPath, Buffer, MaxSize](const firebase::Future<size_t>& Result)
						{
							if(Result.error() != firebase::storage::kErrorNone)
							{
								OnFailToDownload.ExecuteIfBound(Result.error_message());
							}
							else
							{
								const size_t SizeOfFile = *Result.result();
								// Extract contents from buffer
								TArray<uint8> ByteArray = TArray<uint8>(Buffer, FGenericPlatformMath::Min(MaxSize, (int64) SizeOfFile));


								// Save the array to file using FFileHelper::SaveArrayToFile()
								bool SuccessfullyCreatedFile = FFileHelper::SaveArrayToFile(ByteArray, *LocalPath);
								if (SuccessfullyCreatedFile)
								{
									OnDownloaded.ExecuteIfBound();
								}
								else
								{
									OnFailToDownload.ExecuteIfBound("Failed to download file.");
								}	
								
							}
						});
		
	}
	#elif PLATFORM_WINDOWS
	FBPGetStorage();
	if (UFBPFileUtilities::HasGoogleFile)
	{
		firebase::storage::StorageReference StorageReference = FBPGetStorageRef(StoragePath);
		StorageReference.GetFile(
			TCHAR_TO_UTF8(*LocalPath)
		).Await(60 * 1000 * 20);
		firebase::Future<size_t> Result =
			StorageReference.GetFileLastResult();

		if (Result.status() == firebase::kFutureStatusComplete) {
			if (Result.error() == firebase::storage::kErrorNone) {
				OnDownloaded.ExecuteIfBound();
			}
			else {
				OnFailToDownload.ExecuteIfBound("Failed to download file.");

			}
		}

	}
	#endif
}
void UFBPStorage::FBPUploadFile(FString LocalFilePath, TArray<FString> StoragePath, const FOnUploaded& OnUploaded,
	const FOnFailToUpload& OnFailToUpload)
{

	#if PLATFORM_ANDROID || PLATFORM_MAC || PLATFORM_IOS || PLATFORM_WINDOWS
	FBPGetStorage();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::storage::StorageReference StorageReference = FBPGetStorageRef(StoragePath);
		FString LocalFilePathPrefixed = "";

#if PLATFORM_ANDROID
		LocalFilePathPrefixed.Append("file:///");
#endif
		LocalFilePathPrefixed.Append(LocalFilePath);
#if PLATFORM_ANDROID || PLATFORM_WINDOWS || PLATFORM_MAC
		char* Destination = new char[LocalFilePath.Len() + 1];
		FCStringAnsi::Strcpy(Destination, LocalFilePath.Len() + 1, TCHAR_TO_UTF8(*LocalFilePathPrefixed));
		StorageReference.PutFile(Destination).OnCompletion(
			[OnUploaded, OnFailToUpload](const firebase::Future<firebase::storage::Metadata>& Result)
			{
				if(Result.error())
				{
					/*FString ErrorMessage = "[Error Code ";
					ErrorMessage.Append(std::to_string(Result.error()).c_str())
					.Append("] ")
					.Append(Result.error_message());*/
					OnFailToUpload.ExecuteIfBound("Error uploading file...");
				}
				else
				{
					OnUploaded.ExecuteIfBound();
					/*Result.result()->GetReference().GetDownloadUrl().OnCompletion(
						[OnUploaded](const firebase::Future<std::string>& DownloadUrl)
						{
							
						});*/
				
				}
			}
		);
#elif PLATFORM_IOS
		TArray<uint8> FileData;
		if (FFileHelper::LoadFileToArray(FileData, *LocalFilePathPrefixed))
		{
			StorageReference.PutBytes(FileData.GetData(), FileData.Num()).OnCompletion(
			[OnUploaded, OnFailToUpload](const firebase::Future<firebase::storage::Metadata>& Result)
			{
				if(Result.error() != firebase::storage::kErrorNone)
				{
					/*FString ErrorMessage = "[Error Code ";
					ErrorMessage.Append(std::to_string(Result.error()).c_str())
					.Append("] ")
					.Append(Result.error_message());*/
					OnFailToUpload.ExecuteIfBound("Error uploading file...");
				}
				else
				{
					OnUploaded.ExecuteIfBound();
					
				}
			}
		);
		}
		else
		{
			OnFailToUpload.ExecuteIfBound(FString("Failed to load file: ").Append(LocalFilePathPrefixed));
		}

#endif
	}

#endif
	
}

void UFBPStorage::FBPSetMaxDownloadRetryTime(const int Seconds)
{
#if PLATFORM_ANDROID || PLATFORM_MAC || PLATFORM_IOS
	firebase::storage::Storage* StorageRef = FBPGetStorage();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		StorageRef->set_max_download_retry_time(Seconds);
	}
#endif
	
}

void UFBPStorage::FBPSetMaxUploadRetryTime(const int Seconds)
{
#if PLATFORM_ANDROID || PLATFORM_MAC || PLATFORM_IOS
	firebase::storage::Storage* StorageRef = FBPGetStorage();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		StorageRef->set_max_upload_retry_time(Seconds);
	}
#endif
}

void UFBPStorage::FBPSetMaxOperationRetryTime(const int Seconds)
{
#if PLATFORM_ANDROID || PLATFORM_MAC || PLATFORM_IOS
	firebase::storage::Storage* StorageRef = FBPGetStorage();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		StorageRef->set_max_operation_retry_time(Seconds);
	}
#endif
}

