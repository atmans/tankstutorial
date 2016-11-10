// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankPawn.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possessing %s"), *ControlledTank->GetName());
	}

}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardsCrosshair();
}

ATankPawn* ATankPlayerController::GetControlledTank() const
{

	return Cast<ATankPawn>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() 
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; //Out Parameter

	if (GetSightRayHitLocation(HitLocation))  //Has "side-effect" in that it is going to line trace
	{
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"),*HitLocation.ToString());
		//Tell controlled tank to aim at this point
	}
	
	
	//Get world location of linetrace through crosshair
	//if it hits the landscape
		

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//find crosshair posiiton in pixil coordinates
	int32 ViewportSizeX, ViewportSizeY; //out parameters

	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	
	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("LookDirection: %s"), *LookDirection.ToString());
	}
	//line-trace along that look direction and see what we hit (up to a max range)
	
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	FVector LookDirection;

	//"de-project" screen position o fthe crosshair to world direction
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}




