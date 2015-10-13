// Fill out your copyright notice in the Description page of Project Settings.

#include "GameControlledCamera.h"
#include "CameraDirector.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Camera = Cameras;
	n = 0;
}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraDirector::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector NewLocation = MovingActor->GetActorLocation();

	float DeltaMove = FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime);
	NewLocation.Z += DeltaMove * 20;
	MovingActor->SetActorLocation(NewLocation);

	RunningTime += DeltaTime;

	const float TimeBetweenCameraChanges = 2.0f;
	const float SmoothBlendTime = 0.75f;
	TimeToNextCameraChange -= DeltaTime;
	if (TimeToNextCameraChange <= 0.0f)
	{
		TimeToNextCameraChange += TimeBetweenCameraChanges;

		// Find the actor that handles control for the local player.
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if ((OurPlayerController->GetViewTarget() != *Camera) && (*Camera != nullptr))
			{
				if (n == 0)
				{
					// Cut instantly to camera
					OurPlayerController->SetViewTarget(*Camera);
				}
				else 
				{
					// Blend smoothly to camera two.
					OurPlayerController->SetViewTargetWithBlend(*Camera, SmoothBlendTime);
				}
			}
			++n;

			if (n < cameras_number)
			{
				++Camera;
			}
			else
			{
				Camera = Cameras;
				n = 0;
			}
		}
	}
}
