// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Flame.generated.h"

UCLASS()
class TORCH_API AFlame : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlame();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UParticleSystemComponent* FlameParticle;
	
	UParticleSystemComponent* FindFlameParticle();

	void AdvanceTimer();

	void ResetTimer();

	FTimerHandle CountdownTimerHandle;

	UPROPERTY(EditAnywhere)
	int32 CountdownTime;

	UFUNCTION(BlueprintNativeEvent)
	void CountdownHasFinished();

	virtual void CountdownHasFinished_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void AddFuel();

	virtual void AddFuel_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void DouseWithWater();

	virtual void DouseWithWater_Implementation();

	bool Wet;
	
};
