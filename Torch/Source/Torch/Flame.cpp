// Fill out your copyright notice in the Description page of Project Settings.

#include "Torch.h"
#include "Flame.h"


// Sets default values
AFlame::AFlame()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AFlame::BeginPlay()
{
	Super::BeginPlay();
	FlameParticle = FindFlameParticle();
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &AFlame::AdvanceTimer, 1.0f, true);
	Wet = false;
}

// Called every frame
void AFlame::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

UParticleSystemComponent* AFlame::FindFlameParticle()
{
	UParticleSystemComponent* Particle = nullptr;
	TArray<UParticleSystemComponent*> particles;
	GetComponents(particles);
	for (UParticleSystemComponent* particle : particles)
	{
		if (particle->GetName().Equals("Flame"))
		{
			Particle = particle;
			break;
		}
	}

	return Particle;
}

void AFlame::AdvanceTimer()
{
	--CountdownTime;
	if (CountdownTime < 1)
	{
		CountdownHasFinished();
	}
}

void AFlame::ResetTimer() 
{
	CountdownTime = 20;
}

void AFlame::CountdownHasFinished_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("CountdownHasFinished()"));
	AddFuel();
}

void AFlame::AddFuel_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("AddFuel()"));
	if (!Wet) {
		ResetTimer();
		DouseWithWater();
	}
	else {
		CountdownTime = 0;
	}
}

void AFlame::DouseWithWater_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("DouseWithWater()"));
	Wet = true;
	FlameParticle->SetVisibility(false);
	GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
	AddFuel();
}
