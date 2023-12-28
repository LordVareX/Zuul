// Copyright (c) 2022 King Wai Mark
#pragma once

#include "FBPApp.h"

#if PLATFORM_WINDOWS || PLATFORM_MAC || PLATFORM_ANDROID || PLATFORM_IOS
	#include "firebase/firestore.h"
#endif

#include "FBPFirestoreUtilities.h"
#include "FBPDataObject.h"
#include "FBPBatchOperation.h"

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FBPFirestore.generated.h"

// FBPAddDocument | FBPUpdateDocument
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnDocumentAdded, FString, DocumentID);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToAddDocument, FString, ErrorMessage);

// FBPDeleteDocument
DECLARE_DYNAMIC_DELEGATE(FOnDocumentDeleted);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToDeleteDocument, FString, ErrorMessage);

// FBPCommitBatch
DECLARE_DYNAMIC_DELEGATE(FOnBatchCompleted);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToCompleteBatch, FString, ErrorMessage);

// FBPGetDocument
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnDocumentRetrieved, FString, DocumentId, FDocumentSnapshot, DocumentSnapshot);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToRetrieveDocument, FString, ErrorMessage);

// FBPGetCollection
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnDocumentsReceived,  FCollectionSnapshot, CollectionSnapshot);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToRetrieveCollection, FString, ErrorMessage);

// FBPListenToDocument
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnDocumentAddedInCollection, FString, DocumentId, FDocumentSnapshot, DocumentSnapshot);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnDocumentModifiedInCollection, FString, DocumentId, FDocumentSnapshot, DocumentSnapshot);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnDocumentDeletedInCollection, FString, DocumentId, FDocumentSnapshot, DocumentSnapshot);

/**
 * @author King Wai Mark
 * 
 * This class contains the class and to modify Firestore.
 */
