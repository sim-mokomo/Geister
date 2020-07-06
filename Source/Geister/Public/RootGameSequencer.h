// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Geister/Public/GS2AccountService.h"
#include "Geister/Public/GS2LoginDataRepository.h"
#include "Engine/Engine.h"
#include "RootGameSequencer.generated.h"

UCLASS()
class GEISTER_API ARootGameSequencer : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	AGS2AccountService* loginService;
	UPROPERTY(EditAnywhere)
	AGS2LoginDataRepository* loginDataRepository;
	UFUNCTION()
	void OnCompleteInitializedProfile();
	UFUNCTION()
	void OnCompleteCreatedAccount();
	
public:	
	// Sets default values for this actor's properties
	ARootGameSequencer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure)
	AGS2AccountService* GetAccountService();
	UFUNCTION(BlueprintPure)
	AGS2LoginDataRepository* GetAccountSaveService();
};
