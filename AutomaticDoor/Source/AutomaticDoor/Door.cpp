// Fill out your copyright notice in the Description page of Project Settings.

#include "AutomaticDoor.h"
#include "Door.h"


// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	Opened = false;
}

// Called every frame
void ADoor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (!Opened) 
	{
		Opened = true;
	} 
	else
	{
		return;
	}

	FRotator rotation = GetActorRotation();
	rotation.Add(0,60,0);
	SetActorRotation(rotation);

}

