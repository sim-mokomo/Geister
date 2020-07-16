// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "ScreenPresenter.h"
#include "ScreenPresenter.h"
#include "GameFramework/Actor.h"
#include "ScreenManager.generated.h"

UCLASS()
class GEISTER_API AScreenManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScreenManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void AddScreen(UClass* AddScreenPresenterClass);
	void DisposeScreen();
	void AllDispose();
	private:
	UPROPERTY()
	TArray<AScreenPresenter*> StackingScreenPresenters;
	UPROPERTY(EditAnywhere)
	TArray<AScreenPresenter*> DefinedUserWidgets;
};



