// Copyright (c) 2022 King Wai Mark


#include "Firestore/FBPBatchOperation.h"


TArray<FBatchOperationValue> UFBPBatchOperation::AddDocumentBatchOperation(TArray<FString> DocumentPath, TArray<FDataObjectValue> Document, TArray<FBatchOperationValue> Batch)
{
	FBatchOperationValue BatchOperationValue = FBatchOperationValue();
	BatchOperationValue.Operation = FBatchOperationValue::Add;
	BatchOperationValue.DocumentPath = DocumentPath;
	BatchOperationValue.Document = Document;
	Batch.Add(BatchOperationValue);
	return Batch;
}

TArray<FBatchOperationValue> UFBPBatchOperation::UpdateDocumentBatchOperation(TArray<FString> DocumentPath, TArray<FDataObjectValue> Document, TArray<FBatchOperationValue> Batch)
{
	FBatchOperationValue BatchOperationValue = FBatchOperationValue();
	BatchOperationValue.Operation = FBatchOperationValue::Update;
	BatchOperationValue.DocumentPath = DocumentPath;
	BatchOperationValue.Document = Document;
	Batch.Add(BatchOperationValue);
	return Batch;
}

TArray<FBatchOperationValue> UFBPBatchOperation::DeleteDocumentBatchOperation(TArray<FString> DocumentPath, TArray<FBatchOperationValue> Batch)
{
	FBatchOperationValue BatchOperationValue = FBatchOperationValue();
	BatchOperationValue.Operation = FBatchOperationValue::Delete;
	BatchOperationValue.DocumentPath = DocumentPath;
	Batch.Add(BatchOperationValue);
	return Batch;
}