UCLASS()
class FBP_API UFBPFirestore : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	static firebase::firestore::Firestore* Firestore_;
	static firebase::firestore::Firestore* FBPGetFirestore();

	
	
	/**
	 *	Adds a document to Firestore by providing a path and a valid document.
	 *
	 *	Delegates used
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnDocumentAdded, FString, DocumentID);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToAddDocument, FString, ErrorMessage);
	 *
	 *	Document Path Array Ref:
	 *	[0] = Collection, [1] = Document, [2] = Collection, [3] = Document, ... 
	 *
	 *	@param DocumentPath The path to the document.The first element of the array is the Collection and the second element is the Document.
	 *						If more values are added, every even element index represents a Collection and every Odd will represent a document.					
	 *						If a Collection is referenced, it will generate an unique document id for the document.
	 *						
	 *	@param Document The document that will be uploaded to Firestore
	 *	@param OnDocumentAdded A callback that will be called when the document is added to Firestore.
	 *	@param OnFailToAddDocument A callback that will be called when it failed to upload the document to Firestore.
	 *
	 *  @author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Document", Keywords = "Add Document"), Category = "Firestore - Firebase Plugin by KWM")
	static void FBPAddDocument(const TArray<FString> DocumentPath, const TArray<FDataObjectValue> Document, const FOnDocumentAdded& OnDocumentAdded, const FOnFailToAddDocument& OnFailToAddDocument);


	/**
	 *	Deletes a document from Firestore by providing a path to it.
	 *	
	 *	Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE(FOnDocumentDeleted);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToDeleteDocument, FString, ErrorMessage);
	 *
	 *	Document Path Array Ref:
	 *	[0] = Collection, [1] = Document, [2] = Collection, [3] = Document, ... 
	 *
	 *	@param DocumentPath The path to the document.
	 *	@param OnDocumentDeleted A callback that will be called when it successfully deletes the document
	 *	@param OnFailToDeleteDocument A callback that will be called when it failed to delete the document
	 *	
	 *  @author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Delete Document", Keywords = "Delete Document"), Category = "Firestore - Firebase Plugin by KWM")
	static void FBPDeleteDocument(const TArray<FString> DocumentPath, const FOnDocumentDeleted& OnDocumentDeleted, const FOnFailToDeleteDocument& OnFailToDeleteDocument);

	/**
	 *	Updates a document in Firestore by providing a path and a valid document.
	 *
	 *	Delegates used
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnDocumentAdded, FString, DocumentID);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToAddDocument, FString, ErrorMessage);
	 *
	 *		
	 *	Document Path Array Ref:
	 *	[0] = Collection, [1] = Document, [2] = Collection, [3] = Document, ... 
	 *
	 *	@param DocumentPath The path to the document.The first element of the array is the Collection and the second element is the Document.
	 *						If more values are added, every even element index represents a Collection and every Odd will represent a document.					
	 *						The path must be a reference to a document.
	 *						
	 *	@param Document The document that will be used to update the document.
	 *	@param OnDocumentUpdated A callback that will be called when the document is updated.
	 *	@param OnFailToUpdatedDocument A callback that will be called when it failed to update the document.
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Update Document", Keywords = "Update Document"), Category = "Firestore - Firebase Plugin by KWM")
	static void FBPUpdateDocument(const TArray<FString> DocumentPath, const TArray<FDataObjectValue> Document, const FOnDocumentAdded& OnDocumentUpdated, const FOnFailToAddDocument& OnFailToUpdatedDocument);

	/**
	 *	Starts the Batch Operation chain to commit multiple add, update, and delete operations.
	 *
	 *	@return Batch of operations
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Begin Batch", Keywords = "Begin Batch"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FBatchOperationValue> FBPBeginBatch();

	/**
	 *	Performs all the batch operations and update Firestore.
	 *
	 *	If even one operation fails, all the data will be rolled back. 
	 *
	 *	Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE(FOnBatchCompleted);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToCompleteBatch, FString, ErrorMessage);
	 *	
	 *	@param Batch Batch to commit
	 *	@param OnBatchCompleted A callback that will be called when all the operations in the batch is completed
	 *	@param OnFailToCompleteBatch A callback that will be called when it fail one or more of the operations in the batch
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Commit Batch", Keywords = "Commit Batch"), Category = "Firestore - Firebase Plugin by KWM")
	static void FBPCommitBatch(const TArray<FBatchOperationValue> Batch, const FOnBatchCompleted& OnBatchCompleted, const FOnFailToCompleteBatch& OnFailToCompleteBatch);

	/**
	 *	Retrieve contents from a document.
	 *
	 *	Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnDocumentRetrieved, FString, DocumentId, FDocumentSnapshot, DocumentSnapshot);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToRetrieveDocument, FString, ErrorMessage);
	 *
	 *	@param DocumentPath Path to the document
	 *	@param OnDocumentRetrieved Callback that will be called when the contents of the documents are retrieved
	 *	@param OnFailToRetrieveDocument Callback that will be called when it fails to get the document
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Document", Keywords = "Get Document"), Category = "Firestore - Firebase Plugin by KWM")
	static void FBPGetDocument(const TArray<FString> DocumentPath, const FOnDocumentRetrieved& OnDocumentRetrieved, const FOnFailToRetrieveDocument& OnFailToRetrieveDocument);

	/**
	 *	Retrieve contents from a document and also continuously get updates.
	 *
	 *	Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnDocumentRetrieved, FString, DocumentId, FDocumentSnapshot, DocumentSnapshot);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToRetrieveDocument, FString, ErrorMessage);
	 *
	 *	@param DocumentPath Path to the document
	 *	@param OnDocumentRetrieved Callback that will be called when the contents of the documents are retrieved
	 *	@param OnFailToRetrieveDocument Callback that will be called when it fails to get the document
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Listen To Document", Keywords = "Listen To Document"), Category = "Firestore - Firebase Plugin by KWM")
	static void FBPListenToDocument(const TArray<FString> DocumentPath, const FOnDocumentRetrieved& OnDocumentRetrieved, const FOnFailToRetrieveDocument& OnFailToRetrieveDocument);


	/**
	 *	Starts the Get Collection Query chain.
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Begin Get Collection Query", Keywords = "Begin Get Collection Query"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FCollectionQuery> FBPBeginGetCollectionQuery();

	/**
	 *	Execute the query to retrieve the documents in a particular collection.
	 *
	 *	Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnDocumentsReceived, FCollectionSnapshot, CollectionSnapshot);
	 *		DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFailToRetrieveCollection, FString, ErrorMessage);
	 *
	 *	@param CollectionPath Path to collection
	 *	@param Query Query chain used to filter data
	 *	@param OnDocumentsReceived Callback that will be called when the documents was retrieved.
	 *	@param OnFailToRetrieveCollection Callback that will be called when it failed to retrieve the documents in the collection.
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Collection", Keywords = "Get Collection"), Category = "Firestore - Firebase Plugin by KWM")
	static void FBPGetCollection(const TArray<FString> CollectionPath, const TArray<FCollectionQuery> Query, const FOnDocumentsReceived& OnDocumentsReceived, const FOnFailToRetrieveCollection& OnFailToRetrieveCollection);
	/**
	 *	Retrieve contents from a collection and also continuously get updates.
	 *
	 *	Delegates used:
	 *		DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnDocumentAddedInCollection, FString, DocumentId, FDocumentSnapshot, DocumentSnapshot);
	 *		DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnDocumentModifiedInCollection, FString, DocumentId, FDocumentSnapshot, DocumentSnapshot);
	 *		DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnDocumentDeletedInCollection, FString, DocumentId, FDocumentSnapshot, DocumentSnapshot);
	 *
	 *	@param CollectionPath Path to collection
	 *	@param Query Query chain used to filter data
	 *	@param OnDocumentsAdded Callback that will be called when the documents was retrieved and when a new document is added to the collection.
	 *	@param OnDocumentsModified Callback that will be called when a document is modified in the collection. Returns the modified document
	 *	@param OnDocumentsDeleted Callback that will be called when a document is deleted in the collection. Returns the deleted document
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Listen To Collection", Keywords = "Listen To Collection"), Category = "Firestore - Firebase Plugin by KWM")
	static void FBPListenToCollection(const TArray<FString> CollectionPath, TArray<FCollectionQuery> Query, const FOnDocumentAddedInCollection& OnDocumentsAdded, const FOnDocumentModifiedInCollection& OnDocumentsModified, const FOnDocumentDeletedInCollection& OnDocumentsDeleted);
	
	
	/**
	 *	Gets all the Document Snapshots from the Collection Snapshot object.
	 *
	 *	@param CollectionSnapshot Collection Snapshot with all the Document Snapshots
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Documents From Collection", Keywords = "Get Documents From Collection"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FDocumentSnapshot> FBPGetDocumentsFromCollection(FCollectionSnapshot CollectionSnapshot);
	
	/**
	 *	Set the maximum Cache Size for persistence data.
	 *
	 *	@param CacheSize The maximum cache size in bytes
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Cache Size", Keywords = "Set Cache Size"), Category = "Firestore - Firebase Plugin by KWM")
	static void FBPSetCacheSize(const int CacheSize);
	/**
	 *	Set the maximum Cache Size for persistence data.
	 *
	 *	@param Enable Boolean that enables persistence if true
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Enable Persistence", Keywords = "Enable Persistence"), Category = "Firestore - Firebase Plugin by KWM")
	static void FBPEnablePersistence(bool Enable);
	/**
	 *	Determines to enable or disable all network connections to this Firestore instance. When disabled, data will be retrieved from Cache  and pending writes
	 *	will be paused until the network is enabled.
	 *
	 *	@param Enable Boolean that enables Network access if true. If false, it will disable the network.
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Enable Network", Keywords = "Enable Network"), Category = "Firestore - Firebase Plugin by KWM")
	static void FBPEnableNetwork(bool Enable);
	/**
	 *	Clear all the persistence data from this Firestore instance.
	 *
	 *	@author King Wai Mark
	 */
		UFUNCTION(BlueprintCallable, meta = (DisplayName = "Clear Persistence", Keywords = "Clear Persistence"), Category = "Firestore - Firebase Plugin by KWM")
		static void FBPClearPersistence();



	/**
	 *	Get the document id from a Document snapshot.
	 *
	 *	@param DocumentSnapshot Document snapshot
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Document Id", Keywords = "Get Document Id"), Category = "Firestore - Firebase Plugin by KWM")
	static FString GetDocumentId(FDocumentSnapshot DocumentSnapshot);
	
};
