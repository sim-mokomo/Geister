// Fill out your copyright notice in the Description page of Project Settings.

#include "GS2LoginAccountProvider.h"
#include "LogFunctionLibrary.h"

void AGS2LoginAccountProvider::LoginByAccount(gs2::ez::account::EzAccount account)
{
	auto authenticator = gs2::ez::Gs2AccountAuthenticator
	(
		Profile->getGs2Session(),
		*UGS2FunctionLibrary::CreateStringHolderFromFString(initializeConfig.AccountNameSpaceName),
		*UGS2FunctionLibrary::CreateStringHolderFromFString(initializeConfig.AuthAccountEncryptionKeyId),
		account.getUserId(),
		account.getPassword()
	);
	Profile->login([&](gs2::ez::Profile::AsyncLoginResult loggedinResult)
	{
		if (loggedinResult.getError().has_value())
		{
			OnErrorDelegate.Broadcast();
			return;
		}

		GameSession = loggedinResult.getResult().value();

		OnSuccessDelegate.Broadcast();
	}, authenticator);
}

void AGS2LoginAccountProvider::BeginPlay()
{
}

AGS2LoginAccountProvider::AGS2LoginAccountProvider()
{
	SetActorLabel("GS2LoginAccountProvider");
}

void AGS2LoginAccountProvider::SetInitializeConfig(FGS2LoginAccountInitializeData& config)
{
	initializeConfig = config;
}

void AGS2LoginAccountProvider::Login()
{
	AccountLocalSaveGameProvider = GetWorld()->SpawnActor<AGS2AccountLocalSaveGameProvider>();
	AccountLocalSaveGameProvider->SetActorLabel("GS2AccountLocalSaveGameProvider");

	Profile = std::make_shared<gs2::ez::Profile>
		(
			*UGS2FunctionLibrary::CreateStringHolderFromFString(initializeConfig.ClientId),
			*UGS2FunctionLibrary::CreateStringHolderFromFString(initializeConfig.ClientSecretId),
			gs2::ez::Gs2BasicReopener()
			);
	Profile->initialize([&](gs2::ez::Profile::AsyncInitializeResult initializedResult)
	{
		if (initializedResult.getError().has_value())
		{
			OnErrorDelegate.Broadcast();
			return;
		}

		Client = std::make_shared<gs2::ez::account::Client>(*Profile);
		if (AccountLocalSaveGameProvider->ExistsSaveGame())
		{
			auto savedGameInstance = AccountLocalSaveGameProvider->GetSaveGame();
			Client->authentication([&](gs2::ez::account::AsyncEzAuthenticationResult authenticationResult)
			{
				if (authenticationResult.getError().has_value())
				{
					OnErrorDelegate.Broadcast();
					return;
				}

				Account = authenticationResult.getResult().value().getItem();
				LoginByAccount(Account);
			},
				*UGS2FunctionLibrary::CreateStringHolderFromFString(initializeConfig.AccountNameSpaceName),
				*UGS2FunctionLibrary::CreateStringHolderFromFString(savedGameInstance->GetUserId()),
				*UGS2FunctionLibrary::CreateStringHolderFromFString(initializeConfig.AuthAccountEncryptionKeyId),
				*UGS2FunctionLibrary::CreateStringHolderFromFString(savedGameInstance->GetUserPassword()));
		}
		else
		{
			Client->create([&](gs2::ez::account::AsyncEzCreateResult createdAccountResult)
			{
				if (createdAccountResult.getError().has_value())
				{
					OnErrorDelegate.Broadcast();
					return;
				}
				Account = createdAccountResult.getResult().value().getItem();
				AccountLocalSaveGameProvider->Save(
					FString(Account.getUserId().getCString()),
					FString(Account.getPassword().getCString()));
				LoginByAccount(Account);
			}, *UGS2FunctionLibrary::CreateStringHolderFromFString(initializeConfig.AccountNameSpaceName));
		}
	});
}

void AGS2LoginAccountProvider::Logout()
{
}
