// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Spawner.h"
#include "TankStatics.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 2.0f;

	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));
	FVector BoxExtent = SpawnVolume->GetUnscaledBoxExtent();
	BoxExtent.Z = 100.0f;
	SpawnVolume->SetBoxExtent(BoxExtent, false);
	if (RootComponent)
	{
		SpawnVolume->SetupAttachment(RootComponent);
	}
	else
	{
		RootComponent = SpawnVolume;
	}

	SpawnCollisionProfile = TEXT("Spawner:Block");
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
	UTankStatics::PutInZPlane(this);
}

// Called every frame
void ASpawner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (ActorToSpawn)
	{
		if (UWorld* World = GetWorld())
		{
			FCollisionShape CollisionShape;
			CollisionShape.SetBox(SpawnVolume->GetUnscaledBoxExtent());
			if (!World->OverlapAnyTestByProfile(SpawnVolume->GetComponentLocation(), SpawnVolume->GetComponentRotation().Quaternion(), SpawnCollisionProfile, CollisionShape))
			{
				if (AActor* SpawnedActor = World->SpawnActor(ActorToSpawn->GetDefaultObject()->GetClass()))
				{
					SpawnedActor->SetActorLocation(UKismetMathLibrary::RandomPointInBoundingBox(SpawnVolume->GetComponentLocation(), SpawnVolume->GetUnscaledBoxExtent()));
					UTankStatics::PutInZPlane(SpawnedActor);
				}
			}
		}
	}
}
