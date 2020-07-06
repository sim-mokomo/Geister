// Fill out your copyright notice in the Description page of Project Settings.


#include "GS2LoginSaveData.h"

UGS2LoginSaveData::UGS2LoginSaveData()
{
	
}

void UGS2LoginSaveData::SetBuildDatas(FString SavedUserId, FString SavedPassword)
{
	this->UserId = SavedUserId;
	this->Password = SavedPassword;
}

FString UGS2LoginSaveData::GetUserId()
{
	return this->UserId;
}

FString UGS2LoginSaveData::GetPassword()
{
	return this->Password;
}
