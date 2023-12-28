// Copyright (c) 2022 King Wai Mark

#pragma once

#include "FBPApp.h"

#if PLATFORM_WINDOWS || PLATFORM_MAC || PLATFORM_ANDROID || PLATFORM_IOS
	#include "firebase/storage.h"
#endif

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FBPStorage.generated.h"


// FBPDeleteFile
DECLARE_DYNAMIC_DELEGATE(FOnFileDeleted);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToDeleteFile, FString, ErrorMessage);

// FBPDownloadFile
DECLARE_DYNAMIC_DELEGATE(FOnDownloaded);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToDownload, FString, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FStorageProgress, int, BytesTransferred, int, TotalBytes);

// FBPUploadFile
DECLARE_DYNAMIC_DELEGATE(FOnUploaded);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToUpload, FString, ErrorMessage);


/**
 *	@author King Wai Mark
 *	@copyright King Wai Mark
 * 
 *	This file contains the class to manipulate Firebase Storage.
 */
UCLASS()
class FBP_API UFBPStorage : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	static firebase::storage::Storage* Storage;
	static firebase::storage::Storage* FBPGetStorage();
	static firebase::storage::StorageReference FBPGetStorageRef(TArray<FString> StoragePath); 
	/**
	 *	Sets the current storage bucket. This is not needed unless you want to use another bucket other than the default one.
	 *
	 *	@param StorageBucket Storage bucket from Firebase
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Storage Bucket", Keywords = "Set Storage Bucket"), Category = "Storage - Firebase Plugin by KWM")
	static void FBPSetStorageBucket(FString StorageBucket);

	/**
	 *	Deletes a file from Storage.
	 *
	 *	Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE(FOnFileDeleted);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToDeleteFile, FString, ErrorMessage);
	 *
	 *	@param StoragePath Path reference to file
	 *	@param OnFileDeleted Callback that will be called when the file is deleted
	 *	@param OnFailToDeleteFile Callback that will be called when it failed to delete the file
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Delete File", Keywords = "Delete File"), Category = "Storage - Firebase Plugin by KWM")
	static void FBPDeleteFile(TArray<FString> StoragePath, const FOnFileDeleted& OnFileDeleted, const FOnFailToDeleteFile& OnFailToDeleteFile);

	/**
	 *	Download a file from Firebase Storage.
	 *
	 *	Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE(FOnDownloaded);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToDownload, FString, ErrorMessage);
	 *		DECLARE_DYNAMIC_DELEGATE_TwoParams(FStorageProgress, int, BytesTransferred, int, TotalBytes);
	 *		
	 *	@param StoragePath Path reference to file
	 *	@param LocalPath Local path where the file will be placed
	 *	@param MaxSize The maximum amount of bytes to download
	 *	@param OnDownloaded Callback that will be called when the file is downloaded
	 *	@param OnFailToDownload Callback that will be called when it failed to download the file.
	 *	@param StorageProgress Callback that will return the progress completed
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Download File", Keywords = "Download File"), Category = "Storage - Firebase Plugin by KWM")
	static void FBPDownloadFile(TArray<FString> StoragePath, FString LocalPath, int64 MaxSize, const FOnDownloaded& OnDownloaded, const FOnFailToDownload& OnFailToDownload);


	/**
	 *	Uploads a file to Storage.
	 *
	 *	Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnUploaded, FString, DownloadUrl);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToUpload, FString, ErrorMessage);
	 *		
	 *	@param LocalFilePath Local path to the file
	 *	@param StoragePath Path to store the file in Firebase Storage
	 *	@param OnUploaded Callback that will be called when the file is uploaded
	 *	@param OnFailToUpload Callback that will be called when it failed to upload the file.
	 *	@param StorageProgress Callback that will return the progress completed
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Upload File", Keywords = "Upload File"), Category = "Storage - Firebase Plugin by KWM")
	static void FBPUploadFile(FString LocalFilePath, TArray<FString> StoragePath, const FOnUploaded& OnUploaded, const FOnFailToUpload& OnFailToUpload);


	/**
	 *	Set the max Download Retry Time in seconds. Defaults to 600 seconds or 10 minutes.
	 *
	 *	@param Seconds
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Max Download Retry Time", Keywords = "Set Max Download Retry Time"), Category = "Storage - Firebase Plugin by KWM")
	static void FBPSetMaxDownloadRetryTime(const int Seconds = 600);
	/**
	 *	Set the max Upload Retry Time in seconds. Defaults to 600 seconds or 10 minutes.
	 *
	 *	@param Seconds
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Max Upload Retry Time", Keywords = "Set Max Upload Retry Time"), Category = "Storage - Firebase Plugin by KWM")
	static void FBPSetMaxUploadRetryTime(const int Seconds = 600);
	/**
	 *	Set the max Operation Retry Time other than upload and download in seconds. Defaults to 120 seconds or 2 minutes.
	 *
	 *	@param Seconds
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Max Operation Retry Time", Keywords = "Set Max Operation Retry Time"), Category = "Storage - Firebase Plugin by KWM")
	static void FBPSetMaxOperationRetryTime(const int Seconds = 120);
};

/**
 *	Class that contains the callback function that manages download progress.
 *
 *	Delegates used:
 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FProgress, float, PercentCompleted);
 *
 *	@author King Wai Mark
 */
class FBPStorageListener : public firebase::storage::Listener {

private:
	FStorageProgress StorageProgress;
	
public:
	FBPStorageListener(FStorageProgress StorageProgress)
	{
		this->StorageProgress = StorageProgress;
	}
	virtual void OnProgress(firebase::storage::Controller* Controller) {
		StorageProgress.ExecuteIfBound(Controller->bytes_transferred(), Controller->total_byte_count());
	}

	virtual void OnPaused(firebase::storage::Controller* controller)
	{
		
	};
};
