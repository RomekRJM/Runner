// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageInterface.generated.h"

UENUM(BlueprintType)
enum class EDamageType : uint8
{
	Unknown,
	HitWithMissile,
	Crushed,
	ZombieSlap
};


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDamageInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TANKSVSZOMBIES_API IDamageInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// setting to 0, to make it not compile, when no implementation
	virtual void ReceiveDamage(int32 IncomingDamage, EDamageType DamageType) = 0;

	virtual int32 GetHealthRemaining() = 0;
	
};
