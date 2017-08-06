// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageInterface.h"
#include "GameFramework/Actor.h"
#include "Missile.generated.h"

UCLASS()
class TANKSVSZOMBIES_API AMissile : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AMissile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	/** Missile move speed. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	float Speed;

	/** Missile radius for collisions. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	float Radius;

	/** Missile damage. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	int DirectDamage;

	/** Describe what this property hits. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	FName MovementCollisionProfile;

protected:
	void Explode();

	FTimerHandle ExplodeTimerHandle;

	/** What to do when the projectile explodes. The base version just destroys the projectile. */
	UFUNCTION(BlueprintNativeEvent, Category = "Projectile")
	void OnExplode();
	virtual void OnExplode_Implementation();

	
	
};
