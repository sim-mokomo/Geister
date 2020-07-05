// Fill out your copyright notice in the Description page of Project Settings.


#include "GeiserSaveData.h"

UGeiserSaveData::UGeiserSaveData()
{
	
}

void UGeiserSaveData::SetBuildDatas(FString SavedUserId, FString SavedPassword)
{
	this->UserId = SavedUserId;
	this->Password = SavedPassword;
}

FString UGeiserSaveData::GetUserId()
{
	return this->UserId;
}

FString UGeiserSaveData::GetPassword()
{
	return this->Password;
}
