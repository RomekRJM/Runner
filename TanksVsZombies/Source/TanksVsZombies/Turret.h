// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "TankStatics.h"
#include "Missile.h"
#include "Turret.generated.h"

UCLASS()
class TANKSVSZOMBIES_API ATurret : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** The name of the socket at the muzzle - used for spawning missiles. */
	static const FName MuzzleSocketName;

protected:
	// Max turn rate degrees/second for turret.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Turret")
	float YawSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turret")
	class ATank* Tank;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret")
	TArray<TSubclassOf<AMissile>> Projectiles;


private:
	// Which way turret is facing
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turret", meta = (AllowPrivateAccess = "true"))
	UArrowComponent* TurretDirection;

	// Sprite for the turret body.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turret", meta = (AllowPrivateAccess = "true"))
	class UPaperSpriteComponent* TurretSprite;

	// Time to delay between Fire1 commands.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Turret", meta = (AllowPrivateAccess = "true"))
	float Fire1Cooldown;

	// If this value is greater than the current game time, Fire1 is ignored because it has been fired too recently.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turret", meta = (AllowPrivateAccess = "true"))
	float Fire1ReadyTime;

	
};
