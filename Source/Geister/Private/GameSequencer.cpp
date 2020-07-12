// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSequencer.h"

// Sets default values
AGameSequencer::AGameSequencer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameSequencer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameSequencer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameSequencer::StartSequence()
{
}

void AGameSequencer::EndSequence()
{
}

GameSequencerType AGameSequencer::GetSelfSequencerType()
{
	return GameSequencer_None;
}
