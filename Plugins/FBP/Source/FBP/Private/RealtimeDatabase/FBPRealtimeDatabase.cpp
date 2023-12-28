// Copyright (c) 2022 King Wai Mark
#include "RealtimeDatabase/FBPRealtimeDatabase.h"



firebase::database::Database* UFBPRealtimeDatabase::RealtimeDatabase = nullptr;

firebase::database::Database* UFBPRealtimeDatabase::FBPGetDatabase()
{
	firebase::App* App = UFBPApp::FBPGet();
	if(UFBPRealtimeDatabase::RealtimeDatabase == nullptr && App != nullptr)
	{
		UFBPRealtimeDatabase::RealtimeDatabase = firebase::database::Database::GetInstance(App);
	}
	return UFBPRealtimeDatabase::RealtimeDatabase;
	
}

firebase::database::DatabaseReference UFBPRealtimeDatabase::FBPGenDatabaseReference(const TArray<FString> DataPath)
{
	firebase::database::DatabaseReference DatabaseRef = FBPGetDatabase()->GetReference();
	for (FString Path : DataPath)
	{
		if(Path.Len() > 0)
		{
			DatabaseRef = DatabaseRef.Child(TCHAR_TO_UTF8(*Path));
		}
		else
		{
			DatabaseRef = DatabaseRef.PushChild();
		}
	}

	return DatabaseRef;
}

std::map<std::string, firebase::Variant> UFBPRealtimeDatabase::FBPGenerateMapForData(const TArray<FDataObjectValue> Data)
{
	std::map<std::string, firebase::Variant> Map;
	for (FDataObjectValue D : Data)
	{
		std::vector<firebase::Variant> arr(D.ArrayVal.Num());
		int counter = 0;
		switch (D.Type)
		{
		case FDataObjectValue::String:
			Map[TCHAR_TO_UTF8(*D.Key)] = TCHAR_TO_UTF8(*D.Str);
			break;
		case FDataObjectValue::Number:
			Map[TCHAR_TO_UTF8(*D.Key)] = D.FloatVal;
			break;
		case FDataObjectValue::Boolean:
			Map[TCHAR_TO_UTF8(*D.Key)] = D.BoolVal;
			break;
		case FDataObjectValue::StringArray:
			for (FDataObjectValue ArrayVal : D.ArrayVal)
			{
				arr[counter] = TCHAR_TO_UTF8(*ArrayVal.Str);
				counter++;
			}
			Map[TCHAR_TO_UTF8(*D.Key)] = arr;
			break;
		case FDataObjectValue::NumberArray:
			for (FDataObjectValue ArrayVal : D.ArrayVal)
			{
				arr[counter] = ArrayVal.FloatVal;
				counter++;
			}
			Map[TCHAR_TO_UTF8(*D.Key)] = arr;
			break;
		case FDataObjectValue::BooleanArray:
			for (FDataObjectValue ArrayVal : D.ArrayVal)
			{
				arr[counter] = ArrayVal.BoolVal;
				counter++;
			}
			Map[TCHAR_TO_UTF8(*D.Key)] = arr;
			break;
		case FDataObjectValue::Map:
			std::map<std::string, firebase::Variant> MapData = UFBPRealtimeDatabase::FBPGenerateMapForData(D.ArrayVal);
			if(!MapData.empty())
			{
				Map[TCHAR_TO_UTF8(*D.Key)] = MapData;
			}
			break;
		}
	}
	return Map;
}

