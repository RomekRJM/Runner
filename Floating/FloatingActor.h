// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class FLOATING_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	float RunningTime;

	UPROPERTY(EditAnywhere)
	float FloatFactor;

	float PeriodicSin(const float RunningTime, const float DeltaTime);
	float PeriodicCos(const float RunningTime, const float DeltaTime);
	
};
