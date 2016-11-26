// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	//-1 to rotate left and 1 to rotate right
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxDegreesPerSecond = 50.f;
	
};
