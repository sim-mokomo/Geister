// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Geister/Public/GeiserSaveData.h"
#include "Kismet/GameplayStatics.h"
#include "ISaveService.generated.h"

UCLASS()
class GEISTER_API AISaveService : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category = "GesiterSaveData")
		FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = "GeisterSaveData")
		uint32 SaveUserIndex;
	
public:	
	// Sets default values for this actor's properties
	AISaveService();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Save(FString UserId, FString Password);

};
