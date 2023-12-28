// Copyright (c) 2022 King Wai Mark

#include "Firestore/FBPFirestoreUtilities.h"

#if PLATFORM_WINDOWS || PLATFORM_ANDROID || PLATFORM_IOS
firebase::firestore::DocumentReference UFBPFirestoreUtilities::FBPGetDocumentReference(const firebase::firestore::Firestore *Firestore, const TArray<FString> DocumentPath)
{
	FString PathStr = "";
	for(int i = 0; i < DocumentPath.Num(); i++)
	{
		if(i == DocumentPath.Num() - 1)
		{
			PathStr.Append(DocumentPath[i]);
		}
		else
		{
			FString TempStr = DocumentPath[i];
			PathStr.Append(TempStr.Append("/"));
		}
	}

	const FString FinalStr = PathStr;
	// Is Collection
	if(DocumentPath.Num() % 2 == 1)
	{
		
		return Firestore->Collection(TCHAR_TO_UTF8(*FinalStr)).Document();
	}
	else // Is Document
	{
		return Firestore->Document(TCHAR_TO_UTF8(*FinalStr));
	}
}

firebase::firestore::CollectionReference UFBPFirestoreUtilities::FBPGetCollectionReference(const firebase::firestore::Firestore *Firestore, const TArray<FString> CollectionPath)
{
	FString PathStr = "";
	for(int i = 0; i < CollectionPath.Num(); i++)
	{
		if(i == CollectionPath.Num() - 1)
		{
			PathStr.Append(CollectionPath[i]);
		}
		else
		{
			FString TempStr = CollectionPath[i];
			PathStr.Append(TempStr.Append("/"));
		}
	}
	const FString FinalStr = PathStr;
	// Is Collection
	if(CollectionPath.Num() % 2 == 1)
	{
		return Firestore->Collection(TCHAR_TO_UTF8(*FinalStr));
	}
	else // Is Document
	{
		return Firestore->Document(TCHAR_TO_UTF8(*FinalStr)).Parent();
	}
}

firebase::firestore::MapFieldValue UFBPFirestoreUtilities::FBPGenerateMapForDocument(const TArray<FDataObjectValue> Document)
{
	firebase::firestore::MapFieldValue Map = firebase::firestore::MapFieldValue();
	for (FDataObjectValue D : Document)
	{
		
		std::vector<firebase::firestore::FieldValue> arr(D.ArrayVal.Num());
		int Counter = 0;
		switch (D.Type)
		{
		case FDataObjectValue::String:
			Map.insert({TCHAR_TO_UTF8(*D.Key), firebase::firestore::FieldValue::String(TCHAR_TO_UTF8(*D.Str))});
			break;
		case FDataObjectValue::Number:
			Map.insert({TCHAR_TO_UTF8(*D.Key), firebase::firestore::FieldValue::Double(D.FloatVal)});
			break;
		case FDataObjectValue::Boolean:
			Map.insert({TCHAR_TO_UTF8(*D.Key), firebase::firestore::FieldValue::Boolean(D.BoolVal)});
			break;
		case FDataObjectValue::StringArray:

			for (FDataObjectValue ArrayVal : D.ArrayVal)
			{
				arr[Counter] =firebase::firestore::FieldValue::String(TCHAR_TO_UTF8(*ArrayVal.Str));
				Counter++;
			}
			Map.insert({TCHAR_TO_UTF8(*D.Key), firebase::firestore::FieldValue::Array(arr)});
			break;
		case FDataObjectValue::NumberArray:
			for (FDataObjectValue ArrayVal : D.ArrayVal)
			{
				arr[Counter] = firebase::firestore::FieldValue::Double(ArrayVal.FloatVal);
				Counter++;
			}
			Map.insert({TCHAR_TO_UTF8(*D.Key), firebase::firestore::FieldValue::Array(arr)});
			break;
		case FDataObjectValue::BooleanArray:
			for (FDataObjectValue ArrayVal : D.ArrayVal)
			{
				arr[Counter] = firebase::firestore::FieldValue::Boolean(ArrayVal.BoolVal);
				Counter ++;
			}
			Map.insert({TCHAR_TO_UTF8(*D.Key), firebase::firestore::FieldValue::Array(arr)});
			break;
		case FDataObjectValue::Map:
			firebase::firestore::MapFieldValue MapData = UFBPFirestoreUtilities::FBPGenerateMapForDocument(D.ArrayVal);
			Map.insert({TCHAR_TO_UTF8(*D.Key), firebase::firestore::FieldValue::Map(MapData)});
			
			break;
		}
	}
	return Map;
}


