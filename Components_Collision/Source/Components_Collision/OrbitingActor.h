// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "OrbitingActor.generated.h"

UCLASS()
class COMPONENTS_COLLISION_API AOrbitingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOrbitingActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	float PeriodicSin(const float RunningTime, const float DeltaTime);

	float PeriodicCos(const float RunningTime, const float DeltaTime);


	float RunningTime;
	const float r = 30;
	float xc;
	float yc;
	
	
};
