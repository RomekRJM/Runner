// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Zombie.h"
#include "ZombieBrains.generated.h"

/**
 * 
 */
UCLASS()
class TANKSVSZOMBIES_API AZombieBrains : public AAIController
{
	GENERATED_BODY()
	
public:

	virtual void Tick(float DeltaTime) override;

	virtual void Possess(APawn* InPawn) override;
	virtual void UnPossess() override;

protected:
	// Our pawn, pre-cast to a Zombie. Will be NULL if the pawn is NULL or is not a Zombie.
	UPROPERTY(BlueprintReadOnly, Category = "Zombie")
	AZombie* PawnAsZombie;
	
	
};
