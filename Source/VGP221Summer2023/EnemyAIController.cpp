// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

AEnemyAIController::AEnemyAIController()
{
	PawnSensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensing"));
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	PawnSensing->OnSeePawn.AddDynamic(this, &AEnemyAIController::OnSeePawn);

	RunBehaviorTree(BehaviorTree);
}

void AEnemyAIController::OnSeePawn(APawn* PlayerPawn)
{
	AFPSCharacter* player = Cast<AFPSCharacter>(PlayerPawn);

	if (player) 
	{
		SetCanSeePlayer(true, player);
		RunTriggerableTimer();
		UE_LOG(LogTemp, Warning, TEXT("Stop Attacking"));
	}
}

void AEnemyAIController::SetCanSeePlayer(bool SeePlayer, class UObject* Player)
{
	UBlackboardComponent* bb = GetBlackboardComponent();
	if (SeePlayer)
	{
		bb->SetValueAsBool(FName("Can See Player"), SeePlayer);
		bb->SetValueAsObject(FName("Player Target"), Player);
	}
	else 
	{
		bb->SetValueAsBool(FName("Can See Player"), SeePlayer);
	}
}

void AEnemyAIController::RunTriggerableTimer()
{
	GetWorld()->GetTimerManager().ClearTimer(RetriggerableTimerHandle);

	FunctionDelegate.BindUFunction(this, FName("SetCanSeePlayer"), false, GetPawn());

	GetWorld()->GetTimerManager().SetTimer(RetriggerableTimerHandle, FunctionDelegate, PawnSensing->SensingInterval * 2.0f, false);
}
