// Fill out your copyright notice in the Description page of Project Settings.


#include "RootGameSequencer.h"

// Sets default values
ARootGameSequencer::ARootGameSequencer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARootGameSequencer::BeginPlay()
{
	Super::BeginPlay();

	LoginAccountProvider->Initialize();
	LoginAccountProvider->OnSuccessDelegate.AddDynamic(this,&ARootGameSequencer::SuccessedLoggedin);
	LoginAccountProvider->OnErrorDelegate.AddDynamic(this,&ARootGameSequencer::FailedLoggedin);
	LoginAccountProvider->Login();
}

// Called every frame
void ARootGameSequencer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARootGameSequencer::SuccessedLoggedin()
{
	UE_SUCCESS_LOG("sucessed login");
}

void ARootGameSequencer::FailedLoggedin()
{
	UE_SUCCESS_LOG("sucessed logout");
}
