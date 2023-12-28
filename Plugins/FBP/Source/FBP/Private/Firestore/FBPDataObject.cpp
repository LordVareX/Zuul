// Copyright (c) 2022 King Wai Mark



#include "Firestore/FBPDataObject.h"

TArray<FDataObjectValue> UFBPDataObject::FBPBeginWriteDocument()
{
	return TArray<FDataObjectValue>();
}

TArray<FDataObjectValue> UFBPDataObject::AddString(const FString Key, const FString Str, TArray<FDataObjectValue> Document)
{
	FDataObjectValue DataValue = FDataObjectValue();
	DataValue.Type = FDataObjectValue::String;
	DataValue.Key = Key;
	DataValue.Str = Str;
	Document.Add(DataValue);
	return Document;
}


TArray<FDataObjectValue> UFBPDataObject::AddNumber(const FString Key, const float FloatVal, TArray<FDataObjectValue> Document)
{
	FDataObjectValue DataValue = FDataObjectValue();
	DataValue.Type = FDataObjectValue::Number;
	DataValue.Key = Key;
	DataValue.FloatVal = FloatVal;
	Document.Add(DataValue);
	return Document;
}

TArray<FDataObjectValue> UFBPDataObject::AddBoolean(const FString Key, const bool BoolVal, TArray<FDataObjectValue> Document)
{
	FDataObjectValue DataValue = FDataObjectValue();
	DataValue.Type = FDataObjectValue::Boolean;
	DataValue.Key = Key;
	DataValue.BoolVal = BoolVal;
	Document.Add(DataValue);
	return Document;
}


TArray<FDataObjectValue> UFBPDataObject::AddStringArray(const FString Key, const TArray<FString> StrArr, TArray<FDataObjectValue> Document)
{
	FDataObjectValue DataValue = FDataObjectValue();
	DataValue.Type = FDataObjectValue::StringArray;
	DataValue.Key = Key;
	DataValue.ArrayVal = TArray<FDataObjectValue>();
	for (FString ArrVal : StrArr)
	{
		FDataObjectValue TempDataVal = FDataObjectValue();
		TempDataVal.Type = FDataObjectValue::String;
		TempDataVal.Str = ArrVal;
		DataValue.ArrayVal.Add(TempDataVal);
	}
	Document.Add(DataValue);
	return Document;
}


TArray<FDataObjectValue> UFBPDataObject::AddBooleanArray(const FString Key, const TArray<bool> BoolArr, TArray<FDataObjectValue> Document)
{
	FDataObjectValue DataValue = FDataObjectValue();
	DataValue.Type = FDataObjectValue::BooleanArray;
	DataValue.Key = Key;
	DataValue.ArrayVal = TArray<FDataObjectValue>();
	for (bool BoolVal : BoolArr)
	{
		FDataObjectValue TempDataVal = FDataObjectValue();
		TempDataVal.Type = FDataObjectValue::Boolean;
		TempDataVal.BoolVal = BoolVal;
		DataValue.ArrayVal.Add(TempDataVal);
	}
	Document.Add(DataValue);
	return Document;
}

TArray<FDataObjectValue> UFBPDataObject::AddNumberArray(const FString Key, const TArray<float> FloatArr, TArray<FDataObjectValue> Document)
{
	FDataObjectValue DataValue = FDataObjectValue();
	DataValue.Type = FDataObjectValue::NumberArray;
	DataValue.Key = Key;
	DataValue.ArrayVal = TArray<FDataObjectValue>();
	for (float FloatVal : FloatArr)
	{
		FDataObjectValue TempDataVal = FDataObjectValue();
		TempDataVal.Type = FDataObjectValue::Number;
		TempDataVal.FloatVal = FloatVal;
		DataValue.ArrayVal.Add(TempDataVal);
	}
	Document.Add(DataValue);
	return Document;
}



FString UFBPDataObject::GetString(FString Key, FDocumentSnapshot DocumentSnapshot)
{
	FDataObjectValue* DataObjectValue = DocumentSnapshot.Data.Find(Key);
	if(DataObjectValue != nullptr)
	{
		return DataObjectValue->Str;
	}
	return "";
}

float UFBPDataObject::GetNumber(FString Key, FDocumentSnapshot DocumentSnapshot)
{
	FDataObjectValue* DataObjectValue = DocumentSnapshot.Data.Find(Key);
	if(DataObjectValue != nullptr)
	{
		return DataObjectValue->FloatVal
		;
	}
	return -1.0;
}

bool UFBPDataObject::GetBoolean(FString Key, FDocumentSnapshot DocumentSnapshot)
{
	FDataObjectValue* DataObjectValue = DocumentSnapshot.Data.Find(Key);
	if(DataObjectValue != nullptr)
	{
		return DataObjectValue->BoolVal;
	}
	return false;
}

