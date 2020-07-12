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
		
	}
}

void AScreenManager::AddScreen(AScreenPresenter* AddScreenPresenter)
{
	StackingScreenPresenters.Add(AddScreenPresenter);
	AddScreenPresenter->CreateRegistedWidget();
	AddScreenPresenter->OnAddedToScreenDelegate.Broadcast();
}

void AScreenManager::DisposeScreen()
{
}

void AScreenManager::AllDispose()
{
}

AScreenPresenter* AScreenManager::GetPresenter(ScreenPresenterType type)
{
	auto distPresenterPtr = DefinedScreenPresenterTable.FindByPredicate([&type](AScreenPresenter* x)
	{
		return x->GetSelfScreenPresenterType() == type;
	});

	return *distPresenterPtr;
}