TMap<FString, FDataObjectValue> UFBPRealtimeDatabase::FBPGenerateDataMap(const firebase::database::DataSnapshot DataSnapshot)
{
	TMap<FString, FDataObjectValue> TMapData = TMap<FString, FDataObjectValue>();
	
	if(DataSnapshot.exists())
	{
		for (firebase::database::DataSnapshot Snapshot : DataSnapshot.children())
		{
			FDataObjectValue DocumentData = FDataObjectValue();
			DocumentData.Key = FString(Snapshot.key_string().c_str());
			if(Snapshot.value().is_string())
			{
				DocumentData.Type = FDataObjectValue::String;
				DocumentData.Str = UTF8_TO_TCHAR(Snapshot.value().string_value());
			}
			else if(Snapshot.value().is_int64())
			{
				DocumentData.Type = FDataObjectValue::Number;
				DocumentData.FloatVal = Snapshot.value().int64_value();
			}
			else if(Snapshot.value().is_double())
			{
				DocumentData.Type = FDataObjectValue::Number;
				DocumentData.FloatVal = Snapshot.value().double_value();
			}
			else if(Snapshot.value().is_bool())
			{
				DocumentData.Type = FDataObjectValue::Boolean;
				DocumentData.BoolVal = Snapshot.value().bool_value();
			}
			else if(Snapshot.value().is_vector())
			{
				TArray<FDataObjectValue> Arr = TArray<FDataObjectValue>();
				for (firebase::database::DataSnapshot Child : Snapshot.children())
				{
					FDataObjectValue DocumentDataForArray = FDataObjectValue();
					
					if(Child.value().is_string())
					{
						DocumentData.Type = FDataObjectValue::StringArray;
						DocumentDataForArray.Type = FDataObjectValue::String;
						DocumentDataForArray.Str = UTF8_TO_TCHAR(Child.value().string_value());
					}
					else if(Child.value().is_int64())
					{
						DocumentData.Type = FDataObjectValue::NumberArray;
						DocumentDataForArray.Type = FDataObjectValue::Number;
						DocumentDataForArray.FloatVal = Child.value().int64_value();
					}
					else if(Child.value().is_double())
					{
						DocumentData.Type = FDataObjectValue::NumberArray;
						DocumentDataForArray.Type = FDataObjectValue::Number;
						DocumentDataForArray.FloatVal = Child.value().double_value();
					}
					else if(Child.value().is_bool())
					{
						DocumentData.Type = FDataObjectValue::BooleanArray;
						DocumentDataForArray.Type = FDataObjectValue::Boolean;
						DocumentDataForArray.BoolVal = Child.value().bool_value();
					}
					Arr.Add(DocumentDataForArray);
					
				}
				DocumentData.ArrayVal = Arr;
			}
			else if(Snapshot.value().is_map())
			{
				DocumentData.Type = FDataObjectValue::Map;
				TArray<FString> MapKeys = TArray<FString>();
				TArray<FDataObjectValue> MapValues = TArray<FDataObjectValue>();
				TMap<FString, FDataObjectValue> TempMapData  = UFBPRealtimeDatabase::FBPGenerateDataMap(Snapshot);
				for (TTuple<FString, FDataObjectValue> MapData : TempMapData)
				{
					const FString MapKey = MapData.Key;
					const FDataObjectValue MapValue = MapData.Value;
					MapKeys.Add(MapKey);
					MapValues.Add(MapValue);
				}
				DocumentData.MapKeys = MapKeys;
				DocumentData.MapValues = MapValues;
			}
			TMapData.Add(DocumentData.Key, DocumentData);
		}

	}
	return TMapData;
}


void UFBPRealtimeDatabase::FBPAddData(const TArray<FString> DataPath, const TArray<FDataObjectValue> Data, const FOnDataAdded& OnDataAdded, const FOnFailToAddData& OnFailToAddData)
{
	if(!UFBPApp::HaveDatabaseInfo("[FBP] No Realtime Database info found. Go to the Firebase console and setup Realtime Database, then generate a new Google Services file."))
	{
		return;
	}
	firebase::database::Database* Db = FBPGetDatabase();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::database::DatabaseReference DatabaseRef = FBPGenDatabaseReference(DataPath);
		std::map<std::string, firebase::Variant> Map = FBPGenerateMapForData(Data);
		DatabaseRef.SetValue(Map).OnCompletion(
			[OnDataAdded, OnFailToAddData, DatabaseRef](const firebase::Future<void>& Result)
			{
				if(Result.error())
				{
					OnFailToAddData.ExecuteIfBound(Result.error_message());
				}
				else
				{
					OnDataAdded.ExecuteIfBound(FString(DatabaseRef.key_string().c_str()));
				}
			}
		);
	}
}

