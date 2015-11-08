// Fill out your copyright notice in the Description page of Project Settings.

#include "AutomaticDoor.h"
#include "Door.h"


// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	Direction = 1;
	this->ResetTimer();
}

// Called every frame
void ADoor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void ADoor::AdvanceTimer()
{
	--CountdownTime;
	if (CountdownTime < 1)
	{
		CountdownHasFinished();
	}
	else 
	{
		UpdateDoorPosition();
	}
}

void ADoor::UpdateDoorPosition()
{
	FRotator rotation = GetActorRotation();
	FVector pivot = GetPivotOffset();
	pivot.Y -= 80.0;
	SetPivotOffset(pivot);
	rotation.Add(0, 0.7 * Direction, 0);
	SetActorRotation(rotation);
}

void ADoor::CountdownHasFinished_Implementation()
{
	Direction *= -1;
	this->ResetTimer();
}

void ADoor::ResetTimer()
{
	CountdownTime = 50;
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ADoor::AdvanceTimer, 0.07f, true);
}
