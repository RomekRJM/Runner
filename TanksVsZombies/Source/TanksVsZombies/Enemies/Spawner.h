// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Spawner.generated.h"

UCLASS()
class TANKSVSZOMBIES_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ActorToSpawn;

	/** If anything matching this collision profile is present in the spawning volume, spawning will not be inhibited. */
	UPROPERTY(EditAnywhere)
	FName SpawnCollisionProfile;

	UPROPERTY()
	UBoxComponent* SpawnVolume;
};
