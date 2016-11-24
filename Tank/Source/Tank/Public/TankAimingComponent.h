// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//ENUM for aiming state
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

//Forward reference
class UTankBarrel;
class UTankTurret;
class AProjectile;

//Holds barrels properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
	
	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation);

	

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;



private:
	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 8000; // TODO find sensible default value (currently 1000 m/s)

	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;  //see https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf/

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrel(FVector AimDirection);
	void MoveTurret(FVector AimDirection);

	float ReloadTimeInSeconds = 3.f;
	double LastFireTime = 0;

};
