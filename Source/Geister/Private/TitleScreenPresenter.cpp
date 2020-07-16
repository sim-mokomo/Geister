// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleScreenPresenter.h"
#include "TitleWidget.h"

void ATitleScreenPresenter::BeginPlay()
{
}

void ATitleScreenPresenter::Tick(float DeltaTime)
{
}

void ATitleScreenPresenter::Setup()
{
    auto titleUserWidget = CreateWidget<UUserWidget>(GetWorld(),widget);
    auto titleWidget = Cast<UTitleWidget>(titleUserWidget);
    titleWidget->AddToPlayerScreen();
}

void ATitleScreenPresenter::Dispose()
{
}
