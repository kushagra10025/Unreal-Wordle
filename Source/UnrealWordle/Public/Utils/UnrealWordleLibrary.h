// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UnrealWordleLibrary.generated.h"

USTRUCT(BlueprintType)
struct FStringArray
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TArray<FString> Strings;
};

/**
 * 
 */
UCLASS()
class UNREALWORDLE_API UUnrealWordleLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="UnrealWordleLibrary")
	static bool LoadWordsFromFile(FString FileName, int32 RequiredWordLength, TMap<int32, FStringArray>& Words);

private:
	static bool IsASCIILetter(char c);
};
