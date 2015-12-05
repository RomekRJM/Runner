// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PawnMovementComponent.h"
#include "OrbitingPawnMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class COMPONENTS_COLLISION_API UOrbitingPawnMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
	
public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	float PeriodicSin(const float RunningTime, const float DeltaTime);

	float PeriodicCos(const float RunningTime, const float DeltaTime);

	float RunningTime;
	const float r = 30;
	float xc;
	float yc;
	
	
};
