// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Projectile.h"
#include "TankPawn.h"


// Sets default values
ATankPawn::ATankPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//No need to protect points as added at construction
	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATankPawn::Fire()
{

	//if (!Barrel) { return; }

	if (!ensure(TankAimingComponent)) { return; }

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	////Spawn a projectile in the socket

	if (isReloaded)
	{
	//	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(
	//		ProjectileBlueprint,
	//		Barrel->GetSocketLocation(FName("Projectile")),
	//		Barrel->GetSocketRotation(FName("Projectile"))
	//		);

	//	Projectile->LaunchProjectile(LaunchSpeed);
	    TankAimingComponent->Fire(ProjectileBlueprint, LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

void ATankPawn::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
//	auto OurTankName = GetName();
//	UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s"), *OurTankName, *HitLocation.ToString());
}

