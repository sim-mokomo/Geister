// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameSequencer.h"
#include "GameFramework/Actor.h"
#include "GameSequenceSelector.generated.h"

UCLASS()
class GEISTER_API AGameSequenceSelector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameSequenceSelector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// UFUNCTION()
	void ChangeGameSequencer(GameSequencerType type);
private:
	UPROPERTY()
	AGameSequencer* CurrentGameSequencer;
	UPROPERTY(EditAnywhere)
	TArray<AGameSequencer*> DefinedGameSequencerTable;
};
