// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Geister/Public/GS2LoginSaveData.h"
#include "GS2LoginDataRepository.generated.h"

UCLASS()
class GEISTER_API AGS2LoginDataRepository : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, Category = "Geister|SaveData")
		FString SaveSlotName;
	UPROPERTY(EditAnywhere, Category = "Geister|SaveData")
		uint32 SaveUserIndex;
	// Sets default values for this actor's properties
	AGS2LoginDataRepository();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Geister|Save")
		void Save(FString UserId, FString Password);

	UFUNCTION(BlueprintPure, Category = "Geister|Save")
		bool ExistSaveData();

	UFUNCTION(BlueprintPure, Category = "Geister|Save")
		UGS2LoginSaveData* Load();
};
