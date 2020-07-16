// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UserWidget.h"
#include "GameFramework/Actor.h"
#include "ScreenPresenter.generated.h"

UENUM()
enum ScreenPresenterType
{
	ScreenPresenterType_None,
	ScreenPresenterType_Title,
	ScreenPresenterType_All,
};

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
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> widget;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	virtual void Setup();
	UFUNCTION()
	virtual void Dispose();
};
