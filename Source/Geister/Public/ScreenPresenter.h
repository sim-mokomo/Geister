// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScreenPresenter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAddedToScreen);

UCLASS()
class GEISTER_API AScreenPresenter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScreenPresenter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	FAddedToScreen OnAddedToScreenDelegate;
	UFUNCTION()
	virtual void OnAddedToScreen();
	UFUNCTION()
	void CreateRegistedWidget();
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> widget;
	UPROPERTY(EditAnywhere)
	UUserWidget* createdWidget;
};
