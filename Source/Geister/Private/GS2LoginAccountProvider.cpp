// Fill out your copyright notice in the Description page of Project Settings.


#include "GS2LoginAccountProvider.h"

AGS2LoginAccountProvider::AGS2LoginAccountProvider()
{
	
}

void AGS2LoginAccountProvider::SetInitializeConfig(FGS2LoginAccountInitializeData& config)
{
	this->initializeConfig = config;
}

void AGS2LoginAccountProvider::Login()
{
	Profile = std::make_shared<gs2::ez::Profile>
	(
		*new gs2::StringHolder(TCHAR_TO_UTF8(*initializeConfig.ClientId)),
		*new gs2::StringHolder(TCHAR_TO_UTF8(*initializeConfig.ClientSecretId)),
		gs2::ez::Gs2BasicReopener()
	);
	Profile->initialize([&](gs2::ez::Profile::AsyncInitializeResult initializedResult)
	{
		if (initializedResult.getError().has_value())
		{
			return;
		}

		Client = std::make_shared<gs2::ez::account::Client>(*Profile);
		Client->create([&](gs2::ez::account::AsyncEzCreateResult createdAccountResult)
		{
			if (createdAccountResult.getError().has_value())
			{
				return;
			}

			Account = createdAccountResult.getResult().value().getItem();

			auto authenticator = gs2::ez::Gs2AccountAuthenticator
			(
				Profile->getGs2Session(),
				*new gs2::StringHolder(TCHAR_TO_UTF8(*initializeConfig.AccountNameSpaceName)),
				*new gs2::StringHolder(TCHAR_TO_UTF8(*initializeConfig.AuthAccountEncryptionKeyId)),
				*new gs2::StringHolder(TCHAR_TO_UTF8(*Account.getUserId())),
				*new gs2::StringHolder(TCHAR_TO_UTF8(*Account.getPassword()))
			);
			Profile->login([&](gs2::ez::Profile::AsyncLoginResult loggedinResult)
			{
				GameSession = loggedinResult.getResult().value();
			}, authenticator);
		}, *new gs2::StringHolder(TCHAR_TO_UTF8(*initializeConfig.AccountNameSpaceName)));
	});
}

void AGS2LoginAccountProvider::Logout()
{
}
