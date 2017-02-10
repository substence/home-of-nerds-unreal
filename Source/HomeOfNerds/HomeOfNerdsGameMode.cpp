// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "HomeOfNerds.h"
#include "HomeOfNerdsGameMode.h"
#include "HomeOfNerdsPlayerController.h"
#include "HomeOfNerdsCharacter.h"

AHomeOfNerdsGameMode::AHomeOfNerdsGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AHomeOfNerdsPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}