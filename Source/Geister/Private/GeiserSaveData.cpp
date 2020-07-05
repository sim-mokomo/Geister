// Fill out your copyright notice in the Description page of Project Settings.


#include "GeiserSaveData.h"

UGeiserSaveData::UGeiserSaveData()
{
	
}

void UGeiserSaveData::SetBuildDatas(FString UserId, FString Password)
{
	this->UserId = UserId;
	this->Password = Password;
}

FString UGeiserSaveData::GetUserId()
{
	return this->UserId;
}

FString UGeiserSaveData::GetPassword()
{
	return this->Password;
}
