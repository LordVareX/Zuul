// Copyright (c) 2022 King Wai Mark


#pragma once


#include "FBPApp.h"

#if PLATFORM_WINDOWS || PLATFORM_MAC || PLATFORM_ANDROID || PLATFORM_IOS
	#include "firebase/database.h"
#endif

#include "Firestore/FBPDataObject.h"

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FBPRealtimeDatabase.generated.h"

// FBPAddData
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnDataAdded, FString, DataId);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToAddData, FString, ErrorMessage);

// FBPGetValue
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnValueReceived, FDocumentSnapshot, DataSnapshot);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToGetValue, FString, ErrorMessage);

// FBPListenToValue
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnValueChanges, FDocumentSnapshot, DataSnapshot);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnCancelValueListener, FString, ErrorMessage);

// FBPDeleteData
DECLARE_DYNAMIC_DELEGATE(FOnDataDeleted);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToDeleteData, FString, ErrorMessage);

/**
 *	This class contains functions that manipulates Firebase Realtime Database.
 *	
 *	@author King Wai Mark
 */
UCLASS()
class FBP_API UFBPRealtimeDatabase : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static firebase::database::Database* RealtimeDatabase;
	static firebase::database::Database* FBPGetDatabase(); 
	static firebase::database::DatabaseReference FBPGenDatabaseReference(const TArray<FString> DataPath);
	static std::map<std::string, firebase::Variant> FBPGenerateMapForData(const TArray<FDataObjectValue> Data);
	static TMap<FString, FDataObjectValue> FBPGenerateDataMap(const firebase::database::DataSnapshot DataSnapshot);
	
	/**
	 *	Adds data to Realtime Database.
	 *
	 *	Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnDataAdded, FString, DataId);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToAddData, FString, ErrorMessage);
	 *		
	 *	@param DataPath Path that the data will be added.
	 *	@param Data Data to add
	 *	@param OnDataAdded Callback that will be called when the data was added to Realtime Database
	 *	@param OnFailToAddData Callback that will be called when it failed to add the data
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Data", Keywords = "Add Data"), Category = "Realtime Database - Firebase Plugin by KWM")
	static void FBPAddData(const TArray<FString> DataPath, const TArray<FDataObjectValue> Data, const FOnDataAdded& OnDataAdded, const FOnFailToAddData& OnFailToAddData);

	/**
	 *	Gets a value from Firebase's Realtime Database
	 *
	 *	Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnValueReceived, FDocumentSnapshot, DataSnapshot);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToGetValue, FString, ErrorMessage);
	 *
	 *		
	 *	@param DataPath Path to the data in Realtime Database
	 *	@param OnValueReceived Callback that will be called when the data is received
	 *	@param OnFailToGetValue Callback that will be called when it failed to get the data in Realtime Database
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Data", Keywords = "Get Data"), Category = "Realtime Database - Firebase Plugin by KWM")
	static void FBPGetData(const TArray<FString> DataPath, const FOnValueReceived& OnValueReceived, const FOnFailToGetValue& OnFailToGetValue);

	/**
	 *	Updates the data in Realtime Database
	 *	
	 *	Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnDataAdded, FString, DataId);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToAddData, FString, ErrorMessage);
	 *		
	 *	@param DataPath Path that the data will be added.
	 *	@param Data Data to add
	 *	@param OnDataUpdated Callback that will be called when the data was updated in Realtime Database
	 *	@param OnFailToUpdateData Callback that will be called when it failed to update the data
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Update Data", Keywords = "Update Data"), Category = "Realtime Database - Firebase Plugin by KWM")
	static void FBPUpdateData(const TArray<FString> DataPath, const TArray<FDataObjectValue> Data, const FOnDataAdded& OnDataUpdated, const FOnFailToAddData& OnFailToUpdateData);

	/**
	 *	Deletes data from Realtime Database
	 *		DECLARE_DYNAMIC_DELEGATE(FOnDataDeleted);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToDeleteData, FString, ErrorMessage);
	 *
	 *	@param DataPath Path to data
	 *	@param OnDataDeleted Callback that will be called when the data is deleted
	 *	@param OnFailToDeleteData Callback that will be called when it fails to delete the data from Realtime Database
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Delete Data", Keywords = "Delete Data"), Category = "Realtime Database - Firebase Plugin by KWM")
	static void FBPDeleteData(const TArray<FString> DataPath, const FOnDataDeleted& OnDataDeleted, const FOnFailToDeleteData& OnFailToDeleteData);
	
	/**
	 *	Adds a listener to a value. Contains callback that will be called when data changes including its children.
	 *
	 *	Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnValueChanges, FDocumentSnapshot, DataSnapshot);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnCancelValueListener, FString, ErrorMessage);
	 *
	 *	@param DataPath Path that the data
	 *	@param OnValueChanged Callback that will be called when the value changes, including its children
	 *	@param OnCancelValueListener Callback that will be called when the ValueListener is cancelled
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Listen to Value", Keywords = "Listen to  Value"), Category = "Realtime Database - Firebase Plugin by KWM")
	static void FBPListenToValue(const TArray<FString> DataPath, const FOnValueChanges& OnValueChanged, const FOnCancelValueListener& OnCancelValueListener);

	/**
	 *	Adds a listener to a child. Contains callback that will be called when data is added, changed, removed, or moved.
	 *
	 *	Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnValueChanges, FDocumentSnapshot, DataSnapshot);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnCancelValueListener, FString, ErrorMessage);
	 *		
	 *
	 *	@param DataPath Path that the data
	 *	@param OnValueAdded Callback that will be called when a child is added
	 *	@param OnValueChanged Callback that will be called when a child's data is modified
	 *	@param OnValueRemoved Callback that will be called when a child is removed
	 *	@param OnValueMoved Callback that will be called when a child is moved
	 *	@param OnCancelValueListener Callback that will be called when the Child Listener is cancelled
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Listen to Child", Keywords = "Listen to  Child"), Category = "Realtime Database - Firebase Plugin by KWM")
	static void FBPListenToChild(const TArray<FString> DataPath, const FOnValueChanges& OnValueAdded, const FOnValueChanges& OnValueChanged, const FOnValueChanges& OnValueRemoved, const FOnValueChanges& OnValueMoved, const FOnCancelValueListener& OnCancelValueListener);


};

/**
 *	This class contains functions that handles state changes for a value.
 *	
 *	@author King Wai Mark
 */
