// Fill out your copyright notice in the Description page of Project Settings.

#include "ILoginService.h"

// Sets default values
AILoginService::AILoginService()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AILoginService::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AILoginService::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AILoginService::Login()
{
	auto clientIdHolder = new gs2::StringHolder(TCHAR_TO_ANSI(*clientId));
	auto clientSecretHolder = new gs2::StringHolder(TCHAR_TO_ANSI(*clientSecret));
	auto reopener = new gs2::ez::Gs2BasicReopener();
	auto profile = new gs2::ez::Profile
	(	
		*clientIdHolder,
		*clientSecretHolder,
		*reopener
	);
}

