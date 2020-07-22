// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Delegate.h"
#include "BattleSaveDataRepository.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSuccessSavingBattleRate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnErrorSavingBattleRate);

USTRUCT()
struct FBattleRepositoryInitializeData
{
	GENERATED_BODY()
public:
    FBattleRepositoryInitializeData()
    {
		
    }
};

UCLASS()
class GEISTER_API ABattleSaveDataRepository : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABattleSaveDataRepository();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void SaveBattleRate(uint8 newScore);

	UPROPERTY()
    FOnSuccessSavingBattleRate OnSuccessDelegate;
	UPROPERTY()
    FOnErrorSavingBattleRate OnErrorDelegate;
};
