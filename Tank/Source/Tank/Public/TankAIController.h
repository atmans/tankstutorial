// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */

//Forward declarations
class ATankPawn;

UCLASS()
class TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;
	virtual void Tick(float) override;

	ATankPawn* GetControlledTank() const;

	ATankPawn* GetPlayerTank() const;
};
