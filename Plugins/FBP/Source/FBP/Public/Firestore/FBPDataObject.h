// Copyright (c) 2022 King Wai Mark

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FBPDataObject.generated.h"





/**
 *	@author King Wai Mark
 * 
 */
USTRUCT(BlueprintType)
struct FBP_API FDataObjectValue
{
	GENERATED_BODY()

	enum EType
	{
		String,
		Number,
		Boolean,
		StringArray,
		BooleanArray,
		NumberArray,
		Map
	};
	
	EType Type;
	FString Key;
	FString Str;
	float FloatVal;
	bool BoolVal;
	TArray<FDataObjectValue> ArrayVal;
	TArray<FString> MapKeys;
	TArray<FDataObjectValue> MapValues;

};

/**
 *	@author King Wai Mark
 *
 *	Data structure to represent the DocumentSnapshot from Firebase and DataSnapshot from Realtime Database.
 * 
 */
USTRUCT(BlueprintType)
struct FBP_API FDocumentSnapshot
{
	GENERATED_BODY()

	FString Id;
	TMap<FString, FDataObjectValue> Data;
	
};



/**
 *	@author King Wai Mark
 * 
 *	This class contains functions to append a document.
 */
UCLASS()
class FBP_API UFBPDataObject : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	/**
	 *	Creates an blank document so data can be added to it and then uploaded to Firestore.
	 *	
	 *  @author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Begin Write Document", Keywords = "Begin Write Document"), Category = "Database Data - Firebase Plugin by KWM")
	static TArray<FDataObjectValue> FBPBeginWriteDocument();
	
	/**
	 *	Adds an String to the document object
	 *
	 *	@param Key Title to represent the value
	 *	@param Str String value
	 *	@param Document The document to append to
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add String", Keywords = "Add String"), Category = "Database Data - Firebase Plugin by KWM")
	static TArray<FDataObjectValue> AddString(const FString Key, const FString Str, TArray<FDataObjectValue> Document);
	/**
	 *	Adds an Float to the document object
	 *
	 *	@param Key Title to represent the value
	 *	@param FloatVal Float value
	 *	@param Document The document to append to
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Number", Keywords = "Add Number"), Category = "Database Data - Firebase Plugin by KWM")
	static TArray<FDataObjectValue> AddNumber(const FString Key, const float FloatVal, TArray<FDataObjectValue> Document);
	/**
	 *	Adds an Boolean to the document object
	 *
	 *	@param Key Title to represent the value
	 *	@param BoolVal Boolean value
	 *	@param Document The document to append to
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Boolean", Keywords = "Add Boolean"), Category = "Database Data - Firebase Plugin by KWM")
	static TArray<FDataObjectValue> AddBoolean(const FString Key, const bool BoolVal, TArray<FDataObjectValue> Document);
	

	/**
	 *	Adds an Array of Strings to the document object
	 *
	 *	@param Key Title to represent the value
	 *	@param StrArr String array to add
	 *	@param Document The document to append to
	 *
	 *	@author King Wai Mark
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add String Array", Keywords = "Add String Array to Document"), Category = "Database Data - Firebase Plugin by KWM")
	static TArray<FDataObjectValue> AddStringArray(const FString Key, const TArray<FString> StrArr, TArray<FDataObjectValue> Document);

	/**
	 *	Adds an Array of Booleans to the document object
	 *
	 *	@param Key Title to represent the value
	 *	@param BoolArr Boolean array to add
	 *	@param Document The document to append to
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Boolean Array", Keywords = "Add Boolean Array to Document"), Category = "Database Data - Firebase Plugin by KWM")
	static TArray<FDataObjectValue> AddBooleanArray(const FString Key, const TArray<bool> BoolArr, TArray<FDataObjectValue> Document);
	/**
	 *	Adds an Array of Floats to the document object
	 *
	 *	@param Key Title to represent the value
	 *	@param FloatArr Float array to add
	 *	@param Document The document to append to
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Number Array", Keywords = "Add Float Array to Document"), Category = "Database Data - Firebase Plugin by KWM")
	static TArray<FDataObjectValue> AddNumberArray(const FString Key, const TArray<float> FloatArr, TArray<FDataObjectValue> Document);
	


	/**
	 *	Get an String value from the Document Snapshot. Will return an empty string if no key is found from the document.
	 *
	 *	@param Key Key corresponding to the data on the Document
	 *	@param DocumentSnapshot Document used to retrieve the data
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get String", Keywords = "Get String"), Category = "Database Data - Firebase Plugin by KWM")
	static FString GetString(FString Key, FDocumentSnapshot DocumentSnapshot);
	

	/**
	 *	Get an Float value from the Document Snapshot. Will return -1.0 when no key is found.
	 *
	 *	@param Key Key corresponding to the data on the Document
	 *	@param DocumentSnapshot Document used to retrieve the data
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Number", Keywords = "Get Number"), Category = "Database Data - Firebase Plugin by KWM")
	static float GetNumber(FString Key, FDocumentSnapshot DocumentSnapshot);

	/**
	 *	Get an Boolean value from the Document Snapshot. Will return false when no key is found.
	 *
	 *	@param Key Key corresponding to the data on the Document
	 *	@param DocumentSnapshot Document used to retrieve the data
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Boolean", Keywords = "Get Boolean"), Category = "Database Data - Firebase Plugin by KWM")
	static bool GetBoolean(FString Key, FDocumentSnapshot DocumentSnapshot);

	/**
	 *	Get the String array from the Document Snapshot. 
	 *
	 *	@param Key Key corresponding to the data on the Document
	 *	@param DocumentSnapshot Document used to retrieve the data
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get String Array", Keywords = "Get String Array"), Category = "Database Data - Firebase Plugin by KWM")
	static TArray<FString> GetStringArray(FString Key, FDocumentSnapshot DocumentSnapshot);

	/**
	 *	Get the Number array from the Document Snapshot. 
	 *
	 *	@param Key Key corresponding to the data on the Document
	 *	@param DocumentSnapshot Document used to retrieve the data
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Number Array", Keywords = "Get Number Array"), Category = "Database Data - Firebase Plugin by KWM")
	static TArray<float> GetNumberArray(FString Key, FDocumentSnapshot DocumentSnapshot);


	/**
	 *	Get the Boolean array from the Document Snapshot. 
	 *
	 *	@param Key Key corresponding to the data on the Document
	 *	@param DocumentSnapshot Document used to retrieve the data
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Boolean Array", Keywords = "Get Boolean Array"), Category = "Database Data - Firebase Plugin by KWM")
	static TArray<bool> GetBooleanArray(FString Key, FDocumentSnapshot DocumentSnapshot);
	
	/**
	 *	Creates a blank map so data can be added to it.
	 *	Used in conjunction with Add Map to add a map to a document or data.
	 *
	 *	@return Returns a blank map
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Begin Create Map", Keywords = "Begin Create Map"), Category = "Database Data - Firebase Plugin by KWM")
	static TArray<FDataObjectValue> BeginCreateMap();

	/**
	 *	Creates a blank map so data can be added to it.
	 *	Used in conjunction with Add Map to add a map to a document or data.
	 *
	 *	@param Key Title to represent the value
	 *	@param Map Map to add to the document
	 *	@param Document The document to append to
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Map", Keywords = "Add Map"), Category = "Database Data - Firebase Plugin by KWM")
	static TArray<FDataObjectValue> AddMap(const FString Key, const TArray<FDataObjectValue> Map, TArray<FDataObjectValue> Document);

	/**
	 *	Get the Get Map from the Document Snapshot. 
	 *
	 *	@param Key Key corresponding to the data on the Document
	 *	@param DocumentSnapshot Document used to retrieve the data
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Map", Keywords = "Get Map"), Category = "Database Data - Firebase Plugin by KWM")
	static FDocumentSnapshot GetMap(FString Key, FDocumentSnapshot DocumentSnapshot);

	/**
	 *	Converts a FDataObjectValue to a  TMap<FString, FDataObjectValue> if the Type is Map.
	 *
	 *	@author King Wai Mark
	 */
	static TMap<FString, FDataObjectValue> ToDocumentSnapshot(const FDataObjectValue& DataObjectValue);
	
};



