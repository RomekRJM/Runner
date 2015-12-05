// Fill out your copyright notice in the Description page of Project Settings.

#include "Components_Collision.h"
#include "OrbitingActor.h"


// Sets default values
AOrbitingActor::AOrbitingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOrbitingActor::BeginPlay()
{
	Super::BeginPlay();
	FVector StartLocation = GetActorLocation();
	xc = StartLocation.X;
	yc = StartLocation.Y - r;
	
}

// Called every frame
void AOrbitingActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	//float RandomValue = FMath::RandRange(0.6, 1.4);
	//DeltaTime *= RandomValue;

	FVector NewLocation = GetActorLocation();
	float NewX = xc + r * PeriodicCos(RunningTime, DeltaTime);
	float NewY = yc + r * PeriodicSin(RunningTime, DeltaTime);

	NewLocation.X = NewX;
	NewLocation.Y = NewY;

	RunningTime += DeltaTime;

	SetActorLocation(NewLocation);

}

float AOrbitingActor::PeriodicSin(const float RunningTime, const float DeltaTime)
{
	return (FMath::Sin(RunningTime + DeltaTime * 360) - FMath::Sin(RunningTime));
}

float AOrbitingActor::PeriodicCos(const float RunningTime, const float DeltaTime)
{
	return (FMath::Cos(RunningTime + DeltaTime * 360) - FMath::Cos(RunningTime));
}

