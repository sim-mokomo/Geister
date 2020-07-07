// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LoginAccountProvider.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "RootGameSequencer.generated.h"

UCLASS()
class GEISTER_API ARootGameSequencer : public AActor
{
	GENERATED_BODY()
private:
	
public:	
	// Sets default values for this actor's properties
	ARootGameSequencer();
	
	UPROPERTY(EditAnywhere)
	ALoginAccountProvider* LoginAccountProvider;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
