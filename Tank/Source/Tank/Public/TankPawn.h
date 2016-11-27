// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "TankPawn.generated.h"  //Put new includes above


UCLASS()
class TANK_API ATankPawn : public APawn
{
	GENERATED_BODY()

public:
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	
	//Returns current health as a percentage of starting health, between 0 to 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;


private:
	// Sets default values for this pawn's properties
	ATankPawn();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartHealth = 100;
	
	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth = StartHealth;

	virtual void BeginPlay() override;

};
