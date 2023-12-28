// Copyright (c) 2022 King Wai Mark



#include "Firestore/FBPFirestore.h"

firebase::firestore::Firestore* UFBPFirestore::Firestore_ = nullptr;

firebase::firestore::Firestore* UFBPFirestore::FBPGetFirestore()
{
	firebase::App* App = UFBPApp::FBPGet();
	#if PLATFORM_WINDOWS || PLATFORM_ANDROID || PLATFORM_IOS
		if(UFBPFirestore::Firestore_ == nullptr && App != nullptr && UFBPFileUtilities::HasGoogleFile)
		{
			UFBPFirestore::Firestore_ = firebase::firestore::Firestore::GetInstance(App);
		}
	#else
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, TEXT("[FBP] Firestore is not available for the current OS you are using. See documentation for more info."));
	#endif
	return UFBPFirestore::Firestore_;
}





void UFBPFirestore::FBPAddDocument(const TArray<FString> DocumentPath, const TArray<FDataObjectValue> Document, const FOnDocumentAdded& OnDocumentAdded, const FOnFailToAddDocument& OnFailToAddDocument)
{
	#if PLATFORM_ANDROID || PLATFORM_IOS
	
	const firebase::firestore::Firestore *Firestore = UFBPFirestore::FBPGetFirestore();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::firestore::DocumentReference FirebaseDocument = UFBPFirestoreUtilities::FBPGetDocumentReference(Firestore, DocumentPath);
		firebase::firestore::MapFieldValue Map = UFBPFirestoreUtilities::FBPGenerateMapForDocument(Document);


		FirebaseDocument.Set(Map).OnCompletion([OnDocumentAdded, OnFailToAddDocument, FirebaseDocument](const firebase::Future<void>& Result)
		{
			if(Result.error())
			{
				OnFailToAddDocument.ExecuteIfBound(FString(Result.error_message()));
			}
			else
			{
				OnDocumentAdded.ExecuteIfBound(FString(FirebaseDocument.id().c_str()));
			}
		});
	}
	#elif PLATFORM_WINDOWS 
	const firebase::firestore::Firestore* Firestore = UFBPFirestore::FBPGetFirestore();
	if (UFBPFileUtilities::HasGoogleFile)
	{
		firebase::firestore::DocumentReference FirebaseDocument = UFBPFirestoreUtilities::FBPGetDocumentReference(Firestore, DocumentPath);
		firebase::firestore::MapFieldValue Map = UFBPFirestoreUtilities::FBPGenerateMapForDocument(Document);


		FirebaseDocument.Set(Map).OnCompletion([OnDocumentAdded, OnFailToAddDocument, FirebaseDocument](const firebase::Future<void>& Result)
		{
				if (Result.status() == firebase::kFutureStatusComplete) {
					if (Result.error() == firebase::firestore::kErrorNone) {
						
			
						FString str = FirebaseDocument.id().c_str();
						OnDocumentAdded.ExecuteIfBound(str);
					}
					else {
						OnFailToAddDocument.ExecuteIfBound(FString(Result.error_message()));
					}
				}
				
		});




	}
	#else
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, TEXT("[FBP] Firestore is not available for the current OS you are using. See documentation for more info."));
	#endif
}

void UFBPFirestore::FBPDeleteDocument(const TArray<FString> DocumentPath, const FOnDocumentDeleted& OnDocumentDeleted, const FOnFailToDeleteDocument& OnFailToDeleteDocument)
{
	#if PLATFORM_WINDOWS || PLATFORM_ANDROID || PLATFORM_IOS
	
	const firebase::firestore::Firestore *Firestore = UFBPFirestore::FBPGetFirestore();

	if(UFBPFileUtilities::HasGoogleFile)
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
				FString TempStr  = DocumentPath[i];
				PathStr.Append(TempStr.Append("/"));
			}
		}
		Firestore->batch().Delete(Firestore->Document(TCHAR_TO_UTF8(*PathStr))).Commit()
		.OnCompletion([OnDocumentDeleted, OnFailToDeleteDocument](const firebase::Future<void>& Result)
		{
			if(Result.error())
			{
				OnFailToDeleteDocument.ExecuteIfBound(FString(Result.error_message()));
			}
			else
			{
				OnDocumentDeleted.ExecuteIfBound();
			}
		});
	}
	#else
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, TEXT("[FBP] Firestore is not available for the current OS you are using. See documentation for more info."));
	#endif
}