TArray<FString> UFBPDataObject::GetStringArray(FString Key, FDocumentSnapshot DocumentSnapshot)
{
	FDataObjectValue* DataObjectValue = DocumentSnapshot.Data.Find(Key);
	if(DataObjectValue != nullptr)
	{
		TArray<FString> arr = TArray<FString>();
		for (FDataObjectValue ArrayVal : DataObjectValue->ArrayVal)
		{
			arr.Add(ArrayVal.Str);
		}
		return arr;
		;
	}
	return TArray<FString>();
}



TArray<float> UFBPDataObject::GetNumberArray(FString Key, FDocumentSnapshot DocumentSnapshot)
{
	FDataObjectValue* DataObjectValue = DocumentSnapshot.Data.Find(Key);
	if(DataObjectValue != nullptr)
	{
		TArray<float> arr = TArray<float>();
		for (FDataObjectValue ArrayVal : DataObjectValue->ArrayVal)
		{
			arr.Add(ArrayVal.FloatVal);
		}
		return arr;
		;
	}
	return TArray<float>();
}

TArray<bool> UFBPDataObject::GetBooleanArray(FString Key, FDocumentSnapshot DocumentSnapshot)
{
	FDataObjectValue* DataObjectValue = DocumentSnapshot.Data.Find(Key);
	if(DataObjectValue != nullptr)
	{
		TArray<bool> arr = TArray<bool>();
		for (FDataObjectValue ArrayVal : DataObjectValue->ArrayVal)
		{
			arr.Add(ArrayVal.BoolVal);
		}
		return arr;
		;
	}
	return TArray<bool>();
}



TArray<FDataObjectValue> UFBPDataObject::BeginCreateMap()
{
	return TArray<FDataObjectValue>();
}

TArray<FDataObjectValue> UFBPDataObject::AddMap(const FString Key, const TArray<FDataObjectValue> Map, TArray<FDataObjectValue> Document)
{
	FDataObjectValue DataValue = FDataObjectValue();
	DataValue.Type = FDataObjectValue::Map;
	DataValue.Key = Key;
	DataValue.ArrayVal = Map;
	Document.Add(DataValue);
	return Document;
}

FDocumentSnapshot UFBPDataObject::GetMap(FString Key, FDocumentSnapshot DocumentSnapshot)
{
	FDataObjectValue* DataObjectValue = DocumentSnapshot.Data.Find(Key);
	FDocumentSnapshot DocumentSnapshotData = FDocumentSnapshot();
	if(DataObjectValue != nullptr)
	{
		DocumentSnapshotData.Data = ToDocumentSnapshot(*DataObjectValue);
		return DocumentSnapshotData;
	}
	return DocumentSnapshotData;
	
}

TMap<FString, FDataObjectValue> UFBPDataObject::ToDocumentSnapshot(const FDataObjectValue& DataObjectValue)
{
	TMap<FString, FDataObjectValue> Map = TMap<FString, FDataObjectValue>();
	if(DataObjectValue.Type == FDataObjectValue::Map)
	{
		TArray<FString> MapKeys = DataObjectValue.MapKeys;
		TArray<FDataObjectValue> MapValues = DataObjectValue.MapValues;
		for(int i = 0; i < MapKeys.Num(); i++)
		{
			const FString MapKey = MapKeys[i];
			const FDataObjectValue MapValue = MapValues[i];
			Map.Add(MapKey, MapValue);
		}

	}
	return Map;
}



TArray<FCollectionQuery> UFBCollectionQuery::WhereEqualToNumber(FString Key, float Number, TArray<FCollectionQuery> Query)
{
	FCollectionQuery CollectionQuery = FCollectionQuery();

	FDataObjectValue DataObjectValue = FDataObjectValue();
	DataObjectValue.Type = DataObjectValue.Number;
	DataObjectValue.Key = Key;
	DataObjectValue.FloatVal = Number;

	CollectionQuery.Query = FCollectionQuery::WhereEqualTo;
	CollectionQuery.DataObjectValue = DataObjectValue;
	Query.Add(CollectionQuery);
	
	return Query;
}

TArray<FCollectionQuery> UFBCollectionQuery::WhereEqualToString(FString Key, FString Str,
	TArray<FCollectionQuery> Query)
{
	FCollectionQuery CollectionQuery = FCollectionQuery();

	FDataObjectValue DataObjectValue = FDataObjectValue();
	DataObjectValue.Type = DataObjectValue.String;
	DataObjectValue.Key = Key;
	DataObjectValue.Str = Str;

	CollectionQuery.Query = FCollectionQuery::WhereEqualTo;
	CollectionQuery.DataObjectValue = DataObjectValue;
	Query.Add(CollectionQuery);
	
	return Query;
}

