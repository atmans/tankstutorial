// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "TankPawn.generated.h"  //Put new includes above

//Forward declarations
//class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class TANK_API ATankPawn : public APawn
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATankPawn();

	virtual void BeginPlay() override;
	
};