bool UFBPFirestoreUtilities::FBPIsDocumentReference(TArray<FString> DocumentPath)
{
	return DocumentPath.Num() > 0 && DocumentPath.Num() % 2 == 0;
}

bool UFBPFirestoreUtilities::FBPIsCollectionReference(TArray<FString> CollectionPath)
{
	return CollectionPath.Num() > 0 && CollectionPath.Num() % 2 == 1;
}

TMap<FString, FDataObjectValue> UFBPFirestoreUtilities::FBPGenerateDocumentMap(const firebase::firestore::MapFieldValue DocumentSnapshot)
{
	TMap<FString, FDataObjectValue> TMapData = TMap<FString, FDataObjectValue>();
	
	for (std::pair<const std::string, firebase::firestore::FieldValue> Data : DocumentSnapshot)
	{
		FDataObjectValue DocumentData = FDataObjectValue();
		DocumentData.Key = FString(Data.first.c_str());
		if(Data.second.is_string())
		{
			DocumentData.Type = FDataObjectValue::String;
			DocumentData.Str = FString(UTF8_TO_TCHAR(Data.second.string_value().c_str()));
						
		}
		else if(Data.second.is_integer())
		{
			DocumentData.Type = FDataObjectValue::Number;
			DocumentData.FloatVal = Data.second.integer_value();
		}
		else if(Data.second.is_double())
		{
			DocumentData.Type = FDataObjectValue::Number;
			DocumentData.FloatVal = Data.second.double_value();
		}
		else if(Data.second.is_boolean())
		{
			DocumentData.Type = FDataObjectValue::Boolean;
			DocumentData.BoolVal = Data.second.boolean_value();
		}
		else if(Data.second.is_array())
		{
			TArray<FDataObjectValue> arr = TArray<FDataObjectValue>();
			
			for (firebase::firestore::FieldValue Array_Value : Data.second.array_value())
			{
				FDataObjectValue DocumentDataForArray = FDataObjectValue();
				if(Array_Value.is_string())
				{
					DocumentData.Type = FDataObjectValue::StringArray;
					DocumentDataForArray.Type = FDataObjectValue::String;
					DocumentDataForArray.Str = FString(UTF8_TO_TCHAR(Array_Value.string_value().c_str()));
					arr.Add(DocumentDataForArray);
				}
				else if (Array_Value.is_integer())
				{
					DocumentData.Type = FDataObjectValue::NumberArray;
					DocumentDataForArray.Type = FDataObjectValue::Number;
					DocumentDataForArray.FloatVal = Array_Value.integer_value();
					arr.Add(DocumentDataForArray);
				}
				else if (Array_Value.is_double())
				{
					DocumentData.Type = FDataObjectValue::NumberArray;
					DocumentDataForArray.Type = FDataObjectValue::Number;
					DocumentDataForArray.FloatVal = Array_Value.double_value();
					arr.Add(DocumentDataForArray);
				}
				else if (Array_Value.is_boolean())
				{
					DocumentData.Type = FDataObjectValue::BooleanArray;
					DocumentDataForArray.Type = FDataObjectValue::Boolean;
					DocumentDataForArray.BoolVal = Array_Value.boolean_value();
					arr.Add(DocumentDataForArray);
				}
			}
			
			DocumentData.ArrayVal = arr;
		}
		else if (Data.second.is_map())
		{	
			DocumentData.Type = FDataObjectValue::Map;
			TArray<FString> MapKeys = TArray<FString>();
			TArray<FDataObjectValue> MapValues = TArray<FDataObjectValue>();
			TMap<FString, FDataObjectValue> TempMapData  = UFBPFirestoreUtilities::FBPGenerateDocumentMap(Data.second.map_value());
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

	return TMapData;
}


firebase::firestore::Query UFBPFirestoreUtilities::FBPGenerateQuery(const firebase::firestore::CollectionReference FirebaseCollection, const TArray<FCollectionQuery> Query)
{
	firebase::firestore::Query FirebaseCollectionQuery = FirebaseCollection;

	for (FCollectionQuery CollectionQuery : Query)
	{
		firebase::firestore::Query::Direction Direction = firebase::firestore::Query::Direction::kDescending;
		switch (CollectionQuery.Query)
		{
		case FCollectionQuery::WhereIn:
			break;
		case FCollectionQuery::WhereNotIn:
			break;
		case FCollectionQuery::WhereEqualTo:
			switch (CollectionQuery.DataObjectValue.Type)
			{
			case FDataObjectValue::Number:
				FirebaseCollectionQuery = FirebaseCollectionQuery.WhereEqualTo(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Key), firebase::firestore::FieldValue::Double(CollectionQuery.DataObjectValue.FloatVal));
				break;
			case FDataObjectValue::String:
				FirebaseCollectionQuery = FirebaseCollectionQuery.WhereEqualTo(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Key), firebase::firestore::FieldValue::String(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Str)));
				break;
			case FDataObjectValue::Boolean:
				FirebaseCollectionQuery = FirebaseCollectionQuery.WhereEqualTo(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Key), firebase::firestore::FieldValue::Boolean(CollectionQuery.DataObjectValue.BoolVal));
				break;
			}
			break;
		case FCollectionQuery::WhereNotEqualTo:
			switch (CollectionQuery.DataObjectValue.Type)
			{
			case FDataObjectValue::Number:
				FirebaseCollectionQuery = FirebaseCollectionQuery.WhereNotEqualTo(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Key), firebase::firestore::FieldValue::Double(CollectionQuery.DataObjectValue.FloatVal));
				break;
			case FDataObjectValue::String:
				FirebaseCollectionQuery = FirebaseCollectionQuery.WhereNotEqualTo(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Key), firebase::firestore::FieldValue::String(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Str)));
				break;
			case FDataObjectValue::Boolean:
				FirebaseCollectionQuery = FirebaseCollectionQuery.WhereNotEqualTo(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Key), firebase::firestore::FieldValue::Boolean(CollectionQuery.DataObjectValue.BoolVal));
				break;
			}
			break;
		case FCollectionQuery::WhereGreaterThan:
			switch (CollectionQuery.DataObjectValue.Type)
			{
			case FDataObjectValue::Number:
				FirebaseCollectionQuery = FirebaseCollectionQuery.WhereGreaterThan(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Key), firebase::firestore::FieldValue::Double(CollectionQuery.DataObjectValue.FloatVal));
				break;
			case FDataObjectValue::String:
				FirebaseCollectionQuery = FirebaseCollectionQuery.WhereGreaterThan(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Key), firebase::firestore::FieldValue::String(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Str)));
				break;
			}
			break;
		case FCollectionQuery::WhereLessThan:
			switch (CollectionQuery.DataObjectValue.Type)
			{
			case FDataObjectValue::Number:
				FirebaseCollectionQuery = FirebaseCollectionQuery.WhereLessThan(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Key), firebase::firestore::FieldValue::Double(CollectionQuery.DataObjectValue.FloatVal));
				break;
			case FDataObjectValue::String:
				FirebaseCollectionQuery = FirebaseCollectionQuery.WhereLessThan(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Key), firebase::firestore::FieldValue::String(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Str)));
				break;
			}
			break;
		case FCollectionQuery::WhereGreaterThanOrEqualTo:
			switch (CollectionQuery.DataObjectValue.Type)
			{
			case FDataObjectValue::Number:
				FirebaseCollectionQuery = FirebaseCollectionQuery.WhereGreaterThanOrEqualTo(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Key), firebase::firestore::FieldValue::Double(CollectionQuery.DataObjectValue.FloatVal));
				break;
			case FDataObjectValue::String:
				FirebaseCollectionQuery = FirebaseCollectionQuery.WhereGreaterThanOrEqualTo(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Key), firebase::firestore::FieldValue::String(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Str)));
				break;
			}
			break;
		case FCollectionQuery::WhereLessThanOrEqualTo:
			switch (CollectionQuery.DataObjectValue.Type)
			{
			case FDataObjectValue::Number:
				FirebaseCollectionQuery = FirebaseCollectionQuery.WhereLessThanOrEqualTo(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Key), firebase::firestore::FieldValue::Double(CollectionQuery.DataObjectValue.FloatVal));
				break;
			case FDataObjectValue::String:
				FirebaseCollectionQuery = FirebaseCollectionQuery.WhereLessThanOrEqualTo(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Key), firebase::firestore::FieldValue::String(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Str)));
				break;
			}
			break;
		case FCollectionQuery::WhereArrayContains:
			break;
		case FCollectionQuery::WhereArrayContainsAny:
			break;
		case FCollectionQuery::OrderBy:
			
			if(CollectionQuery.DataObjectValue.BoolVal)
			{
				Direction = firebase::firestore::Query::Direction::kAscending;
			}
			FirebaseCollectionQuery = FirebaseCollectionQuery.OrderBy(TCHAR_TO_UTF8(*CollectionQuery.DataObjectValue.Key), Direction);
			break;
		case FCollectionQuery::Limit:
			FirebaseCollectionQuery = FirebaseCollectionQuery.Limit(CollectionQuery.DataObjectValue.FloatVal);
			break;
		}
	}

	return FirebaseCollectionQuery;
}

#endif