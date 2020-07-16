// Fill out your copyright notice in the Description page of Project Settings.


#include "ScreenManager.h"

// Sets default values
AScreenManager::AScreenManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AScreenManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScreenManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	for (auto StackingScreenPresenter : StackingScreenPresenters)
	{
		StackingScreenPresenter->Tick(DeltaTime);
	}
}

void AScreenManager::AddScreen(UClass* AddScreenPresenterClass)
{
	auto DistPresenterPtr = DefinedUserWidgets.FindByPredicate([&](AScreenPresenter* x)
	{
		return AddScreenPresenterClass == x->GetClass();
	});
	auto DistPresenter = *DistPresenterPtr;
	StackingScreenPresenters.Add(DistPresenter);
	DistPresenter->Setup();
}

void AScreenManager::DisposeScreen()
{
	
}

void AScreenManager::AllDispose()
{
	for (auto StackingScreenPresenter : StackingScreenPresenters)
	{
		StackingScreenPresenter->Dispose();
	}
}

