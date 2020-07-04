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

	UE_LOG(LogTemp, Log, TEXT("GS2 SDK クライアント初期化"));

	auto clientIdHolder = new gs2::StringHolder(TCHAR_TO_ANSI(*clientId));
	auto clientSecretHolder = new gs2::StringHolder(TCHAR_TO_ANSI(*clientSecret));
	auto reopener = new gs2::ez::Gs2BasicReopener();
	auto profile = new gs2::ez::Profile
	(	
		*clientIdHolder,
		*clientSecretHolder,
		*reopener
	);

	{	
		auto fun = [&](gs2::ez::Profile::AsyncInitializeResult res) {
			if (res.getError().has_value())
				return;

			auto gs2Client = new gs2::ez::account::Client(*profile);

			UE_LOG(LogTemp, Log, TEXT("アカウントを新規作成"));

			auto accountCreateCallBack = [&](gs2::ez::account::AsyncEzCreateResult res) {
				if (res.getError().has_value())
					return;
				auto account = res.getResult().value().getItem();

				UE_LOG(LogTemp, Log, TEXT("ログイン"));
			};
			auto nameSpaceStringHolder = new gs2::StringHolder(TCHAR_TO_ANSI(*accountNamespaceName));
			gs2Client->create(accountCreateCallBack, *nameSpaceStringHolder);
		};
		profile->initialize(fun);


	}
}