void UFBPFirestore::FBPUpdateDocument(const TArray<FString> DocumentPath, const TArray<FDataObjectValue> Document, const FOnDocumentAdded& OnDocumentUpdated, const FOnFailToAddDocument& OnFailToUpdatedDocument)
{

	#if PLATFORM_WINDOWS || PLATFORM_ANDROID || PLATFORM_IOS
	
	const firebase::firestore::Firestore *Firestore = UFBPFirestore::FBPGetFirestore();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::firestore::DocumentReference FirebaseDocument = UFBPFirestoreUtilities::FBPGetDocumentReference(FBPGetFirestore(), DocumentPath);
		firebase::firestore::MapFieldValue Map = UFBPFirestoreUtilities::FBPGenerateMapForDocument(Document);

		FirebaseDocument.Update(Map).OnCompletion([OnDocumentUpdated, OnFailToUpdatedDocument, FirebaseDocument](const firebase::Future<void>& Result)
		{
			if(Result.error())
			{
				OnFailToUpdatedDocument.ExecuteIfBound(FString(Result.error_message()));
			}
			else
			{
				OnDocumentUpdated.ExecuteIfBound(FString(FirebaseDocument.id().c_str()));
			}
		});
	}
	#else
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, TEXT("[FBP] Firestore is not available for the current OS you are using. See documentation for more info."));
	#endif
}

TArray<FBatchOperationValue> UFBPFirestore::FBPBeginBatch()
{
	return TArray<FBatchOperationValue>();
}


void UFBPFirestore::FBPCommitBatch(const TArray<FBatchOperationValue> Batch, const FOnBatchCompleted& OnBatchCompleted, const FOnFailToCompleteBatch& OnFailToCompleteBatch)
{
	#if PLATFORM_WINDOWS || PLATFORM_ANDROID || PLATFORM_IOS
	
	const firebase::firestore::Firestore *Firestore = UFBPFirestore::FBPGetFirestore();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::firestore::WriteBatch WriteBatch = Firestore->batch();
		for (FBatchOperationValue BatchOperationValue : Batch)
		{
			switch (BatchOperationValue.Operation)
			{
			case FBatchOperationValue::Add:
				WriteBatch.Set(
					UFBPFirestoreUtilities::FBPGetDocumentReference(FBPGetFirestore(), BatchOperationValue.DocumentPath),
					UFBPFirestoreUtilities::FBPGenerateMapForDocument(BatchOperationValue.Document));
				break;
			case FBatchOperationValue::Update:
				WriteBatch.Update(
					UFBPFirestoreUtilities::FBPGetDocumentReference(FBPGetFirestore(), BatchOperationValue.DocumentPath),
					UFBPFirestoreUtilities::FBPGenerateMapForDocument(BatchOperationValue.Document));
				break;
			case FBatchOperationValue::Delete:
				WriteBatch.Delete(UFBPFirestoreUtilities::FBPGetDocumentReference(FBPGetFirestore(), BatchOperationValue.DocumentPath));
				break;
			}
		}
		WriteBatch.Commit().OnCompletion(
			[OnBatchCompleted, OnFailToCompleteBatch](const firebase::Future<void>& Result)
			{
				if(Result.error())
				{
					OnFailToCompleteBatch.ExecuteIfBound(FString(Result.error_message()));
				}
				else
				{
					OnBatchCompleted.ExecuteIfBound();
				}
			});
	}
	#else
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, TEXT("[FBP] Firestore is not available for the current OS you are using. See documentation for more info."));
	#endif
}

void UFBPFirestore::FBPGetDocument(const TArray<FString> DocumentPath, const FOnDocumentRetrieved& OnDocumentRetrieved, const FOnFailToRetrieveDocument& OnFailToRetrieveDocument)
{
	#if PLATFORM_WINDOWS || PLATFORM_ANDROID || PLATFORM_IOS
	
	bool isDocumentPath = UFBPFirestoreUtilities::FBPIsDocumentReference(DocumentPath);
	if(!isDocumentPath)
	{
		OnFailToRetrieveDocument.ExecuteIfBound("Path is not pointing to a document.");
		return;
	}
	const firebase::firestore::Firestore *Firestore = UFBPFirestore::FBPGetFirestore();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::firestore::DocumentReference FirebaseDocument = UFBPFirestoreUtilities::FBPGetDocumentReference(Firestore, DocumentPath);
		FirebaseDocument.Get().OnCompletion(
			[FirebaseDocument, OnDocumentRetrieved, OnFailToRetrieveDocument](const firebase::Future<firebase::firestore::DocumentSnapshot>& Result)
			{
				if(Result.error())
				{
					OnFailToRetrieveDocument.ExecuteIfBound(FString(Result.error_message()));
				}
				else
				{
					FDocumentSnapshot DocumentSnapshot = FDocumentSnapshot();
					const FString DocumentId = FString(FirebaseDocument.id().c_str());
					DocumentSnapshot.Id = DocumentId;
					DocumentSnapshot.Data = UFBPFirestoreUtilities::FBPGenerateDocumentMap(Result.result()->GetData());
					OnDocumentRetrieved.ExecuteIfBound(DocumentId, DocumentSnapshot);
				}
			});
	}
	#else
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, TEXT("[FBP] Firestore is not available for the current OS you are using. See documentation for more info."));
	#endif
}

