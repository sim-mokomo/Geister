// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameSequencer.generated.h"

UENUM()
enum GameSequencerType
{
	GameSequencer_None,
    GameSequencer_Title,
    GameSequencer_All,
};

UCLASS()
class GEISTER_API AGameSequencer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameSequencer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void StartSequence();
	virtual void EndSequence();
	virtual GameSequencerType GetSelfSequencerType();
};