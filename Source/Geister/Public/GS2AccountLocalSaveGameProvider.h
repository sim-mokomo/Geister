// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "GS2AccountLocalSaveGame.h"
#include "GS2AccountLocalSaveGameProvider.generated.h"

UCLASS()
class GEISTER_API AGS2AccountLocalSaveGameProvider : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY()
		FString saveSlotName;
	UPROPERTY()
		uint8 saveSlotIndex;
public:
	// Sets default values for this actor's properties
	AGS2AccountLocalSaveGameProvider();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		bool ExistsSaveGame();
	UFUNCTION()
		UGS2AccountLocalSaveGame* GetSaveGame();
	UFUNCTION()
		bool Save(FString userId, FString userPassword);
};
