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
	CountdownTime = 3;
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
		//We're done counting down, so stop running the timer.
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		CountdownHasFinished();
	}
}

void AFlame::CountdownHasFinished_Implementation()
{
	//Change to a special readout
	FlameParticle->SetVisibility(false);
}
