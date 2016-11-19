// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	//work out difference between current barrel rotation and aimdirection
	//Move Turret in the direction to aim
	//move the burrel height the angle needed to hit target
	auto NewRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);
	auto RotationChange = NewRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));

	//UE_LOG(LogTemp, Warning, TEXT("Elevating at %f "), Rotation);
};


