// Fill out your copyright notice in the Description page of Project Settings.


#include "ScreenPresenter.h"

#include "UserWidget.h"

// Sets default values
AScreenPresenter::AScreenPresenter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScreenPresenter::BeginPlay()
{
	Super::BeginPlay();

	OnAddedToScreenDelegate.AddDynamic(this,&AScreenPresenter::OnAddedToScreen);
}

// Called every frame
void AScreenPresenter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AScreenPresenter::OnAddedToScreen()
{
	
}

void AScreenPresenter::CreateRegistedWidget()
{
	createdWidget = CreateWidget<UUserWidget>(GetWorld(),this->widget);
	createdWidget->AddToViewport();
}

ScreenPresenterType AScreenPresenter::GetSelfScreenPresenterType()
{
	return ScreenPresenterType_None;
}
