// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankPawn.h"
#include "TankPlayerController.h"

ATankPawn* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATankPawn>(GetPawn());
}




