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

void AILoginService::Initialize()
{
	UE_LOG(LogTemp, Display, TEXT("start initialize profile"));
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
			UE_LOG(LogTemp, Error, TEXT("failed initialize profile"));
			return;
		}

		UE_LOG(LogTemp, Display, TEXT("successed initialize profile"));

		CompleteInitializeProfileDelegate.Broadcast();
	}
	);
}

void AILoginService::CreateAccount()
{
	if (ClientPtr == nullptr)
	{
		return;
	}

	UE_LOG(LogTemp, Display, TEXT("start create gs2 account"));

	ClientPtr->account.create(
		[this](gs2::ez::account::AsyncEzCreateResult createdResult)
	{
		if (createdResult.getError())
		{
			UE_LOG(LogTemp, Error, TEXT("failed create gs2 account"));
			return;
		}

		UE_LOG(LogTemp, Display, TEXT("successed create gs2 account"));
		EzAccount = createdResult.getResult()->getItem();
		CompleteCreatedProfileDelegate.Broadcast();
	},
		TCHAR_TO_ANSI(*AccountNamespaceName)
		);
}

FString AILoginService::GetLoggedInUserId()
{
	return FString(EzAccount.getUserId().getCString());
}

FString AILoginService::GetLoggedInUserPassword()
{	
	return FString(EzAccount.getPassword().getCString());
}

void AILoginService::Login(FString UserId,FString Password)
{
	UE_LOG(LogTemp, Display, TEXT("start gs2 login"));

	ProfilePtr->login(
		[this](gs2::ez::Profile::AsyncLoginResult loginedResult)
	{
		if (loginedResult.getError())
		{
			UE_LOG(LogTemp, Error, TEXT("failed gs2 login"));
			return;
		}

		UE_LOG(LogTemp, Display, TEXT("successed gs2 login"));
		GameSession = *loginedResult.getResult();
		CompleteLoggedInDelegate.Broadcast();
	},
		gs2::ez::Gs2AccountAuthenticator(
			ProfilePtr->getGs2Session(),
			TCHAR_TO_ANSI(*AccountNamespaceName),
			TCHAR_TO_ANSI(*AccountEncryptionKeyId),
			TCHAR_TO_ANSI(*UserId),
			TCHAR_TO_ANSI(*Password)
		)
		);
}

void AILoginService::Finalize()
{
	UE_LOG(LogTemp, Display, TEXT("start gs2 finalize"));
	ProfilePtr->finalize(
		[this]()
	{
		UE_LOG(LogTemp, Display, TEXT("successed gs2 finalize"));
		CompleteLoggedOutDelegate.Broadcast();
	}
	);
}

// Called every frame
void AILoginService::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
