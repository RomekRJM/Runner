// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CameraDirector.generated.h"

UCLASS()
class GAMECONTROLLEDCAMERA_API ACameraDirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraDirector();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	static const int cameras_number = 4;

	UPROPERTY(EditAnywhere)
	AActor* Cameras[cameras_number];

	AActor** Camera;
	int n;

	//UPROPERTY(EditAnywhere)
	//AActor* CameraTwo;

	float TimeToNextCameraChange;
	float RunningTime;
	
};