void UFBPFirestore::FBPListenToDocument(const TArray<FString> DocumentPath, const FOnDocumentRetrieved& OnDocumentRetrieved, const FOnFailToRetrieveDocument& OnFailToRetrieveDocument)
{
	#if PLATFORM_WINDOWS || PLATFORM_ANDROID || PLATFORM_IOS
	
	bool isDocumentPath = UFBPFirestoreUtilities::FBPIsDocumentReference(DocumentPath);
	if(!isDocumentPath)
	{
		OnFailToRetrieveDocument.ExecuteIfBound("Path is not pointing to a document.");
		return;
	}
	const firebase::firestore::Firestore *Firestore = UFBPFirestore::FBPGetFirestore();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::firestore::DocumentReference FirebaseDocument = UFBPFirestoreUtilities::FBPGetDocumentReference(Firestore, DocumentPath);

		FirebaseDocument.AddSnapshotListener(
	[FirebaseDocument, OnDocumentRetrieved, OnFailToRetrieveDocument](const firebase::firestore::DocumentSnapshot& Result, const firebase::firestore::Error& Error, const std::string& Str)
			{
				if(!Result.exists())
				{
					OnFailToRetrieveDocument.ExecuteIfBound("Document does not exist.");
				}
				else
				{
					FDocumentSnapshot DocumentSnapshot = FDocumentSnapshot();
					const FString DocumentId = FString(FirebaseDocument.id().c_str());
					DocumentSnapshot.Id = DocumentId;
					DocumentSnapshot.Data = UFBPFirestoreUtilities::FBPGenerateDocumentMap(Result.GetData());
					OnDocumentRetrieved.ExecuteIfBound(DocumentId, DocumentSnapshot);
				}
			});
	}
	#else
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, TEXT("[FBP] Firestore is not available for the current OS you are using. See documentation for more info."));
	#endif


}

TArray<FCollectionQuery> UFBPFirestore::FBPBeginGetCollectionQuery()
{
	return TArray<FCollectionQuery>();
}

void UFBPFirestore::FBPGetCollection(const TArray<FString> CollectionPath, const TArray<FCollectionQuery> Query, const FOnDocumentsReceived& OnDocumentsReceived, const FOnFailToRetrieveCollection& OnFailToRetrieveCollection)
{
	#if PLATFORM_WINDOWS || PLATFORM_ANDROID || PLATFORM_IOS
	
	const firebase::firestore::Firestore *Firestore = UFBPFirestore::FBPGetFirestore();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::firestore::CollectionReference FirebaseCollection = UFBPFirestoreUtilities::FBPGetCollectionReference(Firestore, CollectionPath);
		firebase::firestore::Query FirebaseCollectionQuery;

		if(Query.Num() > 0)
		{
			FirebaseCollectionQuery = UFBPFirestoreUtilities::FBPGenerateQuery(FirebaseCollection, Query);
		}
		else
		{
			FirebaseCollectionQuery = FirebaseCollection;
		}

		FirebaseCollectionQuery.Get().OnCompletion(
			[OnDocumentsReceived, OnFailToRetrieveCollection](const firebase::Future<firebase::firestore::QuerySnapshot>& Result)
			{
				if(Result.error())
				{
					OnFailToRetrieveCollection.ExecuteIfBound(FString(Result.error_message()));
				}
				else
				{
					TArray<FDocumentSnapshot> DocumentSnapshots = TArray<FDocumentSnapshot>();
					for (firebase::firestore::DocumentSnapshot Document : Result.result()->documents())
					{
						FDocumentSnapshot DocumentSnapshot = FDocumentSnapshot();
						const FString DocumentId = FString(Document.id().c_str());
						DocumentSnapshot.Id = DocumentId;
						DocumentSnapshot.Data = UFBPFirestoreUtilities::FBPGenerateDocumentMap(Document.GetData());
						DocumentSnapshots.Add(DocumentSnapshot);
					}
					FCollectionSnapshot CollectionSnapshot = FCollectionSnapshot();
					CollectionSnapshot.Documents = DocumentSnapshots;
					OnDocumentsReceived.ExecuteIfBound(CollectionSnapshot);
				}
			}
		);
	}
	#else
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, TEXT("[FBP] Firestore is not available for the current OS you are using. See documentation for more info."));
	#endif

}

