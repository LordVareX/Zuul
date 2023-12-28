// Copyright (c) 2022 King Wai Mark


#pragma once

#if PLATFORM_WINDOWS || PLATFORM_MAC || PLATFORM_ANDROID || PLATFORM_IOS
	#include "firebase/firestore.h"
#endif


#include "FBPDataObject.h"


#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FBPFirestoreUtilities.generated.h"

/**
 * 
 */
UCLASS()
class FBP_API UFBPFirestoreUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
#if PLATFORM_WINDOWS || PLATFORM_ANDROID || PLATFORM_IOS
public:
	/**
	 *	Gets the document reference based on the FString array provided.
	 *
	 *	Document Path Array Ref:
	 *	[0] = Collection, [1] = Document, [2] = Collection, [3] = Document, ... 
	 *
	 *	@param DocumentPath The path to the document.The first element of the array is the Collection and the second element is the Document.
	 *						If more values are added, every even element index represents a Collection and every Odd will represent a document.					
	 *						If a Collection is referenced, it will generate an unique document id for the document.
	 *	@param Firestore Firestore instance
	 *	
	 *	@author King Wai Mark
	 */
	static firebase::firestore::DocumentReference FBPGetDocumentReference(const firebase::firestore::Firestore *Firestore, const TArray<FString> DocumentPath);
	/**
	 *	Gets the collection reference based on the FString array provided.
	 *
	 *	Document Path Array Ref:
	 *	[0] = Collection, [1] = Document, [2] = Collection, [3] = Document, ... 
	 *
	 *	@param CollectionPath The path to the Collection.The first element of the array is the Collection and the second element is the Document.
	 *						If more values are added, every even element index represents a Collection and every Odd will represent a document.					
	 *						
	 *	@param Firestore Firestore instance
	 *	
	 *	@author King Wai Mark
	 */
	static firebase::firestore::CollectionReference FBPGetCollectionReference(const firebase::firestore::Firestore *Firestore, const TArray<FString> CollectionPath);

	/**
	 *	Checks to see if the Document Path is pointing to a document reference.
	 *
	 *	@param DocumentPath Path to document
	 *
	 *	@author King Wai Mark
	 */
	static bool FBPIsDocumentReference(TArray<FString> DocumentPath);
	/**
	 *	Checks to see if the Collection Path is pointing to a collection reference.
	 *
	 *	@param CollectionPath Path to collection
	 *
	 *	@author King Wai Mark
	 */
	static bool FBPIsCollectionReference(TArray<FString> CollectionPath);
	
	/**
	 *	Generates the Map used to add or update a document.
	 *
	 *	@param Document The document data that will be used to generate the map.
	 *	
	 *	@author King Wai Mark
	 */
	static firebase::firestore::MapFieldValue FBPGenerateMapForDocument(const TArray<FDataObjectValue> Document);

	/**
	 *	Generates a Map that holds the contents of the document.
	 *
	 *	@param DocumentSnapshot Data from Firestore document.
	 *	
	 *	@author King Wai Mark
	 */
	static TMap<FString, FDataObjectValue> FBPGenerateDocumentMap(const firebase::firestore::MapFieldValue DocumentSnapshot);
	

	/**
	 *	Generates a Query to retrieve collection documents.
	 *	
	 *	@author King Wai Mark
	 */
	static firebase::firestore::Query FBPGenerateQuery(const firebase::firestore::CollectionReference FirebaseCollection, const TArray<FCollectionQuery> Query);
#endif
	
};
