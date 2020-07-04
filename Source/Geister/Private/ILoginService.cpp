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

	auto clientIdHolder = new gs2::StringHolder(TCHAR_TO_UTF8(*clientId));
	auto clientSecretHolder = new gs2::StringHolder(TCHAR_TO_UTF8(*clientSecret));
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

				gs2::ez::GameSession session;
				auto authenticator = new gs2::ez::Gs2AccountAuthenticator(
					profile->getGs2Session(),
					*new gs2::StringHolder(TCHAR_TO_UTF8(*accountNamespaceName)),
					*new gs2::StringHolder(TCHAR_TO_UTF8(*accountEncryptionKeyId)),
					*new gs2::StringHolder(TCHAR_TO_UTF8(*account.getUserId())),
					*new gs2::StringHolder(TCHAR_TO_UTF8(*account.getPassword()))
				);
				gs2::ez::Profile::LoginCallbackType loginCallback = [&](gs2::ez::Profile::AsyncLoginResult res)
				{
					session = res.getResult().value();
				};
				profile->login(loginCallback, authenticator);
			};
			auto nameSpaceStringHolder = new gs2::StringHolder(TCHAR_TO_UTF8(*accountNamespaceName));
			gs2Client->create(accountCreateCallBack, *nameSpaceStringHolder);
		};
		profile->initialize(fun);


	}
}