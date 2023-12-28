// Copyright (c) 2022 King Wai Mark
#pragma once

#include "FBPFirestoreUtilities.h"
#include "FBPDataObject.h"

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FBPBatchOperation.generated.h"


/**
 *	@author King Wai Mark
 * 
 */
USTRUCT(BlueprintType)
struct FBP_API FBatchOperationValue
{
	GENERATED_BODY()

	enum EOperation
	{
		Add,
		Update,
		Delete
	};
	
	EOperation Operation;
	TArray<FString> DocumentPath;
	TArray<FDataObjectValue> Document;
};


/**
 *	@author King Wai Mark
 * 
 */
UCLASS()
class FBP_API UFBPBatchOperation : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	/**
	 *	Adds the Add Document operation to the Batch Operation
	 *
	 *	@param DocumentPath Path to the document reference
	 *	@param Document The document to used for the operation
	 *	@param Batch Batch to add the operation to
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Add Document Batch Operation", Keywords = "Add Document Batch Operation"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FBatchOperationValue> AddDocumentBatchOperation(TArray<FString> DocumentPath, TArray<FDataObjectValue> Document, TArray<FBatchOperationValue> Batch);
	/**
	 *	Adds the Update Document operation to the Batch Operation
	 *
	 *	@param DocumentPath Path to the document reference
	 *	@param Document The document to used for the operation
	 *	@param Batch Batch to add the operation to
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Update Document Batch Operation", Keywords = "Update Document Batch Operation"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FBatchOperationValue> UpdateDocumentBatchOperation(TArray<FString> DocumentPath, TArray<FDataObjectValue> Document, TArray<FBatchOperationValue> Batch);
	/**
	 *	Adds the Delete Document operation to the Batch Operation
	 *
	 *	@param DocumentPath Path to the document reference
	 *	@param Batch Batch to add the operation to
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Delete Document Batch Operation", Keywords = "Delete Document Batch Operation"), Category = "Firestore - Firebase Plugin by KWM")
	static TArray<FBatchOperationValue> DeleteDocumentBatchOperation(TArray<FString> DocumentPath, TArray<FBatchOperationValue> Batch);
	
};