TArray<FCollectionQuery> UFBCollectionQuery::WhereEqualToBoolean(FString Key, bool Boolean,
	TArray<FCollectionQuery> Query)
{
	FCollectionQuery CollectionQuery = FCollectionQuery();

	FDataObjectValue DataObjectValue = FDataObjectValue();
	DataObjectValue.Type = DataObjectValue.Boolean;
	DataObjectValue.Key = Key;
	DataObjectValue.BoolVal = Boolean;

	CollectionQuery.Query = FCollectionQuery::WhereEqualTo;
	CollectionQuery.DataObjectValue = DataObjectValue;
	Query.Add(CollectionQuery);
	
	return Query;
}

TArray<FCollectionQuery> UFBCollectionQuery::WhereNotEqualToNumber(FString Key, float Number,
	TArray<FCollectionQuery> Query)
{
	FCollectionQuery CollectionQuery = FCollectionQuery();

	FDataObjectValue DataObjectValue = FDataObjectValue();
	DataObjectValue.Type = DataObjectValue.Number;
	DataObjectValue.Key = Key;
	DataObjectValue.FloatVal = Number;

	CollectionQuery.Query = FCollectionQuery::WhereNotEqualTo;
	CollectionQuery.DataObjectValue = DataObjectValue;
	Query.Add(CollectionQuery);
	
	return Query;
}

TArray<FCollectionQuery> UFBCollectionQuery::WhereNotEqualToString(FString Key, FString Str,
	TArray<FCollectionQuery> Query)
{
	FCollectionQuery CollectionQuery = FCollectionQuery();

	FDataObjectValue DataObjectValue = FDataObjectValue();
	DataObjectValue.Type = DataObjectValue.String;
	DataObjectValue.Key = Key;
	DataObjectValue.Str = Str;

	CollectionQuery.Query = FCollectionQuery::WhereNotEqualTo;
	CollectionQuery.DataObjectValue = DataObjectValue;
	Query.Add(CollectionQuery);
	
	return Query;
}

TArray<FCollectionQuery> UFBCollectionQuery::WhereNotEqualToBoolean(FString Key, bool Boolean,
	TArray<FCollectionQuery> Query)
{
	FCollectionQuery CollectionQuery = FCollectionQuery();

	FDataObjectValue DataObjectValue = FDataObjectValue();
	DataObjectValue.Type = DataObjectValue.Boolean;
	DataObjectValue.Key = Key;
	DataObjectValue.BoolVal = Boolean;

	CollectionQuery.Query = FCollectionQuery::WhereNotEqualTo;
	CollectionQuery.DataObjectValue = DataObjectValue;
	Query.Add(CollectionQuery);
	
	return Query;
}

TArray<FCollectionQuery> UFBCollectionQuery::WhereGreaterThanThisNumber(FString Key, float Number,
	TArray<FCollectionQuery> Query)
{
	FCollectionQuery CollectionQuery = FCollectionQuery();

	FDataObjectValue DataObjectValue = FDataObjectValue();
	DataObjectValue.Type = DataObjectValue.Number;
	DataObjectValue.Key = Key;
	DataObjectValue.FloatVal = Number;

	CollectionQuery.Query = FCollectionQuery::WhereGreaterThan;
	CollectionQuery.DataObjectValue = DataObjectValue;
	Query.Add(CollectionQuery);
	
	return Query;
}

TArray<FCollectionQuery> UFBCollectionQuery::WhereGreaterThanThisString(FString Key, FString Str,
	TArray<FCollectionQuery> Query)
{
	FCollectionQuery CollectionQuery = FCollectionQuery();

	FDataObjectValue DataObjectValue = FDataObjectValue();
	DataObjectValue.Type = DataObjectValue.String;
	DataObjectValue.Key = Key;
	DataObjectValue.Str = Str;

	CollectionQuery.Query = FCollectionQuery::WhereGreaterThan;
	CollectionQuery.DataObjectValue = DataObjectValue;
	Query.Add(CollectionQuery);
	
	return Query;
}

TArray<FCollectionQuery> UFBCollectionQuery::WhereLessThanThisNumber(FString Key, float Number,
	TArray<FCollectionQuery> Query)
{
	FCollectionQuery CollectionQuery = FCollectionQuery();

	FDataObjectValue DataObjectValue = FDataObjectValue();
	DataObjectValue.Type = DataObjectValue.Number;
	DataObjectValue.Key = Key;
	DataObjectValue.FloatVal = Number;

	CollectionQuery.Query = FCollectionQuery::WhereLessThan;
	CollectionQuery.DataObjectValue = DataObjectValue;
	Query.Add(CollectionQuery);
	
	return Query;
}

