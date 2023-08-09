// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSHUD.h"

void AFPSHUD::DrawHUD()
{
	Super::DrawHUD();

	if (CrosshairTexture)
	{
		FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

		float CrosshairCenterWidth = (CrosshairTexture->GetSurfaceWidth() * 0.5f);
		float CrosshairCenterHeight = (CrosshairTexture->GetSurfaceHeight() * 0.5f);
		FVector2D CrossHairDrawPosition(Center.X - CrosshairCenterWidth, Center.Y - CrosshairCenterHeight);

		// Draw crosshair in the center of the screen
		FCanvasTileItem TileItem(CrossHairDrawPosition, CrosshairTexture->GetResource(), FLinearColor::White);
		TileItem.BlendMode = SE_BLEND_Translucent;
		Canvas->DrawItem(TileItem);
	}
}
