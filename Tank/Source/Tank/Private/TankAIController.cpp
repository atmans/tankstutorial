// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankPawn.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	auto ControlledTank = Cast<ATankPawn>(GetPawn());
	auto PlayerTank = Cast<ATankPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerTank)
	{
		//TODO Move towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		//TODO Fire at player when ready

		ControlledTank->Fire();
	}
}



