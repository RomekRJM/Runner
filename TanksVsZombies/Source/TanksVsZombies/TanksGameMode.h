// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TanksGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TANKSVSZOMBIES_API ATanksGameMode : public AGameMode
{
	GENERATED_BODY()
	

public:
	ATanksGameMode();

	// Every Zombie game actor should snap to this Z value during BeginPlay. E.g. zombies, tanks, missiles. Default is 0.
	UPROPERTY(EditAnywhere)
	float PlayInZPlane;
	
	
};
