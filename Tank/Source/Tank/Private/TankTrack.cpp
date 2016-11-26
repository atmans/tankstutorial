// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankTrack.h"


UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();

	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);

}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
//
	//if (CurrentThrottle != 0)
	//{
	//	//UE_LOG(LogTemp, Warning, TEXT("hitting"));
	//	DrivingTrack();
	//	ApplySidewaysForce();
	//	CurrentThrottle = 0;
	//}
//
}

void UTankTrack::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);

	//UE_LOG(LogTemp, Warning, TEXT("%s current throttle %f"), *GetName(), CurrentThrottle);
	//CurrentThrottle = CurrentThrottle + Throttle;
}

void UTankTrack::DrivingTrack()
{
	//auto Time = GetWorld()->GetTimeSeconds();

	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	//Drive tracks
	//apply a sideways force
	//UE_LOG(LogTemp, Warning, TEXT("hitting"));
	DrivingTrack();
	ApplySidewaysForce();
	CurrentThrottle = 0;

}

void UTankTrack::ApplySidewaysForce()
{
	// Calculate the slippage speed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	auto DeltaTime = GetWorld()->GetDeltaSeconds();

	// Calculate the corrective acceleration required
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector(); //we want to apply the corrective acceleration to the opposite direction of the slippage (hence minus)

																				 // calcuate the corrective force sideways (F = m a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; //divide by 2 for the two tracks ---> F = m a

																			   // apply corrective force
	TankRoot->AddForce(CorrectionForce);
}



