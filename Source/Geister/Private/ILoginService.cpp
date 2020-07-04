// Fill out your copyright notice in the Description page of Project Settings.

#include "ILoginService.h"
#include "..\Public\ILoginService.h"


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

void AILoginService::InitializeProfile(std::function<void(gs2::ez::Profile::AsyncInitializeResult)> onComplete)
{
	UE_LOG(LogTemp, Log, TEXT("start initialize profile"));
	ProfilePtr = std::make_shared<gs2::ez::Profile>(
		TCHAR_TO_ANSI(*clientId),
		TCHAR_TO_ANSI(*clientSecret),
		gs2::ez::Gs2BasicReopener()
		);

	ClientPtr = std::make_shared<gs2::ez::Client>(*ProfilePtr);

	ProfilePtr->initialize(
		[this,&onComplete](gs2::ez::Profile::AsyncInitializeResult initializeResult)
	{
		if (initializeResult.getError())
		{
			UE_LOG(LogTemp, Error, TEXT("failed initialize profile"));
			return;
		}

		UE_LOG(LogTemp, Log, TEXT("successed initialize profile"));

		//onComplete(initializeResult);
		CreateAccount(nullptr);
	}
	);
}

void AILoginService::CreateAccount(std::function<void(gs2::ez::account::AsyncEzCreateResult)> onComplete)
{
	if (ClientPtr == nullptr)
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("start create gs2 account"));

	ClientPtr->account.create(
		[this,&onComplete](gs2::ez::account::AsyncEzCreateResult createdResult)
	{
		if (createdResult.getError())
		{
			UE_LOG(LogTemp, Error, TEXT("failed create gs2 account"));
			return;
		}

		UE_LOG(LogTemp, Log, TEXT("successed create gs2 account"));
		//onComplete(createdResult);
		EzAccount = createdResult.getResult()->getItem();
		LoginByProfile(nullptr);
	},
		TCHAR_TO_ANSI(*accountNamespaceName)
		);
}

void AILoginService::LoginByProfile(std::function<void(gs2::ez::Profile::AsyncLoginResult)> onComplete)
{
	UE_LOG(LogTemp, Log, TEXT("start gs2 login"));
	ProfilePtr->login(
		[this,&onComplete](gs2::ez::Profile::AsyncLoginResult loginedResult)
	{
		if (loginedResult.getError())
		{
			UE_LOG(LogTemp, Error, TEXT("failed gs2 login"));
			return;
		}

		UE_LOG(LogTemp, Log, TEXT("successed gs2 login"));
		//onComplete(loginedResult);

		GameSession = *loginedResult.getResult();
	},
		gs2::ez::Gs2AccountAuthenticator(
			ProfilePtr->getGs2Session(),
			TCHAR_TO_ANSI(*accountNamespaceName),
			TCHAR_TO_ANSI(*accountEncryptionKeyId),
			EzAccount.getUserId(),
			EzAccount.getPassword()
		)
		);
}

void AILoginService::FinalizeProfile(std::function<void(void)> onComplete)
{
	UE_LOG(LogTemp, Log, TEXT("start gs2 finalize"));
	ProfilePtr->finalize(
		[this,&onComplete]()
	{
		UE_LOG(LogTemp, Log, TEXT("successed gs2 finalize"));
		//onComplete();
	}
	);
}

// Called every frame
void AILoginService::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AILoginService::Login()
{
	InitializeProfile([this](gs2::ez::Profile::AsyncInitializeResult initializedProfileResult)
	{
		CreateAccount([this](gs2::ez::account::AsyncEzCreateResult createdResult) {
			//EzAccount = createdResult.getResult()->getItem();
			LoginByProfile([this](gs2::ez::Profile::AsyncLoginResult loginedResult) {
				//GameSession = *loginedResult.getResult();
			});
		});
	});
}

void AILoginService::Logout()
{
	FinalizeProfile([this]() {
		//TODO: finalize anything
	});
}
