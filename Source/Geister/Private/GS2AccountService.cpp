// Fill out your copyright notice in the Description page of Project Settings.

#include "GS2AccountService.h"
#include "..\Public\GS2AccountService.h"


// Sets default values
AGS2AccountService::AGS2AccountService()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGS2AccountService::BeginPlay()
{
	Super::BeginPlay();
}

void AGS2AccountService::Initialize()
{
	InitializeProfile();
}

void AGS2AccountService::CreateAccount()
{
	if (ClientPtr == nullptr)
	{
		return;
	}

	UE_SUCCESS_LOG(TEXT("start create gs2 account"));

	ClientPtr->account.create(
		[this](gs2::ez::account::AsyncEzCreateResult createdResult)
	{
		if (createdResult.getError())
		{
			UE_ERROR_LOG(TEXT("failed create gs2 account"));
			return;
		}

		UE_SUCCESS_LOG(TEXT("successed create gs2 account"));
		EzAccount = createdResult.getResult()->getItem();
		CompleteCreatedProfileDelegate.Broadcast();
	},
		TCHAR_TO_ANSI(*AccountNamespaceName)
		);
}

FString AGS2AccountService::GetLoggedInUserId()
{
	return FString(EzAccount.getUserId().getCString());
}

FString AGS2AccountService::GetLoggedInUserPassword()
{	
	return FString(EzAccount.getPassword().getCString());
}

void AGS2AccountService::Login(UAccountLoginDTO* loginDTO)
{
	UE_SUCCESS_LOG(TEXT("start gs2 login"))
	auto gs2LoginDTO = Cast<UGS2AccountLoginDTO>(loginDTO);

	ProfilePtr->login(
		[this](gs2::ez::Profile::AsyncLoginResult loginedResult)
	{
		auto error = loginedResult.getError();
		if (error)
		{
			UE_ERROR_LOG(TEXT("failed gs2 login"))
			return;
		}

		UE_SUCCESS_LOG(TEXT("successed gs2 login"));
		GameSession = *loginedResult.getResult();
		CompleteLoggedInDelegate.Broadcast();
	},
		gs2::ez::Gs2AccountAuthenticator(
			ProfilePtr->getGs2Session(),
			TCHAR_TO_ANSI(*AccountNamespaceName),
			TCHAR_TO_ANSI(*AccountEncryptionKeyId),
			TCHAR_TO_ANSI(*gs2LoginDTO->GetUserId()),
			TCHAR_TO_ANSI(*gs2LoginDTO->GetPassword())
		)
		);
}

void AGS2AccountService::Logout()
{
	UE_SUCCESS_LOG(TEXT("start gs2 finalize"));
	ProfilePtr->finalize(
		[this]()
	{
		UE_ERROR_LOG(TEXT("successed gs2 finalize"));
		CompleteLoggedOutDelegate.Broadcast();
	}
	);
}

void AGS2AccountService::InitializeProfile()
{
	UE_SUCCESS_LOG(TEXT("start initialize profile"));

	ProfilePtr = std::make_shared<gs2::ez::Profile>(
		TCHAR_TO_ANSI(*ClientId),
		TCHAR_TO_ANSI(*ClientSecret),
		gs2::ez::Gs2BasicReopener()
		);

	ClientPtr = std::make_shared<gs2::ez::Client>(*ProfilePtr);

	ProfilePtr->initialize(
		[this](gs2::ez::Profile::AsyncInitializeResult initializeResult)
	{
		if (initializeResult.getError())
		{
			UE_ERROR_LOG(TEXT("failed initialize profile"));
			return;
		}

		UE_SUCCESS_LOG(TEXT("successed initialize profile"));

		CompleteInitializeProfileDelegate.Broadcast();
	}
	);
}

// Called every frame
void AGS2AccountService::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
