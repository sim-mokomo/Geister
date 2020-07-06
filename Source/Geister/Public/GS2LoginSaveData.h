// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GS2LoginSaveData.generated.h"

/**
 * 
 */
UCLASS()
class GEISTER_API UGS2LoginSaveData : public USaveGame
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category = "GS2LoginSaveData")
	FString UserId;

	UPROPERTY(VisibleAnywhere, Category = "GS2LoginSaveData")
		FString Password;
public:
	UGS2LoginSaveData();

	UFUNCTION(BlueprintCallable, Category = "Geister|SaveData")
		void SetBuildDatas(FString SavedUserId, FString SavedPassword);
	UFUNCTION(BlueprintPure, Category = "Geister|SaveData")
		FString GetUserId();
	UFUNCTION(BlueprintPure, Category = "Geister|SaveData")
		FString GetPassword();
};
