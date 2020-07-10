// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LoginAccountProvider.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnError);

USTRUCT()
struct FLoginAccountInitializeData
{
	GENERATED_BODY()
public:
    FLoginAccountInitializeData()
    {
		
    };
};

UCLASS()
class GEISTER_API ALoginAccountProvider : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALoginAccountProvider();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
    FOnSuccess OnSuccessDelegate;
	UPROPERTY()
    FOnError OnErrorDelegate;

	virtual void Login();
	virtual void Logout();
};
