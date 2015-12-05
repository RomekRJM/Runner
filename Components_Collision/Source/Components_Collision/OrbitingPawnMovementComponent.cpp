// Fill out your copyright notice in the Description page of Project Settings.

#include "Components_Collision.h"
#include "OrbitingPawnMovementComponent.h"

void UOrbitingPawnMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Make sure that everything is still valid, and that we are allowed to move.
	if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
	{
		return;
	}

	if (xc == 0 && yc == 0)
	{
		FVector StartLocation = PawnOwner->GetActorLocation();
		xc = StartLocation.X;
		yc = StartLocation.Y - r;
	}

	FVector NewLocation = PawnOwner->GetActorLocation();

	NewLocation.X = xc + r * PeriodicCos(RunningTime, DeltaTime);
	NewLocation.Y = yc + r * PeriodicSin(RunningTime, DeltaTime);

	RunningTime += DeltaTime;

	PawnOwner->SetActorLocation(NewLocation);

}

float UOrbitingPawnMovementComponent::PeriodicSin(const float RunningTime, const float DeltaTime)
{
	return (FMath::Sin(RunningTime + DeltaTime * 360) - FMath::Sin(RunningTime));
}

float UOrbitingPawnMovementComponent::PeriodicCos(const float RunningTime, const float DeltaTime)
{
	return (FMath::Cos(RunningTime + DeltaTime * 360) - FMath::Cos(RunningTime));
}

