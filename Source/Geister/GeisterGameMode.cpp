// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "GeisterGameMode.h"
#include "GeisterPlayerController.h"
#include "GeisterPawn.h"

AGeisterGameMode::AGeisterGameMode()
{
	// no pawn by default
	DefaultPawnClass = AGeisterPawn::StaticClass();
	// use our own player controller class
	PlayerControllerClass = AGeisterPlayerController::StaticClass();
}