void UFBPFirestore::FBPListenToCollection(const TArray<FString> CollectionPath, TArray<FCollectionQuery> Query, const FOnDocumentAddedInCollection& OnDocumentsAdded, const FOnDocumentModifiedInCollection& OnDocumentsModified, const FOnDocumentDeletedInCollection& OnDocumentsDeleted)
{
	#if PLATFORM_WINDOWS || PLATFORM_ANDROID || PLATFORM_IOS
	
	const firebase::firestore::Firestore *Firestore = UFBPFirestore::FBPGetFirestore();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::firestore::CollectionReference FirebaseCollection = UFBPFirestoreUtilities::FBPGetCollectionReference(Firestore, CollectionPath);
		firebase::firestore::Query FirebaseCollectionQuery;

		if(Query.Num() > 0)
		{
			FirebaseCollectionQuery = UFBPFirestoreUtilities::FBPGenerateQuery(FirebaseCollection, Query);
		}
		else
		{
			FirebaseCollectionQuery = FirebaseCollection;
		}

		FirebaseCollectionQuery.AddSnapshotListener(
			[OnDocumentsAdded, OnDocumentsModified, OnDocumentsDeleted](const firebase::firestore::QuerySnapshot& Result, const firebase::firestore::Error& Error, const std::string& Str)
			{
				for (firebase::firestore::DocumentChange DocumentChange : Result.DocumentChanges())
				{
					FDocumentSnapshot DocumentSnapshot = FDocumentSnapshot();
					const FString DocumentId = FString(DocumentChange.document().id().c_str());
					DocumentSnapshot.Id = DocumentId;
					switch (DocumentChange.type())
					{
					case firebase::firestore::DocumentChange::Type::kAdded:
						DocumentSnapshot.Data = UFBPFirestoreUtilities::FBPGenerateDocumentMap(DocumentChange.document().GetData());
						OnDocumentsAdded.ExecuteIfBound(DocumentId, DocumentSnapshot);
						break;
					case firebase::firestore::DocumentChange::Type::kModified:
						DocumentSnapshot.Data = UFBPFirestoreUtilities::FBPGenerateDocumentMap(DocumentChange.document().GetData());
						OnDocumentsModified.ExecuteIfBound(DocumentId, DocumentSnapshot);
						break;
					case firebase::firestore::DocumentChange::Type::kRemoved:
						DocumentSnapshot.Data = UFBPFirestoreUtilities::FBPGenerateDocumentMap(DocumentChange.document().GetData());
						OnDocumentsDeleted.ExecuteIfBound(DocumentId, DocumentSnapshot);
						break;
					}
				}
			}
		);
	}
	#else
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, TEXT("[FBP] Firestore is not available for the current OS you are using. See documentation for more info."));
	#endif
}


TArray<FDocumentSnapshot> UFBPFirestore::FBPGetDocumentsFromCollection(FCollectionSnapshot CollectionSnapshot)
{
	return CollectionSnapshot.Documents;
}

void UFBPFirestore::FBPSetCacheSize(const int CacheSize)
{
	#if PLATFORM_WINDOWS || PLATFORM_ANDROID || PLATFORM_IOS
	
	const firebase::firestore::Firestore *Firestore = UFBPFirestore::FBPGetFirestore();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		Firestore->settings().set_cache_size_bytes(CacheSize);
	}
	#else
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, TEXT("[FBP] Firestore is not available for the current OS you are using. See documentation for more info."));
	#endif
}

void UFBPFirestore::FBPEnablePersistence(bool Enable)
{
	#if PLATFORM_WINDOWS || PLATFORM_ANDROID || PLATFORM_IOS
	
	const firebase::firestore::Firestore *Firestore = UFBPFirestore::FBPGetFirestore();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		Firestore->settings().set_persistence_enabled(Enable);
	}
	#else
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, TEXT("[FBP] Firestore is not available for the current OS you are using. See documentation for more info."));
	#endif
}

void UFBPFirestore::FBPEnableNetwork(bool Enable)
{
	#if PLATFORM_WINDOWS || PLATFORM_ANDROID || PLATFORM_IOS
	
	firebase::firestore::Firestore *Firestore = UFBPFirestore::FBPGetFirestore();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		if(Enable)
		{
			Firestore->EnableNetwork();
		}
		else
		{
			Firestore->DisableNetwork();
		}
	}
	#else
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, TEXT("[FBP] Firestore is not available for the current OS you are using. See documentation for more info."));
	#endif
}

void UFBPFirestore::FBPClearPersistence()
{
	#if PLATFORM_WINDOWS || PLATFORM_ANDROID || PLATFORM_IOS
	
	firebase::firestore::Firestore *Firestore = UFBPFirestore::FBPGetFirestore();
	if(UFBPFileUtilities::HasGoogleFile)
	{
		Firestore->ClearPersistence();
	}
	#else
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, TEXT("[FBP] Firestore is not available for the current OS you are using. See documentation for more info."));
	#endif
}

FString UFBPFirestore::GetDocumentId(FDocumentSnapshot DocumentSnapshot)
{
	return DocumentSnapshot.Id;
}