TArray<FCollectionQuery> UFBCollectionQuery::WhereLessThanThisString(FString Key, FString Str,
	TArray<FCollectionQuery> Query)
{
	FCollectionQuery CollectionQuery = FCollectionQuery();

	FDataObjectValue DataObjectValue = FDataObjectValue();
	DataObjectValue.Type = DataObjectValue.String;
	DataObjectValue.Key = Key;
	DataObjectValue.Str = Str;

	CollectionQuery.Query = FCollectionQuery::WhereLessThan;
	CollectionQuery.DataObjectValue = DataObjectValue;
	Query.Add(CollectionQuery);
	
	return Query;
}

TArray<FCollectionQuery> UFBCollectionQuery::WhereGreaterThanOrEqualToThisNumber(FString Key, float Number,
	TArray<FCollectionQuery> Query)
{
	FCollectionQuery CollectionQuery = FCollectionQuery();

	FDataObjectValue DataObjectValue = FDataObjectValue();
	DataObjectValue.Type = DataObjectValue.Number;
	DataObjectValue.Key = Key;
	DataObjectValue.FloatVal = Number;

	CollectionQuery.Query = FCollectionQuery::WhereGreaterThanOrEqualTo;
	CollectionQuery.DataObjectValue = DataObjectValue;
	Query.Add(CollectionQuery);
	
	return Query;
}

TArray<FCollectionQuery> UFBCollectionQuery::WhereGreaterThanOrEqualToThisString(FString Key, FString Str,
	TArray<FCollectionQuery> Query)
{
	FCollectionQuery CollectionQuery = FCollectionQuery();

	FDataObjectValue DataObjectValue = FDataObjectValue();
	DataObjectValue.Type = DataObjectValue.String;
	DataObjectValue.Key = Key;
	DataObjectValue.Str = Str;

	CollectionQuery.Query = FCollectionQuery::WhereGreaterThanOrEqualTo;
	CollectionQuery.DataObjectValue = DataObjectValue;
	Query.Add(CollectionQuery);
	
	return Query;
}

TArray<FCollectionQuery> UFBCollectionQuery::WhereLessThanOrEqualToThisNumber(FString Key, float Number,
	TArray<FCollectionQuery> Query)
{
	FCollectionQuery CollectionQuery = FCollectionQuery();

	FDataObjectValue DataObjectValue = FDataObjectValue();
	DataObjectValue.Type = DataObjectValue.Number;
	DataObjectValue.Key = Key;
	DataObjectValue.FloatVal = Number;

	CollectionQuery.Query = FCollectionQuery::WhereLessThanOrEqualTo;
	CollectionQuery.DataObjectValue = DataObjectValue;
	Query.Add(CollectionQuery);
	
	return Query;
}

TArray<FCollectionQuery> UFBCollectionQuery::WhereLessThanOrEqualToThisString(FString Key, FString Str,
	TArray<FCollectionQuery> Query)
{
	FCollectionQuery CollectionQuery = FCollectionQuery();

	FDataObjectValue DataObjectValue = FDataObjectValue();
	DataObjectValue.Type = DataObjectValue.String;
	DataObjectValue.Key = Key;
	DataObjectValue.Str = Str;

	CollectionQuery.Query = FCollectionQuery::WhereLessThanOrEqualTo;
	CollectionQuery.DataObjectValue = DataObjectValue;
	Query.Add(CollectionQuery);
	
	return Query;
}


TArray<FCollectionQuery> UFBCollectionQuery::OrderBy(FString Key, bool Ascending, TArray<FCollectionQuery> Query)
{
	FCollectionQuery CollectionQuery = FCollectionQuery();

	FDataObjectValue DataObjectValue = FDataObjectValue();
	DataObjectValue.Type = DataObjectValue.Boolean;
	DataObjectValue.Key = Key;
	DataObjectValue.BoolVal = Ascending;

	CollectionQuery.Query = FCollectionQuery::OrderBy;
	CollectionQuery.DataObjectValue = DataObjectValue;
	Query.Add(CollectionQuery);
	
	return Query;
}

TArray<FCollectionQuery> UFBCollectionQuery::Limit(int Limit, TArray<FCollectionQuery> Query)
{
	FCollectionQuery CollectionQuery = FCollectionQuery();

	FDataObjectValue DataObjectValue = FDataObjectValue();
	DataObjectValue.Type = DataObjectValue.Number;
	DataObjectValue.Key = "LimitQuery";
	DataObjectValue.FloatVal = Limit;

	CollectionQuery.Query = FCollectionQuery::Limit;
	CollectionQuery.DataObjectValue = DataObjectValue;
	Query.Add(CollectionQuery);
	
	return Query;
}