/**
 *	@author King Wai Mark
 * 
 */
USTRUCT(BlueprintType)
struct FBP_API FCollectionQuery
{
	GENERATED_BODY()

	enum EQuery
	{
		WhereIn,
		WhereNotIn,
		WhereEqualTo,
		WhereGreaterThan,
		WhereLessThan,
		WhereNotEqualTo,
		WhereGreaterThanOrEqualTo,
		WhereLessThanOrEqualTo,
		WhereArrayContains,
		WhereArrayContainsAny,
		Limit,
		OrderBy
	};
	
	EQuery Query;
	FDataObjectValue DataObjectValue;


};


/**
 *	@author King Wai Mark
 * 
 *	This class contains functions to append the Get Collection Query chain.
 */
UCLASS()
class FBP_API UFBCollectionQuery : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/**
	 *	Adds the Where Equal to Number query to the query chain.
	 *
	 *	@param Key Key representing the data in the document(s)
	 *	@param Number Number value used for the query
	 *	@param Query Query chain to append this query
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Where Equal To Number", Keywords = "Where Equal To Number"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FCollectionQuery> WhereEqualToNumber(FString Key, float Number, TArray<FCollectionQuery> Query);
	/**
	 *	Adds the Where Equal to String query to the query chain.
	 *
	 *	@param Key Key representing the data in the document(s)
	 *	@param Str String value used for the query
	 *	@param Query Query chain to append this query
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Where Equal To String", Keywords = "Where Equal To String"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FCollectionQuery> WhereEqualToString(FString Key, FString Str, TArray<FCollectionQuery> Query);
	/**
	 *	Adds the Where Equal to Boolean query to the query chain.
	 *
	 *	@param Key Key representing the data in the document(s)
	 *	@param Boolean Boolean value used for the query
	 *	@param Query Query chain to append this query
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Where Equal To Boolean", Keywords = "Where Equal To Boolean"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FCollectionQuery> WhereEqualToBoolean(FString Key, bool Boolean, TArray<FCollectionQuery> Query);

	/**
	 *	Adds the Where Not Equal to Number query to the query chain.
	 *
	 *	@param Key Key representing the data in the document(s)
	 *	@param Number Number value used for the query
	 *	@param Query Query chain to append this query
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Where Not Equal To Number", Keywords = "Where Not Equal To Number"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FCollectionQuery> WhereNotEqualToNumber(FString Key, float Number, TArray<FCollectionQuery> Query);
	
	/**
	 *	Adds the Where Not Equal to String query to the query chain.
	 *
	 *	@param Key Key representing the data in the document(s)
	 *	@param Str String value used for the query
	 *	@param Query Query chain to append this query
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Where Not Equal To String", Keywords = "Where Not Equal To String"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FCollectionQuery> WhereNotEqualToString(FString Key, FString Str, TArray<FCollectionQuery> Query);

	/**
	 *	Adds the Where Not Equal to Boolean query to the query chain.
	 *
	 *	@param Key Key representing the data in the document(s)
	 *	@param Boolean Boolean value used for the query
	 *	@param Query Query chain to append this query
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Where Not Equal To Boolean", Keywords = "Where Not Equal To Boolean"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FCollectionQuery> WhereNotEqualToBoolean(FString Key, bool Boolean, TArray<FCollectionQuery> Query);


	/**
	 *	Adds the Where Greater Than This Number query to the query chain.
	 *
	 *	@param Key Key representing the data in the document(s)
	 *	@param Number Number value used for the query
	 *	@param Query Query chain to append this query
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Where Greater Than This Number", Keywords = "Where Greater Than This Number"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FCollectionQuery> WhereGreaterThanThisNumber(FString Key, float Number, TArray<FCollectionQuery> Query);

	/**
	 *	Adds the Where Greater Than This String query to the query chain.
	 *
	 *	@param Key Key representing the data in the document(s)
	 *	@param Str String value used for the query
	 *	@param Query Query chain to append this query
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Where Greater Than This String", Keywords = "Where Greater Than This String"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FCollectionQuery> WhereGreaterThanThisString(FString Key, FString Str, TArray<FCollectionQuery> Query);

	/**
	 *	Adds the Where Less Than This Number query to the query chain.
	 *
	 *	@param Key Key representing the data in the document(s)
	 *	@param Number Number value used for the query
	 *	@param Query Query chain to append this query
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Where Less Than This Number", Keywords = "Where Less Than This Number"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FCollectionQuery> WhereLessThanThisNumber(FString Key, float Number, TArray<FCollectionQuery> Query);

	/**
	 *	Adds the Where Less Than This String query to the query chain.
	 *
	 *	@param Key Key representing the data in the document(s)
	 *	@param Str String value used for the query
	 *	@param Query Query chain to append this query
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Where Less Than This String", Keywords = "Where Less Than This String"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FCollectionQuery> WhereLessThanThisString(FString Key, FString Str, TArray<FCollectionQuery> Query);

	/**
	 *	Adds the Where Greater Than or Equal To This Number query to the query chain.
	 *
	 *	@param Key Key representing the data in the document(s)
	 *	@param Number Number value used for the query
	 *	@param Query Query chain to append this query
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Where Greater Than or Equal To This Number", Keywords = "Where Greater Than or Equal To This Number"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FCollectionQuery> WhereGreaterThanOrEqualToThisNumber(FString Key, float Number, TArray<FCollectionQuery> Query);
	
	/**
	 *	Adds the Where Greater Than or Equal To This String  query to the query chain.
	 *
	 *	@param Key Key representing the data in the document(s)
	 *	@param Str String value used for the query
	 *	@param Query Query chain to append this query
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Where Greater Than or Equal To This String", Keywords = "Where Greater Than or Equal To This String"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FCollectionQuery> WhereGreaterThanOrEqualToThisString(FString Key, FString Str, TArray<FCollectionQuery> Query);

	/**
	 *	Adds the Where Less Than or Equal To This Number query to the query chain.
	 *
	 *	@param Key Key representing the data in the document(s)
	 *	@param Number Number value used for the query
	 *	@param Query Query chain to append this query
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Where Less Than or Equal To This Number", Keywords = "Where Less Than or Equal To This Number"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FCollectionQuery> WhereLessThanOrEqualToThisNumber(FString Key, float Number, TArray<FCollectionQuery> Query);
	
	/**
	 *	Adds the Where Less Than or Equal To This String  query to the query chain.
	 *
	 *	@param Key Key representing the data in the document(s)
	 *	@param Str String value used for the query
	 *	@param Query Query chain to append this query
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Where Less Than or Equal To This String", Keywords = "Where Less Than or Equal To This String"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FCollectionQuery> WhereLessThanOrEqualToThisString(FString Key, FString Str, TArray<FCollectionQuery> Query);

	
	
	/**
	 *	Orders the Get Collection results by the given key.
	 *
	 *	@param Key Field used as the order parameter
	 *	@param Ascending If true, will order the contents in ascending order. Descending otherwise
	 *	@param Query Query chain to append this query
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Order By", Keywords = "Order By"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FCollectionQuery> OrderBy(FString Key, bool Ascending, TArray<FCollectionQuery> Query);
	/**
	 *	Adds a maximum limit to how many documents can be retrieved.
	 *
	 *	@param Limit The maximum amount of documents to get
	 *	@param Query Query chain to append this query
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Limit", Keywords = "Limit"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FCollectionQuery> Limit(int Limit, TArray<FCollectionQuery> Query);

};

/**
 *	@author King Wai Mark
 * 
 */
USTRUCT(BlueprintType)
struct FBP_API FCollectionSnapshot
{
	GENERATED_BODY()

	TArray<FDocumentSnapshot> Documents;

};