// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Collectable.h"
#include "Kismet/GameplayStatics.h"
#include "VGP221Summer2023GameModeBase.h"
#include "Coin.generated.h"

UCLASS()
class VGP221SUMMER2023_API ACoin : public ACollectable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnCollect() override;

	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* CoinMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RotationRate = 100;

	FTimerHandle DeathTimerHandle;

	void DeathTimerComplete();

	int points = 1;
};
