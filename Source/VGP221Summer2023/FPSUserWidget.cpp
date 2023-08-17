// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSUserWidget.h"

void UFPSUserWidget::NativeConstruct()
{
	SetHealthBar(1.0);
	SetScore(0);

	if (ButtonWidgetRef)
	{
		for (int i = 0; i < 4; i++)
		{
			UUserWidget* widget = CreateWidget(this, ButtonWidgetRef);
			VerticalBox->AddChildToVerticalBox(widget);
			UButtonWidget* button = Cast<UButtonWidget>(widget);
			button->SetText(i);
		}
	}
}

void UFPSUserWidget::SetHealthBar(float percetnage)
{
	if (!HealthBar) return;

	HealthBar->SetPercent(percetnage);
}

void UFPSUserWidget::SetScore(int scoreAmount)
{
	if (!Score) return;

	UIScore += scoreAmount;
	Score->SetText(FText::FromString("Score :" + FString::FromInt(UIScore)));
}
