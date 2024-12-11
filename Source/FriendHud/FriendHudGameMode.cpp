// Copyright Epic Games, Inc. All Rights Reserved.

#include "FriendHudGameMode.h"
#include "FriendHudCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFriendHudGameMode::AFriendHudGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
