// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/VerticalBox.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "ButtonWidget.h"
#include "FPSUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class VGP221SUMMER2023_API UFPSUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
		UVerticalBox* VerticalBox;

	UPROPERTY(meta = (BindWidget))
		UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* Score;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UButtonWidget> ButtonWidgetRef;

	UFUNCTION()
	void SetHealthBar(float percetnage);

	UFUNCTION()
	void SetScore(int scoreAmount);

private:
	int UIScore;
};
