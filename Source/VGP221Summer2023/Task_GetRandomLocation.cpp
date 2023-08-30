// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_GetRandomLocation.h"

EBTNodeResult::Type UTask_GetRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	NavArea = FNavigationSystem::GetCurrent<UNavigationSystemV1>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	if (NavArea)
	{
		NavArea->K2_GetRandomLocationInNavigableRadius(GetWorld(), GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation(), RandomLocation, 15000.0f);
	}
	else
	{
		// When we can't point on the nav mesh
		return EBTNodeResult::Failed;
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("Random Patrol Location"), RandomLocation);

	return EBTNodeResult::Succeeded;
}