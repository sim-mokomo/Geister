// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "GeisterPlayerController.h"

AGeisterPlayerController::AGeisterPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableTouchEvents = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}
