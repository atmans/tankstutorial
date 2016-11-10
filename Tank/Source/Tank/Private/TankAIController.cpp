// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankPawn.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find the player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *PlayerTank->GetName());
	}

}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (GetPlayerTank())
	{
		//TODO Move towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		//TODO Fire at player when ready
	}
}

ATankPawn* ATankAIController::GetControlledTank() const
{

	return Cast<ATankPawn>(GetPawn());
}


ATankPawn* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerTank)
	{
		return nullptr;
	}

	return Cast<ATankPawn>(PlayerTank);
}