class FBPValueListener : public firebase::database::ValueListener {

private:
	FOnValueChanges OnValueChanges;
	FOnCancelValueListener OnCancelValueListener;
public:
	FBPValueListener(FOnValueChanges OnValueChanges, FOnCancelValueListener OnCancelValueListener)
	{
		this->OnValueChanges = OnValueChanges;
		this->OnCancelValueListener = OnCancelValueListener;
	}
	
	void OnValueChanged(const firebase::database::DataSnapshot& Snapshot) override {
		if(Snapshot.exists())
		{
			FDocumentSnapshot DataSnapshot = FDocumentSnapshot();
			DataSnapshot.Data = UFBPRealtimeDatabase::FBPGenerateDataMap(Snapshot);
			OnValueChanges.ExecuteIfBound(DataSnapshot);
		}
	}
	void OnCancelled(const firebase::database::Error& Error_code,
					 const char* Error_message) override {
		OnCancelValueListener.ExecuteIfBound((FString(Error_message)));
	}
	
};
/**
 *	This class contains functions that handles state changes for a child.
 *	
 *	@author King Wai Mark
 */
class FBPChildListener : public firebase::database::ChildListener {

private:
	FOnValueChanges OnValueAdded;
	FOnValueChanges OnValueChanged;
	FOnValueChanges OnValueRemoved;
	FOnValueChanges OnValueMoved;
	FOnCancelValueListener OnCancelValueListener;

	
public:

	FBPChildListener(FOnValueChanges OnValueAdded, FOnValueChanges OnValueChanged, FOnValueChanges OnValueRemoved, FOnValueChanges OnValueMoved, FOnCancelValueListener OnCancelValueListener)
	{
		this->OnValueAdded = OnValueAdded;
		this->OnValueChanged = OnValueChanged;
		this->OnValueRemoved = OnValueRemoved;
		this->OnValueMoved = OnValueMoved;
		this->OnCancelValueListener = OnCancelValueListener;
	}
	
	void OnChildAdded(const firebase::database::DataSnapshot& Snapshot,
					  const char* Previous_sibling) override {
		FDocumentSnapshot DataSnapshot = FDocumentSnapshot();
		DataSnapshot.Data = UFBPRealtimeDatabase::FBPGenerateDataMap(Snapshot);
		OnValueAdded.ExecuteIfBound(DataSnapshot);

	}
	void OnChildChanged(const firebase::database::DataSnapshot& Snapshot,
						const char* Previous_sibling) override {
		FDocumentSnapshot DataSnapshot = FDocumentSnapshot();
		DataSnapshot.Data = UFBPRealtimeDatabase::FBPGenerateDataMap(Snapshot);
		OnValueChanged.ExecuteIfBound(DataSnapshot);
	}
	void OnChildRemoved(
		const firebase::database::DataSnapshot& Snapshot) override {
		FDocumentSnapshot DataSnapshot = FDocumentSnapshot();
		DataSnapshot.Data = UFBPRealtimeDatabase::FBPGenerateDataMap(Snapshot);
		OnValueRemoved.ExecuteIfBound(DataSnapshot);
	}
	void OnChildMoved(const firebase::database::DataSnapshot& Snapshot,
					  const char* Previous_sibling) override {
		FDocumentSnapshot DataSnapshot = FDocumentSnapshot();
		DataSnapshot.Data = UFBPRealtimeDatabase::FBPGenerateDataMap(Snapshot);
		OnValueMoved.ExecuteIfBound(DataSnapshot);
	}
	void OnCancelled(const firebase::database::Error& Error_code,
					 const char* Error_message) override {
		OnCancelValueListener.ExecuteIfBound((FString(Error_message)));
	}
};

