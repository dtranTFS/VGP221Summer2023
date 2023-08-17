// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "ButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class VGP221SUMMER2023_API UButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	UButton* Button;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text;

	int num;
	void SetText(int value);

	UFUNCTION()
	void OnButtonClick();
};
