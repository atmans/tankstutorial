// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...


}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	//auto OurTankName = GetOwner()->GetName();
	//auto BarrelLocation = Barrel->GetComponentLocation();
	//UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s from %s"), *OurTankName, *HitLocation.ToString(),*BarrelLocation.ToString());

	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	// Calculate the OutLaunchVelocity

	if (UGameplayStatics::SuggestProjectileVelocity
			(
				this,
				OutLaunchVelocity,
				StartLocation,
				HitLocation,
				LaunchSpeed,
				false,
				0,
				0,
				ESuggestProjVelocityTraceOption::DoNotTrace
			)
		)
	{
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("Firing at %s "), *AimDirection.ToString());
		MoveBarrel(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();  //current rotation
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(5.f);
}

