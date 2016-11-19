// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	//work out difference between current barrel rotation and aimdirection
	//Move Turret in the direction to aim
	//move the burrel height the angle needed to hit target

	UE_LOG(LogTemp, Warning, TEXT("Elevating at %f "), DegreesPerSecond);
};

