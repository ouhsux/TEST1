/*/ Fill out your copyright notice in the Description page of Project Settings.


#include "TimeManager.h"

// Sets default values
ATimeManager::ATimeManager()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATimeManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATimeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATimeManager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}*/

#include "TimeManager.h"

// Sets default values
ATimeManager::ATimeManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATimeManager::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
		if (TimeReversalAbilityEnabled)
		{
			CurrentRecordedTime = TMathUtil<float>::Min(ReverseTimeMaximum, CurrentRecordedTime + DeltaSeconds * CurrentTimeFactor);
			if (CurrentRecordedTime <= 0.0f)
			{
				EndTimeReverse();
				CurrentRecordedTime = 0.0f;
			}
		}
}

float ATimeManager::GetTimeFactor()
{
	return CurrentTimeFactor;
}
bool ATimeManager::GetAbilityAvailible()
{
	return TimeReversalAbilityEnabled && CurrentRecordedTime >= ReverseTimeThreshold;
}

float ATimeManager::GetCurrentReversableTime()
{
	return CurrentRecordedTime;
}

// Called when the game starts or when spawned
void ATimeManager::BeginPlay()
{
	Super::BeginPlay();
	CurrentTimeFactor = NormalTimeFactor;
}

void ATimeManager::BeginTimeReverse()
{
	if (GetAbilityAvailible()) {
		CurrentTimeFactor = ReverseTimeFactor;
	}
	
}

void ATimeManager::EndTimeReverse()
{
	CurrentTimeFactor = NormalTimeFactor;
}

void ATimeManager::EnableTimeReverseAbility()
{
	if (!TimeReversalAbilityEnabled)
	{
		CurrentRecordedTime = 0.0f;
		TimeReversalAbilityEnabled = true;
	}
}

void ATimeManager::DisableTimeReverseAbility()
{
	if (TimeReversalAbilityEnabled)
	{
		EndTimeReverse();
		TimeReversalAbilityEnabled = false;
	}
}

