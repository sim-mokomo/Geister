// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSequenceSelector.h"

// Sets default values
AGameSequenceSelector::AGameSequenceSelector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AGameSequenceSelector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameSequenceSelector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(CurrentGameSequencer != nullptr)
	{
		CurrentGameSequencer->Tick(DeltaTime);
	}
}

void AGameSequenceSelector::ChangeGameSequencer(GameSequencerType type)
{
	auto DistGameSequencePtr = DefinedGameSequencerTable.FindByPredicate([&type](AGameSequencer* GameSequencer)
	{
		return GameSequencer->GetSelfSequencerType() == type;
	});
	auto DistGameSequencer = *DistGameSequencePtr;
	if(CurrentGameSequencer != nullptr)
	{
		CurrentGameSequencer->EndSequence();
	}
	CurrentGameSequencer = DistGameSequencer;
	CurrentGameSequencer->StartSequence();
}

