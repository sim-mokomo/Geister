// Fill out your copyright notice in the Description page of Project Settings.


#include "GS2AccountLoginDTO.h"

UGS2AccountLoginDTO::UGS2AccountLoginDTO()
{
}

void UGS2AccountLoginDTO::Initialize(FString saveUserId, FString savePassword)
{
	this->UserId = saveUserId;
	this->Password = savePassword;
}

FString UGS2AccountLoginDTO::GetUserId()
{
	return this->UserId;
}

FString UGS2AccountLoginDTO::GetPassword()
{
	return this->Password;
}
