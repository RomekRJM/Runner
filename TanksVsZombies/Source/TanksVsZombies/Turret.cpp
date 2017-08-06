// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"
#include "Tank.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "PaperSpriteComponent.h"


const FName ATurret::MuzzleSocketName(TEXT("Muzzle"));

// Sets default values
ATurret::ATurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = TurretDirection = CreateDefaultSubobject<UArrowComponent>(TEXT("TurretDirection"));

	TurretSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("TurretSprite"));
	TurretSprite->SetupAttachment(TurretDirection);

	YawSpeed = 180.0f;
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	check(GetParentComponent());
	Super::BeginPlay();
	Tank = Cast<ATank>(GetParentComponent()->GetOwner());
	check(Tank);
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	check(TurretDirection);
	if (Tank != nullptr)
	{
		if (APlayerController* PC = Cast<APlayerController>(Tank->GetController()))
		{
			FVector2D AimLocation;
			if (PC->GetMousePosition(AimLocation.X, AimLocation.Y)) 
			{
				FVector2D TurretLocation = FVector2D::ZeroVector;
				UGameplayStatics::ProjectWorldToScreen(PC, TurretDirection->GetComponentLocation(), TurretLocation, true);

				float DesiredYaw;

				if (UTankStatics::FindLookAtAngle2D(TurretLocation, AimLocation, DesiredYaw))
				{
					FRotator CurrentRotation = TurretDirection->GetComponentRotation();
					float DeltaYaw = UTankStatics::FindDeltaAngleDegrees(CurrentRotation.Yaw, DesiredYaw);
					float MaxDeltaYawThisFrame = YawSpeed * DeltaTime;

					if (MaxDeltaYawThisFrame >= FMath::Abs(DeltaYaw))
					{
						CurrentRotation.Yaw = DesiredYaw;
					}
					else
					{
						CurrentRotation.Yaw += FMath::Sign(DeltaYaw) * MaxDeltaYawThisFrame;
					}
					TurretDirection->SetWorldRotation(CurrentRotation);
				}
			}

			// Handle input.
			const FTankInput& CurrentInput = Tank->GetCurrentInput();
			if (CurrentInput.bFire1 && Projectiles.Num())
			{
				if (UWorld* World = GetWorld())
				{
					float CurrentTime = World->GetTimeSeconds();
					if (Fire1ReadyTime <= CurrentTime)
					{
						FVector Loc = TurretSprite->GetSocketLocation(MuzzleSocketName);
						FRotator Rot = TurretDirection->GetComponentRotation();

						for (TSubclassOf<AActor> Projectile : Projectiles)
						{
							if (AActor* NewProjectile = World->SpawnActor(Projectile))
							{
								NewProjectile->SetActorLocation(Loc);
								NewProjectile->SetActorRotation(Rot);
							}
						}

						// Set the cooldown timer.
						Fire1ReadyTime = CurrentTime + Fire1Cooldown;
					}
				}
			}
		}
	}

}