void UFBPRealtimeDatabase::FBPGetData(const TArray<FString> DataPath, const FOnValueReceived& OnValueReceived,
	const FOnFailToGetValue& OnFailToGetValue)
{
	if(!UFBPApp::HaveDatabaseInfo("[FBP] No Realtime Database info found. Go to the Firebase console and setup Realtime Database, then generate a new Google Services file."))
	{
		return;
	}
	firebase::database::Database* Db = FBPGetDatabase();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::database::DatabaseReference DatabaseRef = FBPGenDatabaseReference(DataPath);
		DatabaseRef.GetValue().OnCompletion(
		[OnValueReceived, OnFailToGetValue](const firebase::Future<firebase::database::DataSnapshot>& Result)
		{
			if(Result.error())
			{
				OnFailToGetValue.ExecuteIfBound(FString(Result.error_message()));
			}
			else
			{
				FDocumentSnapshot DataSnapshot = FDocumentSnapshot();
				DataSnapshot.Data = FBPGenerateDataMap(*Result.result());
				OnValueReceived.ExecuteIfBound(DataSnapshot);
			}
		});
	}

}

void UFBPRealtimeDatabase::FBPUpdateData(const TArray<FString> DataPath, const TArray<FDataObjectValue> Data,
	const FOnDataAdded& OnDataUpdated, const FOnFailToAddData& OnFailToUpdateData)
{
	if(!UFBPApp::HaveDatabaseInfo("[FBP] No Realtime Database info found. Go to the Firebase console and setup Realtime Database, then generate a new Google Services file."))
	{
		return;
	}
	firebase::database::Database* Db = FBPGetDatabase();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::database::DatabaseReference DatabaseRef = FBPGenDatabaseReference(DataPath);
		std::map<std::string, firebase::Variant> Map = FBPGenerateMapForData(Data);
		DatabaseRef.UpdateChildren(Map).OnCompletion(
			[OnDataUpdated, OnFailToUpdateData, DatabaseRef](const firebase::Future<void>& Result)
			{
				if(Result.error())
				{
					OnFailToUpdateData.ExecuteIfBound(Result.error_message());
				}
				else
				{
					OnDataUpdated.ExecuteIfBound(FString(DatabaseRef.key_string().c_str()));
				}
			}
		);
	}

}

void UFBPRealtimeDatabase::FBPDeleteData(const TArray<FString> DataPath, const FOnDataDeleted& OnDataDeleted, const FOnFailToDeleteData& OnFailToDeleteData)
{
	if(!UFBPApp::HaveDatabaseInfo("[FBP] No Realtime Database info found. Go to the Firebase console and setup Realtime Database, then generate a new Google Services file."))
	{
		return;
	}
	firebase::database::Database* Db = FBPGetDatabase();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::database::DatabaseReference DatabaseRef = FBPGenDatabaseReference(DataPath);
		DatabaseRef.RemoveValue().OnCompletion(
			[OnDataDeleted, OnFailToDeleteData](const firebase::Future<void>& Result)
			{
				if(Result.error())
				{
					OnFailToDeleteData.ExecuteIfBound(FString(Result.error_message()));
				}
				else
				{
					OnDataDeleted.ExecuteIfBound();
				}
			}
		);
	}

}

void UFBPRealtimeDatabase::FBPListenToValue(const TArray<FString> DataPath, const FOnValueChanges& OnValueChanges, const FOnCancelValueListener& OnCancelValueListener)
{
	if(!UFBPApp::HaveDatabaseInfo("[FBP] No Realtime Database info found. Go to the Firebase console and setup Realtime Database, then generate a new Google Services file."))
	{
		return;
	}
	firebase::database::Database* Db = FBPGetDatabase();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::database::DatabaseReference DatabaseRef = FBPGenDatabaseReference(DataPath);
		DatabaseRef.AddValueListener(new FBPValueListener(OnValueChanges, OnCancelValueListener));
	}
}

void UFBPRealtimeDatabase::FBPListenToChild(const TArray<FString> DataPath,  const FOnValueChanges& OnValueAdded, const FOnValueChanges& OnValueChanged, const FOnValueChanges& OnChildRemoved, const FOnValueChanges& OnChildMoved, const FOnCancelValueListener& OnCancelValueListener)
{
	if(!UFBPApp::HaveDatabaseInfo("[FBP] No Realtime Database info found. Go to the Firebase console and setup Realtime Database, then generate a new Google Services file."))
	{
		return;
	}
	firebase::database::Database* Db = FBPGetDatabase();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::database::DatabaseReference DatabaseRef = FBPGenDatabaseReference(DataPath);
		DatabaseRef.AddChildListener(new FBPChildListener(OnValueAdded, OnValueChanged, OnChildRemoved, OnChildMoved, OnCancelValueListener));
	}
}
