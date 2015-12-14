// Fill out your copyright notice in the Description page of Project Settings.

#include "Components_Collision.h"
#include "SpawnActorComponent.h"
#include "DummyActor.h"


// Sets default values
ADummyActor::ADummyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADummyActor::BeginPlay()
{
	Super::BeginPlay(); 

	// Create an instance of our movement component, and tell it to update the root.
	SpawnComponent = NewObject<USpawnActorComponent>(this);
	SpawnComponent->RegisterComponent();
}

// Called every frame
void ADummyActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

