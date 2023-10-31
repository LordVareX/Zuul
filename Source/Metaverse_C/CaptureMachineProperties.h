// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CaptureMachineProperties.generated.h"

struct FIntVector2D
{
	int32 X;
	int32 Y;

	FIntVector2D()
		: X(0), Y(0)
	{

	}
	FIntVector2D(int32 _X, int32 _Y)
		: X(_X), Y(_Y)
	{
	}

	bool operator != (const FIntVector2D& obj)
	{
		return X != obj.X || Y != obj.Y;
	}
};

UENUM(BlueprintType)
enum class ETitleMatchingWindowSearch : uint8
{
	PerfectMatch,
	ForwardMatch,
	PartialMatch,
	BackwardMatch,
	RegularExpression
};
/**
 * 
 */
USTRUCT(BlueprintType)
struct METAVERSE_C_API FCaptureMachineProperties
{
	//GENERATED_BODY()

public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WindowCapture2D)
	FString CaptureTargetTitle = TEXT("WindowCapture2D");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WindowCapture2D)
	ETitleMatchingWindowSearch TitleMatchingWindowSearch = ETitleMatchingWindowSearch::ForwardMatch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WindowCapture2D)
	int32 FrameRate = 30;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WindowCapture2D)
	bool CheckWindowSize = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WindowCapture2D)
	bool CutShadow = true;
	
};