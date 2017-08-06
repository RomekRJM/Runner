// Fill out your copyright notice in the Description page of Project Settings.

#include "TankStatics.h"

float UTankStatics::FindDeltaAngleDegrees(float A1, float A2)
{
	// Find the difference
	float Delta = A2 - A1;

	if (Delta > 180.0f)
	{
		Delta = Delta - 360.0f;
	}
	else if (Delta < -180.0f)
	{
		Delta = Delta + 360.0f;
	}

	return Delta;
}


bool UTankStatics::FindLookAtAngle2D(const FVector2D& Start, const FVector2D& Target, float& Angle)
{
	FVector2D Normal = (Target - Start).GetSafeNormal();
	if (!Normal.IsNearlyZero())
	{
		Angle = FMath::RadiansToDegrees(FMath::Atan2(Normal.Y, Normal.X));
		return true;
	}

	return false;
}

ATanksGameMode* UTankStatics::GetTanksGameMode(UObject* WorldContextObject)
{
	return Cast<ATanksGameMode>(UGameplayStatics::GetGameMode(WorldContextObject));
}

void UTankStatics::PutInZPlane(AActor* ActorToMove)
{
	if (ATanksGameMode* GM = UTankStatics::GetTanksGameMode(ActorToMove))
	{
		FVector Loc = ActorToMove->GetActorLocation();
		Loc.Z = GM->PlayInZPlane;
		ActorToMove->SetActorLocation(Loc);
	}
}

void UTankStatics::PlayFlipbook(UPaperFlipbookComponent* Component, UPaperFlipbook* NewFlipbook, bool bLooping, float PlayRate /*= 1.0f*/, bool bPlayFromStart /*= false*/)
{
	Component->SetFlipbook(NewFlipbook);
	Component->SetLooping(bLooping);
	Component->SetPlayRate(PlayRate);
	if (bPlayFromStart)
	{
		Component->PlayFromStart();
	}
	else
	{
		Component->Play();
	}
}