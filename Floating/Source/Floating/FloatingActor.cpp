// Fill out your copyright notice in the Description page of Project Settings.

#include "Floating.h"
#include "FloatingActor.h"


// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	//float RandomValue = FMath::RandRange(0.6, 1.4);
	//DeltaTime *= RandomValue;

	FVector NewLocation = GetActorLocation();
	float DeltaHeightX = PeriodicSin(RunningTime, DeltaTime);
	float DeltaHeightY = PeriodicSin(RunningTime, DeltaTime);
	float DeltaHeightZ = PeriodicCos(RunningTime, DeltaTime);
	NewLocation.X -= DeltaHeightX * FloatFactor;
	NewLocation.Y += DeltaHeightY * FloatFactor;
	NewLocation.Z += DeltaHeightZ * FloatFactor;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
}

float AFloatingActor::PeriodicSin(const float RunningTime, const float DeltaTime)
{
	return (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
}

float AFloatingActor::PeriodicCos(const float RunningTime, const float DeltaTime)
{
	return (FMath::Cos(RunningTime + DeltaTime) - FMath::Cos(RunningTime));
}

