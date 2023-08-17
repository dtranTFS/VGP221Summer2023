// Copyright Epic Games, Inc. All Rights Reserved.


#include "VGP221Summer2023GameModeBase.h"

void AVGP221Summer2023GameModeBase::StartPlay()
{
	Super::StartPlay();

	// C asset() <- stop the code here
	check(GEngine != nullptr)
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World! This is FPSGameModeBase!"));

	UE_LOG(LogTemp, Warning, TEXT("Hello World! This is FPSGameModeBase!"));

	// Spawn the starting UI
	// Make sure there's one UI on screen, destroy it
	if (CurrentWidget)
	{
		CurrentWidget->RemoveFromParent();
		CurrentWidget = nullptr;
	}

	// If no UI we gonna spawn one
	if (StartingWidgetClass)
	{
		CurrentWidget = CreateWidget<UFPSUserWidget>(GetWorld(), StartingWidgetClass);
		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}
}