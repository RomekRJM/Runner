// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/ArrowComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "TankStatics.h"
#include "Tank.generated.h"

// This struct covers all possible tank input schemes.
USTRUCT()
struct FTankInput
{
	GENERATED_BODY()

public:
	// Sanitized movement input
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank Input")
	FVector2D MovementInput;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank Input")
	uint32 bFire1 : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank Input")
	uint32 bFire2 : 1;

	void Sanitize();
	void MoveX(float AxisValue);
	void MoveY(float AxisValue);
	void Fire1(bool bPressed);
	void Fire2(bool bPressed);

private:
	// Internal data, game should never see
	FVector2D RawMovementInput;

};


UCLASS()
class TANKSVSZOMBIES_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Tank")
	const FTankInput& GetCurrentInput() { return TankInput;  };

private:
	//
	void MoveX(float AxisValue);
	void MoveY(float AxisValue);
	void Fire1Pressed();
	void Fire1Released();
	void Fire2Pressed();
	void Fire2Released();

private:
	// Which way tank is facing
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank", meta = (AllowPrivateAccess = "true"))
	UArrowComponent* TankDirection;

	// Sprite for the tank body.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank", meta = (AllowPrivateAccess = "true"))
	class UPaperSpriteComponent* TankSprite;

	// The actor used as the turret
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank", meta = (AllowPrivateAccess = "true"))
	class UChildActorComponent* ChildTurret;

	// Our in-game camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	// Current input for our tank. Sanitized in Tick().
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank Input", meta = (AllowPrivateAccess = "true"))
	FTankInput TankInput;

protected:
	
	// Maximum turn degrees/second
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tank", meta = (ClampMin = "0.0"))
	float YawSpeed;

	// <aximum movement rate (units/second)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tank", meta = (ClampMin = "0.0"))
	float MoveSpeed;

	// Acceleration for our tank, when player is trying to move or change directions.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tank", meta = (ClampMin = "0.0"))
	float MoveAccel;
};
