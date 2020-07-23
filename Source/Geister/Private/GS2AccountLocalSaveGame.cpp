// Fill out your copyright notice in the Description page of Project Settings.


#include "GS2AccountLocalSaveGame.h"

UGS2AccountLocalSaveGame::UGS2AccountLocalSaveGame()
{
}

void UGS2AccountLocalSaveGame::Setting(FString _userId, FString _userPassword)
{
	userId = _userId;
	userPassword = _userPassword;
}
