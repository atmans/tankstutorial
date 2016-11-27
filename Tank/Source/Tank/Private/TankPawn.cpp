// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankPawn.h"


float ATankPawn::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartHealth;
}

// Sets default values
ATankPawn::ATankPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

void ATankPawn::BeginPlay()
{
	Super::BeginPlay();

}

float ATankPawn::TakeDamage(float DamageAmount, FDamageEvent const &DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);  //convert and round float to int
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);  //damage somewhere between 0 and current health

	CurrentHealth -= DamageToApply;

	if (CurrentHealth <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s died!"), *GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("DamagePoints %i"), DamagePoints);
	return DamageToApply;
}



