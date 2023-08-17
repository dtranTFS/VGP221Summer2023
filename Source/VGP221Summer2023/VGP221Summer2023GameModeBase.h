// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPSUserWidget.h"
#include "VGP221Summer2023GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class VGP221SUMMER2023_API AVGP221Summer2023GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
		UFPSUserWidget* CurrentWidget;

protected:
	virtual void StartPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<class UFPSUserWidget> StartingWidgetClass;
};
