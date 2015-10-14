// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CameraDirector.generated.h"

USTRUCT()
struct FCameraBlend
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	AActor* Camera;

	UPROPERTY(EditAnywhere)
	float BlendTime;

	FCameraBlend()
	{
		BlendTime = 2.0f;
		Camera = NULL;
	}
};

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

	static const int cameras_number = 6;

	FCameraBlend* CameraBlend;
	int n;

	UPROPERTY(EditAnywhere)
	AActor* MovingActor;

	float TimeToNextCameraChange;
	float RunningTime;

	UPROPERTY(EditAnywhere)
	FCameraBlend CameraBlends[cameras_number];

	void MoveActor(float DeltaTime);
	void BlendCameras(float DeltaTime);
	
};

